#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <socioH.h>
#include <libroH.h>
#include "funcionesPrestamo.h"
#include "prestamoFormato.h"
#include <QMainWindow>
#include <lectura.h>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
//Esto es para que los tipos datos no se mezclen o se sobreescriban en la tabla unos con otros
enum ModoTabla {
    MODO_SOCIOS,
    MODO_LIBROS,
    MODO_NINGUNO
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //Slots privados con los eventos que se inician al clickear los botones de la interfaz

    void on_versocio_clicked();

    void on_verlibro_clicked();

    void on_busSocio_clicked();

    void on_btnBuscLibro_clicked();

    void on_btnAgregarSocio_clicked();

    void on_btnEliminarSo_clicked();



    void on_tableSocios_cellChanged(int row, int column);

    void on_btnAgregarLibro_clicked();


    void on_btnEliminarLibro_clicked();

    void on_btnRegistrarPrestamo_clicked();

    void on_btnVerPrestamos_clicked();

    void on_btnRegistrarDevolucion_clicked();

private:
    Ui::MainWindow *ui;

    std::vector<socio> vector_Socio;

    std::vector<libro> vector_Libro;

    std::vector<datoPrestamo> vector_Prestamo;

    ModoTabla modoActual = MODO_NINGUNO;




    bool mostrandoSocios = true;
    void leerSociosDesdeCSV();
    void cargarPrestamosDesdeCSV();

    void leerLibroDesdeCSV();

    void mostrar(const std::vector<socio>& vec);
    void mostrar2(const std::vector<libro>& vec);
     void mostrar3(const std::vector<datoPrestamo>& vec);
};


#endif // MAINWINDOW_H
