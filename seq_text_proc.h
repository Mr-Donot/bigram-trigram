#ifndef SEQ_TEXT_PROC_H
#define SEQ_TEXT_PROC_H

#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>

// data
std::vector<std::string> get_content_file(const std::string& pathFile, const std::string& mode);

// bigram
std::vector<std::pair<std::string, std::string>> generateBigrams(const std::vector<std::string>& words);
void print_bigrams(std::vector<std::pair<std::string, std::string>> bigrams);

//trigram
std::vector<std::tuple<std::string, std::string, std::string>> generateTrigrams(const std::vector<std::string>& words);
void print_trigrams(std::vector<std::tuple<std::string, std::string, std::string>> trigrams);

// histogram
void printTopBigrams(const std::vector<std::pair<std::string, std::string>>& bigrams, int topCount);

#endif // SEQ_TEXT_PROC_H
