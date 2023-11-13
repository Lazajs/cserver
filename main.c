#include<stdio.h>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib") //Winsock Library

int main(int argc , char *argv[])
{
	// Initialize winsock
	WSADATA wsa;
	SOCKET s;
	struct sockaddr_in server;
	char *message , server_reply[2000];
	int recv_size;

	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("Failed. Error Code : %d",WSAGetLastError());
		return 1;
	}

	//Create a socket
	if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d" , WSAGetLastError());
	}
	
	server.sin_addr.s_addr = inet_addr("142.251.133.36"); // If IP not working, try running ip.c
	server.sin_family = AF_INET;
	server.sin_port = htons( 80 );

	//Connect
	if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		printf("connect error code: %d\n", 	WSAGetLastError());
		return 1;
	}
	
	printf("Connected\n");

	//Send 
	message = "GET / HTTP/1.1\r\n\r\n";
	if( send(s , message , strlen(message) , 0) < 0)
	{
		printf("send error code: %d\n", 	WSAGetLastError());
		return 1;
	}
	printf("Data Send\n");
	
	//Receive 
	if((recv_size = recv(s , server_reply , 2000 , 0)) == SOCKET_ERROR)
	{
		printf("recv error code: %d\n", 	WSAGetLastError());
	}
	
	printf("Reply received\n");

	server_reply[recv_size] = '\0';
	printf(server_reply);


	closesocket(s);
	WSACleanup();
	return 0;
}