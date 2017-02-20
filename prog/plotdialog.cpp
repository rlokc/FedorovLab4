#include "plotdialog.h"
#include "ui_plotdialog.h"

PlotDialog::PlotDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlotDialog)
{
    ui->setupUi(this);
    ui->myPlot->setTitle("Filtered signal");
    ui->myPlot->setAxisTitle(QwtPlot::xBottom, "n");
    ui->myPlot->setAxisTitle(QwtPlot::yLeft, "A");

    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->attach(ui->myPlot);

}

PlotDialog::~PlotDialog()
{
    delete ui;
}

void PlotDialog::getPoints(std::deque<FixedFP> points)
{
    //Creating the curve from all the points we recieved
//    QwtPlotCurve *curve = new QwtPlotCurve();
    if (curve != nullptr)
        curve->detach();
    else
        curve = new QwtPlotCurve();
    curve->setRenderHint(QwtPlotItem::RenderAntialiased, true);

    QPolygonF curvePoints;
    for (int i=0; i<points.size(); i++)
    {
        curvePoints << QPointF(i, points[i].to_float());
    }

    curve->setSamples(curvePoints);
    curve->attach(ui->myPlot);
    ui->myPlot->replot();
}
