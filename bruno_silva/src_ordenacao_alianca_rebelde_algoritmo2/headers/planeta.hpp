#ifndef TP_PLANETA
#define TP_PLANETA
#include <string>

namespace TP {
    
    class Planeta {
        private:
            
            std::string nomePlaneta;
            int distanciaPlaneta;
            int populacaoPlaneta;

        public:

            Planeta();
            Planeta(std::string nomePlaneta, int distanciaPlaneta, int populacaoPlaneta);

            std::string getNomePlaneta();
            int getDistanciaPlaneta();
            int getPopulacaoPlaneta();

            void setNomePlaneta(std::string nomePlaneta);
            void setDistanciaPlaneta(int distanciaPlaneta);
            void setPopulacaoPlaneta(int populacaoPlaneta);

    };
}

#endif