#ifndef CORRETOR_HPP
#define CORRETOR_HPP
#include <string>
#include <vector>
#include <functional>
#include "agenda.h"
#include "imovel.h"

using namespace std;

class Corretor{
    private:
    int id;
    static int nextId;
    string nome;
    string telefone;
    bool avaliador;
    double lat;
    double lng;
    vector<Agenda> agenda;

    public:
    Corretor(string nome, string telefone, bool avaliador, double lat, double lng);
    void setId(int id);
    void setNome(string nome);
    void setTelefone(string telefone);
    void setAvaliador(bool avaliador);
    void setLat(double lat);
    void setLng(double lng);

    ~Corretor() = default;

    int getId();
    string getNome();
    string getTelefone();
    bool getAvaliador();
    double getLat();
    double getLng();
    vector<Agenda>& getAgendas();

};

vector<Corretor> lerCorretor(int quantidade);
void agendamento(vector<reference_wrapper<Corretor>> &avaliadores, vector<Imovel> &imoveis);

#endif
