#ifndef PLOTDIALOG_H
#define PLOTDIALOG_H

#include <QDialog>
#include <qwt_plot.h>
#include <qwt_plot_grid.h>
#include <qwt_legend.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>
#include <deque>
#include <Fixed.h>


typedef Fixed<1, 15> FixedFP;

namespace Ui {
class PlotDialog;
}

class PlotDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlotDialog(QWidget *parent = 0);
    void getPoints(std::deque<FixedFP> points);
    ~PlotDialog();

private:
    Ui::PlotDialog *ui;
    QwtPlot *plot;
    QwtPlotCurve *curve = nullptr;
};

#endif // PLOTDIALOG_H
