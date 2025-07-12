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
    // Construtor
    Corretor(string nome, string telefone, bool avaliador, double lat, double lng);
    // Destrutor
    ~Corretor() = default;

    // Métodos setters e getters possíveis de serem implementados
    void setId(int id);
    void setNome(string nome);
    void setTelefone(string telefone);
    void setAvaliador(bool avaliador);
    void setLat(double lat);
    void setLng(double lng);

    int getId();
    string getNome();
    string getTelefone();
    bool getAvaliador();
    double getLat();
    double getLng();
    vector<Agenda>& getAgendas();

};

// Função a ser implementada para realizar a leitura dos dados informados nos arquivos .txt
vector<Corretor> lerCorretor(int quantidade);
// Função para realizar o "match" de avaliadores com os imóveis
void agendamento(vector<reference_wrapper<Corretor>> &avaliadores, vector<Imovel> &imoveis);

#endif
