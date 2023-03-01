#ifndef SIMBOLO_H
#define SIMBOLO_H


#include <Interprete/Contexto/resultado.h>
#include <Interprete/Contexto/Tipos/tipo.h>

class Simbolo
{
public:
    //valor
    Resultado* resultado;
    Tipo* tipo;
    QString nombre;
    Simbolo(Resultado *resultado, Tipo *tipo, const QString &nombre);
};

#endif // SIMBOLO_H
