#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
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
    //system("python scraping2.py");

    QStringList params;

    params << "D:/projects/PYTHONINQT/scraping4.py";
    //params << "C:/QT_PROJECTS/PYTHONINQT/scraping4.py";
    //params << "scraping3.py";//работает если переместить пайтон скрипт в сборку приложения, если нету сборки указать путь
    //p.start("C:/Users/Vova/AppData/Local/Programs/Python/Python38-32/python.exe", params);
    p.start("python", params);
    p.waitForFinished(-1);
    QString p_stdout = QString::fromLocal8Bit(p.readAll());
    p_stdout = p_stdout.simplified();

    lbl.setText(p_stdout);
    lbl.show();

    p_stdout.remove("ейчас в эфире Радио Рекорд с");
    p_stdout.remove(" Плейлист Радио Рекорд");
    qDebug() << p_stdout;

    QString str_track1 = p_stdout;
    str_track1 = str_track1.left(str_track1.indexOf(":") - 3);
    p_stdout.remove(str_track1);
    p_stdout.remove(p_stdout.left(p_stdout.indexOf(":") + 4));

    QString str_track3 = p_stdout;
    str_track3.remove(str_track3.left(str_track3.indexOf(":") + 4));
    str_track3 = str_track3.left(str_track3.indexOf(":") - 3);

    QString str_track2 = p_stdout;
    str_track2 = str_track2.left(str_track2.indexOf(":") - 3);

    qDebug() << str_track1 << endl << str_track2 << endl << str_track3;

}

void MainWindow::on_pushButton_2_clicked()
{
    //p.waitForFinished(-1);
    //QString p_stdout = p.readAll();
    //qDebug() << p_stdout;
}
