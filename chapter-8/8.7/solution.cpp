#include <iostream>
#include <string>
#include <vector>

std::vector< std::string > emplace(std::string str, std::vector< std::string> perms){
    std::vector< std::string > newPerms;
    if (perms.empty()){
        newPerms.push_back(str);
        return newPerms;
    }
    for(auto perm = perms.begin(); perm != perms.end(); ++perm){
        for(auto ch = (*perm).begin(); ch != (*perm).end(); ++ch){
            std::string front = std::string((*perm).begin(), ch);
            std::string end = std::string((ch), (*perm).end());
            std::string newPerm = front + str + end;
            newPerms.push_back(newPerm);
        }
        newPerms.push_back((*perm) + str);
    }

    return newPerms;
}

std::vector< std::string > genPermsHelp(std::string str, std::vector< std::string > perms){
    if(str.size() == 1){
        return emplace(str, perms);
    }
    std::string reduce = std::string(str.begin()+1, str.end());
    auto newPerms = genPermsHelp(reduce, perms);
    newPerms =  emplace(str.substr(0,1), newPerms);
    return newPerms;
}

std::vector< std::string> genPerms(std::string str){
    std::vector< std::string > perms;
    perms = genPermsHelp(str, perms);
    return perms;
}

int main(){
    std::string input = "1234";
    std::string insert = "MEMES";
    auto perms = genPerms(input);
    int count = 1;
    for(auto outter = perms.begin(); outter != perms.end(); ++outter){
        std::cout << count << ":\t" << *outter << std::endl;
        ++count;
    }

    return 0;
}