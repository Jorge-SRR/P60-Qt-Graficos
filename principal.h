#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <string>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();
protected:
    void paintEvent(QPaintEvent * event)override;

private slots:
    void on_actionGuardar_triggered();

    void on_pushButton_clicked(bool checked);

    void on_intNota1_valueChanged(int arg1);

    void on_intNota2_valueChanged(int arg1);

    void on_intNota3_valueChanged(int arg1);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::Principal *ui;
    QPixmap lienzo;

    void dibujar();

    int getAlto(int valor);
    int increY(int alto);

    string promedio();
};
#endif // PRINCIPAL_H
