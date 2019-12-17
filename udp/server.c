#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#define N 64

int main()
{
	int server_fd;
	int ret;
	char buf[N];
	socklen_t addrlen = sizeof(struct sockaddr_in);
	struct sockaddr_in server_addr,client_addr;
	memset(buf,0,N);
	memset(&server_addr,0,addrlen);
	memset(&client_addr,0,addrlen);
	server_fd = socket(AF_INET,SOCK_DGRAM,0);
	if(server_fd == -1)
	{
		perror("fail to socket");
		return -1;
	}
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8888);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	ret = bind(server_fd,(struct sockaddr *)&server_addr,addrlen);
	if(ret == -1)
	{
		perror("fail to bind");
		return -1;
	}

	while(1)
	{
		ret = recvfrom(server_fd,buf,N,0,(struct sockaddr*)&client_addr,&addrlen);
		if(ret == -1)
		{
			perror("fail to recv");
			return -1;
		}
		else if(ret < 0)
		{
			perror("perr exit");
			return -1;
		}
		else
		{
			printf("Recv: %s\n",buf);
			memset(buf,0,N);
		}
	}
	return 0;
}
