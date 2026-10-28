#include <stdio.h>
#include <string.h>

int main(){
    char lists[3][100];
    int maxStrIndx = 0;
    int minStrIndx = 0;

    int vowelCount = 0;
    int consonant = 0;

    for(int i = 0; i < 3; i++){
        printf("Enter %d sentence: ", i + 1);
        fgets(lists[i], sizeof(lists[i]), stdin);
    }
    for(int i = 0; i < 3; i++){
            if(strlen(lists[i]) < strlen(lists[minStrIndx])){
                minStrIndx = i;
            }
            if(strlen(lists[i]) > strlen(lists[maxStrIndx])){
                maxStrIndx = i;
            }

            
        }
    printf("\nLongest string is: %s", lists[maxStrIndx]);
    printf("Shortest string is %s", lists[minStrIndx]);

    return 0;
}