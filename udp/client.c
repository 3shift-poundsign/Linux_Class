#include <stdio.h>
#include <errno.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <string.h>
#define N 64

int main()
{
	int client_fd;
	int ret;
	socklen_t addrlen = sizeof(struct sockaddr_in);
	char buf[N];
	struct sockaddr_in server_addr;
	memset(buf,0,N);
	memset(&server_addr,0,addrlen);
	client_fd = socket(AF_INET,SOCK_DGRAM,0);
	if(client_fd == -1)
	{
		perror("fail to socket");
		return -1;
	}
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8888);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	while(1)
	{
		scanf("%s",buf);
		ret = sendto(client_fd,buf,strlen(buf),0,(struct sockaddr*)&server_addr,addrlen);
		if(ret == -1)
		{
			perror("fail to send");
			return -1;
		}
		printf("Send: %s\n",buf);
		memset(buf,0,N);
	}
	return 0;
}
