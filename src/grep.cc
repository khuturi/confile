#include"grep.h"
void grep(std::string pattern,std::string filename){
    std::regex r(pattern);
    std::ifstream inputfile(filename);
    std::smatch results;
    if(inputfile.is_open()){
        std::string line;
        while(std::getline(inputfile,line)){
            if(std::regex_match(line,results,r)){
                std::cout<<line<<std::endl;
            }
        }
        inputfile.close();
    }else{
        std::cout << "Unable to open the file." << std::endl;
    }
}