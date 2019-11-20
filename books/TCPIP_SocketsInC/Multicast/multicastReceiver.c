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
  struct sockaddr_in multicastAddr;
  char *multicastIP;
  unsigned int multicastPort;
  char recvString[MAXRECVSTRING + 1];
  int recvStringLen;

  struct ip_mreq multicastRequest;

  if(argc != 3)
  {
    fprintf(stderr, "Usage: %s <Multicast IP> <Multicast Port>\n", argv[0]);
    exit(1);
  }

  multicastIP = argv[1];
  multicastPort = atoi(argv[2]);

  if((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    dieWithError("socket() failed");

  memset(&multicastAddr, 0, sizeof(multicastAddr));

  multicastAddr.sin_family = AF_INET;
  multicastAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  multicastAddr.sin_port = htons(multicastPort);

  if(bind(sock, (struct sockaddr *)&multicastAddr, sizeof(multicastAddr)) < 0)
    dieWithError("bind() failed");

  /* Specify the multicast group */
  multicastRequest.imr_multiaddr.s_addr = inet_addr(multicastIP);
  multicastRequest.imr_interface.s_addr = htonl(INADDR_ANY);

  /* Join the multicast group */
  if(setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *)&multicastRequest, sizeof(multicastRequest)) < 0)
    dieWithError("setsockopt() failed");

  if((recvStringLen = recvfrom(sock, recvString, MAXRECVSTRING, 0, NULL, 0)) < 0)
    dieWithError("recvfrom() failed");

  recvString[recvStringLen] = '\0';
  printf("Received: %s \n", recvString);

  close(sock);
  exit(0);

  return EXIT_SUCCESS;
}
