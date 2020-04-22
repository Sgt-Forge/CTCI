#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* urlify(char* input, int fake_len){
    int i = fake_len-1;
    int curr_ch = strlen(input) - 1;
    for(i; i >= 0; --i){
        if (input[i] == ' '){
            input[curr_ch] = '0';
            input[curr_ch-1] = '2';
            input[curr_ch-2] = '\%';
            curr_ch -= 3;
        } else {
            input[curr_ch] = input[i];
            --curr_ch;
        }
    }

    return input;
}

int main(int argc, char* argv[]) {
    // Expect input string and fake length
    if (argc != 3){
        printf("[ERROR]:\tPlease enter an input string and provide the fake length of that string!\n");
        return -1;
    }
    char* input = argv[1];
    int fake_len = atoi(argv[2]);
    char* ret = urlify(input, fake_len);

    printf("URL:\t%s\n", ret);

    return 0;
}