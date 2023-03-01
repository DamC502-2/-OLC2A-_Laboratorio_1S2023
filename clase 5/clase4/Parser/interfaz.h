#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <string>
#include "../AST/abstractexp.h"
#include "../AST/No_Terminales/nt_s.h"

namespace yy {
    class Parser;
    class location;
}




namespace Clase3 {
    class Interfaz {
    public:
        Interfaz();
        ~Interfaz();
        void* lexer;
        yy::location *loc;
        yy::Parser* Parser;

        QString Analaizar( std::string  entrada );
        QString Ejecutar( std::string  entrada );
        NT_S* raiz;

    };

}


#endif // INTERFAZ_H
