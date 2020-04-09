#include <iostream>

int main(int argc, char* argv[]){
    for (int i = 0; i < argv.length(); ++i){
        std::cout << "[DBG]\t"
        std::cout << argv[i] << std::endl;
    }

    return 0;
}