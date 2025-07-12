#include <functional>

#include "imovel.h"
#include "agenda.h"
using namespace std;

// Construtor
Agenda::Agenda(reference_wrapper<Imovel> imovel): imovel(imovel), hora(""){

}

// Define o horário da agenda
void Agenda::setHora(string hora){
    this->hora = hora;
}

// Retorna o horário atualmente armazenado na agenda
string Agenda::getHora(){
    return hora;
}

// Retorna a referência para o imóvel associado a essa agenda
reference_wrapper<Imovel> Agenda::getImovel(){
    return imovel;
}
