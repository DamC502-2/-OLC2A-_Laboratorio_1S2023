#include "interfaz.h"
#include "parser.hpp"
#include "lex.yy.c"

QString Clase3::Interfaz::Analaizar(std::string entrada) {
    yy_scan_string(entrada.c_str(), this->lexer);
    this->Parser->set_debug_level(true);

    this->Parser->parse();
    if (this->raiz != nullptr){
        return this->raiz->Graficar();

    }
    return QString();


}

Clase3::Interfaz::Interfaz() {
 yylex_init(&this->lexer);
 this->loc = new yy::location();
 this->Parser = new yy::Parser(lexer, *loc, *this);
}

Clase3::Interfaz::~Interfaz() {
    yylex_destroy(lexer);
    delete loc;
    delete Parser;
}
