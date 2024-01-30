#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "seq_text_proc.h"
#include "par_text_proc.h"
#include <chrono>

int main() {
    
    std::string folder = "./data/";
    std::vector<std::string> allPaths = {"a.txt", "b.txt", "c.txt", "d.txt", "e.txt", "f.txt"};
    std::ofstream outputFile("./stat.txt");

    for (const std::string path : allPaths){
        std::string pathFile = folder + path;
        std::vector<std::string> words = get_content_file(pathFile, "word");
        
        std::cout << pathFile << std::endl;

        auto t0 = std::chrono::high_resolution_clock::now();

        std::vector<std::pair<std::string, std::string>> bigrams = generateBigrams(words);
        auto t1 = std::chrono::high_resolution_clock::now();


        std::vector<std::pair<std::string, std::string>> bigramsPara2 = generateBigramsPara(words, 2);
        auto t2 = std::chrono::high_resolution_clock::now();
        std::vector<std::pair<std::string, std::string>> bigramsPara4 = generateBigramsPara(words, 4);
        auto t3 = std::chrono::high_resolution_clock::now();
        std::vector<std::pair<std::string, std::string>> bigramsPara6 = generateBigramsPara(words, 6);
        auto t4 = std::chrono::high_resolution_clock::now();
        std::vector<std::pair<std::string, std::string>> bigramsPara8 = generateBigramsPara(words, 8);
        auto t5 = std::chrono::high_resolution_clock::now();
        

        auto dtSeq = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
        auto dtPar2 = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
        auto dtPar4 = std::chrono::duration_cast<std::chrono::nanoseconds>(t3 - t2).count();
        auto dtPar6 = std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count();
        auto dtPar8 = std::chrono::duration_cast<std::chrono::nanoseconds>(t5 - t4).count();

        //std::cout << "Time in sequential : " << static_cast<double>(dtSeq) / 1'000'000'000.0 << " seconds"<<std::endl;
        //std::cout << "Time in parallel : " << static_cast<double>(dtPar) / 1'000'000'000.0 << " seconds"<<std::endl;
        
        //std::cout << "The best is " << (dtSeq < dtPar ? "sequential" : "parallel") << std::endl;
        outputFile << words.size() << std::endl 
        << dtSeq << std::endl 
        << dtPar2 << std::endl 
        << dtPar4 << std::endl 
        << dtPar6 << std::endl 
        << dtPar8 << std::endl 
        << std::endl;
    }
    outputFile.close();
    
    return 0;
}
