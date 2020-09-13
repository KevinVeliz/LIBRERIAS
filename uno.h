#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int N=100,pq=0;
void randomico(int a[]);
void imprimir(int a[]);
void ordenar(int a[]);
void m_m(int a[]);


void randomico(int a[]){
  srand((unsigned)time(NULL));
  int num,n,m,p;
  cout<<"Cuantos elementos debe tener el vector: ";
  cin>>N;
  for(p=0;p<N;p++){
  n=rand()%99+0;
  a[p]=n; 
  }
  cout<<"Elementos iniciales\n";
  imprimir(a);
  cout<<"Elementos ordenados\n";
  ordenar(a);  
  imprimir(a);
  m_m(a);
}

void imprimir(int a[]){
  ofstream xd;
  xd.open("Ejercicio1.txt",ios::app);
  if(pq==0){
    xd<<"Elementos iniciales\n";
    pq++;
  }
  else if(pq==1){
    xd<<"Elementos ordenados\n";
    pq--;
  }
  for(int i=0;i<N;i++){
    cout<<"["<<a[i]<<"] ";
    xd<<"["<<a[i]<<"] ";
  }
  cout<<endl;
  xd<<endl;
  xd.close();
}

void ordenar(int a[]){
  int j,k;
  double aux;
  for(j=0;j<N;j++){
    for(k=j+1;k<N;k++){
      if(a[k]<a[j]){
        aux=a[j];
        a[j]=a[k];
        a[k]=aux;
      }
    }
  }
}

void m_m(int a[]){
  ofstream numeritos;
  int i=0, s=N-1, t=0,u=0;
  for (int j=0;j<N;j++){
  if(a[i]==a[j]){
    t=t+1;
  }
  else if(a[s]==a[j]){
    u=u+1;
  }
}
numeritos.open("Ejercicio1.txt",ios::app);
cout<<"El menor es " <<a[i]<<" y se repite : "<<t<<" veces\n";
numeritos<<"El menor es " <<a[i]<<" y se repite : "<<t<<" veces\n";
cout<<"El mayor es " <<a[s]<<" y se repite : "<<u<<" veces\n";
numeritos<<"El mayor es " <<a[s]<<" y se repite : "<<u<<" veces\n";
numeritos.close();
}