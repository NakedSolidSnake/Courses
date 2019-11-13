#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <util/util.h>

#define ECHOMAX        255
#define TIMEOUT_SECS   2
#define MAXRIES        5

int tries = 0;

void catchAlarm(int ignored);

int main(int argc, char *argv[])
{
  int sock;
  struct sockaddr_in echoServAddr;
  struct sockaddr_in fromAddr;
  unsigned short echoServPort;
  unsigned int fromSize;
  struct sigaction myAction;
  
  char *servIP;
  char *echoString;
  char echoBuffer[ECHOMAX + 1];
  int echoStringLen;
  int respStringLen;

  if((argc < 3) || (argc > 4))
  {
    fprintf(stderr, "Usage: %s <Server IP> <Echo Word> [<Echo Word>]\n", argv[0]);
    exit(1);
  }

  servIP = argv[1];
  echoString = argv[2];

  if((echoStringLen = strlen(echoString)) > ECHOMAX)
    dieWithError("Echo word too long");

  if (argc == 4)
    echoServPort = atoi(argv[3]);
  else
    echoServPort = 7;

  if((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    dieWithError("socket() failed");

  myAction.sa_handler = catchAlarm;

  if(sigfillset(&myAction.sa_mask) < 0)
    dieWithError("sigfillset() failed");

  myAction.sa_flags = 0;

  if(sigaction(SIGALRM, &myAction, 0) < 0)
    dieWithError("sigaction() failed for SIGALRM" );

  memset(&echoServAddr, 0, sizeof(echoServAddr));

  echoServAddr.sin_family = AF_INET;
  echoServAddr.sin_addr.s_addr = inet_addr(servIP);
  echoServAddr.sin_port = htons(echoServPort);

  if(sendto(sock, echoString, echoStringLen, 0, (struct sockaddr *)&echoServAddr, sizeof(echoServAddr)) != echoStringLen)
    dieWithError("sendto() sent a different number of bytes than expected");

  fromSize = sizeof(fromAddr);
  alarm(TIMEOUT_SECS);

  while((respStringLen = recvfrom(sock, echoBuffer, ECHOMAX, 0, (struct sockaddr*)&fromAddr, &fromSize)) < 0)
    if(errno == EINTR)
    {
      if(tries < MAXRIES)
      {
        printf("timeout, %d more tries...\n", MAXRIES - tries);
        if(sendto(sock, echoString, echoStringLen, 0, (struct sockaddr *)&echoServAddr, sizeof(echoServAddr)) != echoStringLen)
          dieWithError("sendto() failed");
        alarm(TIMEOUT_SECS);
      }
      else {
        dieWithError("No Response");
      }
    }
    else 
      dieWithError("recvfrom() failed");

  alarm(0);
  echoBuffer[respStringLen] = '\0';
  printf("Received: %s\n", echoBuffer);
  close(sock);
  
  return EXIT_SUCCESS;
}

void catchAlarm(int ignored)
{
  tries += 1;
}
