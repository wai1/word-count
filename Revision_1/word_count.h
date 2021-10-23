#if !defined(WORD_COUNT_H)
#define WORD_COUNT_H

#include <string>
#include <map>
#include <regex>

namespace word_count {

	std::map<std::string, int> words(const std::string& input_string);
	const std::string& apostrophe_check(std::string& current_word);

}  // namespace word_count

#endif // WORD_COUNT_H