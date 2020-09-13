#include <iostream>
using namespace std;
#include "uno.h"
#include "dos.h"
#include "tres.h"

int N1=100;
int menug();

int main() {

  int c[N1];
  int opg;
  do{
    opg = menug();
    switch (opg){
      
      case 1:
      randomico(c);    
      break;

      case 2:
      MenuEjer2();
      break;

      case 3:
      ejercicio3();
      break;
    }
  }while(opg!=0);
}


int menug()
{
int opg;
  do {
  cout<<endl;
  cout << "1 - EJERCICIO 1" << endl;
  cout << "2 - EJERCICIO 2" << endl;
  cout << "3 - EJERCICIO 3" << endl;
  cout << "0 ‐ Salir" << endl;
  cout << "Opcion: ";
  cin >> opg;
} while ((opg < 0) || (opg > 3));
  return opg;
}

