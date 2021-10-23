#include "word_count.h"

namespace word_count {

    std::map<std::string, int> words(const std::string& input_string)
    {
        std::map<std::string, int> word_counter;
        std::map<std::string, int>::iterator word_counter_iterator;

        // std::regex regex_string("[a-zA-Z0-9\']+");
        std::regex regex_string("[\\w]+('[\\w]+)*");
        auto words_begin = std::sregex_iterator(input_string.begin(), input_string.end(), regex_string);
        auto words_end = std::sregex_iterator();

        std::string word_lowercase{};
        std::string current_word{};

        // Iterate through complete string
        for (std::sregex_iterator i = words_begin; i != words_end; ++i)
        {
            word_counter_iterator = word_counter.find((*i).str());  

            current_word = ((*i).str());  

            transform(current_word.begin(), current_word.end(), current_word.begin(), ::tolower);

           // word_lowercase = apostrophe_check(current_word);

            // word_counter_iterator = word_counter.find(word_lowercase); 
            word_counter_iterator = word_counter.find(current_word);

            if (word_counter_iterator == word_counter.end())  
                word_counter.insert(std::pair<std::string, int>(current_word, 1));
            else
                ++word_counter[current_word];
        }

        return word_counter;
    }

    const std::string& apostrophe_check(std::string& current_word)
    {
        size_t word_length = current_word.size();  

        size_t apostrophe_location = current_word.find("'");  

        while ((apostrophe_location != word_length - 2) && (apostrophe_location != std::string::npos)) 
        {
            current_word.erase(apostrophe_location, 1);
            word_length -= 1;
            apostrophe_location = current_word.find("'");
        }
        return current_word;
    }

}  // namespace word_count