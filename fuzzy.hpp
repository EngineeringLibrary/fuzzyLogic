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
LinAlg::Matrix<Type> ModelHandler::Fuzzy<Type>::membershipFunctionQuantities(std::map<std::string, std::map<std::string, advancedModelHandler::MembershipFunction<double> *> > &MF)
{
    std::map< std::string, std::map< std::string, advancedModelHandler::MembershipFunction<double>* > >::reverse_iterator iter = MF.rbegin();
    unsigned n = MF.size();
    LinAlg::Matrix<Type> ret(n,1);
    for(unsigned i = 1; i <= n; ++i)
    {
        ret(i,1) = iter->second.size();
        iter++;
    }
    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::Fuzzy<Type>::membershipFunctionPosition(std::map<std::string, std::map<std::string, advancedModelHandler::MembershipFunction<double> *> > &MF, const std::string &firstKey, const std::string &secondKey)
{
    std::map< std::string, std::map< std::string, advancedModelHandler::MembershipFunction<double>* > >::reverse_iterator iterInputs = MF.rbegin();
    unsigned n = MF.size();
    LinAlg::Matrix<Type> ret(1,2);
    for(unsigned i = 1; i <= n; ++i)
    {
        if(iterInputs->first == firstKey)
        {
            ret(1,1) = i;
            std::map< std::string, advancedModelHandler::MembershipFunction<double>* >::reverse_iterator iterMF = iterInputs->second.rbegin();
            unsigned n2 = iterInputs->second.size();
            for(unsigned j = 1; j <= n2; ++j)
            {
                if(iterMF->first == secondKey)
                {
                    ret(1,2) = j;
                    return ret;
                }
                iterMF++;
            }
        }
        iterInputs++;
    }
    return ret;
}

template <typename Type>
void ModelHandler::Fuzzy<Type>::addOutputMF(std::string OutputName,
                                            std::string MFName,
                                            advancedModelHandler::MembershipFunction<Type> *MF){
    if(this->OutputMF.count(OutputName.c_str()) != 0){
        if(this->OutputMF[OutputName].count(MFName.c_str()) != 0){
            std::cout << "Variavel existente: " << MFName;
        }else{
            this->OutputMF[OutputName][MFName] = MF;
        }
    }else{
        std::map<std::string, advancedModelHandler::MembershipFunction<Type>* > MFMap;
        MFMap[MFName] = MF;
        this->OutputMF[OutputName] = MFMap;
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
    //Ex and,Comida:doce,Bebida:Ruim,Saida:seMata

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

template <typename Type>
void ModelHandler::Fuzzy<Type>::addRules(std::string rule)
{
    LinAlg::Matrix<modelString> ret;

    while(!(rule.empty()))
    {
        int partRulePosition = rule.find(",");
        std::string partRule;
        if(partRulePosition != -1)
            partRule = rule.substr(0, partRulePosition);
        else
        {
            partRule = rule;
            partRulePosition = rule.length();
        }

        int colonPosition = partRule.find(":");
        if(colonPosition == -1)
        {
            LinAlg::Matrix<modelString> temp = LinAlg::Matrix<modelString>(modelString(partRule))||modelString("   ");
            ret = ret|temp;
        }
        else
        {
            std::string InOut = partRule.substr(0, colonPosition);
            std::string MF = partRule.substr(colonPosition + 1);
            LinAlg::Matrix<modelString> temp = LinAlg::Matrix<modelString>(modelString(InOut))||modelString(MF);
            ret = ret|temp;
        }
        rule.erase(0, partRulePosition + 1);
    }
    rules = rules||ret;
}

template <typename Type>
std::string ModelHandler::Fuzzy<Type>::viewRules()
{
    std::string str;
    for(unsigned i = 1; i <= rules.getNumberOfRows(); i+=2)
    {
        for(unsigned j = 1; j <= rules.getNumberOfColumns(); ++j)
        {
            str += rules(i,j).getString();
            str += ":";
            str += rules(i+1,j).getString();
            str += "\n";
        }
    }
    return str;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::Fuzzy<Type>::rulesExecute(LinAlg::Matrix<Type> fuzzyficatedValue)
{
    unsigned sumOfMFOutputs = 0;
    LinAlg::Matrix<Type> outputQuantities = membershipFunctionQuantities(this->OutputMF);
    for(unsigned i = 1; i <= outputQuantities.getNumberOfRows(); ++i)
        sumOfMFOutputs += outputQuantities(i,1);

    LinAlg::Matrix<Type> ret(sumOfMFOutputs, this->rules.getNumberOfRows()/2);

    for(unsigned i = 1; i <= this->rules.getNumberOfRows(); i += 2)
    {
        Type tempMFValue;
        for(unsigned j = 2; j <= rules.getNumberOfColumns(); ++j)
        {
            LinAlg::Matrix<Type> inputPosition = this->membershipFunctionPosition(this->InputMF,this->rules(i,j).getString(),this->rules(i+1,j).getString());
            if(!LinAlg::isEqual(inputPosition,LinAlg::Matrix<Type>("0,0")))
            {
                if(j == 2)
                    tempMFValue = fuzzyficatedValue(inputPosition(1,1),inputPosition(1,2));
                else if(this->rules(i,1).getString() == "and")
                    tempMFValue = this->minV(tempMFValue,fuzzyficatedValue(inputPosition(1,1),inputPosition(1,2)));
                else if(this->rules(i,1).getString() == "or")
                    tempMFValue = this->maxV(tempMFValue,fuzzyficatedValue(inputPosition(1,1),inputPosition(1,2)));

                continue;
            }

            LinAlg::Matrix<Type> outputPosition = this->membershipFunctionPosition(this->OutputMF,this->rules(i,j).getString(),this->rules(i+1,j).getString());
            if(!LinAlg::isEqual(outputPosition,LinAlg::Matrix<Type>("0,0")))
            {
                sumOfMFOutputs = 0;
                for(unsigned k = 2; k <= outputPosition(1,1); ++k)
                    sumOfMFOutputs += outputQuantities(k-1,1);
                ret(outputPosition(1,2) + sumOfMFOutputs,(i+1)/2) = tempMFValue;
            }
        }
    }
    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::Fuzzy<Type>::defuzzyfication(LinAlg::Matrix<Type> rulesMatrix)
{
    LinAlg::Matrix<Type> outputQuantities = membershipFunctionQuantities(this->OutputMF);
    LinAlg::Matrix<double> ret(outputQuantities.getNumberOfRows(),1);
    std::map< std::string, std::map< std::string, advancedModelHandler::MembershipFunction<double>* > >::reverse_iterator iterOutputs = this->OutputMF.rbegin();
    unsigned counter = 1;
    for(unsigned i = 1; i <= outputQuantities.getNumberOfRows(); ++i)
    {
        std::map< std::string, advancedModelHandler::MembershipFunction<double>* >::reverse_iterator iter = iterOutputs->second.rbegin();
        unsigned n2 = iterOutputs->second.size();
        Type den = 0, num = 0;
        for(unsigned j = 1; j <= n2; ++j)
        {
            for(unsigned k = 1; k <= rulesMatrix.getNumberOfColumns(); ++k)
            {
                num += rulesMatrix(counter,k)*iter->second->getAverage();
                den += rulesMatrix(counter,k);
            }
            counter++;
            iter++;
        }
        if(den != 0)
            ret(i,1) = num/den;
        iterOutputs++;
    }
    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::Fuzzy<Type>::sim(LinAlg::Matrix<Type> x)
{
    this->fuzzyficatedValue = this->fuzzyfication(x);
    return this->defuzzyfication(this->rulesExecute(this->fuzzyficatedValue));
}

template <typename Type>
Type ModelHandler::Fuzzy<Type>::maxV(Type a, Type b)
{
    if(a < b)
            return b;
        else
            return a;
}

template <typename Type>
Type ModelHandler::Fuzzy<Type>::minV(Type a, Type b)
{
    if(a > b)
        return b;
    else
        return a;
}

