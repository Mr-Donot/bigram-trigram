#include "seq_text_proc.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>


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

std::vector<std::string> get_content_file
(const std::string& pathFile, const std::string& mode) {
    std::ifstream inputFile(pathFile);
    std::vector<std::string> words;
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;return words;
    }
    std::string line;
    if (mode == "word"){
        while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            words.push_back(word);
        }
    }
    return words;
    }
    else{
        std::vector<std::string> letters;
        while (std::getline(inputFile, line)) {
            for (char letter : line) {
                letters.push_back(std::string(1, letter));
            }
        }
        return letters;
    }
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


void printTopBigrams(const std::vector<std::pair<std::string, std::string>>& bigrams, int topCount) {
    std::vector<std::pair<std::pair<std::string, std::string>, int>> histogram;

    for (const auto& bigram : bigrams) {
        auto it = std::find_if(histogram.begin(), histogram.end(),
                               [&bigram](const auto& entry) {
                                   return entry.first == bigram;
                               });

        if (it != histogram.end()) {
            // If the bigram is already in the vector, increment the count.
            it->second++;
        } else {
            // Otherwise, add a new entry with a count of 1.
            histogram.emplace_back(bigram, 1);
        }
    }

    // Sort the vector based on the frequency count in descending order
    std::sort(histogram.begin(), histogram.end(),
              [](const auto& lhs, const auto& rhs) {
                  return lhs.second > rhs.second;
              });

    // Print the top 'topCount' entries
    for (int i = 0; i < topCount && i < histogram.size(); ++i) {
        const auto& entry = histogram[i];
        std::cout << "(" << entry.first.first << ", " << entry.first.second << "): " << entry.second << std::endl;
    }
}