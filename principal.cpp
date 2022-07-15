#include "principal.h"
#include "ui_principal.h"
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>


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
       pincel.setColor(Qt::red);
       pincel.setJoinStyle(Qt::MiterJoin);

       // Establecer el pincel al "pintor"
       painter.setPen(pincel);


       int nota1= ui->intNota1->value();
       int Alturan1=this->getAlto(nota1);
       int incYN1=this->increY(Alturan1);

       // Dibujar primera barra
       painter.drawRect(x+50, y+50+incYN1,100,Alturan1);

       // Crear un objeto color para el relleno
       QColor colorRelleno(Qt::yellow);
       // Crear otro objeto color para el borde
       QColor colorBorde(Qt::yellow);

       // Cambiar el color del pincel
       pincel.setColor(colorBorde);

       // Volver a establecer el pincel al "pintor"
       painter.setPen(pincel);

       // Establecer el color al brush (relleno)
       painter.setBrush(colorRelleno);
       int nota2 = ui->intNota2->value();
       int Alturan2=this->getAlto(nota2);
       int incYN2=this->increY(Alturan2);
       // Dibujar segunda barra
       painter.drawRect(x+170, y+50+incYN2, 100, Alturan2);

       // Creando los colores de la tercera barra
       QColor cRellenoBarra3(253, 253, 115);
       QColor cBordeBarra3(174, 174, 51);

       // Estableciendo colores al pincel y al painter
       pincel.setColor(cBordeBarra3);
       painter.setPen(pincel);
       painter.setBrush(cRellenoBarra3);

       // Dibujar tercera barra
       int nota3=ui->intNota3->value();
       int Alturan3=this->getAlto(nota3);
       int incYN3=this->increY(Alturan3);

       painter.drawRect(x+290,y+50+incYN3,100,Alturan3);

       int a=ui->intNota1->value();
       int b=ui->intNota2->value();
       int c=ui->intNota3->value();
       double prom = (a+b+c)/3;
       // Estableciendo colores al pincel y al painter
       pincel.setColor(Qt::black);
       painter.setPen(pincel);
       painter.drawLine(800,450,0,450);
       painter.drawLine(50,0,50,500);
       int cont=500;
       int as=0;
       for(int i=0;i<=10;i++){
           cont=cont-40;
           qDebug()<<as<< " "<<cont;
           painter.drawText(20,cont,QString::number(as));
           as=as+10;
       }
       painter.drawText(100,490,"N1");
       painter.drawText(200,490,"N2");
       painter.drawText(300,490,"N3");
       pincel.setColor(Qt::blue);
       painter.setPen(pincel);
       painter.drawLine(800,450-prom*4,0,450-prom*4);


   }

   int Principal::getAlto(int a)
   {
       return 4*a;
   }

   int Principal::increY(int a)
   {
       return 400-a;
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

