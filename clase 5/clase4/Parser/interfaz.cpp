#include "interfaz.h"
#include "parser.hpp"
#include "lex.yy.c"

QString Clase3::Interfaz::Analaizar(std::string entrada) {
    yy_scan_string(entrada.c_str(), this->lexer);
    this->Parser->set_debug_level(true);

    this->Parser->parse();
    if (this->raiz != nullptr) {
        return this->raiz->Graficar();

    }
    return QString();


}

QString Clase3::Interfaz::Ejecutar(std::string entrada) {
    yy_scan_string(entrada.c_str(), this->lexer);
    this->Parser->set_debug_level(true);

    this->Parser->parse();
    if (this->raiz != nullptr) {
        Contexto *ctx = new Contexto();
        this->raiz->Interpretar(ctx);
        auto salida = ctx->consola;
        salida += "Reporte Memoria======  \n";
        salida += ctx->reportar();
        salida += "Reporte Errores======= \n";
        salida += ctx->getErrores();
        return salida;
    }
//    return ctx;

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
