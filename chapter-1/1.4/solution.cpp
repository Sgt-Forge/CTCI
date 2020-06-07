#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

std::unordered_map<char, int> buildMap(std::string phrase){
    std::unordered_map<char, int> map;
    for (int i = 0; i < phrase.length(); ++i){
        map[phrase[i]]++;
    }

    return map;
}

bool isPalindrome(std::string phrase){
    std::unordered_map<char, int> freqs;
    freqs = buildMap(phrase);
    int numOdds = 0;
    for (auto it = freqs.begin(); it != freqs.end(); ++it){
        if (it->second %2 != 0){
            ++numOdds;
        }
    }
    if (phrase.length() %2 == 0){
        if (! numOdds){
            return true;
        }
        return false;
    } else {
        if (numOdds == 1){
            return true;
        }
        return false;
    }
}

int main(int argc, char* argv[]){
    std::string phrase = argv[1];
    phrase.erase(std::remove(phrase.begin(), phrase.end(), ' '), phrase.end());
    if (isPalindrome(phrase)){
        std::cout << "[RESULT]:\tYes, your string is a permutation of a palindrom!" << std::endl;
    } else {
        std::cout << "[RESULT]:\tNo, your string is a permutation of a palindrom!" << std::endl;
    }

    return 0;
}