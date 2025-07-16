#include "lectura.h"

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>

void leerSociosDesdeCSV()
{
    QFile archivo("C:/Users/Urano/Documents/Final/ListaDeSocios.csv");  // Ruta


    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo.";
        return;
    }

    QTextStream entrada(&archivo);

    while (!entrada.atEnd()) {
        QString linea = entrada.readLine();
        QStringList campos = linea.split(",");

        if (campos.size() >= 4) {
            QString id = campos[0];
            QString nombre = campos[1];
            QString apellido = campos[2];
            QString dni = campos[3];

            qDebug() << "Socio:" << id << nombre << apellido << dni;
        }
    }

    archivo.close();
}

void leerLibroDesdeCSV(){

    QFile archivo("C:/Users/Urano/Documents/Final/lista_libros.csv");  // Ruta Libro

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo.";
        return;
    }
    archivo.close();
}



