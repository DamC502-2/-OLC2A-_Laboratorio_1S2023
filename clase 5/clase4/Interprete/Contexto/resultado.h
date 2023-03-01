#ifndef RESULTADO_H
#define RESULTADO_H

#include<QString>
#include <Interprete/Contexto/Tipos/tipo.h>

class Resultado
{
public:
    int valor;
    double valorD;
    QString valorS;
    Tipo* tipo;

    Resultado();
    Resultado(int valor);
    Resultado(double valorD);
    Resultado(QString valorS);






};
/*
Resultado* ampliar (Resultado *vIzq , Resultado *vDer){
    if (vIzq->tipo->Equal(vDer->tipo) )
    {
        return vIzq;
    }
    else
    {
        if (vIzq->tipo->Nombre == 'Integer' &&
        vDer->tipo->Nombre == 'Float' ){
            Resultado *resultado = new Resultado();
            resultado->valorD = vIzq->valor;
            resultado->tipo = vIzq->tipo;
            return resultado;
        }

    }
    return nullptr;
}*/
/*
Resultado* ampliar (Resultado *vIzq , Resultado *vDer){
    if (vIzq->tipo->Equal(vDer->tipo) )
    {
        return vIzq;
    }
    else
    {
        switch (vIzq->tipo->indice
        ) {
            case 0: //Integer

                switch (vDer->tipo->indice) {
                    case 2: //float
                    Resultado *resultado = new Resultado();
                    resultado->valorD = vIzq->valor;
                    resultado->tipo = vIzq->tipo;
                    return resultado;
                }
            break;
        }
    }
    return nullptr;
}
 */
// consiste báasicamente en modificar el objeto dentro de si mismo
// acomodandse a otro tipo
/*
Resultado* ampliarSUMA (Resultado *vIzq , Resultado *vDer){
    if (vIzq->tipo->Equal(vDer->tipo) )
    {
        return vIzq;
    }
    else
    {
        // convertir se encargaría de convertir la expresion
        // ya sea dentro de Resultado o usando un conversor
        // independiente
        return vIzq->Convertir(vDer->tipo);
        //ó
        return Conversor.Convertir(vIzq, vDer->tipo);

    }
    return nullptr;
}
*/
#endif // RESULTADO_H
