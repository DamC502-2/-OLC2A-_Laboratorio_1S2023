cmake_minimum_required(VERSION 3.5)

project(clase11 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        Parser/interfaz.h Parser/interfaz.cpp
        Parser/generador.h Parser/generador.cpp

        Parser/parser.y
        Parser/Lexer.l
        Parser/atributos.h Parser/atributos.cpp

        Parser/lex.yy.c
        Parser/parser.hpp Parser/parser.cpp
        Parser/stack.hh Parser/location.hh
        Parser/position.hh

        ParserNodos/parser.y
        ParserNodos/Lexer.l
        ParserNodos/lex.yyN.c
        ParserNodos/parser.hpp
        ParserNodos/parser.cpp
        ParserNodos/position.hh
        ParserNodos/location.hh
        ParserNodos/stack.hh
        ParserNodos/interfazN.cpp
        ParserNodos/interfazN.h
        ParserNodos/Contexto.cpp
        ParserNodos/Contexto.h
        ParserNodos/AST/AbsExpr.cpp
        ParserNodos/AST/AbsExpr.h
        ParserNodos/AST/Resultado.cpp
        ParserNodos/AST/Resultado.h
        ParserNodos/AST/Terminal/Expr/T_ID_e.cpp
        ParserNodos/AST/Terminal/Expr/T_ID_e.h
        ParserNodos/AST/Terminal/Expr/T_Num_e.cpp
        ParserNodos/AST/Terminal/Expr/T_Num_e.h
        ParserNodos/AST/NoTerminal/Expr/NT_Div.cpp
        ParserNodos/AST/NoTerminal/Expr/NT_Div.h
        ParserNodos/AST/NoTerminal/Expr/NT_Sum.cpp
        ParserNodos/AST/NoTerminal/Expr/NT_Sum.h
        ParserNodos/AST/NoTerminal/Expr/NT_Resta.cpp
        ParserNodos/AST/NoTerminal/Expr/NT_Resta.h
        ParserNodos/AST/NoTerminal/Expr/NT_Multi.cpp
        ParserNodos/AST/NoTerminal/Expr/NT_Multi.h
        ParserNodos/AST/NoTerminal/Expr/NT_Operel.cpp
        ParserNodos/AST/NoTerminal/Expr/NT_Operel.h
        ParserNodos/AST/NoTerminal/Expr/NT_Or.cpp
        ParserNodos/AST/NoTerminal/Expr/NT_Or.h
        ParserNodos/AST/NoTerminal/Expr/NT_And.cpp
        ParserNodos/AST/NoTerminal/Expr/NT_And.h
        ParserNodos/AST/NoTerminal/NT_If.cpp
        ParserNodos/AST/NoTerminal/NT_If.h
        ParserNodos/AST/NoTerminal/NT_While.cpp
        ParserNodos/AST/NoTerminal/NT_While.h
        ParserNodos/AST/NoTerminal/NT_LSentencias.cpp
        ParserNodos/AST/NoTerminal/NT_LSentencias.h
        ParserNodos/AST/NoTerminal/NT_else.cpp
        ParserNodos/AST/NoTerminal/NT_else.h
        ParserNodos/AST/NoTerminal/NT_Break.cpp
        ParserNodos/AST/NoTerminal/NT_Break.h
        ParserNodos/AST/NoTerminal/NT_Continue.cpp
        ParserNodos/AST/NoTerminal/NT_Continue.h
        ParserNodos/AST/NoTerminal/NT_S.cpp
        ParserNodos/AST/NoTerminal/NT_S.h Compilador/Simbolo.cpp Compilador/Simbolo.h Compilador/T_Simbolos.cpp Compilador/T_Simbolos.h)

add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}
    DEPENDS ${SOURCE_FILES}/ main.cpp
                   COMMAND  flex --verbose Lexer.l
                   COMMAND  bison --verbose -o parser.cpp  parser.y
                   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Parser
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(clase11
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET clase11 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(clase11 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(clase11
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(clase11 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(clase11 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(clase11)
endif()
