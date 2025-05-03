#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

std::vector<std::string> process_words(const std::vector<std::string>& words) {
    std::vector<std::string> result;

    for (const auto& word : words) {
        if (word.length() <= 3 && any_of(word.begin(), word.end(), ::isupper)) {
            // Process short words with uppercase letters
            std::string processed_word;
            for (char c : word) {
                if (isupper(c)) {
                    processed_word += std::string(1, c) + "-" + std::string(1, c) + "-";
                }
                else {
                    processed_word += c;
                }
            }
            result.push_back(processed_word);
        }
        else {
            result.push_back(word);
        }
    }

    return result;
}

std::vector<std::string> split_text(const std::string& text, const std::string& delimiters) {
    std::vector<std::string> words;
    size_t start = text.find_first_not_of(delimiters);

    while (start != std::string::npos) {
        size_t end = text.find_first_of(delimiters, start);
        if (end == std::string::npos) {
            end = text.length();
        }
        words.push_back(text.substr(start, end - start));
        start = text.find_first_not_of(delimiters, end);
    }

    return words;
}

int main() {
    const std::string special_symbols = " .,!?/:;#@$%^&*()_+=-";
    std::string input_text;

    std::cout << "Enter text and the program will output freaky text -> ";
    std::getline(std::cin, input_text);

    std::vector<std::string> words = split_text(input_text, special_symbols);
    std::vector<std::string> freaky_words = process_words(words);

    for (const auto& word : freaky_words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}