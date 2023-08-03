#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <string.h>
#include <wait.h>

#define MAXLINE 1024 //最大行读取数 
#define MAXARGS 128	//最大参数个数,linux最大支持128K,POSIX最大支持4096[我的记忆是这样的,实用时自己查资料] 

void eval(char *cmdline);//执行 
int parseline(char *buf, char **argv);//解析命令行 
int builtin_command(char **argv);//构建命令 

int main(int argc,char *argv)
{
        char cmdline[MAXLINE];//用户接收用户输入 
        while(1){//构建一个死循环,只有收到信号或者输入quit时退出 
                printf("myshell> ");//提示符如果有需要可以使用系统调用获得用户名称等信息填充 
                fgets(cmdline,MAXLINE,stdin);//从标准输入设备读入 
                if(feof(stdin)) 
                        exit(EXIT_FAILURE);
                eval(cmdline);//执行读入的命令 
        }
}

void eval(char *cmdline)

{
        char * argv[MAXARGS];//最大只允许128个参数,理论上是够了的 
        char buf[MAXLINE];//最大行内容 
        int bg;//是否是后台作业   1 是   0 不是 
        pid_t pid;//创建子进程的进程编号 

        strcpy(buf,cmdline);//还记得我说过,如果对传递过来的字符串处理,记得拷贝后处理副本哦 
        bg = parseline(buf,argv);//解析命令并返回是否是后台作业 
        if(argv[0] == NULL)//如果不存在第一个参数,意味着直接输入了空行,则继续循环显示提示符 
                return;
        if(!builtin_command(argv)){//如果不是quit(返回0),则代表需要执行相应命令 
                if((pid = fork()) == 0){//派生一个子进程用于执行业务逻辑 
                        if(execvp(argv[0],argv) < 0){//此处可以选择execve家族的相关函数,本例为了简便使用了带环境变量的调用execvp 
                                printf("%s: Command not found. \n",argv[0]); 
                                exit(0);
                        }
                }

                if(!bg){//如果不是后台进程 
                        int status;
                        if(waitpid(pid,&status,0) < 0)//阻塞父进程,等待回收子进程 
                                perror("waitpid");
                }else{//后台进程提示 
                        printf("%d %s",pid,cmdline);
                }
        }
        return;

}
int parseline(char *buf, char **argv)
{
        char *delimit;//定义分隔符 
        int argc;//参数个数 
        int bg;//是否是后台进程 
        buf[strlen(buf)-1] = ' ';//将最后一个结束符号替换为 空格  ,确保回车+换行 符号能够正确处理 
        while(*buf && (*buf == ' ')){// 忽略前置的空格字符 
                buf++;
        }
        argc = 0;
        while((delimit = strchr(buf,' '))){//查找字符串,返回第一个匹配的地方,此例中匹配空格为分隔符 
                argv[argc++] = buf; 
                *delimit = '\0';
                buf = delimit + 1;
                while(*buf && (*buf == ' ')){//忽略空格 
                        buf++;
                }
        }
        argv[argc] = NULL;//添加哨兵,意味着命令参数结束 
        if(argc == 0)//忽略空行输入 
                return 1;
        if((bg = (*argv[argc-1] == '&')) != 0)//如果最后一个参数是 & 代表是后台作业 
                argv[--argc] = NULL;//添加哨兵 

        return bg;
}
int builtin_command(char **argv)
{
        if(!strcmp(argv[0],"quit"))//退出条件 
                exit(0);
        if(!strcmp(argv[0],"&"))//  
                return 1;
        return 0;
}

