#include "triangular.h"

template <typename Type>
advancedModelHandler::triangular<Type>::triangular(Type leftLimit,Type peak, Type rigthLimit)
{
    this->leftLimit = leftLimit;
    this->peak = peak;
    this->rigthLimit = rigthLimit;
}

template <typename Type>
Type advancedModelHandler::triangular<Type>::sim(Type x)
{
        return this->maxV(this->minV((x - this->leftLimit)/(this->peak-this->leftLimit),
                         (this->rigthLimit - x)/(this->rigthLimit - this->peak)),0);

}

template <typename Type>
LinAlg::Matrix<Type> advancedModelHandler::triangular<Type>::sim(LinAlg::Matrix<Type> x)
{
    for(unsigned i = 1; i <= x.getNumberOfRows(); ++i)
           for(unsigned j = 1; j <= x.getNumberOfColumns(); ++j)
                x(i,j) = this->sim(x(i,j));

        return x;
}
