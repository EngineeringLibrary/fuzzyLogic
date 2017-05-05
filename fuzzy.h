#ifndef FUZZY_H
#define FUZZY_H

#include "SistemasdeControle/headers/modelLibs/model.h"
#include "triangular.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include <vector>
#include <map>

namespace ModelHandler {
    struct modelString
    {
        std::string str;
    public:
        modelString(){}
        ~modelString(){str.clear();}
        modelString(std::string str) {this->str = str;}
        std::string getString(){return this->str;}
        void setString(std::string str){this->str = str;}
    };

    template <typename Type>
        class Fuzzy: public Model<Type>
        {
//            LinAlg::Matrix<modelString> InputNames;
//            LinAlg::Matrix<advancedModelHandler::MembershipFunction<double>*> InputMF;
            std::map< std::string, std::map< std::string, advancedModelHandler::MembershipFunction<double>* > > InputMF;
//            LinAlg::Matrix<modelString> OutputNames;
//            LinAlg::Matrix<advancedModelHandler::MembershipFunction<double>*> OutputMF;
            std::map< std::string, std::map< std::string, advancedModelHandler::MembershipFunction<double>* > > OutputMF;
            LinAlg::Matrix<modelString> rules;
            LinAlg::Matrix<Type> fuzzyficatedValue;

        public:

            void addInputMF(std::string InputName,
                            std::string MFName,
                            advancedModelHandler::MembershipFunction<Type>* MF);

            std::map<std::string, advancedModelHandler::MembershipFunction<Type>*> getInputMF(std::string InputName);

            void addOutputMF(std::string OutputName,
                             std::string MFName,
                             advancedModelHandler::MembershipFunction<Type>* MF);

            void removeInputMF(unsigned nInput,
                            std::string MFName,
                            const advancedModelHandler::MembershipFunction<Type>* MF);
            void removeOutputMF(unsigned nOutput,
                            std::string MFName,
                            const advancedModelHandler::MembershipFunction<Type>* MF);


            void addRules(std::string rule);

            std::string viewRules();

            void removeRules();

            LinAlg::Matrix<Type> membershipFunctionPosition (std::map<std::string, std::map<std::string, advancedModelHandler::MembershipFunction<double> *> > &MF, const std::string &firstKey, const std::string &secondKey);
            LinAlg::Matrix<Type> membershipFunctionQuantities(std::map<std::string, std::map<std::string, advancedModelHandler::MembershipFunction<double> *> > &MF);

            unsigned getMaxNumberOfMembershipFunctions(std::map<std::__cxx11::string, std::map<std::__cxx11::string, advancedModelHandler::MembershipFunction<double> *> > &Input);

            LinAlg::Matrix<Type> fuzzyfication( LinAlg::Matrix<Type> Input);

            LinAlg::Matrix<Type> rulesExecute(LinAlg::Matrix<Type> fuzzyficatedValue);

            LinAlg::Matrix<Type> defuzzyfication(LinAlg::Matrix<Type> rulesMatrix);

            Type maxV(Type a, Type b);
            Type minV(Type a, Type b);

            Type         sim(Type x){}
            Type         sim(Type x, Type y){}
            LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x);
            LinAlg::Matrix<Type> sim(Type lmin, Type lmax, Type step){}
            LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x, LinAlg::Matrix<Type> y){}

            std::string print(){}
            unsigned getNumberOfVariables() const{}
            unsigned getNumberOfInputs() const{}
            unsigned getNumberOfOutputs() const{}
            void setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output){}
            void setLinearModel(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output){}

            Fuzzy(){}
        private:
//            getInputNames();
//            getMFNames(std::string InputName)

        };
}
#include "fuzzy.hpp"
#endif // FUZZY_H
