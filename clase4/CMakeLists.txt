cmake_minimum_required(VERSION 3.5)

project(clase4 VERSION 0.1 LANGUAGES CXX)

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
        AST/abstractexp.h AST/abstractexp.cpp
        Interprete/Contexto/contexto.h Interprete/Contexto/contexto.cpp
Interprete/Contexto/resultado.h Interprete/Contexto/resultado.cpp
AST/No_Terminales/nt_lsentencias.h AST/No_Terminales/nt_lsentencias.cpp
AST/No_Terminales/nt_bloque.h AST/No_Terminales/nt_bloque.cpp
AST/No_Terminales/nt_asigvar.h AST/No_Terminales/nt_asigvar.cpp
AST/No_Terminales/nt_declvar.h AST/No_Terminales/nt_declvar.cpp
AST/No_Terminales/nt_imprimir.h AST/No_Terminales/nt_imprimir.cpp
AST/No_Terminales/nt_listaexpr.h AST/No_Terminales/nt_listaexpr.cpp
AST/No_Terminales/nt_s.h AST/No_Terminales/nt_s.cpp
AST/No_Terminales/nt_sentencia.h AST/No_Terminales/nt_sentencia.cpp
AST/No_Terminales/nt_tipo.h AST/No_Terminales/nt_tipo.cpp
AST/Terminales/t_id.h AST/Terminales/t_id.cpp
AST/Terminales/t_numero.h AST/Terminales/t_numero.cpp
AST/Terminales/t_string.h AST/Terminales/t_string.cpp
Parser/interfaz.h Parser/interfaz.cpp
Parser/parser.cpp Parser/parser.hpp
Parser/location.hh Parser/stack.hh
Parser/position.hh Parser/lex.yy.c
Parser/parser.y Parser/Lexer.l
AST/No_Terminales/Expresiones/nt_id.h AST/No_Terminales/Expresiones/nt_id.cpp
AST/No_Terminales/Expresiones/nt_negacion.h AST/No_Terminales/Expresiones/nt_negacion.cpp
AST/No_Terminales/Expresiones/nt_suma.h AST/No_Terminales/Expresiones/nt_suma.cpp


)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(clase4
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET clase4 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(clase4 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(clase4
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(clase4 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(clase4 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(clase4)
endif()
