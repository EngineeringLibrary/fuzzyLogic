#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_simularButton_clicked()
{
    identifyVar(ui->lineEquacao->text().toStdString());
}

void MainWindow::calTF(std::string valor){

    std::string pol = valor;
    std::string num = pol.substr(0,pol.find('/'));
    std::string den = pol.substr(pol.find('/')+1);

    ModelHandler::TransferFunction<double> TF(num,den);
    std::string str; str << TF;

    ui->textResult->append(str.c_str());

    LinAlg::Matrix<double> U = ui->lineValorVar->text().toStdString();
    plotyG1 = new PlotHandler::plot<double> (U, ui->widget);

    LinAlg::Matrix<double> Y = TF.sim(U);
    plotyG2 = new PlotHandler::plot<double> (Y, ui->widget_2);
}

void MainWindow::identifyVar(std::string str)
{
    std::size_t pos = str.find('=');
    std::string var = str.substr(0,pos);
    std::string value = str.substr(pos+1);

    x.push_back(var);
    y.push_back(value);

//    ui->textResult->append(x[0].c_str());
//    ui->textResult->append(y[0].c_str());

    calTF(y[0]);
}

void MainWindow::on_pushButton_clicked()
{
    ModelHandler::Fuzzy<double> F;
    F.addInputMF("Comida","salgada", new advancedModelHandler::triangular<double>(1,2,3));
    F.addInputMF("Comida","doce", new advancedModelHandler::triangular<double>(3,4,5));
    F.addInputMF("Comida","Azeda", new advancedModelHandler::triangular<double>(5,6,7));

    F.addInputMF("Bebida","ruim", new advancedModelHandler::triangular<double>(1,2,3));
    F.addInputMF("Bebida","boa ", new advancedModelHandler::triangular<double>(3,4,5));
    F.addInputMF("Bebida","+o- ", new advancedModelHandler::triangular<double>(5,6,7));

    F.addOutputMF("Jogar","Fora", new advancedModelHandler::triangular<double>(5,6,7));
    F.addOutputMF("Jogar","Dentro", new advancedModelHandler::triangular<double>(3,4,5));

    F.addRules("or,Comida:salgada,Bebida:ruim,Jogar:Fora");
    F.addRules("or,Comida:salgada,Bebida:boa,Jogar:Dentro");

    std::string str; str << F.sim(ui->lineEdit->text().toStdString().c_str());
    ui->textEdit->append(str.c_str());

//    std::cout << F.fuzzyfication("1.5;1.5") << std::endl;
//    LinAlg::Matrix<double> rules = F.rulesExecute();
//    std::cout << rules << std::endl;
//    std::cout << F.defuzzyfication(rules) << std::endl;
//    ui->textEdit->append(F.viewRules().c_str());
}
