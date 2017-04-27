#ifndef MEMBERSHIPFUNCTION_H
#define MEMBERSHIPFUNCTION_H
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

namespace advancedModelHandler {
    template <typename Type>
    class MembershipFunction
    {
    public:
        MembershipFunction(){}
        virtual Type         sim(Type x) = 0;
        virtual LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x) = 0;

    protected:
        Type maxV(Type a, Type b)
        {
            if(a < b)
                return b;
            else
                return a;
        }

        Type minV(Type a, Type b)
        {
            if(a > b)
                return b;
            else
                return a;
        }
    };
}



//namespace membershipFunction {

//    double triangular(double input, LinAlg::Matrix<double> left2rigth);
//    double trapezoidal(double input, LinAlg::Matrix<double> left2rigth);
//    double gaussiana(double input, LinAlg::Matrix<double> left2rigth);
//    double maxV(double a,double b);
//    double minV(double a,double b);

//}

#endif // MEMBERSHIPFUNCTION_H
