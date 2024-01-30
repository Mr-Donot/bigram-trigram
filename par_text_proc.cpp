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



std::vector<std::pair<std::string, std::string>> generateBigramsPara
(const std::vector<std::string>& words, size_t nbThread) {
    std::vector<size_t> threadStartIndices(nbThread, 0);
    size_t totalLength = words.size() - 1;
    size_t chunkSize = totalLength / nbThread;
    for (size_t i = 1; i < nbThread; ++i) {
        threadStartIndices[i] = threadStartIndices[i - 1] + chunkSize;
    }
    std::vector<std::pair<std::string, std::string>> result;
    result.reserve(totalLength);  // Avoid unnecessary reallocations
    std::vector<std::vector<std::pair<std::string, std::string>>> threadResults(nbThread);

    omp_set_num_threads(static_cast<int>(nbThread));
    #pragma omp parallel 
    #pragma omp for
    for (int threadId = 0; threadId < static_cast<int>(nbThread); ++threadId) {
        size_t startIndex = threadStartIndices[threadId];
        size_t endIndex = (threadId == nbThread - 1) ? totalLength : threadStartIndices[threadId + 1];
        for (size_t i = startIndex; i < endIndex; ++i) {
            threadResults[threadId].emplace_back(words[i], words[i + 1]);
        }
    }
    for (auto& threadResult : threadResults) {
        result.insert(result.end(), 
        std::make_move_iterator(threadResult.begin()), 
        std::make_move_iterator(threadResult.end()));
        threadResult.clear();
    }
    return result;
}