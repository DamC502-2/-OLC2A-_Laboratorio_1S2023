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

    // nodos No terminales
    #include "../AST/No_Terminales/nt_s.h"
    #include "../AST/No_Terminales/nt_lsentencias.h"
    #include "../AST/No_Terminales/nt_sentencia.h"
    #include "../AST/No_Terminales/nt_imprimir.h"
    #include "../AST/No_Terminales/nt_listaexpr.h"
    #include "../AST/No_Terminales/nt_bloque.h"
    #include "../AST/No_Terminales/nt_declvar.h"
    #include "../AST/No_Terminales/nt_asigvar.h"
    #include "../AST/No_Terminales/Expresiones/nt_suma.h"
    #include "../AST/No_Terminales/Expresiones/nt_negacion.h"
    #include "../AST/No_Terminales/Expresiones/nt_id.h"
    #include "../AST/No_Terminales/nt_tipo.h"
    
    // nodos terminales
    #include "../AST/Terminales/t_numero.h"
    #include "../AST/Terminales/t_id.h"
    #include "../AST/Terminales/t_string.h"

    //Interfaz
    #include "interfaz.h"


    /*
    Se pueden definir estructuras y tipos para los no terminales
    */

}
/* enlace con la función del retorno de simbolos */
%code
{
yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class Clase3::Interfaz & intr);
}


%token END 0;  //token de salida

/// %token<tipo> nombre+
//cuidado con el orden
// %token <std::string> ID NUMERO
%token <std::string>  NUMERO ID STRING INT STR FLO
// token de tipo por defecto
    //token por ID
%token SUMA MENOS DIM AS IMPR ; 
    //token por texto
%token ';' '*' '/' '(' ')' '=' '{' '}' ; 
// negación unaria
%token NEG

/*
forma alterna
%token SUMA '+'
%token ID 'un_id'


*/
// precedencia menor a mayor
%left NUMERO
%left SUMA MENOS //menos -
%left '*' '/' //más
%left NEG

/* fin de la definción de tipos*/

/* La clase que envuele al parser se pasa por referencia
del parser al escaner evitando crear variables globales

*/

%lex-param {void *scanner} {yy::location& loc} { class Clase3::Interfaz & intr }
%parse-param {void *scanner} {yy::location& loc} { class Clase3::Interfaz & intr }

/* es posible hacer tipos personalizados para definir no terminales añadiendo lo siguiente

%union {
    std::string;
    double;
    AbstractExp*;
}*/

/*definicion de no terminales*/


%type<AbstractExp*>  s declaracion_var;
%type<NT_LSentencias*> lSentencia ;
%type<AbstractExp*> sentencia asignacion_var;
%type<AbstractExp*> expr tipo;
%type<AbstractExp*> bloque;
%type<NT_Imprimir*> imprimir;
%type<NT_ListaExpr*> lista_Expr;


// printer
%printer { yyoutput << $$; } <*>;

/*
inicio de la grámatica
*/
%%
/* produccion inicial */
%start s; 

s: lSentencia  { 
    intr.raiz = new NT_S($1);
    $$ = intr.raiz; 
    }
;
    

lSentencia: lSentencia sentencia z {
                                    $$ = $1; 
                                    $$->AddSentencia($2);
                                    }
    | sentencia z { 
        $$ = new NT_LSentencias();
        $$->AddSentencia($1);
    }
    ;
    /*sentencias*/
sentencia: declaracion_var {$$ = $1;}
    | asignacion_var {$$ = $1; }
    | imprimir {$$ = $1; }
    | bloque {$$ = $1;}
    ;


lista_Expr: lista_Expr ','  expr {   $1->AddNodo($3); 
                                    $$ = $1;
                                }
    | expr { $$ = new NT_ListaExpr($1);}
    ;

imprimir: IMPR '(' lista_Expr ')' { $$ = new NT_Imprimir($3); }
    ;

bloque: '{' lSentencia '}' { $$ = new NT_Bloque($2); }

z: ';' {  }
    | %empty { }
    ;


declaracion_var: DIM ID AS tipo {   T_ID* id = new T_ID(QString::fromStdString($2));
                                    $$ = new NT_DeclVar($4, id); }
    | DIM ID AS tipo '=' expr { T_ID* id = new T_ID(QString::fromStdString($2));
                                $$ = new NT_DeclVar($4, id,$6 );  }
    ;

asignacion_var: ID '=' expr {   T_ID* id_avar = new T_ID(QString::fromStdString($1));
                                $$ = new NT_AsigVar(id_avar, $3);
                                }
    ;


    
expr: expr SUMA expr   { $$ = new NT_Suma($1, $3);  }
    | expr MENOS expr { $$ = $1;  
                        /*pendiente de implementar*/}
    | '(' expr ')' { $$ = $2; }
    | MENOS expr %prec NEG  { $$ = new NT_Negacion($2);  }
    | NUMERO { $$ = new T_Numero( QString::fromStdString($1)); } 
    | ID { $$ = new NT_ID( QString::fromStdString($1)); }
    | STRING { $$ = new T_String( QString::fromStdString($1));  }
    ;

tipo:  INT { $$ = new NT_Tipo( QString::fromStdString($1)); }
    | STR { $$ = new NT_Tipo( QString::fromStdString($1)); }
    | FLO { $$ = new NT_Tipo( QString::fromStdString($1)); }
    ;

%%
void yy::Parser::error(const yy::location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}

