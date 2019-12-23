#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <unistd.h>
#define N 64

int main()
{
	int client_fd;
	struct sockaddr_in server_addr,client_addr;
	socklen_t addrlen = sizeof(struct sockaddr_in);
	int ret;
	char buf[N];
	memset(buf,0,N);
	client_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(client_fd == -1)
	{
		perror("Fail to socket");
		return -1;
	}
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8888);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = connect(client_fd, (struct sockaddr *)&server_addr, addrlen);
	if(ret == -1)
	{
		perror("Fail to connect");
		return -1;
	}
	while(1)
	{
		printf("Please input message: ");
		scanf("%s",buf);
		ret = send(client_fd, buf, strlen(buf), 0);
		if(ret == -1)
		{
			perror("Fail to send");
			//return -1;
		}
		else if(ret > 0)
		{
			printf("Send: %s\n",buf);
			memset(buf,0,N);		
		}
	}
}
