#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QProcess p;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //system("python scraping2.py");

    QStringList params;

    params << "C:/QT_PROJECTS/PYTHONINQT/scraping4.py";
    //params << "scraping3.py";//работает если переместить пайтон скрипт в сборку приложения, если нету сборки указать путь
    //p.start("C:/Users/Vova/AppData/Local/Programs/Python/Python38-32/python.exe", params);
    p.start("python", params);
    p.waitForFinished(-1);
    QString p_stdout = QString::fromLocal8Bit(p.readAll());
    p_stdout = p_stdout.simplified();
    lbl.setText(p_stdout);
    QString p_stdout2 = "vova";
    qDebug() << p_stdout << p_stdout2;
    lbl.show();

    //QString str1 = p_stdout.right(p_stdout.indexOf('Сейчас в эфире Радио Рекорд'));

    p_stdout.remove("ейчас в эфире Радио Рекорд с");
    //qDebug() << str1 << p_stdout;// << endl << str2 << endl << str3;
    QString str1 = p_stdout;
    qDebug() << str1.left(str1.indexOf(" Плейлист Радио Рекорд"));
    QString str2 = p_stdout;
    qDebug() << str2.left(str2.indexOf(" Плейлист Радио Рекорд"));
}

void MainWindow::on_pushButton_2_clicked()
{
    //p.waitForFinished(-1);
    //QString p_stdout = p.readAll();
    //qDebug() << p_stdout;
}
