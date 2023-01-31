#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "parserctx.hpp"


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // se crea un mensaje y que muestra el texto del textArea
    QMessageBox *msg = new QMessageBox();
    msg->setText("¡Hola a todos! \n el texto es: " +
                 ui->textEdit->toPlainText());
    msg->exec();
    //ui->textEdit->setText("se ha pulsado el botón");

    // añadimos el parser
    OCL2Calc::ParserCtx analizador;

   analizador.Analizar(ui->textEdit->toPlainText().toStdString());

    QMessageBox *msg2 = new QMessageBox();
    msg2->setText(QString::fromStdString( analizador.Salida));
    msg2->exec();
}

