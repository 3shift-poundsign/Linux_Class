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
	FILE *fp;
	int client_fd;
	int ret;
	char ch[2];
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

	if((fp = fopen("./text","r")) == NULL)
	{
		perror("fail to open file");
		return -1;
	}
	printf("Open file success\n");

	printf("Send file to server? (Y|N): ");
	scanf("%s",ch);
	if(!strcmp(ch,"y") || !(strcmp(ch,"Y")))
	while(fgets(buf,N,fp) != NULL)
	{
		ret = sendto(client_fd,buf,strlen(buf),0,(struct sockaddr*)&server_addr,addrlen);
		if(ret == -1)
		{
			perror("fail to send");
			return -1;
		}
		printf("Send: %s",buf);
		memset(buf,0,N);
	}
	fclose(fp);

	while(1)
	{
		printf("Please input message:");
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
