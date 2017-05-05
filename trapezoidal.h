#ifndef TRAPEZOIDAL_H
#define TRAPEZOIDAL_H
#include "membershipfunction.h"

namespace advancedModelHandler {
    template <typename Type>
    class trapezoidal : public MembershipFunction<Type>
    {
        Type leftLimit, rigthLimit, peak1, peak2;
    public:
        trapezoidal(Type leftLimit, Type rigthLimit, Type peak1, Type peak2);
        Type         sim(Type x);
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x);
        Type getAverage(){ return (this->peak1 + this->peak2)/2; }
    };
}

#include "trapezoidal.hpp"
#endif // TRAPEZOIDAL_H
