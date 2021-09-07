#include "routers.h"

using namespace std;

char routers::getNombre() const
{
    return nombre;
}

routers::routers()//constructor de la clase por defecto
{
    nombre = 'A';//nombre por defecto del router
}

routers::routers(char name)//constructor sobrecargado
{
    nombre = name;
}

void routers::crearRed(int size, int flag)
{
    char letra='A';
    int costo;
    for(int i=0;i<size;i++){
        if(letra==nombre){
            enlaces[letra]=0;
        }
        if(flag==ALEATORIO){//para inicializar las conexiones de manera aleatoria
            enlaces[letra]=rand()%11;
        }else if(flag == ZERO){//para inicializar todas las conexiones en cero
            enlaces[letra]=0;
        }else if(flag == MANUAL){//para inicializar las conexiones de forma manual
            cout<<"Ingrese el valor del costo de " <<letra<<": ";
            cin>>costo;
            enlaces[letra]=costo;
        }

        letra++;
    }
}

void routers::crearRedManual(char letra,int size)
{
    int costo=0;
    for(int i=0;i<size;i++){
        cout<<"Ingrese el nombre del router que desea conectar: ";
        cin>>letra;
        cout<<"Ingrese el costo de conexion del router "<<letra<<" - " <<nombre<<" : ";
        cin>>costo;
        if(letra==nombre){
            enlaces[letra]=0;
        }
        else{
           enlaces[letra]=costo;
        }

    }
}

void routers::agregarRouter(char nombre, int costo)
{
    if(existeRouter(nombre)){
        cout<<"Error en la operacion "<<"<<"<<nombre<<">>"<<" El router ya existe!"<<endl;
    }
    enlaces[nombre]=costo;
}

void routers::eliminarRouter(char nombre)
{
   map<char,int>::iterator it;
   it = enlaces.find(nombre);
   enlaces.erase(it,enlaces.end());
}

void routers::imprimirEnlaces()
{
    map<char,int>::iterator it;
    for(it=enlaces.begin();it!=enlaces.end();it++){
        cout<<"|"<<it->first<<":"<<it->second<<"\t";
    }
    cout<<"|"<<endl;
}

void routers::readFile()
{

}

bool routers::existeRouter(char nombre)
{
    map<char,int>::iterator it= enlaces.find(nombre);
    if(it==enlaces.end()){
        return false;
    }
    return true;
}
