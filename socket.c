#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>  
#include <unistd.h>  
#include <errno.h>  
  
#define SERVER_IP "127.0.0.1"  // 服务器IP地址  
#define SERVER_PORT 8080       // 服务器端口号  
#define BUFFER_SIZE 1024       // 缓冲区大小  
  
int main() {  
    int sockfd; // 套接字文件描述符  
    struct sockaddr_in server_addr; // 服务器地址结构体  
    char buffer[BUFFER_SIZE]; // 数据缓冲区  
  
    // 创建套接字  
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {  
        perror("socket creation failed");  
        exit(EXIT_FAILURE);  
    }  
  
    // 设置服务器地址结构体  
    memset(&server_addr, 0, sizeof(server_addr));  
    server_addr.sin_family = AF_INET;  
    server_addr.sin_port = htons(SERVER_PORT);  
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {  
        perror("invalid address/Address not supported");  
        exit(EXIT_FAILURE);  
    }  
  
    // 连接到服务器  
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {  
        perror("connect failed");  
        exit(EXIT_FAILURE);  
    }  
  
    // 发送数据到服务器  
    strcpy(buffer, "Hello, Server!");  
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {  
        puts("send failed");  
    }

    // 关闭套接字
    close(sockfd);

    return 0;
}