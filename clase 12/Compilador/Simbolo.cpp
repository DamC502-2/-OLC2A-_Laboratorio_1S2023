//
// Created by damihan on 10/04/23.
//

#include <iostream>
#include "Simbolo.h"

Simbolo::Simbolo(const QString &nombre, int linea, int columna) : nombre(nombre), linea(linea), columna(columna) {
    this->Minimo = QVector<int>();
    this->Maximo = QVector<int>();
    this->Dimensiones = 0;
    this->pos_stack = 0;
}

// 1..3, 1..4, ...
void Simbolo::addDimension(int minimo, int maiximo) {
    this->Dimensiones++;
    this->Minimo.push_back(minimo);
    this->Maximo.push_back(maiximo);
}

int Simbolo::getDimFilas(int dimension) {
    if (dimension > this->Dimensiones){
        std::cerr << "error: " << this->nombre.toStdString()
        << " no contiene las suficientes dimensiones" << std::endl;
        return -1;
    }
    int tamaño = 1;
    int diferencia;

    for (int i = dimension; i < this->Dimensiones; i ++ ){
        std::cout<< this->Maximo[i] << " - " << this->Minimo[i] << std::endl;
        diferencia = this->Maximo[i] - this->Minimo[i] + 1;
        tamaño = tamaño * diferencia;
    }
    return tamaño;
}
