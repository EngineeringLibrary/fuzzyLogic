#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <SistemasdeControle/headers/modelLibs/transferfunction.h>
#include <SistemasdeControle/headers/graphicLibs/plot.h>
#include <vector>
#include "fuzzy.h"
#include "triangular.h"

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
    void on_simularButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    identifyVar(std::string str);
    calTF(std::string valor);
    PlotHandler::plot<double> *plotyG1;
    PlotHandler::plot<double> *plotyG2;
    std::vector<std::string> x;
    std::vector<std::string> y;
};

#endif // MAINWINDOW_H
