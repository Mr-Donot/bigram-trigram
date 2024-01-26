#include "seq_text_proc.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<std::pair<std::string, std::string>> generateBigrams(const std::vector<std::string>& words) {
    std::vector<std::pair<std::string, std::string>> bigrams;

    for (size_t i = 0; i < words.size() - 1; ++i) {
        bigrams.push_back(std::make_pair(words[i], words[i + 1]));
    }

    return bigrams;
}

std::vector<std::tuple<std::string, std::string, std::string>> generateTrigrams(const std::vector<std::string>& words) {
    std::vector<std::tuple<std::string, std::string, std::string>> trigrams;

    for (size_t i = 0; i < words.size() - 2; ++i) {
        trigrams.push_back(std::make_tuple(words[i], words[i + 1], words[i + 2]));
    }

    return trigrams;
}

std::vector<std::string> get_content_file(const std::string& pathFile) {
    std::ifstream inputFile(pathFile);
    std::vector<std::string> words;

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return words;
    }

    std::string line;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string word;

        while (iss >> word) {
            words.push_back(word);
        }
    }

    return words;
}

void print_bigrams(std::vector<std::pair<std::string, std::string>> bigrams){
    for (const auto& bigram : bigrams) {
        std::cout << "(" << bigram.first << ", " << bigram.second << ") ";
    }
}


void print_trigrams(std::vector<std::tuple<std::string, std::string, std::string>> trigrams){
    for (const auto& trigram : trigrams) {
        std::cout << "(" << std::get<0>(trigram) << ", " << std::get<1>(trigram) << ", " << std::get<2>(trigram) << ") ";
    }
}


