#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void parseHtml(char *input){
    int start, end = 0;
    char *content = NULL;
    for (int i = 0; i < strlen(input); i++){
        if(input[i] == '<'){
            start = i;
            while(input[i] != '>' && i < strlen(input)){
                i++;
            }
            end = i;
        }
    }
    content = (char *)malloc((end - start + 1) * sizeof(char));
    for(int i = 0; i <= sizeof(content); i++){
        content[i] = input[start + i];
    }
    content[end - start + 1] = '\0';
    printf("\nParsed content: %s\n", content);
    free(content);
}

int main(int argc, char *argv[]){
    char buffer[BUFFER_SIZE];
    int count = 0;
    while(fgets(buffer, BUFFER_SIZE, stdin) != NULL){
        
        buffer[strcspn(buffer, "\n")] = 0;
        count++;
       // printf("%s", buffer);
        parseHtml(buffer);
         
    }
    printf("\nTotal lines read: %d\n", count);
            fprintf(stderr, "Error reading input\n");
    return 0;
}
