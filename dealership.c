#include <stdio.h>
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

printf("Hello welcome to \nAuto World first class \n");
printf("Our goal is help you find the best auto for you\n");
printf("Would you like to see our car catalog Enter Y for yes or N for no: \n");
scanf("%c",&answer);

if(answer == 'y' || answer == 'Y'){
    FILE *f;
f = fopen("CarInventory.csv", "r");
char *var;
char varchar[301];
var = &varchar[20];
fscanf(f,"%s",var);
printf("%s\n",var);
fclose(f);
}
else {
    printf("Thank you for your time\n");
}
return 0;
}