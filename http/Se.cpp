int main(int argc,char* argv[])
{
  int lfd,cfd,n,i;
  struct sockaddr_in serv_addr,clie_addr;
  socklen_t clie_addr_len;
  char buf[BUFSIZ];
  lfd = socket(AF_INET,SOCK_STREAM,0);
  if(lfd == -1)//检查返回值
  {
   perror("socket");
   exit(EXIT_FAILURE);
  }
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(SERV_PORT);
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  bind(lfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

  listen(lfd,32);//同时允许有32个客户端发起连接

  clie_addr_len = sizeof(clie_addr);
  cfd = accept(lfd,(struct sockaddr*)&clie_addr,&clie_addr_len);
while(1)
{
  n = read(cfd,buf,sizeof(buf));
  for(i = 0;i < n;++i)
  {
     buf[i] = toupper(buf[i]);
  }
  write(cfd,buf,n);
}
  close(lfd);
  close(cfd);
}