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
if(answer == 'y' || answer == 'Y'){
   FILE *g;
g = fopen("CarInventory.csv", "r");
char *var;
char varchar[301];
var = &varchar[0];
char *ptr;
char ptr2[20];
ptr = &ptr2[0];
while (1){
    fgets(var, 300,g);
    if(feof(g)){
        break;
    }
    printf("%s",var);
}
while (*(var +i) != ','){
     *(ptr + i) = *(var + i);
    i = i + 1;
}
printf("%s\n",ptr);
}
else {
    printf("Thank you for your time\n");
}

return 0;
}