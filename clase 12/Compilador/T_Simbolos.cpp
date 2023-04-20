//
// Created by damihan on 10/04/23.
//

#include "T_Simbolos.h"


void T_Simbolos::addSimbolo(QString nombre, Simbolo *simbolo) {
    //manejo de stack
    simbolo->pos_stack = this->pos_libre_stack; //se le asigna la posicion libre
    this->pos_libre_stack++;  //se incrementa esa posicion

    //contructo anterior
    this->variables->insert(nombre, simbolo);
}

Simbolo *T_Simbolos::getSimbolo(QString nombre) {
    if (this->variables->contains(nombre)) {
        return this->variables->value(nombre);
    }
    if (this->anterior != nullptr){
        return this->anterior->getSimbolo(nombre);
    }
    return nullptr;
}

bool T_Simbolos::exitSimbolo(QString nombre) {
    return this->variables->contains(nombre);
}

QString T_Simbolos::getTamDimF(QString id, int dimension) {
    Simbolo* simbolo = this->getSimbolo(id);
    if (simbolo == nullptr){
        return "-1";
    }
    return QString::number( simbolo->getDimFilas(dimension));
}

void T_Simbolos::addDim(QString id, QString minimo, QString maximo) {
    Simbolo* simbolo = this->getSimbolo(id);
    if (simbolo == nullptr){
        return ;
    }
    simbolo->addDimension( minimo.toInt(), maximo.toInt() );
}

T_Simbolos::T_Simbolos(T_Simbolos *anterior) : anterior(anterior) {
    this->variables =  new QMap<QString, Simbolo*>();
    this->pos_libre_stack = anterior->pos_libre_stack;
}

T_Simbolos::T_Simbolos() {
    this->variables =  new QMap<QString, Simbolo*>();
    this->anterior = nullptr;
    this->pos_libre_stack = 0; //inicia en 0
}
