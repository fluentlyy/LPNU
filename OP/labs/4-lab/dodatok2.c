#include <stdio.h>
#include <string.h>

int main(){
    char str[256];
    char wordList[20][256];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    char *token = strtok(str, " ,.!?\n");


    int i = 0;
    while(token != NULL){
        strcpy(wordList[i], token);
        i++;
        token = strtok(NULL, " ,.!?\n");
    }

    int maxIndxStr = 0;
    int minIndxStr = 0;

    for(int j = 0; j < i; j++){
        if(strlen(wordList[maxIndxStr]) < strlen(wordList[j])){
            maxIndxStr = j;
        }
        if(strlen(wordList[minIndxStr]) > strlen(wordList[j])){
            minIndxStr = j;
        }
    }

    printf("Longest word is: %s\n", wordList[maxIndxStr]);
    printf("Shortest word is: %s", wordList[minIndxStr]);

    return 0;
}