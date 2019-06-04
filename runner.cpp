#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

void drawMenu() {
  printf("\n\n");
  printf("---------------------------\n");
  printf("---------------------------\n");
  printf("-V  WELCOME TO THE CPP!  V-\n");
  printf("---------------------------\n");
  printf("---------------------------\n");
}

int getOption() {
  int cont = 0;

  while(true){
    int option = 0;
    printf("\n>> Choose your option: ");
    scanf("%d", &option);

    if(option > 0 && option < 4){
      return option;
    }
  }
}

int main() {
  try{
    throw 20;
  }catch(int e){
    cout << e;
  }
return true;
  while(true){
    drawMenu();

    int option = getOption();

    switch(option) {
      case 1: { 
        printf("FIRST OPTION");
        break;
      }
      case 2: { 
        printf("SECOND OPTION");
        break;
      }
      case 3: { 
        printf("THIRD OPTION");
        break;

      }
      default: {
        printf("FOURTH OPTION");
        break;

      }
    }

  }
}
