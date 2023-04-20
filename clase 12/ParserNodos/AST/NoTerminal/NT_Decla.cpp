//
// Created by damihan on 19/04/23.
//

#include "NT_Decla.h"



NT_Decla::NT_Decla(std::string id, std::string tipo) {
    this->id = QString::fromStdString(id);
    this->tipo = QString::fromStdString(tipo);
}

Resultado *NT_Decla::Compilar(Contexto *ctx) {
    // se agrega la nueva variable a la tabla de simbolos
    // no se genera código
    auto nuevo_s = new Simbolo(this->id, 0 ,0);
    nuevo_s->tipo = this->tipo;
    nuevo_s->tipo_variable = QString("Local"); //es una variable de tipo local
    ctx->gen->tSimbolos->addSimbolo(this->id, nuevo_s);
    return nullptr;
}
