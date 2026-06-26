#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "calculadora_c++.h" // Mantenemos tu lógica intacta

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Slots de los botones
    void on_BTNpaneles_clicked();
    void on_BTNbaterias_clicked();
    void on_BTNinversores_clicked();
    void on_BTNcalcular_clicked();
    void on_BTNimprimir_clicked();

private:
    Ui::MainWindow *ui;

    // elecciones del usuario :p
    int panelSelec;
    int bateriaSelec;
    int inversorSelec;
    int lugarSelec;

    // Arreglos de datos inicializados idénticos a tu main.cpp
    panel paneles[10];
    bateria baterias[2];
    inversor inversores[2];

    // Actualiza el UI
    void actualizarVistaSelecciones();
};

#endif // MAINWINDOW_H