#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    w = 5;
    h = 7;

    numberExamples = 10000;

    int size = w * h;

    matrix = QVector<int>(size);
    matrix.fill(-1);

    percetrons = QVector<Perceptron>(10);
    int i = 0;
    for(auto a : percetrons)
    {
        a = Perceptron(size, i++);
    }

    load_fromTextfile();

    exampleCount = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::training()
{
    int bestSeries = 0;
    float learnConst = 0.1;
    int series = 0;
    for(int i = 0; i < numberExamples; ++i)
    {
        int TreningExample = rand() % 10;
        percetrons[TreningExample]; // wybieramy perceptron
        int indexOfExample = rand() % exampleCount;
        int value = percetrons[TreningExample].calculate(examples[indexOfExample].matrix);
        bool result = false;
        result = (examples[indexOfExample].label == TreningExample) ? (1 == value) : (-1 == value);
        if(result)
        {
            series++;
            if(series > bestSeries)
            {
                percetrons[TreningExample].saveBest();
                bestSeries = series;
            }
        }
        else
        {
            series = 0;
            for(int i = 0; i < percetrons[TreningExample].getWeightsSize(); ++i)
            {
                percetrons[TreningExample].getWeights()[i] = learnConst * value * examples[indexOfExample].matrix[i];
            }
        }
    }
}


//------------------------------------------------------------//
//-------------------------GUI--------------------------------//
//------------------------------------------------------------//

void MainWindow::showExample()
{
    for(int i = 0; i < examples.size(); ++i)
    {
        if(examples[i].label == my_label)
        {
            ex_num = i;
        }
    }

}


void MainWindow::on_ClearButton_clicked()
{
    matrix.fill(-1);
    for(auto pb : ui->buttonGroup->buttons())
    {
        pb->setStyleSheet(unclickedColor);
    }
}


void MainWindow::on_SaveButton_clicked()
{
    Example example;
    example.label = ui->Numbers->currentText().toInt();
    example.matrix = this->matrix;

    examples.push_back(example);
}


void MainWindow::changeColorOfButton(QObject* sender)
{
    QPushButton* target = qobject_cast<QPushButton*>(sender);
    if (target != nullptr)
    {
        if(target->styleSheet() == unclickedColor)
        {
            target->setStyleSheet(clickedColor);
        }
        else
        {
            target->setStyleSheet(unclickedColor);
        }
    }
}

int cmpLabel(const void * s1, const void *s2)
{
    return ( *(int*)s1 - *(int*)s2 );
}

void MainWindow::load_fromTextfile()
{
    QFile file("./examples.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this, tr("Unable to open file"),file.errorString());
        return;
    }

    QTextStream in(&file);
    while(!in.atEnd())
    {
        Example ex;
        QString line = in.readLine();
        QStringList values = line.split(" ");
        ex.label = values[0].toInt();
        for(int i = 1; i < values.size(); ++i)
        {
            ex.matrix.push_back(values[i].toInt());
        }
        examples.push_back(ex);
    }

    std::qsort(examples.begin(), examples.size(), sizeof(int), cmpLabel);

    file.close();
}

void MainWindow::on_ToTextfile_clicked()
{
    QFile file("./examples.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::information(this, tr("Unable to open file"),file.errorString());
        return;
    }

    QTextStream out(&file);
    for(auto ex : examples)
    {
        out << QString::number(ex.label) << " ";
        for(auto ma : ex.matrix)
        {
            out << QString::number(ma) << " ";
        }
        out << QString("\n");
    }

    file.close();
}

void MainWindow::on_Button11_clicked()
{
    matrix[0] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button12_clicked()
{
    matrix[1] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button13_clicked()
{
    matrix[2] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button14_clicked()
{
    matrix[3] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button15_clicked()
{
    matrix[4] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button21_clicked()
{
    matrix[5] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button22_clicked()
{
    matrix[6] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button23_clicked()
{
    matrix[7] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button24_clicked()
{
    matrix[8] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button25_clicked()
{
    matrix[9] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button31_clicked()
{
    matrix[10] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button32_clicked()
{
    matrix[11] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button33_clicked()
{
    matrix[12] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button34_clicked()
{
    matrix[13] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button35_clicked()
{
    matrix[14] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button41_clicked()
{
    matrix[15] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button42_clicked()
{
    matrix[16] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button43_clicked()
{
    matrix[17] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button44_clicked()
{
    matrix[18] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button45_clicked()
{
    matrix[19] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button51_clicked()
{
    matrix[20] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button52_clicked()
{
    matrix[21] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button53_clicked()
{
    matrix[22] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button54_clicked()
{
    matrix[23] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button55_clicked()
{
    matrix[24] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button61_clicked()
{
    matrix[25] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button62_clicked()
{
    matrix[26] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button63_clicked()
{
    matrix[27] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button64_clicked()
{
    matrix[28] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button65_clicked()
{
    matrix[29] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button71_clicked()
{
    matrix[30] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button72_clicked()
{
    matrix[31] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button73_clicked()
{
    matrix[32] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button74_clicked()
{
    matrix[33] *= -1;
    changeColorOfButton(sender());
}


void MainWindow::on_Button75_clicked()
{
    matrix[34] *= -1;
    changeColorOfButton(sender());
}

void MainWindow::on_Numbers_currentIndexChanged(int index)
{
    my_label = index;
    ex_num = 0;
}

