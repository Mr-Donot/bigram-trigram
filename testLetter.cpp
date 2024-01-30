#include <vector>
#include <string>
#include "seq_text_proc.h"

int main(){


        std::vector<std::string> words = get_content_file("./data/very_small.txt", "letter");

        std::vector<std::pair<std::string, std::string>> bigrams = generateBigrams(words);

        print_bigrams(bigrams);



    return 0;

}