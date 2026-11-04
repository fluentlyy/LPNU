#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char sentenceParts[50][350];
    char sentence[350] = "Are you actually saying you fixed the code without testing it!? did you really push those changes straight to production on a Friday afternoon!? how could you possibly think that was a good idea!? What on earth were you expecting to happen!? Have you completely lost your mind!?";

    char *token = strtok(sentence, "!?.\n");

    int i = 0;
    while(token != NULL){
        while(*token == ' ') token++;
        strcpy(sentenceParts[i], token);
        i++;
        token = strtok(NULL, "!?.\n");
    }
    int longestSentenceIndx = 0;
    for(int j = 0; j < i; j++){
        sentenceParts[j][0] = toupper(sentenceParts[j][0]);
        char *pSpace = strchr(sentenceParts[j], ' ');
        while(pSpace != NULL){
            *pSpace = '_';
            pSpace = strchr(sentenceParts[j], ' ');
        }
        if(strlen(sentenceParts[longestSentenceIndx]) < strlen(sentenceParts[j])) longestSentenceIndx = j;
        printf("%s\n", sentenceParts[j]);
    }
    printf("Longest sentence is: %s", sentenceParts[longestSentenceIndx]);
    return 0;
}