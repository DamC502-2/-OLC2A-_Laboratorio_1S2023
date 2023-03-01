
#include "t_tipos.h"
#include "../contexto.h"

T_Tipos::T_Tipos(int nivel, T_Tipos *anterior) : nivel(nivel), anterior(anterior) {
    this->tipos =  QHash<QString, Tipo *>();
//    this->anterior = nullptr;
}

int T_Tipos::getSize() {
    return this->tipos.size();
}

bool T_Tipos::existTipo(QString id) {
    if (!this->tipos.contains(id)) {
        if (this->anterior != nullptr) {
            return this->anterior->existTipo(id);
        } else {
            return false;
        }
    }
    return true;
}

Tipo *T_Tipos::getTipo(QString id) {
    if (this->tipos.contains(id)) {
        return this->tipos.value(id);

    } else {
        if (this->anterior != nullptr){
            return this->anterior->getTipo(id);
        }else {
            return nullptr;

        }

    }
}

void T_Tipos::addTipoCtx(Tipo *nuevoTipo, Contexto* contexto) {
    bool existe = this->existTipo(nuevoTipo->Nombre);

    if (!existe) {
        nuevoTipo->indice = this->nivel;
        this->tipos.insert(nuevoTipo->Nombre, nuevoTipo);
        this->nivel++;
    }else {
        //        contexto.

    }



}

void T_Tipos::addTiposBásicos() {

    auto boolean = new Tipo(nullptr, -1, 1, 1, 1, QString::fromStdString("Boolean"));
    auto integer = new Tipo(nullptr, -1, 1, 1, 1, QString::fromStdString("Integer"));
    auto Float = new Tipo(nullptr, -1, 1, 1, 1, QString::fromStdString("Float"));
    auto str = new Tipo(nullptr, -1, 1, 1, 1, QString::fromStdString("String"));

    this->addTipo(boolean);
    this->addTipo(integer);
    this->addTipo(Float);
    this->addTipo(str);
}

void T_Tipos::addTipo(Tipo *nuevoTipo) {
    nuevoTipo->indice = this->nivel;
    this->tipos.insert(nuevoTipo->Nombre, nuevoTipo);
    this->nivel++;
}



