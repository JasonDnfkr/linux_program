#include "../ch09.h"

int g = 0;
int fd_out;

void p(int pid){
    g++;
    char buf[20];
    memset(buf, 0,20); 
    sprintf(buf, "pid %d : g = %d\n", pid, g);
    write(fd_out, buf, strlen(buf));
}

void d(){
    pid_t pid;
    pid = vfork();

    if(pid<0){
        exit(-1);
    }
    else if(pid==0){    
        p(getpid());
        d();
        exit(0);
    }
    else{
        p(getpid());

        pid_t pid2;
        pid2 = vfork();
        if(pid<0){
            exit(-1);
        }
        else if(pid==0){
            p(getpid());
            d();
            exit(0);
        }else{
            exit(0);
        }
    }
}

int main(){
    fd_out = open("./out2.txt", O_WRONLY|O_CREAT|O_TRUNC, MODE);
    d();
}