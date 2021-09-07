#ifndef ROUTERS_H
#define ROUTERS_H

#include<map>
#include<vector>
#include<iostream>

using namespace std;

enum opciones{
    ALEATORIO,
    ZERO,
    MANUAL
};


class routers
{
private://atributos de la clase
    char nombre;
    map <char,int> enlaces;//contenedor de conexiones -> enlaces['Z']=6
public://metodos de la clase
    routers();//constructor de la clase
    routers(char name);//constructor sobrecargado

    void crearRed(int size, int flag);
    void crearRedManual(char letra,int size);
    void agregarRouter(char nombre, int costo);
    void eliminarRouter(char nombre);
    void imprimirEnlaces();
    void readFile();
    bool existeRouter(char nombre);
    char getNombre() const;
    int getRuta(vector<routers>Red);
};

#endif // ROUTERS_H
