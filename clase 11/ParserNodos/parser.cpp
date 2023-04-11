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


// Take the name prefix into account.
#define yylex   yyNlex



#include "parser.hpp"


// Unqualified %code blocks.
#line 76 "parser.y"

yyN::ParserN::symbol_type yylex(void* yyscanner, yyN::location& loc, class Compilador::Interfaz & intr);

#line 52 "parser.cpp"


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
#if YYNDEBUG

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

#else // !YYNDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYNDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yyN {
#line 144 "parser.cpp"

  /// Build a parser object.
  ParserN::ParserN (void *scanner_yyarg, yyN::location& loc_yyarg, class Compilador::Interfaz & intr_yyarg)
#if YYNDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      loc (loc_yyarg),
      intr (intr_yyarg)
  {}

  ParserN::~ParserN ()
  {}

  ParserN::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  ParserN::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  ParserN::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  ParserN::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  ParserN::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  ParserN::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  ParserN::symbol_kind_type
  ParserN::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  ParserN::stack_symbol_type::stack_symbol_type ()
  {}

  ParserN::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_s: // s
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_if: // if
      case symbol_kind::S_else: // else
      case symbol_kind::S_while: // while
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
        value.YY_MOVE_OR_COPY< AbsExpr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lSentencias: // lSentencias
        value.YY_MOVE_OR_COPY< NT_LSentencias* > (YY_MOVE (that.value));
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

  ParserN::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_s: // s
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_if: // if
      case symbol_kind::S_else: // else
      case symbol_kind::S_while: // while
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
        value.move< AbsExpr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lSentencias: // lSentencias
        value.move< NT_LSentencias* > (YY_MOVE (that.value));
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
  ParserN::stack_symbol_type&
  ParserN::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_s: // s
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_if: // if
      case symbol_kind::S_else: // else
      case symbol_kind::S_while: // while
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
        value.copy< AbsExpr* > (that.value);
        break;

      case symbol_kind::S_lSentencias: // lSentencias
        value.copy< NT_LSentencias* > (that.value);
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

  ParserN::stack_symbol_type&
  ParserN::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_s: // s
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_if: // if
      case symbol_kind::S_else: // else
      case symbol_kind::S_while: // while
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
        value.move< AbsExpr* > (that.value);
        break;

      case symbol_kind::S_lSentencias: // lSentencias
        value.move< NT_LSentencias* > (that.value);
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
  ParserN::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYNDEBUG
  template <typename Base>
  void
  ParserN::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
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
#line 138 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 381 "parser.cpp"
        break;

      case symbol_kind::S_ID: // ID
#line 138 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 387 "parser.cpp"
        break;

      case symbol_kind::S_STRING: // STRING
#line 138 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 393 "parser.cpp"
        break;

      case symbol_kind::S_s: // s
#line 138 "parser.y"
                 { yyoutput << yysym.value.template as < AbsExpr* > (); }
#line 399 "parser.cpp"
        break;

      case symbol_kind::S_lSentencias: // lSentencias
#line 138 "parser.y"
                 { yyoutput << yysym.value.template as < NT_LSentencias* > (); }
#line 405 "parser.cpp"
        break;

      case symbol_kind::S_sentencia: // sentencia
#line 138 "parser.y"
                 { yyoutput << yysym.value.template as < AbsExpr* > (); }
#line 411 "parser.cpp"
        break;

      case symbol_kind::S_if: // if
#line 138 "parser.y"
                 { yyoutput << yysym.value.template as < AbsExpr* > (); }
#line 417 "parser.cpp"
        break;

      case symbol_kind::S_else: // else
#line 138 "parser.y"
                 { yyoutput << yysym.value.template as < AbsExpr* > (); }
#line 423 "parser.cpp"
        break;

      case symbol_kind::S_while: // while
#line 138 "parser.y"
                 { yyoutput << yysym.value.template as < AbsExpr* > (); }
#line 429 "parser.cpp"
        break;

      case symbol_kind::S_cond: // cond
#line 138 "parser.y"
                 { yyoutput << yysym.value.template as < AbsExpr* > (); }
#line 435 "parser.cpp"
        break;

      case symbol_kind::S_operel: // operel
#line 138 "parser.y"
                 { yyoutput << yysym.value.template as < AbsExpr* > (); }
#line 441 "parser.cpp"
        break;

      case symbol_kind::S_expr: // expr
#line 138 "parser.y"
                 { yyoutput << yysym.value.template as < AbsExpr* > (); }
#line 447 "parser.cpp"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  ParserN::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  ParserN::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  ParserN::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYNDEBUG
  std::ostream&
  ParserN::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  ParserN::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  ParserN::debug_level_type
  ParserN::debug_level () const
  {
    return yydebug_;
  }

  void
  ParserN::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYNDEBUG

  ParserN::state_type
  ParserN::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  ParserN::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  ParserN::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  ParserN::operator() ()
  {
    return parse ();
  }

  int
  ParserN::parse ()
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
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_if: // if
      case symbol_kind::S_else: // else
      case symbol_kind::S_while: // while
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
        yylhs.value.emplace< AbsExpr* > ();
        break;

      case symbol_kind::S_lSentencias: // lSentencias
        yylhs.value.emplace< NT_LSentencias* > ();
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
#line 146 "parser.y"
        { //se añade la raiz a la interfaz
        intr.raiz = new NT_S(yystack_[0].value.as < AbsExpr* > ());                 
        yylhs.value.as < AbsExpr* > () = yystack_[0].value.as < AbsExpr* > ();
      
 }
#line 725 "parser.cpp"
    break;

  case 3: // s: lSentencias
#line 151 "parser.y"
               { //se añade la raiz a la interfaz
    intr.raiz = new NT_S(yystack_[0].value.as < NT_LSentencias* > ()); 
    yylhs.value.as < AbsExpr* > () = nullptr; }
#line 733 "parser.cpp"
    break;

  case 4: // lSentencias: lSentencias sentencia
#line 156 "parser.y"
                                   { yystack_[1].value.as < NT_LSentencias* > ()->addNodo(yystack_[0].value.as < AbsExpr* > ());
                                    yylhs.value.as < NT_LSentencias* > () = yystack_[1].value.as < NT_LSentencias* > (); }
#line 740 "parser.cpp"
    break;

  case 5: // lSentencias: sentencia
#line 158 "parser.y"
                { auto lSentencias = new NT_LSentencias();
                    lSentencias->addNodo(yystack_[0].value.as < AbsExpr* > ());
                    yylhs.value.as < NT_LSentencias* > () = lSentencias;
                    }
#line 749 "parser.cpp"
    break;

  case 6: // sentencia: if
#line 164 "parser.y"
              {  yylhs.value.as < AbsExpr* > () = yystack_[0].value.as < AbsExpr* > (); }
#line 755 "parser.cpp"
    break;

  case 7: // sentencia: while
#line 165 "parser.y"
            { yylhs.value.as < AbsExpr* > () = yystack_[0].value.as < AbsExpr* > (); }
#line 761 "parser.cpp"
    break;

  case 8: // sentencia: BREAK
#line 166 "parser.y"
            { // sentenica break
        // TODO: verificar la existencia de la etiqueta
        yylhs.value.as < AbsExpr* > () = new NT_Continue();
    }
#line 770 "parser.cpp"
    break;

  case 9: // sentencia: CONTINUE
#line 170 "parser.y"
               { // sentencia continue 
        // TODO: verificar la existencia de la etiqueta
        yylhs.value.as < AbsExpr* > () = new NT_Break();
        
    }
#line 780 "parser.cpp"
    break;

  case 10: // if: IF '(' cond ')' '{' lSentencias '}' else
#line 177 "parser.y"
                                             {
    yylhs.value.as < AbsExpr* > () = new NT_If(yystack_[5].value.as < AbsExpr* > (), yystack_[2].value.as < NT_LSentencias* > (), yystack_[0].value.as < AbsExpr* > ());
    }
#line 788 "parser.cpp"
    break;

  case 11: // else: ELSE '{' lSentencias '}' else
#line 182 "parser.y"
                                    { yylhs.value.as < AbsExpr* > () = new NT_else(yystack_[2].value.as < NT_LSentencias* > (), yystack_[0].value.as < AbsExpr* > ()); }
#line 794 "parser.cpp"
    break;

  case 12: // else: ELSE if
#line 183 "parser.y"
              {  yylhs.value.as < AbsExpr* > () = new NT_else(yystack_[0].value.as < AbsExpr* > ());  }
#line 800 "parser.cpp"
    break;

  case 13: // else: %empty
#line 184 "parser.y"
             {  yylhs.value.as < AbsExpr* > () = nullptr; }
#line 806 "parser.cpp"
    break;

  case 14: // while: WHILE '(' cond ')' '{' lSentencias '}'
#line 187 "parser.y"
                                              { 
    yylhs.value.as < AbsExpr* > () = new NT_While( yystack_[4].value.as < AbsExpr* > (), yystack_[1].value.as < NT_LSentencias* > ());
 }
#line 814 "parser.cpp"
    break;

  case 15: // cond: cond OR cond
#line 192 "parser.y"
                  {     
    yylhs.value.as < AbsExpr* > () = new NT_Or(yystack_[2].value.as < AbsExpr* > (), yystack_[0].value.as < AbsExpr* > ());
  }
#line 822 "parser.cpp"
    break;

  case 16: // cond: cond AND cond
#line 195 "parser.y"
                 {
    yylhs.value.as < AbsExpr* > () = new NT_And(yystack_[2].value.as < AbsExpr* > (), yystack_[0].value.as < AbsExpr* > ());    
 }
#line 830 "parser.cpp"
    break;

  case 17: // cond: operel
#line 198 "parser.y"
         { yylhs.value.as < AbsExpr* > () = yystack_[0].value.as < AbsExpr* > (); }
#line 836 "parser.cpp"
    break;

  case 18: // operel: expr EQ expr
#line 202 "parser.y"
                     {
    yylhs.value.as < AbsExpr* > () = new NT_Operel(yystack_[2].value.as < AbsExpr* > (), yystack_[0].value.as < AbsExpr* > (), QString("=="));

 }
#line 845 "parser.cpp"
    break;

  case 19: // operel: expr '<' expr
#line 206 "parser.y"
               { 
    yylhs.value.as < AbsExpr* > () = new NT_Operel(yystack_[2].value.as < AbsExpr* > (), yystack_[0].value.as < AbsExpr* > (), QString("<"));
    
 }
#line 854 "parser.cpp"
    break;

  case 20: // expr: expr SUMA expr
#line 212 "parser.y"
                     {
    yylhs.value.as < AbsExpr* > () = new NT_Sum(yystack_[2].value.as < AbsExpr* > (),yystack_[0].value.as < AbsExpr* > ());
 }
#line 862 "parser.cpp"
    break;

  case 21: // expr: expr MENOS expr
#line 215 "parser.y"
                      { 
        yylhs.value.as < AbsExpr* > () = new NT_Resta(yystack_[2].value.as < AbsExpr* > (),yystack_[0].value.as < AbsExpr* > ());
    }
#line 870 "parser.cpp"
    break;

  case 22: // expr: expr '*' expr
#line 218 "parser.y"
                    {
        yylhs.value.as < AbsExpr* > () = new NT_Multi(yystack_[2].value.as < AbsExpr* > (),yystack_[0].value.as < AbsExpr* > ());

     }
#line 879 "parser.cpp"
    break;

  case 23: // expr: expr '/' expr
#line 222 "parser.y"
                    {
        yylhs.value.as < AbsExpr* > () = new NT_Div(yystack_[2].value.as < AbsExpr* > (),yystack_[0].value.as < AbsExpr* > ());
     }
#line 887 "parser.cpp"
    break;

  case 24: // expr: NUMERO
#line 225 "parser.y"
             {
        yylhs.value.as < AbsExpr* > () = new T_Num_e(QString::fromStdString(yystack_[0].value.as < std::string > ()));
    }
#line 895 "parser.cpp"
    break;

  case 25: // expr: ID
#line 228 "parser.y"
         { 
        yylhs.value.as < AbsExpr* > () = new T_ID_e(QString::fromStdString(yystack_[0].value.as < std::string > ()));
    }
#line 903 "parser.cpp"
    break;

  case 26: // expr: '(' expr ')'
#line 231 "parser.y"
                   {
        yylhs.value.as < AbsExpr* > () = yystack_[1].value.as < AbsExpr* > ();     
    }
#line 911 "parser.cpp"
    break;


#line 915 "parser.cpp"

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
  ParserN::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  ParserN::yytnamerr_ (const char *yystr)
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
  ParserN::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // ParserN::context.
  ParserN::context::context (const ParserN& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  ParserN::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
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
  ParserN::yy_syntax_error_arguments_ (const context& yyctx,
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
  ParserN::yysyntax_error_ (const context& yyctx) const
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


  const signed char ParserN::yypact_ninf_ = -16;

  const signed char ParserN::yytable_ninf_ = -1;

  const signed char
  ParserN::yypact_[] =
  {
      15,   -16,   -16,    -1,    16,    17,   -16,   -16,    20,    64,
     -16,   -16,   -16,    19,   -16,     2,    38,    -1,    -1,   -16,
     -16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   -16,
      -3,    21,    25,   -16,    -4,    -4,    42,    42,   -16,   -16,
      23,    31,    64,    64,    39,    46,    28,   -16,   -15,   -16,
      64,   -16,    53,    28,   -16
  };

  const signed char
  ParserN::yydefact_[] =
  {
       0,    24,    25,     0,     0,     0,     8,     9,     0,     3,
       5,     6,     7,     2,    17,     0,     0,     0,     0,     1,
       4,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,     0,    15,    16,    20,    21,    18,    19,    22,    23,
       0,     0,     0,     0,     0,     0,    13,    14,     0,    10,
       0,    12,     0,    13,    11
  };

  const signed char
  ParserN::yypgoto_[] =
  {
     -16,   -16,     4,    -9,    10,     7,   -16,    63,   -16,    -2
  };

  const signed char
  ParserN::yydefgoto_[] =
  {
       0,     8,     9,    10,    11,    49,    12,    13,    14,    15
  };

  const signed char
  ParserN::yytable_[] =
  {
      20,    16,     1,     2,    50,    21,    22,     4,    23,    24,
      27,    28,    25,    26,    40,     3,    27,    28,     1,     2,
      19,    34,    35,    36,    37,    38,    39,    21,    22,    21,
      22,     3,    17,    18,    22,    20,    20,     4,    41,     5,
       6,     7,    42,    20,    23,    24,    44,    45,    23,    24,
      43,    48,    27,    28,    52,    29,    27,    28,    51,    46,
      54,     4,     0,     5,     6,     7,    47,     0,     4,     0,
       5,     6,     7,    53,     0,     4,     0,     5,     6,     7,
      30,    31,     0,     0,    32,    33,     4,     0,     5,     6,
       7
  };

  const signed char
  ParserN::yycheck_[] =
  {
       9,     3,     3,     4,    19,     8,     9,    22,     6,     7,
      14,    15,    10,    11,    17,    16,    14,    15,     3,     4,
       0,    23,    24,    25,    26,    27,    28,     8,     9,     8,
       9,    16,    16,    16,     9,    44,    45,    22,    17,    24,
      25,    26,    19,    52,     6,     7,    42,    43,     6,     7,
      19,    23,    14,    15,    50,    17,    14,    15,    48,    20,
      53,    22,    -1,    24,    25,    26,    20,    -1,    22,    -1,
      24,    25,    26,    20,    -1,    22,    -1,    24,    25,    26,
      17,    18,    -1,    -1,    21,    22,    22,    -1,    24,    25,
      26
  };

  const signed char
  ParserN::yystos_[] =
  {
       0,     3,     4,    16,    22,    24,    25,    26,    28,    29,
      30,    31,    33,    34,    35,    36,    36,    16,    16,     0,
      30,     8,     9,     6,     7,    10,    11,    14,    15,    17,
      34,    34,    34,    34,    36,    36,    36,    36,    36,    36,
      17,    17,    19,    19,    29,    29,    20,    20,    23,    32,
      19,    31,    29,    20,    32
  };

  const signed char
  ParserN::yyr1_[] =
  {
       0,    27,    28,    28,    29,    29,    30,    30,    30,    30,
      31,    32,    32,    32,    33,    34,    34,    34,    35,    35,
      36,    36,    36,    36,    36,    36,    36
  };

  const signed char
  ParserN::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       8,     5,     2,     0,     7,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     1,     3
  };


#if YYNDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const ParserN::yytname_[] =
  {
  "END", "error", "\"invalid token\"", "NUMERO", "ID", "STRING", "SUMA",
  "MENOS", "OR", "AND", "EQ", "'<'", "'>'", "';'", "'*'", "'/'", "'('",
  "')'", "'='", "'{'", "'}'", "NEG", "IF", "ELSE", "WHILE", "BREAK",
  "CONTINUE", "$accept", "s", "lSentencias", "sentencia", "if", "else",
  "while", "cond", "operel", "expr", YY_NULLPTR
  };
#endif


#if YYNDEBUG
  const unsigned char
  ParserN::yyrline_[] =
  {
       0,   146,   146,   151,   156,   158,   164,   165,   166,   170,
     177,   182,   183,   184,   187,   192,   195,   198,   202,   206,
     212,   215,   218,   222,   225,   228,   231
  };

  void
  ParserN::yy_stack_print_ () const
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
  ParserN::yy_reduce_print_ (int yyrule) const
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
#endif // YYNDEBUG


} // yyN
#line 1416 "parser.cpp"

#line 235 "parser.y"

void yyN::ParserN::error(const yyN::location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}

/*
nodos 
if 
*/
