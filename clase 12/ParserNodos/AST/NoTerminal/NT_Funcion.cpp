//
// Created by damihan on 19/04/23.
//

#include "NT_Funcion.h"

Resultado *NT_Funcion::Compilar(Contexto *ctx) {
    //añadimos la funcion a la tabla de funciones
    ctx->gen->tFunciones->addFuncion(this->nombre);

    //hacemos push a la tabla de simbolos
    ctx->gen->tSimbolos = new T_Simbolos(ctx->gen->tSimbolos);



    ctx->gen->imprimir("void " + this->nombre + "() {");
    //si hay parametros los reconocemos
    if (this->parametros != nullptr){
        this->parametros->Compilar(ctx);
    }
    // añadimos el return como "variable" (si es que es necesario)
    if (this->tipo_retorno != "Void" ){
        auto s_return = new Simbolo(QString("return"),0 ,0);
        s_return->tipo_variable = "Local";
        s_return->tipo = this->tipo_retorno;
        ctx->gen->tSimbolos->addSimbolo(QString("return"), s_return );
    }
    //luego de haberse reconocido todos los parámetros se guarda la función
    ctx->gen->tFunciones->guardarFuncion();

    // compilamos las sentencias
    this->lSentencias->Compilar(ctx);

    //se impirme la parte final
    ctx->gen->imprimir("return;");
    ctx->gen->imprimir("}");
    //guardamos la funcion

    //hacemoso pop de la tabla de simbolos
    ctx->gen->tSimbolos = ctx->gen->tSimbolos->anterior;

    return nullptr;
}

NT_Funcion::NT_Funcion(std::string id, std::string tipo_retorno, NT_LParams *parametros, NT_LSentencias* sentencias ) {
    this->nombre = QString::fromStdString(id);
    this->tipo_retorno = QString::fromStdString(tipo_retorno);
    this->parametros = parametros;
    this->lSentencias = sentencias;
}
