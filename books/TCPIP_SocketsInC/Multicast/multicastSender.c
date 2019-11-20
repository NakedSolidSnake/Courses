#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <util/util.h>

int main(int argc, char *argv[])
{

  int sock;
  struct sockaddr_in multicastAddr;
  char *multicastIP;
  unsigned short multicastPort;
  char *sendString;
  unsigned char multicastTTL;
  unsigned int sendStringLen;

  if((argc < 4) || (argc > 5))
  {
    fprintf(stderr, "Usage: %s <Multicast Address> <Port> <Send String> [<TTL>]\n", argv[0]);
    exit(1);
  }

  multicastIP = argv[1];
  multicastPort = atoi(argv[2]);
  sendString = argv[3];

  if(argc == 5)
    multicastTTL = atoi(argv[4]);
  else
    multicastTTL = 1;

  if((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    dieWithError("socket() failed");

  if(setsockopt(sock, IPPROTO_IP, IP_MULTICAST_TTL, (void *)&multicastTTL, sizeof(multicastTTL)) < 0)
    dieWithError("setsockopt() failed");

  memset(&multicastAddr, 0, sizeof(multicastAddr));

  multicastAddr.sin_family = AF_INET;
  multicastAddr.sin_addr.s_addr = inet_addr(multicastIP);
  multicastAddr.sin_port = htons(multicastPort);

  sendStringLen = strlen(sendString);
  for(;;)
  {
    if(sendto(sock, sendString, sendStringLen, 0, (struct sockaddr *)&multicastAddr, sizeof(multicastAddr)) != sendStringLen)
      dieWithError("sendto() sent a different number of bytes than expected");

    sleep(3);
  }
  return EXIT_SUCCESS;
}
