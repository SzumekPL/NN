#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <stdlib.h>
#include "perceptron.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Example
{
    int label;
    QVector<int> matrix;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QVector <int> matrix;

    QVector<Example> examples;

    int exampleCount;

private:
    int w;
    int h;

    int numberExamples;

    QString clickedColor = "background-color: rgb(255, 64, 64); border: none;";
    QString unclickedColor = "background-color: rgb(255, 255, 255); border: none;";

    void changeColorOfButton(QObject* sender);
    void training();

    QVector<Perceptron> percetrons;

    int my_label = 0;
    int ex_num = 0;

private slots:
    void on_Button11_clicked();
    void on_Button12_clicked();
    void on_Button13_clicked();
    void on_Button14_clicked();
    void on_Button15_clicked();

    void on_Button21_clicked();
    void on_Button22_clicked();
    void on_Button23_clicked();
    void on_Button24_clicked();
    void on_Button25_clicked();

    void on_Button31_clicked();
    void on_Button32_clicked();
    void on_Button33_clicked();
    void on_Button34_clicked();
    void on_Button35_clicked();

    void on_Button41_clicked();
    void on_Button42_clicked();
    void on_Button43_clicked();
    void on_Button44_clicked();
    void on_Button45_clicked();

    void on_Button51_clicked();
    void on_Button52_clicked();
    void on_Button53_clicked();
    void on_Button54_clicked();
    void on_Button55_clicked();

    void on_Button61_clicked();
    void on_Button62_clicked();
    void on_Button63_clicked();
    void on_Button64_clicked();
    void on_Button65_clicked();

    void on_Button71_clicked();
    void on_Button72_clicked();
    void on_Button73_clicked();
    void on_Button74_clicked();
    void on_Button75_clicked();

    void on_ClearButton_clicked();

    void on_SaveButton_clicked();

    void on_ToTextfile_clicked();

    void load_fromTextfile();

    void showExample();

    void on_Numbers_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
