#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void MenuEjer2();
void Ejerci2(int Vector[],int Vec[],int n);
void Ingresar(int n, int Vector[], int Vec[]);
void Dividir(int Elementos[],int inicial,int final);
void Fucionar(int Elementos[],int pinicial,int pfinal, int medio);
int Busqueda(int Vec[], int Elem, int n);

void MenuEjer2()
{

  int n=0;
  int Elem;
  int Opci;
  int Vector[100];
  int Vec[100];
  ofstream Ejercicio2;


  Ejercicio2.open("Ejercicio 2",ios::app);

 do{ 
   cout << "\t\tBienvenido\n";
   cout << "1.-Ingresar Elementos\n";
   cout << "2.-Buscar Elementos\n";
   cout << "3.-Salir\n";
   cin >> Opci;

  switch(Opci)
  {
    case 1:{
      do
  {
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;
    if(n<0)
    {
      cout << "Valor Invalido,Vuelva a ingresar\n";
    }

  }while(n<0);
      Ejerci2(Vector, Vec,n);
      break;
    }
    case 2:
    {
      cout << "Que Elemento desea buscar: ";
      cin >> Elem;
      Ejercicio2 <<"Elemento a buscar: " <<Elem << endl;

      if((Busqueda(Vec, Elem, n))==(-1))
      {
        Ejercicio2 << "Elemento No encontrado\n";
        cout << "Elemento No encontrado\n";
      }else
      {
        Ejercicio2<< "Elemento encontrado en la posision " << Busqueda(Vec, Elem, n) << endl;
        cout << "Elemento encontrado en la posision " << Busqueda(Vec, Elem, n) << endl;
      }
      break;
    }
  }

 }while(Opci !=3);

 Ejercicio2.close();

}

void Ejerci2(int Vector[],int Vec[],int n)
{
  ofstream Ejercicio2;
  Ingresar(n,Vector,Vec);

  Dividir (Vec,0,n-1);
  Ejercicio2.open("Ejercicio 2",ios::app);
  
  cout  << "Arreglo Original: {";
  for(int i=0;i<n;i++)
  {
    cout << Vector[i] << " ";
  }
  cout  << "}\n";

  
  
  Ejercicio2 << "Arreglo Ordenado: {";

  cout << "\nArreglo Ordenado: {";
   for(int i=0;i<n;i++)
  {
    cout << Vec[i] << " ";
    Ejercicio2 << Vec[i] << " ";
  }
  cout << "}\n";
  Ejercicio2 << "}\n";
  Ejercicio2.close(); 


}

void Ingresar(int n,int Vector[] , int Vec[])
{
  
  ofstream Ejercicio2;
  Ejercicio2.open("Ejercicio 2",ios::app);
  Ejercicio2 << "Cantidad de elementos: " << n << endl;

  Ejercicio2 << "Arreglo Original: {"; 
  for(int i=0;i<n;i++)
  {
    cout << "Ingrese el Elemento " << i+1 << ": ";
    cin >> Vector[i];
    Vec[i]=Vector[i];
    Ejercicio2 << Vector[i] << " ";

  }
  Ejercicio2 << "}\n";
  Ejercicio2.close();
  
}

void Dividir(int Elementos[],int inicial,int final)
{
  int Mitad;
  if(inicial<final)
  {
    Mitad =(final+inicial)/2;
    Dividir(Elementos, inicial,Mitad);
    Dividir(Elementos, Mitad+1,final);
    Fucionar(Elementos,inicial,final,Mitad);
  }
}

void Fucionar(int Elementos[],int pinicial,int pfinal, int medio)
{
  int i,j,k,temp[pfinal-pinicial+1];
  i=pinicial;
  k=0;
  j=medio+1;

  while(i<=medio && j<=pfinal)
  {
    if(Elementos[i]<Elementos[j])
    {
      temp[k]=Elementos[i];
      k++;
      i++;
    }else
    {
      temp[k]=Elementos[j];
      k++;
      j++;
    }
  }
  while(i<=medio)
  {
    temp[k]=Elementos[i];
    k++;
    i++;
  }
  while(j<=pfinal)
  {
    temp[k]=Elementos[j];
    j++;
    k++;
  }
  for(i=pinicial;i<=pfinal;i++)
  {
    Elementos[i]=temp[i-pinicial];
  }

}


int Busqueda(int Vec[], int Elem,int n)
{
  
  for(int i=0;i<n;i++)
  {
    if(Vec[i]==Elem)
    {
      return i;
    }
  }
  return -1;
}

