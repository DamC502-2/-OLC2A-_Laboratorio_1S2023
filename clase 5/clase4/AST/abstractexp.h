#ifndef ABSTRACTEXP_H
#define ABSTRACTEXP_H

#include <QString>
#include "../Interprete/Contexto/contexto.h"
#include "../Interprete/Contexto/resultado.h"
#include <sstream>

class AbstractExp
{
public:
    virtual Resultado* Interpretar(Contexto* ctx) = 0;
    virtual QString Graficar() = 0;
};

#endif // ABSTRACTEXP_H
