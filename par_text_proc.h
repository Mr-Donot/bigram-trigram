#ifndef PAR_TEXT_PROC_H
#define PAR_TEXT_PROC_H

#include <vector>
#include <tuple>
#include <string>



// bigram
std::vector<std::pair<std::string, std::string>> generateBigramsPara(const std::vector<std::string>& words, size_t nbThread);

//trigram
std::vector<std::tuple<std::string, std::string, std::string>> generateTrigramsPara(const std::vector<std::string>& words, size_t nbThread);



#endif // PAR_TEXT_PROC_H
