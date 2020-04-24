#include <stdio.h>
#include <string.h>

void buildHashMap(char* phrase, int* map){
    int index;
    for(int i = 0; i < strlen(phrase); ++i){
        index = (int)phrase[i] - (int)'a';
        ++map[index];
    }
}

int isPalindrome(char* phrase){
    int freqs[26] = {0};
    buildHashMap(phrase, freqs);
    for (int i = 0; i < 26; ++i){
        printf("[DBG]:\tIndex [%d]:\t%d\n", i, freqs[i]);
    }
    
    return 0;
}

int main(int argc, char* argv[]){
    if (argc != 2){
        printf("[ERROR]:\tPlease enter a single string to see if it is a permutation of a palindrome!\n");
        return -1;
    }
    char* phrase = argv[1];
    int ret_val = isPalindrome(phrase);

    return 0;
}