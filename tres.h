#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void ejercicio3();
void escribir(ofstream& archivo, char x);

void ejercicio3(){
    ofstream file;
    char caracter = '/';
    escribir(file, caracter);
}

void escribir(ofstream& archivo, char x){
    string y, z;
    float pre, cant;
    float cont1=0, cont2=0, cont3=0;
    archivo.open("Inventario.txt", ios::out);
    if(!archivo.is_open()){
        cout <<"ERROR";
    }else{
        archivo << "*******   DATOS DEL PROVEEDOR   *******" << endl;
        archivo << "Código" << setw(10) 
                << "Nombre" << setw(10)
                << "Ciudad" << setw(15)
                << "Teléfono" << endl;
        archivo << "ABC001" << setw(13)
                << "Favorita" << setw(10)
                << "Quito " << setw(15)
                << "0995644186" << endl;

        archivo << "\n\n\n*******   DATOS DEL Producto   *******" << endl;

        archivo << "nombre" << "\t" << "precio" << "\t" << "cantidad" << "\t" << "estado" << "\n";
        while(x!= '*'){
            cont1++;
            cout << "Nombre producto: ";
            cin >> y;
            cout << "precio: ";
            cin >> pre;
            cont2 += pre;
            cout << "Cantidad: ";
            cin >> cant;
            cont3 += cant;
            cout << "estado: ";
            cin >> z;
            archivo << y << "\t\t" << pre << "\t\t" << cant << "\t\t" << z << "\n";
            cout << "Pulse (*) para salir, sino cualquier tecla: ";
            cin >> x;
        }
    }

    archivo << "\n\n\nTotal Productos: " << cont2 << endl;
    archivo << "Cantidad de productos adquiridos: " << cont1 << endl;
    archivo << "El valor total: " << cont2*cont1 << endl;

    archivo.close();
    cout << "Se guardó la información exitósamente" << endl;

}