#include <iostream>
#include <string>
#include <vector>


/*
    - Number of parentheses is 2n 

*/

void genParentheses(std::string currStr, std::vector< std::string >& validStrs, int leftPar, int rightPar){
    if( leftPar == 0 && rightPar == 0){
        validStrs.push_back(currStr);
        return;
    }
    if( leftPar == 0 && rightPar > 0){
        genParentheses(currStr+")", validStrs, leftPar, rightPar-1);
    }
    if (leftPar > 0 && rightPar >= leftPar){
        std::string goLeft = currStr + "(";
        std::string goRight = currStr + ")";
        genParentheses(goLeft, validStrs, leftPar-1, rightPar);
        genParentheses(goRight, validStrs, leftPar, rightPar-1);
    }
}

std::vector< std::string > validPar(int n){
    std::vector< std::string > valid;
    std::string start = "";
    genParentheses(start, valid, n, n);
    return valid;
}

int main(){
    auto validParen = validPar(3);
    int count = 1;
    for(auto it = validParen.begin(); it != validParen.end(); ++it){
        std::cout << count << " ";
        std::cout << *it << std::endl;
        ++count;
    }

    return 0;
}