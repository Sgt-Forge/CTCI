#include <stdio.h>
#include <string.h>

int is_unique(char* input){
    int i = 0;
    int j;
    for(; i < strlen(input); ++i){
        for(j=i+1; j < strlen(input); ++j){
            if(input[i] == input[j]){
                return 0;
            }
        }
    }
    return 1;
}

int main(int argc, char* argv[]) {

    // Check for input
    if (argc != 2){
        printf("ERROR: Please provide a single string to test!\n");
        return 1;
    }

    printf("[DBG]\tInput:\t%s\n", argv[1]);
    char* input = argv[1];
    if(is_unique(input)){
        printf("No Duplicates!\n");
    } else {
        printf("Duplicates\n");
    }

    return 0;
}
