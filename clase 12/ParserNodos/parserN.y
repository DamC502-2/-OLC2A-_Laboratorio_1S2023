/*comando   bison --verbose -o parser.cpp  parserN.y */

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
%define api.prefix{yyN}

/* indica la clase que envuelve al parser */
%define api.parser.class {ParserN}

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
    #include "interfazN.h"

    //Nodos
    #include "ParserNodos/AST/NoTerminal/NT_S.h"
    #include "ParserNodos/AST/NoTerminal/NT_LSentencias.h"
    #include "ParserNodos/AST/NoTerminal/NT_While.h"
    #include "ParserNodos/AST/NoTerminal/NT_If.h"
    #include "ParserNodos/AST/NoTerminal/NT_else.h"
    #include "ParserNodos/AST/NoTerminal/NT_Continue.h"
    #include "ParserNodos/AST/NoTerminal/NT_Break.h"

    #include "ParserNodos/AST/NoTerminal/Expr/NT_And.h"
    #include "ParserNodos/AST/NoTerminal/Expr/NT_Div.h"
    #include "ParserNodos/AST/NoTerminal/Expr/NT_Multi.h"
    #include "ParserNodos/AST/NoTerminal/Expr/NT_Operel.h"
    #include "ParserNodos/AST/NoTerminal/Expr/NT_Or.h"
    #include "ParserNodos/AST/NoTerminal/Expr/NT_Resta.h"
    #include "ParserNodos/AST/NoTerminal/Expr/NT_Sum.h"

    #include "ParserNodos/AST/Terminal/Expr/T_ID_e.h"
    #include "ParserNodos/AST/Terminal/Expr/T_Num_e.h"

    #include "ParserNodos/AST/NoTerminal/NT_Funcion.h"
    #include "ParserNodos/AST/NoTerminal/NT_LParams.h"
    #include "ParserNodos/AST/NoTerminal/NT_Asig.h"
    #include "ParserNodos/AST/NoTerminal/NT_Decla.h"    
    #include "ParserNodos/AST/NoTerminal/NT_Return.h"
    #include "ParserNodos/AST/NoTerminal/NT_LLamada.h"
    #include "ParserNodos/AST/NoTerminal/NT_LExprLLamada.h"

    /*
    Se pueden definir estructuras y tipos para los no terminales
    */

}
/* enlace con la función del retorno de simbolos */
%code
{
yyN::ParserN::symbol_type yylex(void* yyscanner, yyN::location& loc, class Compilador::Interfaz & intr);
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
// palabras para funciones
%token  PRINT AS FUNCTION DIM RETURN
%token <std::string> INT VOID BYREF BYVAL
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

%lex-param {void *scanner} {yyN::location& loc} { class Compilador::Interfaz & intr }
%parse-param {void *scanner} {yyN::location& loc} { class Compilador::Interfaz & intr }

/* es posible hacer tipos personalizados para definir no terminales añadiendo lo siguiente

%union {
    std::string;
    double;
    AbstractExp*;
}*/

/*definicion de no terminales*/
%type<AbsExpr*> s 
%type<AbsExpr*> cond
%type<AbsExpr*> expr operel
%type<NT_LSentencias*> lSentencias lSentenciasG
%type<AbsExpr*> sentencia if while else
//funciones
%type<AbsExpr*> funcion  declaracion_var asignacion 
%type<NT_LExprLLamada*> lExprLlamada
%type<NT_LParams*> lParams
%type<std::string>  tipoFuncion

// printer
%printer { yyoutput << $$; } <*>;



%%

%start s; 

s: cond { //se añade la raiz a la interfaz
        intr.raiz = new NT_S($1);                 
        $$ = $1;
      
 }
 | lSentenciasG { //se añade la raiz a la interfaz
    intr.raiz = new NT_S($1); 
    $$ = nullptr; }
 ;

lSentenciasG: lSentenciasG funcion { $1->addNodo($2);
                                    $$ = $1; }
    | funcion { auto lSentencias = new NT_LSentencias();
                    lSentencias->addNodo($1);
                    $$ = lSentencias;
               }
    ; 
; 
lSentencias: lSentencias sentencia { $1->addNodo($2);
                                    $$ = $1; }
    | sentencia { auto lSentencias = new NT_LSentencias();
                    lSentencias->addNodo($1);
                    $$ = lSentencias;
                    }
    ; 

sentencia: if {  $$ = $1; } 
    | while { $$ = $1; }    
    | BREAK { // sentenica break
        // TODO: verificar la existencia de la etiqueta
        $$ = new NT_Continue();
    }
    | CONTINUE { // sentencia continue 
        // TODO: verificar la existencia de la etiqueta
        $$ = new NT_Break();
        
    }
    | asignacion ';' { $$ = $1; }     
    | declaracion_var ';' { $$ = $1;}
    | RETURN  ';' { new NT_Return(nullptr); }
    | RETURN expr  ';' { $$ = new NT_Return($2); }
    | ID '(' lExprLlamada ')' ';' { $$ = new  NT_LLamada($1, $3); }
    | ID '(' ')' ';'  {$$ =  new NT_LLamada($1, nullptr); }
    ; 

funcion: FUNCTION ID '(' lParams ')' tipoFuncion  '{' lSentencias '}'  {
    // NT_Funcion( id, tipo_retorno, parametros, sentencias )
    $$ = new NT_Funcion( $2, $6, $4, $8 );
}
| FUNCTION ID '(' ')' tipoFuncion  '{' lSentencias '}' {
    $$ = new NT_Funcion( $2, $5, nullptr , $7 );
}
; 

lParams: lParams ',' BYVAL ID AS INT { $1->addParam($4, $6, $3);
                                        $$ = $1;  }
    | lParams ',' BYREF ID AS INT { $1->addParam($4, $6, $3);
                                    $$ = $1;  }
    | BYREF ID AS INT { auto params = new NT_LParams();
                        params->addParam($2, $4, $1);
                        $$ = params;
                        }
    | BYVAL ID AS INT { auto params = new NT_LParams();
                        params->addParam($2, $4, $1);
                        $$ = params;
                        }
    ;

tipoFuncion: AS INT  { $$ = $2;  }
    | AS VOID { $$ = $2; }
;

declaracion_var: DIM ID AS INT {
    $$ = new NT_Decla( $2, $4 ); 
}
; 

asignacion: ID '=' expr {
    $$ = new NT_Asig($1, $3);
}
; 



if: IF '(' cond ')' '{' lSentencias '}' else {
    $$ = new NT_If($3, $6, $8);
    }
    ;

else: ELSE '{' lSentencias '}' else { $$ = new NT_else($3, $5); }
    | ELSE if {  $$ = new NT_else($2);  }
    | %empty {  $$ = nullptr; }
    ; 

while: WHILE '(' cond ')' '{' lSentencias '}' { 
    $$ = new NT_While( $3, $6);
 }
    ;

cond: cond OR cond{     
    $$ = new NT_Or($1, $3);
  }
| cond AND  cond {
    $$ = new NT_And($1, $3);    
 }
| operel { $$ = $1; }
;

    
operel: expr EQ expr {
    $$ = new NT_Operel($1, $3, QString("=="));

 }
| expr '<' expr{ 
    $$ = new NT_Operel($1, $3, QString("<"));
    
 }
; 

expr: expr SUMA expr {
    $$ = new NT_Sum($1,$3);
 }
    | expr MENOS expr { 
        $$ = new NT_Resta($1,$3);
    }
    | expr '*' expr {
        $$ = new NT_Multi($1,$3);

     }
    | expr '/' expr {
        $$ = new NT_Div($1,$3);
     }
    | NUMERO {
        $$ = new T_Num_e(QString::fromStdString($1));
    }
    | ID { 
        $$ = new T_ID_e(QString::fromStdString($1));
    }
    | '(' expr ')' {
        $$ = $2;     
    }
    | ID '('  ')'  {
        $$ = new NT_LLamada( $1, nullptr ); 
     }
    | ID '(' lExprLlamada ')'  {
        $$ = new NT_LLamada( $1, $3 ); 
     }
    ;

lExprLlamada: lExprLlamada ',' expr { $1->addExpr($3);
                                        $$ = $1; }
     | expr { $$ = new NT_LExprLLamada(); 
                $$->addExpr($1); }
     ;
%%
void yyN::ParserN::error(const yyN::location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}

/*
nodos 
if 
*/