#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <firfilter.h>
#include <plotdialog.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_btnOpen_clicked();

    void on_btnFilter_clicked();

    void on_btnPlot_clicked();

private:
    Ui::MainWindow *ui;
    FIRFilter *filter;
    std::deque<FixedFP> inSignal;
    std::deque<FixedFP> outSignal;
    PlotDialog *plotWindow;
};

#endif // MAINWINDOW_H
