#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>

#include<netdb.h>

void print_ip(int ip)
{
    unsigned char bytes[4];
    bytes[0] = ip & 0xFF;
    bytes[1] = (ip >> 8) & 0xFF;
    bytes[2] = (ip >> 16) & 0xFF;
    bytes[3] = (ip >> 24) & 0xFF;   
    printf("%d.%d.%d.%d\n", bytes[0], bytes[1], bytes[2], bytes[3]);        
}

void main()
{
	
	//	Given the name of a host, gethostbyname () returns a hostent structure containing a description of the named host. 
	
	struct hostent * h = gethostbyname("localhost");
	
	if(h)
	{
		puts(h->h_name);
		print_ip(( * ((unsigned long *) h->h_addr_list [ 0] )));
	}
	else
	{
		herror("gethostbyname");
	}
	
	printf("\n");
	
	struct protoent *servptr;
	char plist[3][10] = {"ip", "tcp", "udp"};
	
	for(int i = 0; i < 3; i++)
	{
		servptr = getprotobyname(plist[i]);
		printf("%s %d\n", servptr->p_name, servptr->p_proto);
	}
	
	
	// Given the name of a service (e.g., echo) and the protocol implementing that service, getservbyname() returns a servent structure containing a 		//	description of the named service. 	
	
	printf("\n");
	
	struct servent * s = getservbyname("echo", "tcp");	
	
	printf("%s %d %s", s->s_name, s->s_port, s->s_proto);

}
