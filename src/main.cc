#include <iostream>
#include "ls.h"
#include "cat.h"
#include "grep.h"
#include "file.h"

void printhelp(){
    std::cout   <<"命令行工具：\n"
                <<"ls:打印当前文件夹下的文件与文件夹\n"
                <<"cat <FileName>:查看文件内容\n"
                <<"grep <Pattern> <filename>:通过正则表达式搜索对应的行\n"
                <<"file <FileName>[Path]:递归搜索文件\n";
}

int main(int argc, char const *argv[])
{
    // int a=32,b=64;
    // cout<<"最小值为"<<_MIN(a,b)<<endl;
    // cout<<"最大值为"<<_MAX(a,b)<<endl;
    if(argc == 1){
        std::cout<<"参数列表错误"<<std::endl;
        printhelp();
        return 0;
    }
    std::string command = argv[1];
    if(command == "ls"){
        ls();
    }else if(command == "cat"){
        cat(argv[2]);
    }else if(command == "grep"){
        grep(argv[2],argv[3]);
    }else if(command =="file"){
        switch(argc){
            case 3:
                file(argv[2]);
                break;
            case 4:
                file(argv[2],argv[3]);
                break;
        }
    }
    return 0;
}
