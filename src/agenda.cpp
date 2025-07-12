#include <functional>

#include "imovel.h"
#include "agenda.h"
using namespace std;

Agenda::Agenda(reference_wrapper<Imovel> imovel): imovel(imovel), hora(""){

}

void Agenda::setHora(string hora){
    this->hora = hora;
}

string Agenda::getHora(){
    return hora;
}

reference_wrapper<Imovel> Agenda::getImovel(){
    return imovel;
}
