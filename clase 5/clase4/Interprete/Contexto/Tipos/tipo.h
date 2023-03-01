#ifndef TIPO_H
#define TIPO_H


#include <QString>



class Tipo {

    // el padre del tipo (para structs)
    Tipo* Padre;

    // la base del tipo (para arrays)
    int Base;
    // Dimension (arrays/structs)
    int Dimension;
    // limites, dimensiones, (para arrays)
    int minimo;
    int maximo;
    // conteido struct
    /* vector de <Tipo*> */
public:
    QString Nombre;
    int indice;
    Tipo(Tipo *padre, int base, int dimension, int minimo, int maximo,  QString nombre);
    bool Equal( Tipo* tipo);

};

#endif // TIPO_H
