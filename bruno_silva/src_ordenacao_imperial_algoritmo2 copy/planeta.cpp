#include "headers/planeta.hpp"

using namespace TP;

Planeta::Planeta() : Planeta ("",0,0){}

Planeta::Planeta(std::string nomePlaneta, int distanciaPlaneta, int populacaoPlaneta){
    this->nomePlaneta = nomePlaneta;
    this->distanciaPlaneta = distanciaPlaneta;
    this->populacaoPlaneta = populacaoPlaneta;
}

std::string Planeta::getNomePlaneta(){
    return this->nomePlaneta;
}

int Planeta::getDistanciaPlaneta(){
    return this->distanciaPlaneta;
}

int Planeta::getPopulacaoPlaneta(){
    return this->populacaoPlaneta;
}

void Planeta::setNomePlaneta(std::string nomePlaneta){
    this->nomePlaneta = nomePlaneta;
}

void Planeta::setDistanciaPlaneta(int distanciaPlaneta){
    this->distanciaPlaneta = distanciaPlaneta;
}
void Planeta::setPopulacaoPlaneta(int populacaoPlaneta){
    this->populacaoPlaneta = populacaoPlaneta;
}

