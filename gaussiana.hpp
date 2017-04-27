#include "gaussiana.h"

template <typename Type>
advancedModelHandler::gaussiana<Type>::gaussiana(Type c, Type sigma)
{
    this->c = c;
    this->sigma = sigma;
}

template <typename Type>
Type advancedModelHandler::gaussiana<Type>::sim(Type input)
{
        return exp((-pow((input-this->c),2) /(pow((2 + this->sigma),2))));
}

template <typename Type>
LinAlg::Matrix<Type> advancedModelHandler::gaussiana<Type>::sim(LinAlg::Matrix<Type> input)
{
    for(unsigned i = 1; i <= input.getNumberOfRows(); ++i)
           for(unsigned j = 1; j <= input.getNumberOfColumns(); ++j)
                input(i,j) = this->sim(input(i,j));

        return input;
}
