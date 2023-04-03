// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 56 "parser.y"

yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class Clase6::Interfaz & intr);

#line 50 "parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 142 "parser.cpp"

  /// Build a parser object.
  Parser::Parser (void *scanner_yyarg, yy::location& loc_yyarg, class Clase6::Interfaz & intr_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      loc (loc_yyarg),
      intr (intr_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_s: // s
      case symbol_kind::S_markIF2: // markIF2
      case symbol_kind::S_markWhile1: // markWhile1
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
        value.YY_MOVE_OR_COPY< atributos* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_s: // s
      case symbol_kind::S_markIF2: // markIF2
      case symbol_kind::S_markWhile1: // markWhile1
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
        value.move< atributos* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_s: // s
      case symbol_kind::S_markIF2: // markIF2
      case symbol_kind::S_markWhile1: // markWhile1
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
        value.copy< atributos* > (that.value);
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_s: // s
      case symbol_kind::S_markIF2: // markIF2
      case symbol_kind::S_markWhile1: // markWhile1
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
        value.move< atributos* > (that.value);
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_NUMERO: // NUMERO
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 355 "parser.cpp"
        break;

      case symbol_kind::S_ID: // ID
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 361 "parser.cpp"
        break;

      case symbol_kind::S_STRING: // STRING
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 367 "parser.cpp"
        break;

      case symbol_kind::S_s: // s
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < atributos* > (); }
#line 373 "parser.cpp"
        break;

      case symbol_kind::S_markIF2: // markIF2
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < atributos* > (); }
#line 379 "parser.cpp"
        break;

      case symbol_kind::S_markWhile1: // markWhile1
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < atributos* > (); }
#line 385 "parser.cpp"
        break;

      case symbol_kind::S_cond: // cond
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < atributos* > (); }
#line 391 "parser.cpp"
        break;

      case symbol_kind::S_operel: // operel
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < atributos* > (); }
#line 397 "parser.cpp"
        break;

      case symbol_kind::S_expr: // expr
#line 117 "parser.y"
                 { yyoutput << yysym.value.template as < atributos* > (); }
#line 403 "parser.cpp"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, loc, intr));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_s: // s
      case symbol_kind::S_markIF2: // markIF2
      case symbol_kind::S_markWhile1: // markWhile1
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
        yylhs.value.emplace< atributos* > ();
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // s: cond
#line 123 "parser.y"
        {
        yylhs.value.as < atributos* > () = yystack_[0].value.as < atributos* > (); 
        intr.gen->imprimir(QString::fromStdString("// verdadero"));
        intr.gen->imprimir(yystack_[0].value.as < atributos* > ()->EV + ":");
        intr.gen->imprimir(QString::fromStdString("// falso"));
        intr.gen->imprimir(yystack_[0].value.as < atributos* > ()->EF + ":");
 }
#line 677 "parser.cpp"
    break;

  case 3: // s: lSentencias
#line 130 "parser.y"
               {}
#line 683 "parser.cpp"
    break;

  case 4: // lSentencias: lSentencias sentencia
#line 133 "parser.y"
                                   { }
#line 689 "parser.cpp"
    break;

  case 5: // lSentencias: sentencia
#line 134 "parser.y"
                {}
#line 695 "parser.cpp"
    break;

  case 6: // sentencia: if
#line 137 "parser.y"
              { }
#line 701 "parser.cpp"
    break;

  case 7: // sentencia: while
#line 138 "parser.y"
            { }
#line 707 "parser.cpp"
    break;

  case 8: // sentencia: BREAK
#line 139 "parser.y"
            { // sentenica break
        // TODO: verificar la existencia de la etiqueta
        intr.gen->imprimir( QString( "goto ")+ intr.gen->peekEtqF() + " //break");
    }
#line 716 "parser.cpp"
    break;

  case 9: // sentencia: CONTINUE
#line 143 "parser.y"
               { // sentencia continue 
        // TODO: verificar la existencia de la etiqueta
        intr.gen->imprimir( QString( "goto ")+ intr.gen->peekEtqInicio() + " //continue");
    }
#line 725 "parser.cpp"
    break;

  case 10: // if: IF '(' cond ')' markIF '{' lSentencias '}' markIF2 else
#line 149 "parser.y"
                                                              {
                                                //gen(LSalidaIF)
                                        intr.gen->imprimir(yystack_[1].value.as < atributos* > ()->LSalida + ":") ;}
#line 733 "parser.cpp"
    break;

  case 11: // markIF: %empty
#line 154 "parser.y"
               { 
        // codigo marcador        
        //gen (cond.EV)        
        intr.gen->imprimir(yystack_[(0) - (-1)].value.as< atributos* > ()->EV + ":");
}
#line 743 "parser.cpp"
    break;

  case 12: // markIF2: %empty
#line 160 "parser.y"
                {
    //gen(goto LSalidaIF)
    //gen(cond.EF)
    auto etqSalidaIF = intr.gen->newLabel();
    intr.gen->imprimir("goto " + etqSalidaIF);
    intr.gen->imprimir( yystack_[(0) - (-5)].value.as< atributos* > ()->EF + ":" );
    atributos* mark = new atributos();
    mark->LSalida = etqSalidaIF; 
    yylhs.value.as < atributos* > () = mark; 

}
#line 759 "parser.cpp"
    break;

  case 13: // else: ELSE '{' lSentencias '}' else
#line 172 "parser.y"
                                    {}
#line 765 "parser.cpp"
    break;

  case 14: // else: ELSE if
#line 173 "parser.y"
              {}
#line 771 "parser.cpp"
    break;

  case 15: // else: %empty
#line 174 "parser.y"
             {}
#line 777 "parser.cpp"
    break;

  case 16: // while: WHILE markWhile1 '(' cond ')' markWhile2 '{' lSentencias '}'
#line 177 "parser.y"
                                                                    { 
    intr.gen->imprimir(yystack_[5].value.as < atributos* > ()->EF+":");
    intr.gen->popDisplay(); // pop display
 }
#line 786 "parser.cpp"
    break;

  case 17: // markWhile1: %empty
#line 182 "parser.y"
                   {
    intr.gen->imprimir("// inicio while");
    atributos* etqInicio = new atributos();    
    etqInicio->LInicio = intr.gen->newLabel(); 
    intr.gen->imprimir(etqInicio->LInicio + ":");    
    yylhs.value.as < atributos* > () = etqInicio; 
}
#line 798 "parser.cpp"
    break;

  case 18: // markWhile2: %empty
#line 191 "parser.y"
                   {
    atributos* cond = yystack_[(0) - (-1)].value.as< atributos* > ();
    atributos* Linicio = yystack_[(0) - (-3)].value.as< atributos* > ();    
    intr.gen->imprimir(cond->EV +":");
    intr.gen->pushDisplay( cond->EV, cond->EF, Linicio->LInicio);
    }
#line 809 "parser.cpp"
    break;

  case 19: // cond: cond OR markOR cond
#line 199 "parser.y"
                         { 
    atributos* cond = new atributos();
    cond->EV = yystack_[3].value.as < atributos* > ()->EV + ":\n" + yystack_[0].value.as < atributos* > ()->EV;
    cond->EF = yystack_[0].value.as < atributos* > ()->EF ;
    yylhs.value.as < atributos* > () = cond; 
    std::cout<<std::endl << "location:!!"
    << yystack_[2].location.begin.column << " " << yystack_[2].location
    <<" linea: " <<yystack_[2].location.begin.line << std::endl;


  }
#line 825 "parser.cpp"
    break;

  case 20: // cond: cond AND markAND cond
#line 210 "parser.y"
                        {
    atributos* cond = new atributos();
    cond->EV = yystack_[0].value.as < atributos* > ()->EV ;
    cond->EF = yystack_[3].value.as < atributos* > ()->EF + ":\n" + yystack_[0].value.as < atributos* > ()->EF; 
    yylhs.value.as < atributos* > () = cond; 
 }
#line 836 "parser.cpp"
    break;

  case 21: // cond: operel
#line 216 "parser.y"
         { yylhs.value.as < atributos* > () = yystack_[0].value.as < atributos* > (); }
#line 842 "parser.cpp"
    break;

  case 22: // markOR: %empty
#line 219 "parser.y"
               {
    intr.gen->imprimir( yystack_[(0) - (-1)].value.as< atributos* > ()->EF + ":" );
}
#line 850 "parser.cpp"
    break;

  case 23: // markAND: %empty
#line 223 "parser.y"
                {
    intr.gen->imprimir(yystack_[(0) - (-1)].value.as< atributos* > ()->EV + ":");
}
#line 858 "parser.cpp"
    break;

  case 24: // operel: expr EQ expr
#line 228 "parser.y"
                     {
    atributos* expr = new atributos();
    expr->EV = intr.gen->newLabel(); 
    expr->EF = intr.gen->newLabel(); 
    intr.gen->imprimir( "if " + yystack_[2].value.as < atributos* > ()->dir + " == " + yystack_[0].value.as < atributos* > ()->dir + " goto " + expr->EV );
    intr.gen->imprimir("goto " + expr->EF);
    yylhs.value.as < atributos* > () = expr; 
 }
#line 871 "parser.cpp"
    break;

  case 25: // operel: expr '<' expr
#line 236 "parser.y"
               { 
    /* if expr1.dir < expr2.dir goto L#
        goto L#    
    */
    atributos* expr = new atributos();
    expr->EV = intr.gen->newLabel(); 
    expr->EF = intr.gen->newLabel(); 
    intr.gen->imprimir( "if " + yystack_[2].value.as < atributos* > ()->dir + " < " + yystack_[0].value.as < atributos* > ()->dir + " goto " + expr->EV );
    intr.gen->imprimir("goto " + expr->EF);
    yylhs.value.as < atributos* > () = expr; 
 }
#line 887 "parser.cpp"
    break;

  case 26: // expr: expr SUMA expr
#line 249 "parser.y"
                     {
        atributos* expr = new atributos();
        QString temp = intr.gen->newTempB(yystack_[2].value.as < atributos* > ()->isTemp, yystack_[0].value.as < atributos* > ()->isTemp);
        intr.gen->imprimir(temp + " = " + yystack_[2].value.as < atributos* > ()->dir + " + " + yystack_[0].value.as < atributos* > ()->dir);
        expr->isTemp = true; 
        expr->dir = temp; 
        yylhs.value.as < atributos* > () = expr;
 }
#line 900 "parser.cpp"
    break;

  case 27: // expr: expr MENOS expr
#line 257 "parser.y"
                      { 
        atributos* expr = new atributos();
        QString temp = intr.gen->newTempB(yystack_[2].value.as < atributos* > ()->isTemp, yystack_[0].value.as < atributos* > ()->isTemp);
        intr.gen->imprimir(temp + " = " + yystack_[2].value.as < atributos* > ()->dir + " - " + yystack_[0].value.as < atributos* > ()->dir);
        expr->isTemp = true; 
        expr->dir = temp; 
        yylhs.value.as < atributos* > () = expr;
    }
#line 913 "parser.cpp"
    break;

  case 28: // expr: expr '*' expr
#line 265 "parser.y"
                    {
        atributos* expr = new atributos();
        QString temp = intr.gen->newTempB(yystack_[2].value.as < atributos* > ()->isTemp, yystack_[0].value.as < atributos* > ()->isTemp);
        intr.gen->imprimir(temp + " = " + yystack_[2].value.as < atributos* > ()->dir + " * " + yystack_[0].value.as < atributos* > ()->dir);
        expr->isTemp = true; 
        expr->dir = temp; 
        yylhs.value.as < atributos* > () = expr;

     }
#line 927 "parser.cpp"
    break;

  case 29: // expr: expr '/' expr
#line 274 "parser.y"
                    {
        atributos* expr = new atributos();
        QString temp = intr.gen->newTempB(yystack_[2].value.as < atributos* > ()->isTemp, yystack_[0].value.as < atributos* > ()->isTemp);
        intr.gen->imprimir(temp + " = " + yystack_[2].value.as < atributos* > ()->dir + " / " + yystack_[0].value.as < atributos* > ()->dir);
        expr->isTemp = true; 
        expr->dir = temp; 
        yylhs.value.as < atributos* > () = expr;        
     }
#line 940 "parser.cpp"
    break;

  case 30: // expr: NUMERO
#line 282 "parser.y"
             {
        atributos* expr = new atributos();
        expr->dir = QString::fromStdString(yystack_[0].value.as < std::string > ());        
        yylhs.value.as < atributos* > () = expr; 
    }
#line 950 "parser.cpp"
    break;

  case 31: // expr: ID
#line 287 "parser.y"
         { 
        atributos* expr = new atributos();
        expr->dir = QString::fromStdString(yystack_[0].value.as < std::string > ());
        yylhs.value.as < atributos* > () = expr; 
    }
#line 960 "parser.cpp"
    break;

  case 32: // expr: '(' expr ')'
#line 292 "parser.y"
                   {
        yylhs.value.as < atributos* > () = yystack_[1].value.as < atributos* > (); 
    }
#line 968 "parser.cpp"
    break;


#line 972 "parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -37;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
      11,   -37,   -37,     3,    -7,   -37,   -37,   -37,    28,    64,
     -37,   -37,   -37,    38,   -37,    49,    37,     3,    18,   -37,
     -37,   -37,   -37,     3,     3,     3,     3,     3,     3,   -37,
      21,     3,     3,     3,    43,    43,    -3,    -3,   -37,   -37,
     -37,    23,    32,   -37,    26,   -37,    64,    29,    45,    64,
     -37,    52,    27,   -37,   -14,   -37,    64,   -37,    59,    27,
     -37
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    30,    31,     0,     0,    17,     8,     9,     0,     3,
       5,     6,     7,     2,    21,     0,     0,     0,     0,     1,
       4,    22,    23,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,     0,    26,    27,    24,    25,    28,    29,
      11,     0,    19,    20,     0,    18,     0,     0,     0,     0,
      12,     0,    15,    16,     0,    10,     0,    14,     0,    15,
      13
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -37,   -37,   -36,    -9,    -1,   -37,   -37,     2,   -37,   -37,
     -37,   -15,   -37,   -37,   -37,    -2
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     8,     9,    10,    11,    44,    52,    55,    12,    18,
      47,    13,    32,    33,    14,    15
  };

  const signed char
  Parser::yytable_[] =
  {
      20,    16,    30,    23,    24,    56,     1,     2,     4,    17,
      48,    27,    28,    51,     1,     2,    41,    42,    43,     3,
      58,    34,    35,    36,    37,    38,    39,     3,    19,    21,
      22,    21,    22,     4,    31,     5,     6,     7,    40,    20,
      45,    22,    20,    23,    24,    46,    21,    22,    49,    20,
      54,    27,    28,    57,    29,    23,    24,    27,    28,    25,
      26,    60,     0,    27,    28,    50,     0,     4,     0,     5,
       6,     7,    53,     0,     4,     0,     5,     6,     7,    59,
       0,     4,     0,     5,     6,     7,     4,     0,     5,     6,
       7
  };

  const signed char
  Parser::yycheck_[] =
  {
       9,     3,    17,     6,     7,    19,     3,     4,    22,    16,
      46,    14,    15,    49,     3,     4,    31,    32,    33,    16,
      56,    23,    24,    25,    26,    27,    28,    16,     0,     8,
       9,     8,     9,    22,    16,    24,    25,    26,    17,    48,
      17,     9,    51,     6,     7,    19,     8,     9,    19,    58,
      23,    14,    15,    54,    17,     6,     7,    14,    15,    10,
      11,    59,    -1,    14,    15,    20,    -1,    22,    -1,    24,
      25,    26,    20,    -1,    22,    -1,    24,    25,    26,    20,
      -1,    22,    -1,    24,    25,    26,    22,    -1,    24,    25,
      26
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     3,     4,    16,    22,    24,    25,    26,    28,    29,
      30,    31,    35,    38,    41,    42,    42,    16,    36,     0,
      30,     8,     9,     6,     7,    10,    11,    14,    15,    17,
      38,    16,    39,    40,    42,    42,    42,    42,    42,    42,
      17,    38,    38,    38,    32,    17,    19,    37,    29,    19,
      20,    29,    33,    20,    23,    34,    19,    31,    29,    20,
      34
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    27,    28,    28,    29,    29,    30,    30,    30,    30,
      31,    32,    33,    34,    34,    34,    35,    36,    37,    38,
      38,    38,    39,    40,    41,    41,    42,    42,    42,    42,
      42,    42,    42
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
      10,     0,     0,     5,     2,     0,     9,     0,     0,     4,
       4,     1,     0,     0,     3,     3,     3,     3,     3,     3,
       1,     1,     3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "END", "error", "\"invalid token\"", "NUMERO", "ID", "STRING", "SUMA",
  "MENOS", "OR", "AND", "EQ", "'<'", "'>'", "';'", "'*'", "'/'", "'('",
  "')'", "'='", "'{'", "'}'", "NEG", "IF", "ELSE", "WHILE", "BREAK",
  "CONTINUE", "$accept", "s", "lSentencias", "sentencia", "if", "markIF",
  "markIF2", "else", "while", "markWhile1", "markWhile2", "cond", "markOR",
  "markAND", "operel", "expr", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   123,   123,   130,   133,   134,   137,   138,   139,   143,
     149,   154,   160,   172,   173,   174,   177,   182,   191,   199,
     210,   216,   219,   223,   228,   236,   249,   257,   265,   274,
     282,   287,   292
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1482 "parser.cpp"

#line 296 "parser.y"

void yy::Parser::error(const yy::location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}

/*
nodos 
if 
*/
