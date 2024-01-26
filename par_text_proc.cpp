#include <vector>
#include <string>
#include <iostream>
#include <omp.h>
#include <chrono>
#include "seq_text_proc.h"

std::vector<std::vector<std::string>> split_text(const std::vector<std::string>& words, size_t nbThread){

    std::vector<std::vector<std::string>> result;

    // Calculate the size of each section
    size_t sectionSize = words.size() / nbThread;
    size_t remainder = words.size() % nbThread;

    // Iterator to traverse the original list
    auto iter = words.begin();

    // Split the list into sections
    for (size_t i = 0; i < nbThread; ++i) {
        size_t currentSectionSize = sectionSize + (i < remainder ? 1 : 0);

        // Create a vector representing the current section
        std::vector<std::string> section(iter, iter + currentSectionSize);

        // Add the section to the result
        result.push_back(section);

        // Move the iterator to the next section
        iter += currentSectionSize;
    }

    return result;
}


std::vector<std::pair<std::string, std::string>> generateBigramsPara(const std::vector<std::string>& words, size_t nbThread){

    std::vector<std::vector<std::string>> subTextList = split_text(words, nbThread);

    // Concatenate all thread bigrams into one vector
    std::vector<std::pair<std::string, std::string>> result;

#pragma omp parallel
    {
        std::vector<std::pair<std::string, std::string>> localResult;

        #pragma omp for
        for (int i = 0; i < nbThread; ++i) {
            std::vector<std::pair<std::string, std::string>> bigrams = generateBigrams(subTextList[i]);
            localResult.insert(localResult.end(), bigrams.begin(), bigrams.end());
        }

        // Combine local results using critical section
        #pragma omp critical
        result.insert(result.end(), localResult.begin(), localResult.end());
    }

    return result;
}




