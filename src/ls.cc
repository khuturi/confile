#include"ls.h"
void ls(){
    std::filesystem::path currentpath = std::filesystem::current_path();
    std::cout<<currentpath<<"下的文件夹及文件：";
    for(const auto& entry:std::filesystem::directory_iterator(currentpath)){
        std::string name=entry.path().filename().string();
        if(entry.is_directory()){
            std::cout<<"[文件夹]"<<name<<std::endl;
        }else if(entry.is_regular_file()){
            std::cout<<"[文件名]"<<name<<std::endl;
        }else {
            // 处理符号链接、设备文件等特殊文件（可选）
            std::cout<< "[其他]" << name << std::endl;
        }
    }
}