//#include "membershipfunction.h"

//double membershipfunction::FuncTriangular(double input, LinAlg::Matrix<double> left2rigth)
//{
//    double leftLimit = left2rigth(1,1);
//    double peak = left2rigth(1,2);
//    double rigthLimite = left2rigth(1,3);

//    return maxV(minV((input - leftLimit)/(peak-leftLimit),
//                     (rigthLimite - input)/(rigthLimite - peak)),0);

//}

//double membershipfunction::FuncTrapezoidal(double input, LinAlg::Matrix<double> left2rigth)
//{
//    double leftLimit = left2rigth(1,1);
//    double peak1 = left2rigth(1,2);
//    double peak2 = left2rigth(1,3);
//    double rigthLimite = left2rigth(1,4);

//    return maxV(minV((input - leftLimit)/(peak1-leftLimit),
//                     (rigthLimite - input)/(rigthLimite-peak2)),0);

//}

//double membershipfunction::FuncGaussiana(double input, LinAlg::Matrix<double> left2rigth)
//{
//    double c = left2rigth(1,1);
//    double sigma = left2rigth(1,2);

//    return exp((-pow((input-c),2) /(pow((2 + sigma),2))));
//}

//double membershipfunction::maxV(double a, double b)
//{
//    if(a < b)
//        return b;
//    else
//        return a;
//}

//double membershipfunction::minV(double a, double b)
//{
//    if(a > b)
//        return b;
//    else
//        return a;
//}

