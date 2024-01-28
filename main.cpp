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
    std::vector<std::string> allPaths = {"very_small.txt", "small.txt", "middle.txt", "almost_big.txt", "quite_big.txt", "big.txt"};
    std::ofstream outputFile("./stat.txt");

    for (const std::string path : allPaths){
        std::string pathFile = folder + path;
        std::vector<std::string> words = get_content_file(pathFile);
        size_t nbThread = 8;
        std::cout << pathFile << std::endl;

        auto t0 = std::chrono::high_resolution_clock::now();

        std::vector<std::pair<std::string, std::string>> bigrams = generateBigrams(words);
        auto t1 = std::chrono::high_resolution_clock::now();


        std::vector<std::pair<std::string, std::string>> bigramsPara = generateBigramsPara(words, nbThread);
        auto t2 = std::chrono::high_resolution_clock::now();

        auto dtSeq = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
        auto dtPar = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

        std::cout << "Time in sequential : " << static_cast<double>(dtSeq) / 1'000'000'000.0 << " seconds"<<std::endl;
        std::cout << "Time in parallel : " << static_cast<double>(dtPar) / 1'000'000'000.0 << " seconds"<<std::endl;
        
        std::cout << "The best is " << (dtSeq < dtPar ? "sequential" : "parallel") << std::endl;
        outputFile << words.size() << std::endl << dtSeq << std::endl << dtPar << std::endl << std::endl;

    }
    outputFile.close();
    
    return 0;
}
