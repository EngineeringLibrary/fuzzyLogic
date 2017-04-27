#include "trapezoidal.h"

template <typename Type>
advancedModelHandler::trapezoidal<Type>::trapezoidal(Type leftLimit, Type rigthLimit, Type peak1, Type peak2)
{
    this->leftLimit = leftLimit;
    this->rigthLimit = rigthLimit;
    this->peak1 = peak1;
    this->peak2 = peak2;
}

template <typename Type>
Type advancedModelHandler::trapezoidal<Type>::sim(Type input)
{
        return this->maxV(this->minV((input -  this->leftLimit)/(this->peak1-this->leftLimit),
                             (this->rigthLimit - input)/(this->rigthLimit - this->peak2)),0);

}

template <typename Type>
LinAlg::Matrix<Type> advancedModelHandler::trapezoidal<Type>::sim(LinAlg::Matrix<Type> input)
{
    for(unsigned i = 1; i <= input.getNumberOfRows(); ++i)
           for(unsigned j = 1; j <= input.getNumberOfColumns(); ++j)
                input(i,j) = this->sim(input(i,j));

        return input;
}
