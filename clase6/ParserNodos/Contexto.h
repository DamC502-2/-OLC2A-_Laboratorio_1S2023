//
// Created by damihan on 1/04/23.
//

#ifndef CLASE6_CONTEXTO_H
#define CLASE6_CONTEXTO_H


#include "ParserNodos/AST/Resultado.h"
#include "Parser/generador.h"
/*TODO manejo de tipos
     // Tabla de simbolos
     // etc
      */
class Contexto {
public:
    Contexto();
    generador* gen;
     Resultado* r_Heredado;
     QString Linicio;
     QString LSalida;

};


#endif //CLASE6_CONTEXTO_H
