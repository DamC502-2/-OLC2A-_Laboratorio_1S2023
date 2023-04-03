#include <ParserNodos/interfazN.h>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Parser/interfaz.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Clase6::Interfaz* interfaz = new Clase6::Interfaz();
    interfaz->CompilarDDS( ui->textEdit->toPlainText().toStdString());
    ui->textEdit_2->setText( interfaz->gen->salida);
}


void MainWindow::on_pushButton_2_clicked()
{
    Compilador::Interfaz* interfaz  = new Compilador::Interfaz();
    auto  salida = interfaz->CompilarDDS( ui->textEdit->toPlainText().toStdString());
    ui->textEdit_2->setText( salida);
}

