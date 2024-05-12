#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* replaceOccurrencesChar(char*, char, char);
int startWith(char*, char*);
char* removeCharactersRepeated(char *);

int main(void) {
    int option = 0;
    char string [50];
    char stringVerify [50];
    char newChar;
    char oldChar;

    while(option!=10){
        printf("\n-----MENU----\n4.Function #4 \n5.Function #5 \n6.Function #6 \n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                printf("Input string\n");
                scanf(" %[^\n]", string);
                printf("Input character to replace\n");
                scanf(" %c", &oldChar);
                printf("Input new character\n");
                scanf(" %c", &newChar);
                printf("%s", replaceOccurrencesChar(string, oldChar, newChar));
                break;
            case 5:
                printf("Input base string\n");
                scanf(" %[^\n]", string);
                printf("Input string to verify\n");
                scanf(" %[^\n]", stringVerify);

                if(startWith(string, stringVerify)==0){
                    printf("The string to be verified (%s) NO exist in the start!",stringVerify);
                }else{
                    printf("The string to be verified (%s) is in the start",stringVerify );
                }
                break;
            case 6:
                printf("Input string\n");
                scanf(" %[^\n]", string);
                printf("%s", removeCharactersRepeated(string));
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                printf("\n-- exit --");
                break;
        }
    }

    return 0;
}

char* removeCharactersRepeated(char *input) {
    char *output = (char *)malloc(strlen(input) + 1);
    int aux = 1;
    output[0] = input[0];
    //
    int j;
    for(int i=1; i<strlen(input); i++){
        for(j=0; j<aux; j++){
            if(output[j] == input[i]){
                break; //for j
            }
        }
        if (j==aux) {
            output[aux] = input[i];
            aux++;
        }
    }
    output[aux] = '\0';
    return output;
}

char* replaceOccurrencesChar(char *input, char oldChar, char newChar){
    char *out = input;
    for(int i=0; i<strlen(input); i++){
        if(input[i] == oldChar){
            out[i] = newChar;
        }
    }
    return out;
}

/*
 * char* removeCharactersRepeated(char *input){
    int aux = 0;
    char *output = (char *)malloc(strlen(input) + 1);

    for(int i=0; i<strlen(input); i++){
        if(strchr(output, input[i]) == NULL){
            output[aux] = input[i];
            aux++;
        }

    }
    return output;
}
 */

int startWith(char *baseString, char *verifyString){
    if(strlen(verifyString) > strlen(baseString)){
        return 0;
    }else{
        for(int i=0; i<strlen(verifyString); i++){
            if(baseString[i] != verifyString[i]){
                return 0;
            }
        }
        return 1;
    }
}