#include "fuzzy.h"

template <typename Type>
void ModelHandler::Fuzzy<Type>::addInputMF(std::string InputName, std::string MFName, advancedModelHandler::MembershipFunction<Type> *MF){
    if(this->InputMF.count(InputName.c_str()) != 0){
        if(this->InputMF[InputName].count(MFName.c_str()) != 0){
            std::cout << "Variavel existente: " << MFName;
        }else{
            this->InputMF[InputName][MFName] = MF;
        }
    }else{
        std::map<std::string, advancedModelHandler::MembershipFunction<Type>* > MFMap;
        MFMap[MFName] = MF;
        this->InputMF[InputName] = MFMap;
    }

}

template <typename Type>
std::map<std::string, advancedModelHandler::MembershipFunction<Type>* > ModelHandler::Fuzzy<Type>::getInputMF(std::string InputName){
    return this->InputMF[InputName];
}

template<typename Type>
unsigned ModelHandler::Fuzzy<Type>::getMaxNumberOfMembershipFunctions(std::map< std::string, std::map< std::string, advancedModelHandler::MembershipFunction<double>*>> &Input)
{
    unsigned n = 0;

    for(std::map< std::string, std::map< std::string, advancedModelHandler::MembershipFunction<double>*>>::iterator iter = Input.begin(); iter != Input.end(); ++iter)
    {
        if(iter->second.size() > n)
            n = iter->second.size();
    }
    return n;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::Fuzzy<Type>::fuzzyfication( LinAlg::Matrix<Type> Input)
{
    unsigned n = Input.getNumberOfRows();
    unsigned n2 = this->getMaxNumberOfMembershipFunctions(this->InputMF);
    LinAlg::Matrix<Type> ret(n,n2);// Cada linha é uma entrada e cada coluna nessa linha é uma função de pertinência.
                                     // A matriz ret armazenará os valores fuzzificados nessa forma

    std::map< std::string, std::map< std::string, advancedModelHandler::MembershipFunction<double>* > >::reverse_iterator iterInputs = this->InputMF.rbegin();
    for(unsigned i = 1; i <= n; ++i)
    {
        std::map< std::string, advancedModelHandler::MembershipFunction<double>* >::reverse_iterator iterMF = iterInputs->second.rbegin();
        unsigned n2 = iterInputs->second.size();
        for(unsigned j = 1; j <= n2; ++j)
        {
            ret(i,j) = iterMF->second->sim(Input(i,1));
            iterMF++;
        }
        iterInputs++;
    }
    return ret;
}
