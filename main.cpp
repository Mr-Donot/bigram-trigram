#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

// Function to generate bigrams from a given vector of words
std::vector<std::pair<std::string, std::string>> generateBigrams(const std::vector<std::string>& words) {
    std::vector<std::pair<std::string, std::string>> bigrams;
    
    for (size_t i = 0; i < words.size() - 1; ++i) {
        bigrams.push_back(std::make_pair(words[i], words[i + 1]));
    }
    
    return bigrams;
}

// Function to generate trigrams from a given vector of words
std::vector<std::tuple<std::string, std::string, std::string>> generateTrigrams(const std::vector<std::string>& words) {
    std::vector<std::tuple<std::string, std::string, std::string>> trigrams;

    for (size_t i = 0; i < words.size() - 2; ++i) {
        trigrams.push_back(std::make_tuple(words[i], words[i + 1], words[i + 2]));
    }

    return trigrams;
}

int main() {
    // Assuming the file is named "fr.txt"
    std::ifstream inputFile("./data/fr.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::vector<std::string> words;
    std::string line;
    
    // Read the content of the file
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string word;
        
        // Tokenize the line into words
        while (iss >> word) {
            words.push_back(word);
        }
    }

    // Generate bigrams
    std::vector<std::pair<std::string, std::string>> bigrams = generateBigrams(words);
    std::vector<std::tuple<std::string, std::string, std::string>> trigrams = generateTrigrams(words);

    // Display the bigrams
    //for (const auto& bigram : bigrams) {
    //    std::cout << "(" << bigram.first << ", " << bigram.second << ") ";
    //}

    for (const auto& trigram : trigrams) {
        std::cout << "(" << std::get<0>(trigram) << ", " << std::get<1>(trigram) << ", " << std::get<2>(trigram) << ") ";
    }

    return 0;
}
