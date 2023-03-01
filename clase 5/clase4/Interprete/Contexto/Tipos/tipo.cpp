#include <sstream>
#include "tipo.h"

Tipo::Tipo(Tipo *padre, int base, int dimension, int minimo, int maximo,  QString nombre) : Padre(
        padre), Base(base), Dimension(dimension), minimo(minimo), maximo(maximo), Nombre(nombre){}

bool Tipo::Equal(Tipo *tipo) {
//    return std::equal(this->Nombre.begin(), this->Nombre.end(), tipo->Nombre.begin(), tipo->Nombre.end());
int i =  QString::compare(this->Nombre, tipo->Nombre, Qt::CaseInsensitive);
    return i == 0;

}


