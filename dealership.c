#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



typedef struct{
    int vin;
    int year;
    char *model[30];
    char *branch[30];
}Car_t;


int main(void)
{
char answer;
printf("**********************************************************************\n");
printf("Hello welcome to \nAuto World first class \n");
printf("Our goal is help you find the best auto for you\n");
printf("Would you like to see our car catalog Enter Y for yes or N for no: ");
scanf("%c",&answer);
printf("**********************************************************************\n");
int i = 0;
if(answer == 'y' || answer == 'Y')
{
FILE *g;
g = fopen("CarInventory.csv", "r");
char line[10000];
char word2[10000][20];
int index = 0;
while (fgets(line, sizeof(line), g))
{
    if(index >= 10000){
        break;
    }
char *wordTaken;
wordTaken = strtok(line, ",");

int counter = 0;

while (wordTaken != NULL)
{
    strcpy(word2[index], wordTaken);
    printf("%-14s", wordTaken);
    wordTaken = strtok(NULL, ",");
    counter++;
}
printf("\n");
index++;
}
char input[20];
printf("Would like to input a car branch: ");
scanf("%s", input);
for (int i = 0; i < 10000; i++){
    if(strstr(word2[i],input) != NULL)
    {
        for (int j = 0; j < 8; j++)
        {
             printf("%-14s", word2[i]);
        }
       
        printf("\n"); 
    }
}
}
else 
{
    printf("Thank you for your time\n");
}
return 0;
}   
