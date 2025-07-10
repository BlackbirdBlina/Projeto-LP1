#ifndef AGENDA_HPP
#define AGENDA_HPP
#include <string>
#include <functional>

#include "imovel.h"

using namespace std;

class Agenda{
    private:
    reference_wrapper<Imovel> imovel;
    string hora;


    public:
    Agenda(reference_wrapper<Imovel> imovel);
    void setHora(string hora);

    ~Agenda() = default;

    string getHora();
    reference_wrapper<Imovel> getImovel();

};



#endif
