#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>

int main(int argc, char **argv)
{
	// create socket
   int network_socket;
   network_socket = socket(AF_INET, SOCK_STREAM, 0); // TCP
	
	// specify an address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002); // byte ordering
	server_address.sin_addr.s_addr = INADDR_ANY;

	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	// check for connection
	if (connection_status == -1)
	{
		printf("There was an error making a connection");
	}
	

	
	while(1)
	{	
		char server_message[256];
		scanf("%s",server_message);
		send(network_socket, server_message, sizeof(server_message), 0);
		char server_response[256];
		recv(network_socket, &server_response, sizeof(server_response), 0);
		printf("%s\n", server_response);
	}
	
	
	// print out server's response
//	printf("\nThe Server Sent The Data : %s\n", server_response);
	
	// close the socket
	close(network_socket);
	
	return 0;
}
