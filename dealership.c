#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void monthlyPayment(int *a, int *b)
{
   int downPayment;
   int maxPayment;

   printf("Please enter the amount you plan to use as a down payment: ");
   scanf("%d", &downPayment);
   printf("Please enter your maximum monthly payment: ");
   scanf("%d", &maxPayment);

   *a = *a - downPayment;
   while(1)
   {
      if(*a / *b > maxPayment)
      {
         *b = *b + 1;
      }
      else
      {
         *a = *a / *b;
         break;
      }
   }
}

int main(void)
{
   // here I'm asking the user if the user want to continue
   // if is it y is going to start the database if is it not
   // the program is going to stop

   char answer;
   printf("**********************************************************************\n");
   printf("Hello welcome to \nAuto World first class \n");
   printf("Our goal is help you find the best auto for you\n");
   printf("Would you like to see our car catalog Enter Y for yes or N for no: ");
   scanf("%c", &answer);
   printf("**********************************************************************\n");

   if(answer == 'y' || answer == 'Y')
   {
      FILE *g;
      g = fopen("CarInventory.csv", "r");
      char fileStore[10000];

      while(fgets(fileStore, sizeof(fileStore), g))
      {
         char *wordTaken;

         // The strtok function marks the end of the token by storing a null character

         wordTaken = strtok(fileStore, ",");
         // the strtok will separate the the file
         //  The strtok function returns a pointer to the first character of the token.
         //  If no token is found, a null pointer is returned.

         while(wordTaken != NULL)
         {
            /*
            Here I'm using the -%16 to print all the data inside the csv file with space
            */
            printf("%-16s", wordTaken);
            wordTaken = strtok(NULL, ",");
         }
         printf("\n");
      }
      int carPrice;
      char CarName[20];
      char Model[20];

      printf("Enter the car you like the most: ");
      scanf("%s", CarName);
      printf("Enter the model you like the most: ");
      scanf("%s", Model);
      printf("Enter the price of the car: ");
      scanf("%d", &carPrice);
      int months = 1;

      monthlyPayment(&carPrice, &months);
      printf("Your car payment will be %d per month for %d months.\n", carPrice, months);
      printf("\nCONGRATULATIONS on your new %s %s!\n", CarName, Model);
   }
   else
   {
      printf("Thank you for your time\n");
   }
   return 0;
}