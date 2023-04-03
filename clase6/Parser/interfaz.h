#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <string>
#include <QString>
#include "generador.h"

namespace yy {
    class Parser;
    class location;
}

namespace Clase6 {
class Interfaz
{
public:
    Interfaz();
    ~Interfaz();
    void *lexer;
    yy::location *loc;
    yy::Parser* Parser;

    // metodos
    QString CompilarDDS(std::string entrada);

    generador* gen;
};


}


#endif // INTERFAZ_H
