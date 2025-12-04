#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

void print_dir(std::string path, bool print_hidden = false){

    try
    {
        std::cout << path << ":\n";

        for(auto entry : fs::directory_iterator(path)){
            std::string path_name = entry.path().filename().string();

            if(!print_hidden && path_name[0] == '.'){
                continue;
            }

            std::cout << "  " <<path_name << std::endl;
        }

        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Cannot access " << path << '\n';
        return;
    }
    
        
}


int main(int argc, char const *argv[]){

    bool print_hidden = false;

    if(argc == 1){
        print_dir(".", print_hidden);
    }
    else {
        bool first = false;
        for (size_t i = 1; i < argc; i++){
            if(argv[i][0] == '-'){
                if(std::string(argv[i]) == "-h"){
                    print_hidden = true;
                }
                else{
                    std::cout << "invalid flag!\n";
                    return 1;
                }
            }
            else{
                print_dir("./" + std::string(argv[i]));
            }
            
        }
        
    }
    
    

    return 0;
}

