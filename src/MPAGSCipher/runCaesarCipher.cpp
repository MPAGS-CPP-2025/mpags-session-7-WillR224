#include "runCaesarCipher.hpp"

#include <iostream>
#include <string>
#include <vector>

std::string runCaesarCipher(const std::string& inputText, const std::size_t key,
                            const bool encrypt)
{
    std::vector<char> alphabet{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                               'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                               'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    std::string transformedText;
    for (const char& eachChar : inputText){
        for(std::size_t i{0}; i < alphabet.size(); i++){
            if(eachChar == alphabet[i]){
                if(encrypt){
                    transformedText += alphabet[(i+key)%26];
                }
                else{
                    transformedText += alphabet[(i-key+26)%26];
                }
            }
        }
    }
    return transformedText;
}