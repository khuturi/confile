#include"cat.h"
void cat(std::string filename){
    std::ifstream inputfile(filename);
    if(inputfile.is_open()){
        std::string line;
        while(std::getline(inputfile,line)){
            std::cout<<line<<std::endl;
        }
        inputfile.close();
    }else{
        std::cout << "Unable to open the file." << std::endl;
    }
}