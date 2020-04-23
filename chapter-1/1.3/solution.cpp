#include <iostream>
#include <string>

std::string urlify(std::string input, int fake_len){
    int curr_pos = input.length() - 1;
    for (int i = fake_len-1; i >= 0; --i){
        if (input[i] == ' '){
            input[curr_pos] = '0';
            input[curr_pos-1] = '2';
            input[curr_pos-2] = '%';
            curr_pos -= 3;
        } else {
            input[curr_pos] = input[i];
            --curr_pos;
        }
    }

    return input;
}

int main(int argc, char* argv[]){
    if (argc != 3){
        std::cout << "[ERROR]\tPlease enter a string and it's fake length!\n";
        return -1;
    }

    std::string input = argv[1];
    int fake_len = std::stoi(argv[2]);

    std::string ret = urlify(input, fake_len);
    std::cout << "URL:\t" << ret << std::endl;

    return 0;
}