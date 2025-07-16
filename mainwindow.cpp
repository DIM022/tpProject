#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <gestionVectorSocio.h>
#include <vector>
#include <libroH.h>
#include <socioH.h>
#include <gestionVectorLibro.h>
#include "cargar_libros.h"
#include <QMessageBox>
#include "prestamoFormato.h"
#include "funcionesPrestamo.h"
#include "cargar_socios.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //SETEO DE INTERFAZ/CARGA DE DATOS/CONEXIONES

    leerSociosDesdeCSV();
    leerLibroDesdeCSV();
    cargarPrestamosDesdeCSV();

    //Busq Socio
   connect(ui->busSocio, &QPushButton::clicked, this, &MainWindow::on_busSocio_clicked);
    //Busq Libro


    ui-> combo ->addItem("ISBN");
    ui-> combo->addItem("Nombre");
    ui-> combo->addItem("Autor");
    ui-> combo ->addItem("Área");
    ui-> combo->addItem("Subárea");
    ui-> combo->addItem("Editorial");
    ui-> combo ->addItem("Año");



    disconnect(ui->btnBuscLibro, &QPushButton::clicked, this, &MainWindow::on_btnBuscLibro_clicked);

    //Agregar Socio

    connect(ui->btnAgregarSocio, &QPushButton::clicked, this, &MainWindow::on_btnAgregarSocio_clicked);

    //Eliminar Socio

    connect(ui->btnEliminarSo, &QPushButton::clicked, this , &MainWindow::on_btnEliminarSo_clicked);

    //Modificar Socio
    disconnect(ui->tableSocios, &QTableWidget::cellChanged, this, &MainWindow::on_tableSocios_cellChanged);

    //Prestamo

    connect(ui->btnRegistrarPrestamo, &QPushButton::clicked, this, &MainWindow::on_btnRegistrarPrestamo_clicked);


    //QlinesEditPlaceHolders

    ui->lineEditEliminarDNI->setPlaceholderText("Ingrese DNI del socio...");
    ui->lineEditEliminarCodigoLibro->setPlaceholderText("Ingrese Nombre del Libro...");


    //LOS CONNECT QUIZAS SE BORREN. ALGUNOS ME DABAN ERRORES POR ESO LOS DESCONECTE. POR AHORA ASI FUNCIONA BIEN.

}


void MainWindow::leerSociosDesdeCSV()
{
    vector_Socio = cargarSocio("C:/Users/Urano/Documents/Final/ListaDeSocios.csv");
}

void MainWindow::leerLibroDesdeCSV()
{
   vector_Libro = cargarLibro("C:/Users/Urano/Documents/Final/lista_libros.csv");

}

void MainWindow::cargarPrestamosDesdeCSV()
{

  vector_Prestamo = cargarPrestamos("C:/Users/Urano/Documents/Final/prestamos.csv");
}




MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_versocio_clicked()
{
    ui->tableSocios->clearContents();
    ui->tableSocios->setRowCount(0);
      mostrandoSocios = true;

    ui->tableSocios->setColumnCount(8);
    QStringList l;
    l<<"Apellido"<<"DNI"<<"Sexo"<<"Direccion"<<"Numero"<<"Edad"<<"FechaN"<<"Email";

    ui->tableSocios->setHorizontalHeaderLabels(l);

    ui->tableSocios->setColumnWidth(0, 150);
    ui->tableSocios->setColumnWidth(1, 150);
    ui->tableSocios->setColumnWidth(2, 80);
    ui->tableSocios->setColumnWidth(3, 150);
    ui->tableSocios->setColumnWidth(4, 200);
    ui->tableSocios->setColumnWidth(5, 80);
    ui->tableSocios->setColumnWidth(6, 70);
    ui->tableSocios->setColumnWidth(7, 80);



    mostrar(vector_Socio);
}

void MainWindow::mostrar(const std::vector<socio>& vec)
{
    modoActual=MODO_SOCIOS;

    ui->tableSocios->clearContents();
    ui->tableSocios->blockSignals(true);
    ui->tableSocios->setRowCount(0); // Limpiar tabla
    ui->tableSocios->setColumnCount(8);

    for (size_t i = 0; i < vec.size(); ++i) {
        ui->tableSocios->insertRow(static_cast<int>(i));

        ui->tableSocios->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(vec[i].getapll())));
        ui->tableSocios->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(vec[i].getdni())));
        ui->tableSocios->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(vec[i].getsex())));
        ui->tableSocios->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(vec[i].getdir())));
        ui->tableSocios->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(vec[i].getnum())));
        ui->tableSocios->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(vec[i].getedad())));
        ui->tableSocios->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(vec[i].getfechaN())));
        ui->tableSocios->setItem(i, 7, new QTableWidgetItem(QString::fromStdString(vec[i].getmail())));
    }

    ui->tableSocios->blockSignals(false);
}




void MainWindow::on_verlibro_clicked()
{
    ui->tableSocios->clearContents();
    ui->tableSocios->setRowCount(0);
    mostrandoSocios = false;
    ui->tableSocios->setColumnCount(10);
    QStringList f;
    f<<"Nombre"<<"Area"<<"Subarea"<<"Autores"<<"Editorial"<<"Anio"<<"Columna"<<"Fila"<<"Disponibilidad"<<"Codigo de barras";

    ui->tableSocios->setHorizontalHeaderLabels(f);

    ui->tableSocios->setColumnWidth(0, 200);
    ui->tableSocios->setColumnWidth(1, 100);
    ui->tableSocios->setColumnWidth(2, 100);
    ui->tableSocios->setColumnWidth(3, 150);
    ui->tableSocios->setColumnWidth(4, 100);
    ui->tableSocios->setColumnWidth(5, 80);



    mostrar2(vector_Libro);

}

void MainWindow::mostrar2(const std::vector<libro>& vec)
{
    modoActual=MODO_LIBROS;
    ui->tableSocios->setRowCount(0);
    ui->tableSocios->clearContents();
    ui->tableSocios->blockSignals(true);

    for (size_t i = 0; i < vec.size(); ++i) {
        ui->tableSocios->insertRow(static_cast<int>(i));

        ui->tableSocios->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(vec[i].get_nombre())));
        ui->tableSocios->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(vec[i].get_area())));
        ui->tableSocios->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(vec[i].get_sub_area())));
        ui->tableSocios->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(vec[i].get_autores())));
        ui->tableSocios->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(vec[i].get_editorial())));
        ui->tableSocios->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(vec[i].get_anio_P())));
        ui->tableSocios->setItem(i, 6, new QTableWidgetItem(QString::number(vec[i].getColumna())));
        ui->tableSocios->setItem(i, 7, new QTableWidgetItem(QString::number(vec[i].getFila())));
        //Disponibilidad cambie "1/0" por algo mas practico
        QString disponibilidad = (vec[i].getEstadoSN()) ? "Disponible" : "No Disponible";
        ui->tableSocios->setItem(i, 8, new QTableWidgetItem(disponibilidad));
        ui->tableSocios->setItem(i, 9, new QTableWidgetItem(QString::fromStdString(vec[i].generar_barras())));



    }


}


void MainWindow::on_busSocio_clicked()
{
    QString dniBuscado = ui->barraSocio->text().trimmed();

    if (dniBuscado.isEmpty()) {
        QMessageBox::information(this, "Buscar Socio", "Ingrese un DNI para buscar.");
        return;
    }

    std::vector<socio> resultados;

    for (const auto& s : vector_Socio) {
        if (QString::fromStdString(s.getdni()) == dniBuscado) {
            resultados.push_back(s);
            break; //DNI Unico por ahora

        }
    }

    if (resultados.empty()) {
        QMessageBox::information(this, "Buscar Socio", "No se encontró ningún socio con ese DNI.");
        //limpio la tabla o muestro todos
        ui->tableSocios->setRowCount(0);
    } else {
        mostrar(resultados);
    }
}







void MainWindow::on_btnBuscLibro_clicked()
{
    QString textoBusqueda = ui->barraLibro->text().trimmed();
    QString tipoBusqueda = ui->combo->currentText();

    if (textoBusqueda.isEmpty()) {
        QMessageBox::information(this, "Buscar Libro", "Ingrese un término de búsqueda.");
        return;
    }

    std::vector<libro> resultados;

    for (const auto& l : vector_Libro) {
        QString valorComparar;

        if (tipoBusqueda == "Nombre") valorComparar = QString::fromStdString(l.get_nombre());
        else if (tipoBusqueda == "Autor") valorComparar = QString::fromStdString(l.get_autores());
        else if (tipoBusqueda == "Área") valorComparar = QString::fromStdString(l.get_area());
        else if (tipoBusqueda == "Subárea") valorComparar = QString::fromStdString(l.get_sub_area());
        else if (tipoBusqueda == "Editorial") valorComparar = QString::fromStdString(l.get_editorial());
        else if (tipoBusqueda == "Año") valorComparar = QString::fromStdString(l.get_anio_P());

        else continue;

        if (valorComparar.contains(textoBusqueda, Qt::CaseInsensitive)) {
            resultados.push_back(l);
        }
    }

    if (resultados.empty()) {
        QMessageBox::information(this, "Buscar Libro", "No se encontraron libros.");
        ui->tableSocios->setRowCount(0);
    } else {
        mostrar2(resultados);
    }
}


void MainWindow::on_btnAgregarSocio_clicked()
{

    QString apellido = ui->lineEditApellido->text().trimmed();
    QString dni = ui->lineEditDNI->text().trimmed();
    QString sexo = ui->lineEditSexo->text().trimmed();
    QString direccion = ui->lineEditDireccion->text().trimmed();
    QString telefono = ui->lineEditNumero->text().trimmed();
    QString edad = ui->lineEditEdad->text().trimmed();
    QString fechaNac = ui->lineEditFechaN->text().trimmed();
    QString email = ui->lineEditEmail->text().trimmed();

    if (apellido.isEmpty() || dni.isEmpty()) {
        QMessageBox::warning(this, "Datos incompletos", "Apellido y DNI son obligatorios.");
        return;
    }

    socio nuevo(
        apellido.toStdString(),
        dni.toStdString(),
        sexo.toStdString(),
        direccion.toStdString(),
        telefono.toStdString(),
        edad.toStdString(),
        fechaNac.toStdString(),
        email.toStdString(),
        static_cast<int>(vector_Socio.size()) // posicionA
        );

    vector_Socio.push_back(nuevo);

    mostrar(vector_Socio); // Actualiza la tabla

    QMessageBox::information(this, "Socio agregado", "El socio fue agregado correctamente.");

    // Limpiar campos
    ui->lineEditApellido->clear();
    ui->lineEditDNI->clear();
    ui->lineEditSexo->clear();
    ui->lineEditDireccion->clear();
    ui->lineEditNumero->clear();
    ui->lineEditEdad->clear();
    ui->lineEditFechaN->clear();
    ui->lineEditEmail->clear();

    std::ofstream archivo("C:/Users/Urano/Documents/Final/ListaDeSocios.csv", std::ios::app); // modo append

    if (archivo.is_open()) {
        archivo << nuevo.stringFile() << std::endl;
        archivo.close();
    }

}


void MainWindow::on_btnEliminarSo_clicked()
{
    QString dniEliminar = ui->lineEditEliminarDNI->text().trimmed();

    if (dniEliminar.isEmpty()) {
        QMessageBox::warning(this, "Eliminar Socio", "Ingrese un DNI.");
        return;
    }

    int indice = buscarIndicePorDNI(vector_Socio, dniEliminar.toStdString());

    if (indice != -1) {
        eliminarSocio(vector_Socio, indice);

        // guardo el CSV
        std::ofstream archivo("C:/Users/Urano/Documents/Final/ListaDeSocios.csv");
        for (const auto& s : vector_Socio) {
            archivo << s.stringFile() << std::endl;
        }

        mostrar(vector_Socio); // actualiza tabla

        QMessageBox::information(this, "Éxito", "Socio eliminado correctamente.");
    } else {
        QMessageBox::information(this, "No encontrado", "No se encontró ningún socio con ese DNI.");
    }

    ui->lineEditEliminarDNI->clear();
}





void MainWindow::on_tableSocios_cellChanged(int row, int column)
{


    if (row < 0 || column < 0) return;

    QTableWidgetItem* item = ui->tableSocios->item(row, column);
    if (!item) return;

    std::string nuevoValor = item->text().toStdString();

    if (modoActual == MODO_SOCIOS) {
        if (row >= vector_Socio.size()) return;

        switch (column) {
        case 0: vector_Socio[row].setDato(nuevoValor, 1); break; // apellido
        case 1: vector_Socio[row].setDato(nuevoValor, 2); break; // dni
        case 2: vector_Socio[row].setDato(nuevoValor, 3); break; // sexo
        case 3: vector_Socio[row].setDato(nuevoValor, 4); break; // dirección
        case 4: vector_Socio[row].setDato(nuevoValor, 5); break; // teléfono
        case 5: vector_Socio[row].setDato(nuevoValor, 6); break; // edad
        case 6: vector_Socio[row].setDato(nuevoValor, 7); break; // fecha nacimiento
        case 7: vector_Socio[row].setDato(nuevoValor, 8); break; // mail
        default: break;
        }

        std::ofstream archivo("C:/Users/Urano/Documents/Final/ListaDeSocios.csv");
        for (const auto& s : vector_Socio)
            archivo << s.stringFile() << "\n";
    }

    else if (modoActual == MODO_LIBROS) {
        if (row >= vector_Libro.size()) return;

        switch (column) {
        case 0: vector_Libro[row].setDato(nuevoValor, 1); break; // Nombre
        case 1: vector_Libro[row].setDato(nuevoValor, 2); break; // Género
        case 2: vector_Libro[row].setDato(nuevoValor, 3); break; // Subgénero
        case 3: vector_Libro[row].setDato(nuevoValor, 4); break; // Autor
        case 4: vector_Libro[row].setDato(nuevoValor, 5); break; // Editorial
        case 5: vector_Libro[row].setDato(nuevoValor, 6); break; // Año
        case 6: vector_Libro[row].setDato(nuevoValor, 7); break; // Columna
        case 7: vector_Libro[row].setDato(nuevoValor, 8); break; // Fila

        default: break;
        }

        fstream file;
        ///LIBRO
        ///OUT PARA ESCRIBIR Y TRUNC PARA ELIMINAR EL CONTENIDO ANTERIOIR DEL ARCHIVO
        file.open("C:/Users/Urano/Documents/Final/lista_libros.csv", ios::out | ios::trunc);

        for(size_t i=0; i<vector_Libro.size(); i++){

            ///ALMACENAMOS EN ARCHIVO --- stringFile
            ///stringFile -- CONVIERTE LOS ATRIBUTOS DEL OBJETO EN UN STRING QUE RETORNA
            file << vector_Libro[i].stringFile()<<'\n';
        }

        file.close();
    }
}


void MainWindow::on_btnAgregarLibro_clicked()
{
    QString nombre = ui->lineEditNombre->text().trimmed();
    QString area = ui->lineEditArea->text().trimmed();
    QString subArea = ui->lineEditSubArea->text().trimmed();
    QString autores = ui->lineEditAutores->text().trimmed();
    QString editorial = ui->lineEditEditorial->text().trimmed();
    QString anioPublicacion = ui->lineEditAnio->text().trimmed();
    QString columnaStr = ui->lineEditColumna->text().trimmed();
    QString filaStr = ui->lineEditFila->text().trimmed();


    // validar que campos no esten vacios
    if (nombre.isEmpty() || area.isEmpty() || subArea.isEmpty() ||
        autores.isEmpty() || editorial.isEmpty() || anioPublicacion.isEmpty() ||
        columnaStr.isEmpty() || filaStr.isEmpty()) {

        QMessageBox::warning(this, "Datos incompletos", "Todos los campos son obligatorios.");
        return;
    }

    // validar nombre (usamos tu función validarNombre, adaptada)
    if (validarNombre(nombre.toStdString())) {
        QMessageBox::warning(this, "Nombre inválido", "El nombre contiene caracteres inválidos.");
        return;
    }

    // validar area y subArea
    if (verificarCharString(area.toStdString()) || verificarCharString(subArea.toStdString())) {
        QMessageBox::warning(this, "Área o Subárea inválida", "Solo se permiten caracteres válidos.");
        return;
    }

    // validar autores y editorial
    if (validarAutores(autores.toStdString()) || validarAutores(editorial.toStdString())) {
        QMessageBox::warning(this, "Autores o Editorial inválida", "Solo se permiten caracteres válidos.");
        return;
    }

    // Validar año publicación


    // convierte columna y fila a int
    bool okCol, okFila;
    int columna = columnaStr.toInt(&okCol);
    int fila = filaStr.toInt(&okFila);

    if (!okCol || !okFila) {
        QMessageBox::warning(this, "Ubicación inválida", "Columna y fila deben ser números enteros.");
        return;
    }

    int ubicacion[2] = {columna, fila};

    // validar ubicación con vectorLibro
    if (validarUbicacion(ubicacion, vector_Libro)) {
        QMessageBox::warning(this, "Ubicación ocupada", "La fila y columna ya están asignadas a otro libro.");
        return;
    }

    // aca se crea el libro y se agrega al vector
    libro nuevoLibro(
        nombre.toStdString(),
        area.toStdString(),
        subArea.toStdString(),
        autores.toStdString(),
        editorial.toStdString(),
        anioPublicacion.toStdString(),
     ubicacion,


        true // disponible
        );


    vector_Libro.push_back(nuevoLibro);

    // Guardar en archivo
    std::ofstream archivo("C:/Users/Urano/Documents/Final/lista_libros.csv", std::ios::app); // modo append

    if (archivo.is_open()) {
        archivo << nuevoLibro.stringFile() << std::endl;
        archivo.close();
    }



    QMessageBox::information(this, "Libro agregado", "El libro fue agregado correctamente.");

    // Limpiar campos
    ui->lineEditNombre->clear();
    ui->lineEditArea->clear();
    ui->lineEditSubArea->clear();
    ui->lineEditAutores->clear();
    ui->lineEditEditorial->clear();
    ui->lineEditAnio->clear();
    ui->lineEditColumna->clear();
    ui->lineEditFila->clear();


    mostrar2(vector_Libro);
}


void MainWindow::on_btnEliminarLibro_clicked()
{
    // agarra el codigo que se puso en el QlineEdit
    QString nombreEliminar = ui->lineEditEliminarCodigoLibro->text().trimmed();

    if (nombreEliminar.isEmpty()) {
        QMessageBox::warning(this, "Eliminar Libro", "Por favor, ingrese el nombre del libro que desea eliminar.");
        return;
    }

    //busqueda de libro en vector
    auto it = std::find_if(vector_Libro.begin(), vector_Libro.end(),
                           [&](const libro& l) {
                               return QString::fromStdString(l.get_nombre()) == nombreEliminar;
                           });


    if (it != vector_Libro.end()) {
        //confirmacion antes de borrar
        QMessageBox::StandardButton rta;
        rta = QMessageBox::question(this, "Confirmar Eliminación",
                                      "¿Está seguro de que desea eliminar el libro " + nombreEliminar + "?",
                                      QMessageBox::Yes|QMessageBox::No);

        if (rta == QMessageBox::Yes) {
            // eliminar el libro del vector
            vector_Libro.erase(it);


            std::ofstream archivo("C:/Users/Urano/Documents/Final/lista_libros.csv");
            if (archivo.is_open()) {
                for (const auto& libroActual : vector_Libro) {
                    archivo << libroActual.stringFile() << std::endl;
                }
                archivo.close();
                QMessageBox::information(this, "Éxito", "Libro eliminado correctamente.");
            } else {
                QMessageBox::critical(this, "Error", "No se pudo abrir el archivo para guardar los cambios.");
            }


            mostrar2(vector_Libro);
            ui->lineEditEliminarCodigoLibro->clear();
        }
    } else {
        QMessageBox::information(this, "No encontrado", "No se encontró ningún libro con ese código.");
    }
}


void MainWindow::on_btnRegistrarPrestamo_clicked()
{

    QString dniSocio = ui->lineEditPrestamoDNI->text().trimmed();
    QString nombreLibro = ui->lineEditPrestamoLibro->text().trimmed();
    QDate fechaDevolucion = ui->dateEditDevolucion->date();

   //validar campos completos
    if (dniSocio.isEmpty() || nombreLibro.isEmpty()) {
        QMessageBox::warning(this, "Datos incompletos", "El DNI del socio y el nombre del libro no pueden estar vacíos.");
        return;
    }
    //validar fecha
    if (!fechaDevolucion.isValid() || fechaDevolucion <= QDate::currentDate()) {
        QMessageBox::warning(this, "Fecha Inválida", "La fecha de devolución debe ser posterior a la fecha actual.");
        return;
    }

   //validar socio
    int indiceSocio = buscarIndicePorDNI(vector_Socio, dniSocio.toStdString());
    if (indiceSocio == -1) {
        QMessageBox::warning(this, "Socio no encontrado", "No se encontró un socio con el DNI proporcionado.");
        return;
    }


    //validar libro
    if (verificarExistenciaNombreLibro(nombreLibro.toStdString(), vector_Libro)) {
       QMessageBox::warning(this, "Libro no disponible", "El libro no existe o ya ha sido prestado.");
        return;
    }


    datoPrestamo nuevoPrestamo(nombreLibro.toStdString(), dniSocio.toStdString());


    nuevoPrestamo.realizarPrestamo(); // pone la fecha de hoy como inicio


    tm fechaFinalTm = {};
    fechaFinalTm.tm_mday = fechaDevolucion.day();
    fechaFinalTm.tm_mon = fechaDevolucion.month() - 1;
    fechaFinalTm.tm_year = fechaDevolucion.year() - 1900;
    nuevoPrestamo.setFechaFinal(fechaFinalTm);


    vector_Prestamo.push_back(nuevoPrestamo);


    QMessageBox::information(this, "Éxito", "Préstamo registrado correctamente.");


    ui->lineEditPrestamoDNI->clear();
    ui->lineEditPrestamoLibro->clear();
    ui->dateEditDevolucion->setDate(QDate::currentDate().addDays(1));


    if (modoActual == MODO_LIBROS) {
        mostrar2(vector_Libro);
    }


    subirCambiosLibro(vector_Libro);
    subirCambiosPrestamos(vector_Prestamo);

}

//Seteo de tabla
void MainWindow::on_btnVerPrestamos_clicked()
{
    modoActual = MODO_NINGUNO;
    ui->tableSocios->setColumnCount(4); // 4 columnas para prestamo

    QStringList headers;
    headers << "DNI Socio" << "Nombre Libro" << "Fecha de Préstamo" << "Fecha de Devolución";
    ui->tableSocios->setHorizontalHeaderLabels(headers);

    // Ajustar anchos de columna
    ui->tableSocios->setColumnWidth(0, 100);
    ui->tableSocios->setColumnWidth(1, 250);
    ui->tableSocios->setColumnWidth(2, 150);
    ui->tableSocios->setColumnWidth(3, 150);

    mostrar3(vector_Prestamo);
}

// Relleno de tabla con datos del vector
void MainWindow::mostrar3(const std::vector<datoPrestamo>& vec)
{

    ui->tableSocios->setRowCount(0);
    ui->tableSocios->clearContents();
    ui->tableSocios->blockSignals(true);


    for (size_t i = 0; i < vec.size(); ++i) {
        ui->tableSocios->insertRow(static_cast<int>(i));

        ui->tableSocios->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(vec[i].getDni())));
        ui->tableSocios->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(vec[i].getNombreLibro())));
         ui->tableSocios->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(vec[i].getFechaInicio())));
        ui->tableSocios->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(vec[i].getFechaFinal())));
    }
}


void MainWindow::on_btnRegistrarDevolucion_clicked()
{

    if (modoActual != MODO_NINGUNO) {
        QMessageBox::warning(this, "Vista Incorrecta", "Esta función solo está disponible en la vista de préstamos.");
        return;
    }


    QModelIndexList seleccion = ui->tableSocios->selectionModel()->selectedRows();
    if (seleccion.isEmpty()) {
        QMessageBox::warning(this, "Sin Selección", "Por favor, seleccione un préstamo de la tabla para registrar su devolución.");
        return;
    }
    int filaSeleccionada = seleccion.at(0).row();


    string nombreLibroDevuelto = vector_Prestamo[filaSeleccionada].getNombreLibro();

    QMessageBox::StandardButton respuesta;
    respuesta = QMessageBox::question(this, "Confirmar Devolución",
                                  "¿Confirma la devolución del libro '" + QString::fromStdString(nombreLibroDevuelto) + "'?",
                                  QMessageBox::Yes|QMessageBox::No);

    if (respuesta == QMessageBox::No) {
        return; // El usuario canceló la operación
    }


    auto it_libro = std::find_if(vector_Libro.begin(), vector_Libro.end(),
                                 [&](const libro& l) {
                                     return l.get_nombre() == nombreLibroDevuelto;
                                 });

    if (it_libro != vector_Libro.end()) {
        it_libro->setDato_estadoSN(true); // true = disponible
    }


    vector_Prestamo.erase(vector_Prestamo.begin() + filaSeleccionada);


    subirCambiosPrestamos(vector_Prestamo);
    subirCambiosLibro(vector_Libro);


    mostrar3(vector_Prestamo);
    QMessageBox::information(this, "Éxito", "La devolución ha sido registrada correctamente.");
}

