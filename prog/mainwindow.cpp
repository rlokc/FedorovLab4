#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <firfilter.h>
#include <deque>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FIRFilter *filter = new FIRFilter();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    //Opening the file
    inSignal.clear();
    outSignal.clear();
    ui->textInput->clear();
    ui->textOutput->clear();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Kek"),"/home/rlokc/Dropbox/Education/6 sem/electronics/labs/lab4/program/");
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }
    QTextStream in(&file);
    //Reading the file and pushing the signal into the deque
    while(!in.atEnd())
    {
        QString line = in.readLine();
        //Dirty hack, I'm very sorry for it :(
        //Replacing -1 with -0.99 since -1 overflows
        if (line=="-1") line = "-0.99";
        inSignal.push_back(line.toFloat());
    }
    //setting the deque as the input of the filter
//    filter->getOutput(inSignal);

    //Write the lines into the text field
    for (int i=0; i<inSignal.size(); i++)
    {
        QString str = QString::number(inSignal[i].to_float());
        ui->textInput->append(str);
    }

    //Enable filtration
    ui->btnFilter->setEnabled(true);
    ui->btnPlot->setEnabled(false);
}

void MainWindow::on_btnOpen_clicked()
{
    this->on_actionOpen_triggered();
}

void MainWindow::on_btnFilter_clicked()
{
    outSignal = filter->getOutput(inSignal);
    FixedFP test = inSignal[0];
    FixedFP test2 = inSignal[1];
    qDebug() << test.to_float() << "=" << test.to_raw() << "\n" <<  test2.to_float() << "=" << test2.to_raw();
    //Write the lines into the text field
    for (int i=0; i<outSignal.size(); i++)
    {
        QString str = QString::number(outSignal[i].to_float());
        ui->textOutput->append(str);
    }
    ui->btnPlot->setEnabled(true);
}

void MainWindow::on_btnPlot_clicked()
{
    if (!plotWindow)
    {
        plotWindow = new PlotDialog();
    }

    plotWindow->show();
    plotWindow->activateWindow();
    plotWindow->getPoints(outSignal);
}
