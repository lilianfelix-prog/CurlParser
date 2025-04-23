#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

void parseHtml(char *input){
    int start, end = -1;
    for (int i = 0; i < strlen(input); i++){
        if(input[i] == '<'){
            start = i;
            while(input[i] != '>' && i < strlen(input)){
                i++;
            }
            end = i;
        }
    }

    int length = end - start + 1;

    if(end != -1 && start != -1){

       char *content = (char *)malloc((length) * sizeof(char));

        strncpy(content, input + start, length);
       //for(int i = 0; i < length; i++){
        //    content[i] = input[start + i];
        //}

        content[length] = '\0';
        printf("\nParsed content: %s\n", content);
        free(content); 
    }
    
}

int main(int argc, char *argv[]){
    clock_t start, end;

    start = clock();
    char buffer[BUFFER_SIZE];
    int count = 0;
    while(fgets(buffer, BUFFER_SIZE, stdin) != NULL){
        
        buffer[strcspn(buffer, "\n")] = 0;
        count++;
       //printf("%s", buffer);
        parseHtml(buffer);
         
    }
    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken to parse: %f seconds\n", time_taken);
    printf("\nTotal lines read: %d\n", count);
            
    return 0;
}
