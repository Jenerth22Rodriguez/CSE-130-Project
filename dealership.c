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

void monthlyPayment(int *a, int *b){

int downPayment;
int maxPayment;

printf("Please enter the amount you plan to use as a down payment: ");
scanf("%d", &downPayment);
printf("Please enter your maximum monthly payment: ");
scanf("%d", &maxPayment);

*a = *a - downPayment;
while(1){
if(*a / *b > maxPayment){
    *b = *b + 1;      
}
else{
*a = *a / *b;
break;
}
}
}

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

while(fgets(line,sizeof(line), g))
{
char *wordTaken;
wordTaken = strtok(line, ",");

while(wordTaken != NULL)
{
    printf("%-14s", wordTaken);
    wordTaken = strtok(NULL, ",");
}
printf("\n");
}
int carPrice;
char CarName[20];
char Model[20];

printf("Enter the car you like the most: ");
scanf("%s",CarName);
printf("Enter the model you like the most: ");
scanf("%s", Model);
printf("Enter the price of the car: ");
scanf("%d",&carPrice);
int months = 1;

monthlyPayment(&carPrice,&months);
printf("Your car payment will be %d per month for %d months.\n",carPrice,months);
printf("\nCONGRATULATIONS on your new %s %s!\n",CarName, Model);
}
else 
{
    printf("Thank you for your time\n");
}
return 0;
} 

