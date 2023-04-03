//
// Created by damihan on 1/04/23.
//

#ifndef CLASE6_INTERFAZN_H
#define CLASE6_INTERFAZN_H

#include <QString>
#include <ParserNodos/AST/NoTerminal/NT_S.h>

namespace yyN {
    class ParserN;
    class location;
}
namespace Compilador {
    class Interfaz {
        void *lexer;
        yyN::location *loc;
        yyN::ParserN* Parser;
    public:
        ~Interfaz();
        QString CompilarDDS(std::string entrada);
        NT_S* raiz;
        Interfaz();
    };

}




#endif //CLASE6_INTERFAZN_H
