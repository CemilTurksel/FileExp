#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *file;
    int choice;
    char choiceEe;
    char c;
    char d;
    file=fopen("source.txt","r");
    if(file==NULL){
        perror("Error creating");
        return -1;
    }
    else{
        printf("Which operation do you want to imply to the file\n 1.Read File\n 2.Append to The File\n:");
        scanf(" %d",&choice);
        getchar();
        if(choice==1){
            do{
                c=fgetc(file);
                printf("%c",c);
            }while(c!=EOF);
        }
        else if(choice==2){
            file=fopen("source.txt","a+");
            char input[999];
            printf("What do you want to append to the file:\n");
            scanf(" %s",input);
            fprintf(file,input);
            printf("Appended!\nDo you want to read the file: Y/n\n");
            scanf(" %c",&choiceEe);
            if(choiceEe=='Y'){
                rewind(file);
                do{
                    d=fgetc(file);
                    printf("%c",d);
                }while(d!=EOF);
            }
            else if(choiceEe=='n'){
                printf("Program finished.");
            }
        }
        fclose(file);
    }
    return 0;
}
