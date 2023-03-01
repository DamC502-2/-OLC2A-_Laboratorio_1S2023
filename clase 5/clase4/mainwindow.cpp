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
    Clase3::Interfaz* interfaz = new Clase3::Interfaz();
    QString cabecera = QString("digraph G {\n \
                               graph [ratio=.48];\n \
                               node [style=filled, color=black, shape=circle, width=.6\n \
                                   fontname=Helvetica, fontweight=bold, fontcolor=white,\n \
                                   fontsize=10, fixedsize=true];\n");
    QString dot = interfaz->Analaizar(ui->textEdit->toPlainText().toStdString());
    ui->textEdit_2->setText( cabecera + dot + "}");



}


void MainWindow::on_pushButton_2_clicked()
{
    Clase3::Interfaz* interfaz = new Clase3::Interfaz();
    ui->textEdit_2->setText(
            interfaz->Ejecutar(
                    ui->textEdit->toPlainText().toStdString())
            );
}

