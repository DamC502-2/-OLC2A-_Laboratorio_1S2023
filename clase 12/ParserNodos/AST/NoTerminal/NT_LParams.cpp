//
// Created by damihan on 19/04/23.
//

#include "NT_LParams.h"

void NT_LParams::addParam(std::string nombre, std::string tipo, std::string tipo_parametro) {
   auto nuevoParam = new Parametro( QString::fromStdString(nombre),
                                QString::fromStdString(tipo),
                                tipo_parametro=="ByRef") ;
    this->parametros->push_back(nuevoParam);
}

NT_LParams::NT_LParams() {
    this->parametros = new QVector<Parametro*>();
}

Resultado *NT_LParams::Compilar(Contexto *ctx) {
    //se insertan los parametros al generador para:
    // añadirlos a la tabla de simbolos para continuar con la compilación
    // añadirlos a la tabla de funciones para ser usados cuando existan las llamadas
    // a la funcion que se esta compilando
    for (auto parametro : *this->parametros){
        Simbolo* nuevaVariable = new Simbolo(parametro->nombre,0,0);
        nuevaVariable->tipo_variable = parametro->referencia ? QString("Referencia") : QString("Valor");
        nuevaVariable->tipo = parametro->tipo;
        //se añade el parametro a la tabla de simbolos
        ctx->gen->tSimbolos->addSimbolo(parametro->nombre, nuevaVariable);
        //se añade el simbolo a la funcion que se esta reconociendo
        ctx->gen->tFunciones->addParametro(parametro);
    }

    return nullptr;
}
