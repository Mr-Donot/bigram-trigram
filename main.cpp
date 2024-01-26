#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "seq_text_proc.h"
#include "par_text_proc.h"
#include <chrono>

int main() {
    
    std::string pathFile = "./data/fr.txt";
    std::vector<std::string> words = get_content_file(pathFile);

    auto start1 = std::chrono::high_resolution_clock::now();

    std::vector<std::pair<std::string, std::string>> bigrams = generateBigrams(words);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count();

    size_t nbThread = 8;

    auto start2 = std::chrono::high_resolution_clock::now();
    std::vector<std::pair<std::string, std::string>> bigramsPara = generateBigramsPara(words, nbThread);
    auto end2 = std::chrono::high_resolution_clock::now();

    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count();

    std::cout << "Time in sequential : " << static_cast<double>(duration1) / 1'000'000.0 << " seconds"<<std::endl;
    std::cout << "Time in parallel : " << static_cast<double>(duration2) / 1'000'000.0 << " seconds"<<std::endl;
    
    std::cout << "The best is " << (duration1 < duration2 ? "sequential" : "parallel") << std::endl;

    return 0;
}
