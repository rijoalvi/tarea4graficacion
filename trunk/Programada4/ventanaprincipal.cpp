#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include "paneldibujo.h"
#include <iostream>
using namespace std;

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :QMainWindow(parent), ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::on_botonDibujar_clicked()
{
    cout << "hola" << endl;
    //initializeGL();

}

