#include "parserctx.hpp"
//#include "lexer.hpp"
#include "parser.hpp"
#include "lex.yy.c"
//#include "lexer.cpp"
/*
OCL2Calc::ParserCtx::ParserCtx()
{


}*/

namespace OCL2Calc {
ParserCtx::ParserCtx()
{
    //inicializamos el lexer ( el *void se convierte en un scanner)
    yylex_init(&lexer);
    // se crea un location
    loc = new yy::location();
    // se crea un parser
    Parser = new yy::Parser(lexer, *loc, *this);
    Salida = "";
}

ParserCtx::~ParserCtx(){
    yylex_destroy(lexer);
    delete loc;
    delete Parser;
}

std::string ParserCtx::Analizar(std::string entrada){


    // se carga el buffer en en analizador
    yy_scan_string(entrada .c_str(), lexer );
    // se activan registro de depuracion
    this->Parser->set_debug_level(true);
    //se analiza

    this->Parser->parse();
    return "";
}


}
