#ifndef __TCPECHOSERVER_H
#define __TCPECHOSERVER_H

void handleTCPClient(int clntSocket);
int createTCPServerSocket(unsigned short port);
int acceptTCPConnection(int servSock);

#endif
