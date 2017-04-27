#ifndef TRIANGULAR_H
#define TRIANGULAR_H
#include "membershipfunction.h"

namespace advancedModelHandler {
    template <typename Type>
    class triangular : public MembershipFunction<Type>
    {
        Type leftLimit, rigthLimit, peak;
    public:
        triangular(Type leftLimit, Type rigthLimit, Type peak);
        Type         sim(Type x);
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x);
    };
}

#include "triangular.hpp"
#endif // TRIANGULAR_H
