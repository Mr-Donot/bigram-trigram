#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

int main(){

    std::string build_folder = "build";

    std::vector<std::string> cppFiles = {"main"};
    std::size_t vectorSize = cppFiles.size();
    
    int result;

    for (std::size_t i = 0 ; i < vectorSize ; i++){
        std::string compileCommand = "g++ -Wall -o " + build_folder + "/" + cppFiles[i] + " " + cppFiles[i] + ".cpp";
        std::cout << "Compiling " + cppFiles[i] + ".cpp ..." << std::endl;
        result = std::system(compileCommand.c_str());

        if (result == 0) {
            std::cout << "Compilation successful!" << std::endl;
        } else {
            std::cerr << "Compilation failed. Error code: " << result << std::endl;
        }
    }
    

    

    return 0;
}