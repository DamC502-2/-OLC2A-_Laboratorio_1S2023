#include <QString>
#include <iostream>
#include <sstream>
#include "memoria.h"



Memoria::Memoria() {
    this->variables = QMap<QString, Simbolo *>();
    this->anterior = nullptr;
}

Memoria::Memoria(Memoria *anterior) {
    this->variables =  QMap<QString, Simbolo *>();
    this->anterior = anterior;
}

Simbolo *Memoria::getSimbolo(QString nombre) {
//    std::cout<<nombre.toStdString()<<": nombre"<<std::endl;
//    QMapIterator<QString, Simbolo*> iter(this->variables);
//    while(iter.hasNext())
//    {
//        iter.next();
//        qDebug() << iter.key() << " : " << iter.value();
//    }

    if (this->variables.contains(nombre)) {
        return this->variables.value(nombre);
    }


    if (this->anterior != nullptr) {
        return this->anterior->getSimbolo(nombre);
    }
    return nullptr;
}

bool Memoria::existSimbolo( QString nombre) {
    std::cout<<nombre.toStdString()<<" existSimbolo"<<std::endl;

    if (this->variables.isEmpty()){
        if (this->anterior == nullptr){
            return false;
        }
        return this->anterior->existSimbolo(nombre);
    }

    if (!(this->variables.contains(nombre))) {
        if (this->anterior != nullptr) {
            return this->anterior->existSimbolo(nombre);
        } else {
            return false;
        }
    }
    return true;
}

void Memoria::addSimbolo(QString nombre, Simbolo *simbolo) {
    if (this->existSimboloInThisScope(nombre)) {
        //error
        std::cout << "No se puede redeclarar " << nombre.toStdString()  << "En este ámbito"  << std::endl;
        return;
    }
    std::cout<<"insertado: "<<nombre.toStdString() <<std::endl;
    this->variables.insert(nombre, simbolo);
}

QString Memoria::reportar() {
    std::stringstream reporte;
    QMap<QString, Simbolo *>::const_iterator iterador = this->variables.constBegin();
    auto pos_final = this->variables.constEnd();
    Simbolo* temp;
    while(iterador != pos_final){
        temp = iterador.value();
        reporte << temp->nombre.toStdString() <<"," << temp->tipo->Nombre.toStdString() << " \n";
         iterador++;
    }
    return QString::fromStdString(reporte.str());
//    return QString();
}

bool Memoria::existSimboloInThisScope(QString nombre) {
    return this->variables.contains(nombre);
}
