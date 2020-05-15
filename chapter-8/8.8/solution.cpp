#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::unordered_map< std::string, int > emplace(std::string str, std::unordered_map< std::string , int> hash){
    std::unordered_map< std::string, int > newPerms;
    std::string front, end, newPerm;
    if( hash.empty() ){
        newPerms[str] = 1;
        return newPerms;
    }
    for(auto perm = hash.begin(); perm != hash.end(); ++perm){
        std::string word = (*perm).first;
        for(auto ch = word.begin(); ch != word.end(); ++ch){
            front = std::string(word.begin(), ch);
            end = std::string(ch, word.end());
            newPerm =  front + str + end;
            if (newPerms[newPerm] == 0){
                newPerms[newPerm] == 1;
            }
        }
        newPerm = word + str;
        if (newPerms[newPerm] == 0){
            newPerms[newPerm] == 1;
        }
    }
    return newPerms;
}

std::unordered_map< std::string, int > getPerms(std::string str, std::unordered_map< std::string, int> hash){
    if (str.size() == 1){
        return emplace(str, hash);
    }
    hash = getPerms(str.substr(1), hash);
    return emplace(str.substr(0,1), hash);
}

int main(){
    std::unordered_map< std::string, int > perms;
    perms = getPerms("122", perms);
    int count = 1;
    for(auto it = perms.begin(); it != perms.end(); ++it){
        std::cout << count << ": " << (*it).first << std::endl;
        ++count;
    }

    return 0;
}