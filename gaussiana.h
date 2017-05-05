#ifndef GAUSSIANA_H
#define GAUSSIANA_H
#include "membershipfunction.h"
#include <math.h>

namespace advancedModelHandler {
    template <typename Type>
    class gaussiana : public MembershipFunction<Type>
    {
        Type c, sigma;
    public:
        gaussiana(Type c, Type sigma);
        Type         sim(Type input);
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> input);
        Type getAverage(){return this->c;}
    };
}

#include "gaussiana.hpp"
#endif // GAUSSIANA_H
