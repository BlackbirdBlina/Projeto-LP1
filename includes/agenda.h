#ifndef AGENDA_HPP
#define AGENDA_HPP
#include <string>
#include <functional>

#include "imovel.h"

using namespace std;

// Classe que associa o imovel a um horário
class Agenda{
    private:
    reference_wrapper<Imovel> imovel; // Referência para um objeto Imovel
    string hora;

    public:
    // Construtor
    Agenda(reference_wrapper<Imovel> imovel);

    // Método para definir o horário
    void setHora(string hora);

    // Destrutor
    ~Agenda() = default;

    // Retorna o horário
    string getHora();

    // Retorna a referência para o imovel associado
    reference_wrapper<Imovel> getImovel();

};

#endif