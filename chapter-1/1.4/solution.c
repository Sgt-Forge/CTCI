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
    int numOddCounts = 0;
    for (int i = 0; i < 26; ++i){
        if (freqs[i] %2 != 0){
            ++numOddCounts;
        }
    }
    if (strlen(phrase) %2 == 0){
        return !numOddCounts;
    } else {
       if (numOddCounts == 1){
           return 1;
       } 
       return 0;
    }
    
    return 0;
}

void removeSpaces(char* str){
    int count = 0;
    int total_len = strlen(str);
    for(int i = 0; i < total_len; ++i){
        if (str[i] != ' '){
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
}

int main(int argc, char* argv[]){
    if (argc != 2){
        printf("[ERROR]:\tPlease enter a single string to see if it is a permutation of a palindrome!\n");
        return -1;
    }
    char* phrase = argv[1];
    removeSpaces(phrase);

    if(isPalindrome(phrase)){
        printf("[RESULT]:\tYes!  Your word is a permutation of a palindrome!\n");
    } else {
        printf("[RESULT]:\tNo!  Your word is NOT a permutation of a palindrome!\n");
    }

    return 0;
}