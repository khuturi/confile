#include"file.h"
bool file(std::string filename,std::filesystem::path mainfolnder){
    for(const auto& entry:std::filesystem::directory_iterator(mainfolnder)){
        std::string name=entry.path().filename().string();
        if(entry.is_directory()){
            if(file(filename,mainfolnder / name)){
                return 1;
            }
        }else{
            if(name == filename){
                std::cout<<mainfolnder.string()<<"/"<<filename<<std::endl;
                return 1;
            }
        }
    }
    return 0;
}