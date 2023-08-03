#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
char path[1024];//要查找的路径名 
char name[128];//要查找的文件名 
void myls(char *path,char *name){
	char apath[1024];	//存储绝对路径
	char newpath[1024]; //递归时存储临时的路径 
	DIR *dir;           //千万不能设为全局变量
	struct dirent *ptr;
	dir=opendir(path);  //根据传入参数打开指定路径 
	if(dir!=NULL){//存在该目录时 
	while((ptr=readdir(dir))!=NULL){
		if(ptr->d_type==4/*DT_DIR*/&&strcmp(ptr->d_name,".")!=0&&strcmp(ptr->d_name,"..")!=0){ //递归调用深度遍历目录 
		    if(strcmp(ptr->d_name,name)==0){//如果找到了匹配的记录,则拼接并打印路径 
		        strcpy(apath,path);               //不能直接获取绝对路径,将路径path内容拷贝到临时路径apath中 
		        if(apath[strlen(apath)-1]=='/'){   //判断地址格式,如果结尾是/则直接添加文件名即可 
		          strcat(apath,ptr->d_name);
		        }else{//如果结尾不是/则添加/分隔符并追加文件名 
		          strcat(apath,"/");
		          strcat(apath,ptr->d_name);
		        }
			  	printf("%s\n",apath);               //打印绝对地址
		    }
			//如果没有对应文件则拼接路径后用于递归调用 
			if(path[strlen(path)-1]=='/'){
				sprintf(newpath,"%s%s",path,ptr->d_name);//路径的拼接 
			}else{
				sprintf(newpath,"%s/%s",path,ptr->d_name);
			}
			myls(newpath,name);  //递归循环调用 
		}else if(strcmp(ptr->d_name,".")!=0&&strcmp(ptr->d_name,"..")!=0&&strcmp(ptr->d_name,name)==0){  //找出同名文件
			strcpy(apath,path);
			if(apath[strlen(apath)-1]=='/'){//路径拼接 
				strcat(apath,ptr->d_name);
			}else{
				sprintf(apath,"%s/%s",apath,ptr->d_name);
			}
			printf("%s\n",apath);//打印绝对路径 
		}
	}//while结束 
	closedir(dir);//关闭目录资源 
	}//存在目录的判断分支结束 
	else{//如果目录不能访问,则提示错误 
		printf("opendir error %s, need permission!\n",path);
	}
}//自定义的函数结束 
int main(void){
	while(1){
		printf("path:");       //查找目录
		scanf("%s",path);      //文件名称
		printf("file:");
		scanf("%s",name);
		myls(path,name);
	}
}
