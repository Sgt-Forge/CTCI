#include <iostream>

int recMult(int a,  int b){
    int smaller, larger;
    if (a <= b){
        smaller = a;
        larger = b;
    } else {
        smaller = b;
        larger = a;
    }

    if (smaller == 0){ return 0; }
    if (smaller == 1){ return larger; }

    int result = 0;
    int s = smaller;
    int half = 0;
    if(smaller % 2 == 1){ // if smaller is odd
        result += larger;
        s = (smaller-1) >> 1;
        if (larger % 2 == 1){ // if both smaller and larger are odd
            half = recMult(s, larger-1);
            result += smaller + half + half;
        } else {
            half = recMult(s, larger);
            result += half + half;
        }
    } else {
        s = smaller >> 1;
        if (larger % 2 == 1){ // if only larger is odd
            half = recMult(s, larger-1);
            result += smaller + half + half;
        } else {
            half = recMult(s, larger);
            result += half + half;
        }
    }
    return result;
}

int main(){
    std::cout << "================" << std::endl;
    std::cout << recMult(0, 0) << std::endl;
    std::cout << recMult(1, 0) << std::endl;
    std::cout << recMult(0, 1) << std::endl;
    std::cout << "================" << std::endl;
    std::cout << recMult(1, 1) << std::endl;
    std::cout << "================" << std::endl;
    std::cout << recMult(1, 2) << std::endl;
    std::cout << recMult(2, 1) << std::endl;
    std::cout << "================" << std::endl;
    std::cout << recMult(3, 1) << std::endl;
    std::cout << recMult(1, 3) << std::endl;
    std::cout << "================" << std::endl;
    std::cout << recMult(2, 3) << std::endl;
    std::cout << recMult(3, 2) << std::endl;
    std::cout << "================" << std::endl;
    std::cout << recMult(10, 5) << std::endl;
    std::cout << recMult(5, 10) << std::endl;
    std::cout << "================" << std::endl;
    std::cout << recMult(4, 4) << std::endl;
    std::cout << "================" << std::endl;
    std::cout << recMult(10, 10) << std::endl;


    return 0;
}