#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <util/util.h>

#define MAXRECVSTRING 255

int main(int argc, char *argv[])
{
  int sock;
  struct sockaddr_in broadcastAddr;
  unsigned int broadcastPort;
  char recvString[MAXRECVSTRING + 1];
  int recvStringLen;

  if(argc != 2)
  {
    fprintf(stderr, "Usage: %s <Broadcast Port>\n", argv[0]);
    exit(1);
  }

  broadcastPort = atoi(argv[1]);

  if((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    dieWithError("socket() failed");

  memset(&broadcastAddr, 0, sizeof(broadcastAddr));

  broadcastAddr.sin_family = AF_INET;
  broadcastAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  broadcastAddr.sin_port = htons(broadcastPort);

  if(bind(sock, (struct sockaddr *)&broadcastAddr, sizeof(broadcastAddr)) < 0)
    dieWithError("bind() failed");

  if((recvStringLen = recvfrom(sock, recvString, MAXRECVSTRING, 0, NULL, 0)) < 0)
    dieWithError("recvfrom() failed");

  recvString[recvStringLen] = '\0';
  printf("Received: %s\n", recvString);

  close(sock);
  exit(0);

  return EXIT_SUCCESS;
}