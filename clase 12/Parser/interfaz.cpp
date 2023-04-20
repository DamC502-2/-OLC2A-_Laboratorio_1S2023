#include "interfaz.h"
#include "parser.hpp"
#include "lex.yy.c"

Clase6::Interfaz::Interfaz()
{
    yylex_init(&this->lexer);
    this->loc = new yy::location();
    this->Parser = new yy::Parser(lexer, *loc, *this);
    this->gen = new generador();
}


Clase6::Interfaz::~Interfaz(){
    yylex_destroy(lexer);
    delete loc;
    delete Parser;
    delete gen;
}

QString Clase6::Interfaz::CompilarDDS(std::string entrada){
    yy_scan_string(entrada.c_str(), this->lexer);
    this->Parser->set_debug_level(true);
    this->Parser->parse();
    return this->gen->salida;
}


