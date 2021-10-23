#include "word_count.h"
#include <regex>

namespace word_count {

    std::map<std::string, int> words(const std::string& input_string)
    {
        std::map<std::string, int> word_counter;
    
        std::regex regex_string("[\\w]+('[\\w]+)*");
        auto words_begin = std::sregex_iterator(input_string.begin(), input_string.end(), regex_string);
        auto words_end = std::sregex_iterator();

        std::string current_word{};

        for(std::sregex_iterator i = words_begin; i != words_end; ++i)
        {
            current_word = (i->str());
            transform(current_word.begin(), current_word.end(), current_word.begin(), [](unsigned char c) { return std::tolower(c); });
            word_counter[current_word]++;
        }

        return word_counter;
    }

}  // namespace word_count