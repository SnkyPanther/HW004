#include <stdio.h>

//Functions definitions.

void printIntro(void);
int printPipe(int);
int computerMove(int);
//***************************************************************************************

// Main function begins here.


int main( int argc, char *argv[] )  {
   
  int n, i, m, j;
  char str[60];
 
  printIntro();   

  if( argc == 2 ) {
    if (sscanf(argv[1], "%d", &n) != 1 || n<10) {
      printf("Something is wrong.\n");
      return 0;
    }
  } else if( argc > 2 ) {
    printf("ERROR: please supply either zero or one command line arguments.\n");
    return 0;
  } else {
    printf("How many sticks do you want to play with:  ");
    if(fgets(str, 60, stdin) == NULL || sscanf(str, "%d",&n)!=1 || n<10){
      printf("Something is wrong.\n");
      return 0;
    }
  }
  printf("The game will be played with %d sticks.\n", n);
  printPipe(n);
  while(n != 0)  {
    while(1){
      printf("How many sticks do you want to draw.(1, 2, 3, or 4)?  ");
      if (fgets(str, 60, stdin) != NULL && sscanf(str, "%d", &i )==1 && i>0 && i<5){
        break;
      }
    }
  n=n-i;
  if(n < 1)  {
    printf("You won!!\n");
    return 0;
  }
  printPipe(n);
  m=n%5;
  if(m>0 && m<5) {
    j=m;
  }
  else {
    j=1;
  }
  printf("Computer takes %d sticks.\n", j);
  n=n-j;
  if(n==0)  {
    printf("Computer won!!!\n");
    return 0;
  }
  printPipe(n);

  
  }
}


void printIntro(void)  {

  printf("Welcome to the stick picking game.\n");
  printf("Each turn you can take 1, 2, 3, or 4 sticks.\n");

  printf("The last person that draws that last stick win the game. Good luck.\n");
}


int printPipe(int number)    {
  int count=0;
  while( count != number )  {
    printf("|");
    count++;
  }
  printf("(%d)\n", number);
}
