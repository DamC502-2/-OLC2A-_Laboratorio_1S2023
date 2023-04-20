//
// Created by damihan on 19/04/23.
//

#include <iostream>
#include "NT_LLamada.h"

NT_LLamada::NT_LLamada(std::string nombre, NT_LExprLLamada *parametros) {
    this->lExpresiones = parametros;
    this->nombre = QString::fromStdString(nombre);
}

Resultado *NT_LLamada::Compilar(Contexto *ctx) {

    ctx->gen->imprimir("//llamada:");

    //se compilan los resultados
    Funcion *funcionLLamada = ctx->gen->tFunciones->getFuncion(this->nombre);
    // se prepara el futuro os

    //si hay parámetros
    if (this->lExpresiones != nullptr) {

        this->lExpresiones->Compilar(ctx);

        if (this->lExpresiones->expresiones->size() != funcionLLamada->parametros.size()) {
            //si el numero de parametros en incorrecto entonces es un error
            std::cerr << "Error numero incorrecto de parametros en la llamada: "
                      << this->nombre.toStdString() << this->lExpresiones->resultados.size() << std::endl;
            return nullptr;
        }
    }

    int size_segmento = ctx->gen->tSimbolos->pos_libre_stack +
                        ctx->gen->segmento_temps->size();

    //se imprime y se genera el futuro pos
    auto futuro_pos = ctx->gen->newTemp();
    ctx->gen->imprimir("// futuro pos: " + futuro_pos);
    ctx->gen->imprimir(futuro_pos + " = P +  " +
                       QString::number(size_segmento));

    auto pos_param = ctx->gen->newTemp();

    if (this->lExpresiones != nullptr){
        ctx->gen->imprimir("// se guardan parametros");

        for (int i = 0; i < this->lExpresiones->resultados.size(); i++) {
            // TODO  verificacion de tipos  expresion <-> parametro esperado
            // se imprime el código que guardara los parámetros en el stackç

            //si parámetro es por referencia
            ctx->gen->imprimir("// param: " + funcionLLamada->parametros[i]->nombre);
            if (funcionLLamada->parametros[i]->referencia){
                ctx->gen->imprimir(pos_param + " = " + futuro_pos + "  + " + QString::number(i));
                ctx->gen->imprimir("stack[" + futuro_pos + "] = " + this->lExpresiones->resultados[i]->Referencia);
            }else {
                //si es por valor se usar el E.dir (valor)
                ctx->gen->imprimir(pos_param + " = " + futuro_pos + "  + " + QString::number(i));
                ctx->gen->imprimir("stack[" + futuro_pos + "] = " + this->lExpresiones->resultados[i]->Dir);

            }
            // si el parámetro es por valor

        }
    }

    ctx->gen->segmento_temps->remove(futuro_pos);
    ctx->gen->segmento_temps->remove(pos_param);

    // se genera el código para incrementar P
    ctx->gen->imprimir("P = P +  " +
                       QString::number(ctx->gen->tSimbolos->pos_libre_stack));

    //se genera el código que guardan los temporales
    ctx->gen->imprimir("//push temporales");
    ctx->gen->pushTemporales();

    ctx->gen->imprimir(funcionLLamada->nombre + "();");
    //se genera el código que guardan los temporales
    ctx->gen->imprimir("//pop temporales");
    ctx->gen->popTemporales();

    // se genera el código para decrementar P
    ctx->gen->imprimir("P = P -  " +
                       QString::number(size_segmento));

    Resultado *resultado = new Resultado();
    // se verifica si la funcion es void
    if (funcionLLamada->tipoRetorno != "Void") {
        ctx->gen->imprimir("// lectura return");

        // se genera el codigo se calcula de nuevo el futuro pos
        ctx->gen->imprimir(futuro_pos + " = P +  " +
                           QString::number(size_segmento));
        // se genera el codigo que calcule la posicion de return (al final de los parámetros)
        ctx->gen->imprimir(futuro_pos + " = " + futuro_pos +
        " + " + QString::number(funcionLLamada->parametros.size()));
        // se general el codigo que  asigna el valor del return a un temporal
        resultado->Dir = ctx->gen->newTemp();
        ctx->gen->imprimir(resultado->Dir + " = stack[" + futuro_pos + "];");
        resultado->Tipo = funcionLLamada->tipoRetorno;
    }
    return resultado; //NULL - o no?
}
