#include <stdio.h>
#include <time.h>
void take_enter() {
   printf("Press enter to stop the counter \n");
   while(1) {
      if (getchar())
      break;
   }
}
int main() 
{
   clock_t t;
   t = clock();
   printf("Timer starts\n");
   take_enter();
   printf("Timer ends \n");
   t = clock() - t;
   double time_taken = ((double)t)/CLOCKS_PER_SEC; 
   printf("The program took %f seconds to execute \n", time_taken);
}
