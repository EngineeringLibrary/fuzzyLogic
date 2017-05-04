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
LinAlg::Matrix<Type> ModelHandler::Fuzzy<Type>::rulesExecute(LinAlg::Matrix<Type> Output)
{
    // Onde Paramos: como definir quem é saida e regra no indice de ret;
    // verificar OR é min e AND é max?
    // Permitir o uso de maxV e minV
//    unsigned sizeOfRules = this->rules.size();
//    unsigned numberOfOutputs = this->outputMF.size();
    LinAlg::Matrix<Type> ret(this->OutputMF.size(),this->rules.getNumberOfRows()/2);
    for(unsigned i = 1; i <= this->rules.getNumberOfRows()/2; ++i)
    {
        if(this->rules(1,1).getString() == "and")
            continue;
        else if(this->rules(1,1).getString() == "or")
            continue;
        // Algoritmo aqui deve ser:
        // ret deve receber o valor correspondente a qual entrada estiver na string e/ou a outra entrada
        // saber qual entrada e saida está na regra
        // realizar as operações e ou ou
        // atribuir a ret na sequência: às saídas que as regras afetam;
    }
//    std::map<std::string, std::string>::reverse_iterator iter = this->rules[i].rbegin();
//    if(iter->first == "and")
//    {
//        iter++;
//        for(unsigned i = 1; i < sizeOfRules; i += 2)
//        {
//            std::map<std::string, std::string>::reverse_iterator iter = this->rules[i].rbegin();
//            for esse for é para iterar as entradas na regra
//            ret(saida,regra) = maxV(ret(saida,regra),this->InputMF[iter->first][iter->second].sim(Output));
//            iter++;
//        }
//    }
//    else if(iter->first == "or")
//    {
//        iter++;
//        for(unsigned i = 1; i < sizeOfRules; i += 2)
//        {
//            std::map<std::string, std::string>::reverse_iterator iter = this->rules[i].rbegin();
//            //            for esse for é para iterar as entradas na regra
//            ret(saida,regra) = minV(ret(saida,regra),this->InputMF[iter->first][iter->second].sim(Output));
//            iter++;
//        }
//    }
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
