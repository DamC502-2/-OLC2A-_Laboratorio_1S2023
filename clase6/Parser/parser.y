/*comando   bison --verbose -o parser.cpp  parser.y */

/* Se requiere una versión minima de Bison */
%require  "3.0.4"
/* Se usa el skeleton más recienta para c++ */
%skeleton "lalr1.cc"

/* indica que se deben de crear archivos de cabeceras (.h)
    para las definiciones de tokens
*/
%defines

/* indica el namespace que contiene al parser */
// %name-prefix="yy" ó
%define api.prefix{yy}

/* indica la clase que envuelve al parser */
%define api.parser.class {Parser}

/* indica que se generaran clases de tipo locations que leerá el lexer*/
%locations

/* indica que se deben crear contructores y funciones tipo make_TOKEN para cada token */

%define api.token.constructor

/* indica que se utilizará la notacion $1 -> $$ de los no terminales */
%define api.value.type variant

/* indica que el analizador mostrara un trace cuando haya un error*/
%define parse.trace

/* indica que el analizador mostrará los errores de forma descriptiva */
%define parse.error verbose

%code requires
{
    /* código  que se inserta al inicio por lo regular son cabeceras*/
    #include <iostream>
    #include <string>
    #include <QString>     


    //Interfaz
    #include "interfaz.h"
    #include "atributos.h"


    /*
    Se pueden definir estructuras y tipos para los no terminales
    */

}
/* enlace con la función del retorno de simbolos */
%code
{
yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class Clase6::Interfaz & intr);
}


%token END 0;  //token de salida

/// %token<tipo> nombre+
//cuidado con el orden
// %token <std::string> ID NUMERO
%token <std::string>  NUMERO ID STRING
// token de tipo por defecto
    //token por ID
%token SUMA MENOS OR AND EQ
    //token por texto
%token '<' '>' ';' '*' '/' '(' ')' '=' '{' '}' ;
// negación unaria
%token NEG
// palabras reservadas 
%token IF ELSE WHILE BREAK CONTINUE
/*
forma alterna
%token SUMA '+'
%token ID 'un_id'

*/
// precedencia menor a mayor
%left NUMERO
%left  OR
%left AND
%left EQ
%left '>' '<' 
%left SUMA MENOS //menos -
%left '*' '/' //más
%left NEG

/* fin de la definción de tipos*/

/* La clase que envuele al parser se pasa por referencia
del parser al escaner evitando crear variables globales

*/

%lex-param {void *scanner} {yy::location& loc} { class Clase6::Interfaz & intr }
%parse-param {void *scanner} {yy::location& loc} { class Clase6::Interfaz & intr }

/* es posible hacer tipos personalizados para definir no terminales añadiendo lo siguiente

%union {
    std::string;
    double;
    AbstractExp*;
}*/

/*definicion de no terminales*/
%type<atributos*> s 
%type<atributos*> cond
%type<atributos*> expr operel>
%type<atributos*> markIF2 markWhile1

// printer
%printer { yyoutput << $$; } <*>;

%%

%start s; 

s: cond {
        $$ = $1; 
        intr.gen->imprimir(QString::fromStdString("// verdadero"));
        intr.gen->imprimir($1->EV + ":");
        intr.gen->imprimir(QString::fromStdString("// falso"));
        intr.gen->imprimir($1->EF + ":");
 }
 | lSentencias {}
 ;

lSentencias: lSentencias sentencia { }
    | sentencia {}
    ; 

sentencia: if { } 
    | while { }    
    | BREAK { // sentenica break
        // TODO: verificar la existencia de la etiqueta
        intr.gen->imprimir( QString( "goto ")+ intr.gen->peekEtqF() + " //break");
    }
    | CONTINUE { // sentencia continue 
        // TODO: verificar la existencia de la etiqueta
        intr.gen->imprimir( QString( "goto ")+ intr.gen->peekEtqInicio() + " //continue");
    } 
    ; 

if: IF '(' cond ')' markIF  '{' lSentencias '}' markIF2  else {
                                                //gen(LSalidaIF)
                                        intr.gen->imprimir($9->LSalida + ":") ;}
    ;

markIF: %empty { 
        // codigo marcador        
        //gen (cond.EV)        
        intr.gen->imprimir($<atributos*>-1->EV + ":");
}
    ;
markIF2: %empty {
    //gen(goto LSalidaIF)
    //gen(cond.EF)
    auto etqSalidaIF = intr.gen->newLabel();
    intr.gen->imprimir("goto " + etqSalidaIF);
    intr.gen->imprimir( $<atributos*>-5->EF + ":" );
    atributos* mark = new atributos();
    mark->LSalida = etqSalidaIF; 
    $$ = mark; 

}
    ; 
else: ELSE '{' lSentencias '}' else {}
    | ELSE if {}
    | %empty {}
    ; 

while: WHILE markWhile1 '(' cond ')' markWhile2 '{' lSentencias '}' { 
    intr.gen->imprimir($4->EF+":");
    intr.gen->popDisplay(); // pop display
 }
    ;
markWhile1: %empty {
    intr.gen->imprimir("// inicio while");
    atributos* etqInicio = new atributos();    
    etqInicio->LInicio = intr.gen->newLabel(); 
    intr.gen->imprimir(etqInicio->LInicio + ":");    
    $$ = etqInicio; 
}
    ;

markWhile2: %empty {
    atributos* cond = $<atributos*>-1;
    atributos* Linicio = $<atributos*>-3;    
    intr.gen->imprimir(cond->EV +":");
    intr.gen->pushDisplay( cond->EV, cond->EF, Linicio->LInicio);
    }
    ;

cond: cond OR markOR cond{ 
    atributos* cond = new atributos();
    cond->EV = $1->EV + ":\n" + $4->EV;
    cond->EF = $4->EF ;
    $$ = cond; 
    std::cout<<std::endl << "location:!!"
    << @2.begin.column << " " << @2
    <<" linea: " <<@2.begin.line << std::endl;


  }
| cond AND markAND cond {
    atributos* cond = new atributos();
    cond->EV = $4->EV ;
    cond->EF = $1->EF + ":\n" + $4->EF; 
    $$ = cond; 
 }
| operel { $$ = $1; }
;

markOR: %empty {
    intr.gen->imprimir( $<atributos*>-1->EF + ":" );
}
;
markAND: %empty {
    intr.gen->imprimir($<atributos*>-1->EV + ":");
}
;
    
operel: expr EQ expr {
    atributos* expr = new atributos();
    expr->EV = intr.gen->newLabel(); 
    expr->EF = intr.gen->newLabel(); 
    intr.gen->imprimir( "if " + $1->dir + " == " + $3->dir + " goto " + expr->EV );
    intr.gen->imprimir("goto " + expr->EF);
    $$ = expr; 
 }
| expr '<' expr{ 
    /* if expr1.dir < expr2.dir goto L#
        goto L#    
    */
    atributos* expr = new atributos();
    expr->EV = intr.gen->newLabel(); 
    expr->EF = intr.gen->newLabel(); 
    intr.gen->imprimir( "if " + $1->dir + " < " + $3->dir + " goto " + expr->EV );
    intr.gen->imprimir("goto " + expr->EF);
    $$ = expr; 
 }
; 

expr: expr SUMA expr {
        atributos* expr = new atributos();
        QString temp = intr.gen->newTempB($1->isTemp, $3->isTemp);
        intr.gen->imprimir(temp + " = " + $1->dir + " + " + $3->dir);
        expr->isTemp = true; 
        expr->dir = temp; 
        $$ = expr;
 }
    | expr MENOS expr { 
        atributos* expr = new atributos();
        QString temp = intr.gen->newTempB($1->isTemp, $3->isTemp);
        intr.gen->imprimir(temp + " = " + $1->dir + " - " + $3->dir);
        expr->isTemp = true; 
        expr->dir = temp; 
        $$ = expr;
    }
    | expr '*' expr {
        atributos* expr = new atributos();
        QString temp = intr.gen->newTempB($1->isTemp, $3->isTemp);
        intr.gen->imprimir(temp + " = " + $1->dir + " * " + $3->dir);
        expr->isTemp = true; 
        expr->dir = temp; 
        $$ = expr;

     }
    | expr '/' expr {
        atributos* expr = new atributos();
        QString temp = intr.gen->newTempB($1->isTemp, $3->isTemp);
        intr.gen->imprimir(temp + " = " + $1->dir + " / " + $3->dir);
        expr->isTemp = true; 
        expr->dir = temp; 
        $$ = expr;        
     }
    | NUMERO {
        atributos* expr = new atributos();
        expr->dir = QString::fromStdString($1);        
        $$ = expr; 
    }
    | ID { 
        atributos* expr = new atributos();
        expr->dir = QString::fromStdString($1);
        $$ = expr; 
    }
    | '(' expr ')' {
        $$ = $2; 
    }
    ;
%%
void yy::Parser::error(const yy::location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}

/*
suma(a,b)  
    return a + b / suma( a * b , 2 /c );

    if (a * suma(a,b))


Lsentencias -> if 
    | while 
    | assignacion

asignacion: mark id = expr   

E -> E  + E
    E .... E  temp = new Temp () // acumulador.push(newTemp)
    ID ( listaParametros) {
//LLAMADA
    <CODIGO DE PARAMETROS>
    acumulador.save() // codigo para guardar temporales en stack
    P = p + 1
    stack[p] = t1
    P = p + 1
    stack[p] = t2
    P = p + 1
    stack[p] = t3
    id()
    actulador.restore()// codigo para sacaar todo de stack 
    tN = stack[p] //return
    }


mark: {acumulador.reset() // quitar todos los temporales }

suma(a, b ) {
mark int a = suma(a,b) / resta(c,d) 
}
t1 = P + 1
t2 = stack[t1] //a 
t3 = P + 1
t4 = stack[t3] //b // acumulador = t1,t2,t3,t4

P = p + 1
stack[p] = t2
p = p + 1
stack[p] = t4

//acumulador.save
p = p + 1
stack[p] = t1
p = p + 1
stack[p] = t2
p = p + 1
stack[p] = t3
p = p + 1
stack[p] = t4
suma()
//acumulador.restore

t5 = P //return
t5 = stack [t5]
stack[p] = t4
p = p - 1
stack[p] = t2
p = p - 1
stack[p] = t2
p = p - 1
stack[p] = t1
p = p - 1
*/

