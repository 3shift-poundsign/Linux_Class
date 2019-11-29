#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h> 
#include <stdlib.h>
#define PORT 9999
#define SIZE 1024
int Creat_Socket()
{
	int listen_socket;
	if((listen_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket error!\n");
		return -1;
	}
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int ret;
	if((ret = bind(listen_socket, (struct sockaddr *)&addr, sizeof(addr))) == -1)
	{
		perror("bind error!\n");
		return -1;
	}
	if((ret = listen(listen_socket, 5)) == -1)
	{
		perror("listen error!\n");
		return -1;
	}
	return listen_socket;
}

int wait_client(int listen_socket)
{
	struct sockaddr_in cliaddr;
	int addrlen = sizeof(cliaddr);
	printf("waitting for client connect...\n");
	int client_socket;
	if((accept(listen_socket, (struct sockaddr *)&cliaddr, &addrlen)) == -1)
	{
		perror("accept error!\n");
		return -1;
	}
	printf("success to connect client: %s\n", inet_ntoa(cliaddr.sin_addr));
	return client_socket;
}

void hanld_client(int listen_socket, int client_socket)
{
	char buf[SIZE];
	FILE *fp;
	if((fp = fopen("test","w")) == NULL)
	{
		printf("Open file error!\n");
		exit(0);
	}
	while(1)
	{
		int ret;
		if((ret = read(client_socket, buf, SIZE-1)) == -1||0)
		{
			perror("read error!\n");
			break;
		}
		buf[ret] = '\0';
		printf("buf = %s\n", buf);
		write(client_socket, buf, ret);
		if(strncmp(buf, "end", 3) == 0)
		{
			break;
		}
		strcat(buf, "\n");
		fputs(buf,fp);
	}
	fclose(fp);
	close(client_socket);
}



void main()
{
	int listen_socket = Creat_Socket();
	int client_socket = wait_client(listen_socket);
	hanld_client(listen_socket, client_socket);
	close(listen_socket);
}
