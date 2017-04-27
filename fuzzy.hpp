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
