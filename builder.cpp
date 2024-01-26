#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

int main(){

    std::string build_folder = "build";



    std::string name = "main";
    
    int result;

    std::string cppOrdered  = "seq_text_proc.cpp par_text_proc.cpp main.cpp";

    
    std::string compileCommand = "g++ -fopenmp -o " + build_folder + "/" + name + " " + cppOrdered;
    std::cout << "Compiling ..." << std::endl;
    result = std::system(compileCommand.c_str());

    if (result == 0) {
        std::cout << "Compilation successful!" << std::endl;
    } else {
        std::cerr << "Compilation failed. Error code: " << result << std::endl;
    }
    
    

    

    return 0;
}