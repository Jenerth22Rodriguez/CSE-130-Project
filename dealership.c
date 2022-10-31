#include "stdio.h"
#include "string.h"
#include "math.h"

int main(void)
{

char answer;

printf("Hello welcome to \nAuto World first class \n");
printf("Our goal is help you find the best auto for you\n");
printf("Would you like to see our car catalog Enter Y for yes or N for no: \n");
scanf("%c",&answer);

if(answer == 'y' || answer == 'Y'){
    printf("struct\n");
}
else {
    printf("Thank you for your time\n");
}
return 0;
}