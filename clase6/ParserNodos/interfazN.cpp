//
// Created by damihan on 1/04/23.
//

#include "ParserNodos/lex.yyN.c"
#include "interfazN.h"


QString Compilador::Interfaz::CompilarDDS(std::string entrada) {
    yy_scan_string(entrada.c_str() , this->lexer);
    this->Parser->set_debug_level(true);
    this->Parser->parse();
    if (this->raiz != nullptr){
        Contexto* ctx = new Contexto();
        this->raiz->Compilar(ctx);
        return ctx->gen->salida;
    }
    return QString();
}

Compilador::Interfaz::Interfaz() {
    yylex_init(&this->lexer);
    this->loc = new yyN::location();
    this->Parser = new yyN::ParserN( lexer, *loc, *this);

}

Compilador::Interfaz::~Interfaz() {
    yylex_destroy(lexer);
    delete loc;
    delete Parser;
    if (this->raiz != nullptr){
        delete this->raiz;
    }

}
