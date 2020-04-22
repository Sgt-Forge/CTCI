#include <iostream>

bool is_unique(std::string input){
    for (int i = 0; i < input.length(); ++i){
        for(int j = i+1; j < input.length(); ++j){
            if(input[i] == input[j]){
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char* argv[]){
    if (argc != 2){
        std::cout << "[ERROR]\tPlease enter a single string as input.";
    }
    std::string input = argv[1];
    if (is_unique(input)){
        std::cout << "Duplicates!" << std::endl;
    } else {
        std::cout << "No duplicate!" << std::endl;
    }

    return 0;
}