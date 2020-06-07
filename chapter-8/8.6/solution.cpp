#include <iostream>
#include <stack>

void printTowers(std::stack<int> s1, std::stack<int> s2, std::stack<int> s3){
    std::cout << "T1\tT2\tT3\n" ;
    while (!s1.empty() || !s2.empty() || !s3.empty()){
        if(!s1.empty()){
            std::cout << s1.top() << "\t" ;
            s1.pop();
        } else  { std::cout << "|\t" ; }
        if(!s2.empty()){
            std::cout << s2.top() << "\t" ;
            s2.pop();
        } else  { std::cout << "|\t" ; }
        if(!s3.empty()){
            std::cout << s3.top() << "\t" ;
            s3.pop();
        } else  { std::cout << "|\t" ; }
        std::cout << std::endl;
    }
}

void hanoi(int size, std::stack<int>& source, std::stack<int>& buffer, std::stack<int>& destination){ int top;
    if(size == 1){
        top = source.top();
        source.pop();
        destination.push(top);
        return;
    }
    hanoi(size-1, source, destination, buffer); // This should unroll the first stack until we get to the base disk
    top = source.top(); // Now we're at the base disk we push it to the destination
    source.pop();
    destination.push(top);
    hanoi(size-1, buffer, source, destination); // Now place everything in the buffer onto the destination
}

int main(){
    int size = 5;
    std::stack<int> s1, s2, s3;
    for(int i = size; i > 0; --i){
        s1.push(i);
    }
    std::cout << "==========BEFORE=========\n";
    printTowers(s1, s2, s3);
    hanoi(size, s1, s2, s3);
    std::cout << "==========AFTER==========\n";
    printTowers(s1, s2, s3);
    
    return 0;
}