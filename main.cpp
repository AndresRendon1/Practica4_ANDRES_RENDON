#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "routers.h"

using namespace std;

//prototipos de funciones
vector<routers>crearRed();
vector<routers>crearRedManual();
void imprimirRed(vector<routers>R);
void agregarRouter(vector<routers>&R);
void eliminarRouter(vector<routers>&R);
void leerArchivo();
//variables globales
int opcion=1;
int num_routers=0;
int main()
{
    vector<routers>Red;
    while(opcion!=0){
        cout << "GUIA#4 INFORMATICA II ANDRES FELIPE RENDON VILLADA 2021-1" << endl;
        cout<<"MENU DE FUNCIONAMIENTO."<<endl;
        cout<<"1.CREAR RED AUTOMATICA."<<endl;
        cout<<"2.CREAR RED MANUAL."<<endl;
        cout<<"3.AGREGAR NODO."<<endl;
        cout<<"4.ELIMINAR NODO."<<endl;
        cout<<"5.CONOCER LA MEJOR RUTA."<<endl;
        cout<<"6.LEER ARCHIVO."<<endl;
        cout<<"0.PARA SALIR"<<endl;
        cout<<"Ingrese la opcion que desea ejecutar: ";
        cin>>opcion;
        switch(opcion){
        case 1:{
            cout<<"CREANDO RED AUTOMATICA...."<<endl;
            Red = crearRed();
            imprimirRed(Red);
        }break;
        case 2:{
            cout<<"CREANDO RED MANUAL...."<<endl;
            Red = crearRedManual();
            imprimirRed(Red);

        }break;
        case 3:{
            cout<<"AGREGANDO ROUTER...."<<endl;
            agregarRouter(Red);
            imprimirRed(Red);
        }break;
        case 4:{
            cout<<"ELIMINANDO ROUTER...."<<endl;
            eliminarRouter(Red);
            imprimirRed(Red);
        }break;
        case 5:{
            cout<<"pendiente..."<<endl;
        }break;
        case 6:{
            cout<<"LEYENDO ARCHIVO TXT...."<<endl;
            leerArchivo();
        }break;

        }
    }

    return 0;
}

vector<routers> crearRed(){
    vector<routers>Red;
    cout<<"Ingrese la cantidad de routers que tendra la red: ";
    cin>>num_routers;
    for(int i=0;i<num_routers;i++){
        routers aux('A'+i);
        aux.crearRed(num_routers,ALEATORIO);
        Red.push_back(aux);
    }

    return Red;
}

vector<routers> crearRedManual(){
    vector<routers>Red;
    char letra;
    cout<<"Ingrese la cantidad de routers que tendra la red: ";
    cin>>num_routers;
    for(int i=0;i<num_routers;i++){
        cout<<"Ingrese el nombre del router que va a crear: ";
        cin>>letra;
        routers aux(letra);
        aux.crearRedManual(letra,num_routers);
        Red.push_back(aux);
    }
    return Red;
}

void imprimirRed(vector<routers>R){
    for(unsigned i=0;i<R.size();i++){
        cout<<R[i].getNombre();
        R[i].imprimirEnlaces();
    }
    cout<<endl;
}

void agregarRouter(vector<routers>&R){
    char letra;
    int costo;
    cout<<"Ingrese el nombre del router que desea agregar: ";
    cin>>letra;
    cout<<"Ingrese el costo de conexion: ";
    cin>>costo;
    for(unsigned i=0;i<R.size();i++){
        R[i].agregarRouter(letra,costo);
    }
}

void eliminarRouter(vector<routers>&R){
    char letra;
    cout<<"Ingrese el nombre del router que desea eliminar: ";
    cin>>letra;
    for(unsigned i=0;i<R.size();i++){
        if(R[i].getNombre()==letra){
            R[i].eliminarRouter(R[i].getNombre());
        }
    }
}

void leerArchivo(){
    ifstream Leer;
    string contenido,texto;
    char nombre='0';
    char nombre2='0';
    char costo='0';
    Leer.open("RED.txt");
    if(Leer.is_open()){//si el archivo se pudo abrir correctamente entonces
        cout<<"El archivo RED.TXT se pudo abrir correctamente"<<endl;
        while(!Leer.eof()){//mientras no sea el final del txt
            getline(Leer,contenido);//se lee linea por linea el archivo
            texto+=contenido+'\n';
        }
    }
    Leer.close();
    for(int i=0;texto[i]!='\0';i++){
        if(texto[i]==';'||texto[i]=='|'||texto[i]==':'){
            continue;
        }
        if(nombre!='0'||nombre2!='0'){
            if(texto[i]==nombre2||texto[i]==costo){
                continue;
            }
            if(texto[i]=='0'||texto[i]=='1'||texto[i]=='2'||texto[i]=='3'||texto[i]=='4'||texto[i]=='5'||texto[i]=='6'||texto[i]=='7'||texto[i]=='8'||texto[i]=='9'){
                costo=texto[i];
                cout<<"Costo "<<costo<<endl;
            }
            if(texto[i]!='0'||texto[i]!='1'||texto[i]!='2'||texto[i]!='3'||texto[i]!='4'||texto[i]!='5'||texto[i]!='6'||texto[i]!='7'||texto[i]!='8'){
                nombre2=texto[i];
                cout<<"Conectado con: "<<nombre2<<endl;
            }

        }
        if(nombre=='0'||texto[i]=='\n'){
            nombre=texto[i];
            if(texto[i]=='\n'){
                nombre=texto[i+1];
            }
            cout<<"Router: "<<nombre<<endl;
        }


    }

    cout<<"RED.... "<<endl<<texto<<endl;
}
