#include <stdio.h>
#include <stdarg.h>

void sentenceDoubleAlph(const char *first, ...){
    if(first == NULL) return;

    int count = 0;
    
    va_list args;
    va_start(args, first);

    const char *current = first;

    while(current != NULL){
        char *firstAlphaP = current;
        while(*current != '\0'){
            if(*current == *(current + 1)){
                printf("Word with double letter: %s\n", firstAlphaP);
                count++;
                break;
            }
            current++;
        }
        current = va_arg(args, char*);
    }
    va_end(args);

    if(count == 0) printf("There are no words with double letter.");
}

int main(){
    sentenceDoubleAlph("Hello", "Illia", "name", "oil", "apple", NULL);
    return 0;
}