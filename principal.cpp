#include "principal.h"
#include "ui_principal.h"



Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    lienzo = QPixmap(500,500);
    this->dibujar();

    ui->outCuadro->setPixmap(lienzo);

}

Principal::~Principal()
{
    delete ui;
}

void Principal::paintEvent(QPaintEvent *event)
{
    ui->outCuadro->setPixmap(lienzo);

}

void Principal::dibujar()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);

    int x = 0;
    int y = 0;

    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::green);
    pincel.setJoinStyle(Qt::MiterJoin);

    // Establecer el pincel al "pintor"
    painter.setPen(pincel);

    //Obtener datos para la primera barra
    int nota1 = ui->intNota1->value();
    int altoN1 = this->getAlto(nota1);
    int increYN1 = this->increY(altoN1);

    // Dibujar primera barra
    painter.drawRect(x+50, y+50+increYN1,100,altoN1);

    // Crear un objeto color para el relleno
    QColor colorRelleno(190,120,162);
    // Crear otro objeto color para el borde
    QColor colorBorde(78,3,48);

    // Cambiar el color del pincel
    pincel.setColor(colorBorde);

    // Volver a establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Establecer el color al brush (relleno)
    painter.setBrush(colorRelleno);

    //Obtener datos para la segunda barra
    int nota2 = ui->intNota2->value();
    int altoN2 = this->getAlto(nota2);
    int increYN2 = this->increY(altoN2);

    // Dibujar segunda barra
    painter.drawRect(x+170, y+50+increYN2, 100, altoN2);

    // Creando los colores de la tercera barra
    QColor cRellenoBarra3(253, 253, 115);
    QColor cBordeBarra3(174, 174, 51);

    // Estableciendo colores al puncel y al painter
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    //Obtener datos para la segunda barra
    int nota3 = ui->intNota3->value();
    int altoN3 = this->getAlto(nota3);
    int increYN3 = this->increY(altoN3);

    // Dibujar tercera barra
    painter.drawRect(x+290,y+50+increYN3,100,altoN3);

    string str = promedio();
    QString qstr = QString::fromStdString(str);
    ui->lineEdit->setText(qstr);
}

int Principal::getAlto(int valor)
{
    return 4 * valor;
}

int Principal::increY(int alto)
{
    return 400 - alto;
}

string Principal::promedio()
{
    int nota1 = ui->intNota1->value();
    int nota2 = ui->intNota2->value();
    int nota3 = ui->intNota3->value();

    int notaFinal;
    notaFinal = (nota1 + nota2 + nota3)/3;
    string Promedio = "Promedio: " + to_string(notaFinal);
    return Promedio;
}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}

void Principal::on_pushButton_clicked(bool checked)
{

}

void Principal::on_intNota1_valueChanged(int arg1)
{
    dibujar();
}


void Principal::on_intNota2_valueChanged(int arg1)
{
    dibujar();
}


void Principal::on_intNota3_valueChanged(int arg1)
{
    dibujar();
}


void Principal::on_lineEdit_textChanged(const QString &arg1)
{

}



void Principal::on_lineEdit_textEdited(const QString &arg1)
{

}

