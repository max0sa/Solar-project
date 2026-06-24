#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , panelSelec(-1)
    , bateriaSelec(-1)
    , inversorSelec(-1)
    , lugarSelec(-1)
    , paneles{
          {"Restarsolar", "monocristalino", "celda grado A", 250, 23.5, 127415},
          {"Canadian Solar", "monocristalino", "mono perc", 410, 21, 114750},
          {"DAH Solar", "monocristalino", "mono perc", 450, 20.7, 187200},
          {"JA Solar", "monocristalino", "half-cell", 550, 21.3, 142000},
          {"Canadian Solar", "monocristalino", "N-type topcon", 595, 23, 111250},
          {"Resun", "policristalino", "standard poly", 150, 15.2, 6900},
          {"Resun", "policristalino", "standard poly", 200, 15.5, 113400},
          {"Sine Energy", "policristalino", "standard poly", 285, 15.8, 105900},
          {"Jinko Solar", "policristalino", "standard poly", 305, 16, 75000},
          {"Sine Energy", "policristalino", "standard poly", 340, 16.2, 128990}
      }
    , baterias{
          bateria("Deep Cycle", "gel", 1200, 115000),
          bateria("Pylontech", "litio", 2400, 480000)
      }
    , inversores{
          inversor("Voltronic 3kW", 3000, 320000, 27, 1),
          inversor("Growatt 5kW", 5000, 580000, 13, 2)
      }
{
    ui->setupUi(this);

    // Dejo los Qtext pa que solo sea lectura
    ui->textEdit->setReadOnly(true);   // este es el de selecciones
    ui->textEdit_2->setReadOnly(true); // y este del del resumen
    actualizarVistaSelecciones();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Ventana que emerge para elegir panel
void MainWindow::on_BTNpaneles_clicked()
{
    //Muestra los items
    QStringList items;
    for(int i = 0; i < 10; ++i) {
        items << QString("%1 - %2 (%3W, %4)").arg(i + 1).arg(QString::fromStdString(paneles[i].getNombre())).arg(paneles[i].getPotencia()).arg(QString::fromStdString(paneles[i].getTipo()));
    }

    bool ok;
    //eleccion panel
    QString item = QInputDialog::getItem(this, "Seleccionar Panel Solar", "Seleccione un modelo del repertorio:",items, 0, false, &ok);
    if (ok && !item.isEmpty()) {
        panelSelec = items.indexOf(item) + 1;
        actualizarVistaSelecciones();//actualiza el qtext de las selecciones
    }
}

// Ventana emergente para seleccionar baterias (mismo proceso que para los paneles bro)
void MainWindow::on_BTNbaterias_clicked()
{
    QStringList items;
    for(int i = 0; i < 2; ++i) {
        items << QString("%1 - %2 (Material: %3, %4W)").arg(i + 1).arg(QString::fromStdString(baterias[i].getNombre())).arg(QString::fromStdString(baterias[i].getmaterial())).arg(baterias[i].getCapacidad());
    }

    bool ok;
    QString item = QInputDialog::getItem(this, "Seleccionar Batería","Seleccione un modelo disponible:",items, 0, false, &ok);
    if (ok && !item.isEmpty()) {
        bateriaSelec = items.indexOf(item) + 1;
        actualizarVistaSelecciones();
    }
}

// Ventana emergente para escoger inversor
void MainWindow::on_BTNinversores_clicked()
{
    QStringList items;
    for(int i = 0; i < 2; ++i) {
        items << QString("%1 - %2 (Max: %3W)").arg(i + 1).arg(QString::fromStdString(inversores[i].getNombre())).arg(inversores[i].getMaxPotencia());
    }

    bool ok;
    QString item = QInputDialog::getItem(this, "Seleccionar Inversor","Seleccione un modelo disponible:",items, 0, false, &ok);
    if (ok && !item.isEmpty()) {
        inversorSelec = items.indexOf(item) + 1;
        actualizarVistaSelecciones();
    }
}

// Esta funcion nos permite mostrar en el cuadro de texto nuestras elecciones en tiempo real jujujujujjuj
//DEP Gaspi (2002-2026) quepena
void MainWindow::actualizarVistaSelecciones()
{
    QString texto = "=== SELECCIONES ===\n\n";

    if (panelSelec != -1) {
        texto += QString("- Panel: %1 (%2W)\n").arg(QString::fromStdString(paneles[panelSelec - 1].getNombre())).arg(paneles[panelSelec - 1].getPotencia());
    } else {
        texto += "- Panel: Sin seleccionar\n";
    }

    if (bateriaSelec != -1) {
        texto += QString("- Batería: %1 (%2)\n").arg(QString::fromStdString(baterias[bateriaSelec - 1].getNombre())).arg(QString::fromStdString(baterias[bateriaSelec - 1].getmaterial()));
    } else {
        texto += "- Batería: Sin seleccionar\n";
    }

    if (inversorSelec != -1) {
        texto += QString("- Inversor: %1\n").arg(QString::fromStdString(inversores[inversorSelec - 1].getNombre()));
    } else {
        texto += "- Inversor: Sin seleccionar\n";
    }

    ui->textEdit->setText(texto);
}

// Calcula cuando apretan el boton
void MainWindow::on_BTNcalcular_clicked()
{
    int consumo = ui->SBConsumo->value();
    double cobertura = ui->SBCobertura->value();
    lugarSelec = ui->CBregiones->currentIndex();

    // Este sapo tira las warnings por si faltan datos o no son validos
    if (consumo <= 0) {
        QMessageBox::warning(this, "Faltan Datos", "Por favor ingrese un consumo mensual válido mayor a 0 kW.");
        return;
    }
    if (cobertura < 10 || cobertura > 100) {
        QMessageBox::warning(this, "Faltan Datos", "El porcentaje de cobertura debe estar entre el 10% y el 100%.");
        return;
    }
    if (panelSelec == -1 || bateriaSelec == -1 || inversorSelec == -1) {
        QMessageBox::warning(this, "Faltan Datos", "Debe seleccionar un Panel, una Batería y un Inversor antes de calcular.");
        return;
    }
    if (lugarSelec <= 0) {
        QMessageBox::warning(this, "Faltan Datos", "Por favor, seleccione una Región válida del listado.");
        return;
    }

    // calculos que los sacamos del archivo "funciones_c++.cpp"
    int totalPaneles = calcularNpaneles(paneles, consumo, cobertura, panelSelec, lugarSelec);
    int totalBaterias = calcularBaterias(baterias, consumo, cobertura, bateriaSelec);
    int totalInversores = calcularInversores(paneles, consumo, lugarSelec, cobertura, panelSelec, inversorSelec, inversores);
    int valorTotal = calcularCosto(paneles, baterias, inversores, panelSelec, bateriaSelec, inversorSelec, totalPaneles, totalBaterias, totalInversores);

    // En el otro qtext hacemos el resumen
    QString resumen = "====================================\n";
    resumen += "               PRESUPUESTO SOLAR\n";
    resumen += "====================================\n\n";
    resumen += QString("- Paneles Necesarios:\n  %1 unidades de %2W (%3)\n\n").arg(totalPaneles).arg(paneles[panelSelec - 1].getPotencia()).arg(QString::fromStdString(paneles[panelSelec - 1].getNombre()));
    resumen += QString("- Baterías Necesarias:\n  %1 unidades de tipo %2 (%3)\n\n").arg(totalBaterias).arg(QString::fromStdString(baterias[bateriaSelec - 1].getmaterial())).arg(QString::fromStdString(baterias[bateriaSelec - 1].getNombre()));
    resumen += QString("- Inversores Necesarios:\n  %1 unidades de %2W (%3)\n\n").arg(totalInversores).arg(inversores[inversorSelec - 1].getMaxPotencia()).arg(QString::fromStdString(inversores[inversorSelec - 1].getNombre()));
    resumen += "====================================\n";
    resumen += QString(" El costo estimado es de: $%1 CLP\n").arg(valorTotal);
    resumen += "====================================\n";

    ui->textEdit_2->setText(resumen);
}