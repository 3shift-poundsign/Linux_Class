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
	int server_fd,client_fd;
	struct sockaddr_in server_addr,client_addr;
	socklen_t addrlen = sizeof(struct sockaddr_in);
	int ret;
	char buf[N];
	memset(buf,0,N);
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(server_fd == -1)
	{
		perror("Fail to socket");
		return -1;
	}
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8888);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	ret = bind(server_fd, (struct sockaddr *)&server_addr, addrlen);
	if(ret == -1)
	{
		perror("Fail to bind");
		return -1;
	}
	ret = listen(server_fd, 5);
	if(ret == -1)
	{
		perror("Fail to listen");
		return -1;
	}
	client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen);
	if(client_fd == -1)
	{
		perror("Fail to accept");
		return -1;
	}
	while(1)
	{
		ret = recv(client_fd, buf, N, 0);
		if(ret < 0)
		{
			perror("Fail to recv");
			return -1;
		}
		else if(ret == 0)
		{
			perror("Peer exit");
			close(server_fd);
			close(client_fd);
			return -1;
		}
		else
		{
			printf("Recv: %s\n",buf);
			memset(buf,0,N);
		}
	}
}
