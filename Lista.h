#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Nodo.h"
using namespace std;


template <typename Tipo>
class Lista
{
public:
    Nodo<Tipo>* inicio;

    Lista()
    {
        inicio = NULL;
    }

    void imprimir()
    {
        for(Nodo<Tipo>* temp = inicio;
            temp!=NULL;
            temp = temp->sig)
        {
            cout<<temp->num<<endl;
        }
    }

    void agregarAlInicio(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            nuevo->sig = inicio;
            inicio = nuevo;
        }
    }

    void agregarAlFinal(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            Nodo<Tipo>*temp = inicio;
            while(temp->sig!=NULL)
            {
                temp=temp->sig;
            }
            temp->sig = nuevo;
        }
    }

    void borrar(Tipo valor_a_borrar)
    {
        if(inicio->num == valor_a_borrar)
        {
            Nodo<Tipo>* borrar = inicio;
            inicio = inicio->sig;
            delete borrar;
        }else
        {
            Nodo<Tipo>* temp = inicio;
            while(temp->sig->num!=valor_a_borrar)
            {
                temp=temp->sig;
                if(temp->sig==NULL)
                    return;
            }
            Nodo<Tipo>* borrar = temp->sig;
            temp->sig = temp->sig->sig;
            delete temp->sig;
        }
    }

    //Devuelve true si la lista esta vacia, de lo contrario devuelve false
    bool estaVacia()
    {
        if(inicio==NULL)//Realizamos un IF para ver si la lista esta vacia
            return true; //Devolvera True si se cumple la condicion inicio==NULL
        else
            return false; //Caso contrario nos retorna False
    }

    //Devuelve el valor almacenado en el primer nodo de la lista
    Tipo obtenerPrimerValor()
    {
        return inicio->valor; //Retornamos el valor que tenemos almacenado en el primer nodo "inicio"
    }

    //Devuelve el valor almacenado en el ultimo nodo de la lista
    Tipo obtenerUltimoValor()
    {
        //REFERENCIA: https://github.com/Ceutec/Listas/blob/master/main.cpp
        Nodo<Tipo>*temp = inicio; // Asignamos el valor inicio al Nodo
        while(temp->sig!=NULL) //Definimos un While que nos permite obtener el ultimo valor mientras sea diferente a NULL
        {
            temp=temp->sig;//Recoremos el valor para obtener el ultimo.
        }
        return temp->valor; //Retornamos el valor que esta al final en la lista.
    }

    //Devuelve el valor mayor almacenado en la lista
    Tipo obtenerMayor()
    {
        Nodo<Tipo>*temp = inicio; // Asignamos el valor inicio al Nodo
        Nodo<Tipo> *mayor; // Definimos nodo *mayor
        while(temp!=NULL) //Definimos un While que nos permite comparar la variable temp que sea diferente de NULL
        {
            if(mayor<temp) //Creamos un IF para asignar el valor mayor y almacenarlo en la variable temp
            {
                mayor = temp; //Asignamos el valor de temp a Mayor
            }
        temp=temp->sig;//nos desplazamos por el siguiente valor.
        }
    return mayor->valor; //Devolvemos el valor mayor que encontramos en el While / If

    }
};
#endif // LISTA_H
