#ifndef CORRETOR_HPP
#define CORRETOR_HPP
#include <string>
#include <vector>
#include <functional>
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

};

vector<Corretor> lerCorretor(int quantidade, vector<reference_wrapper<Corretor>> &avaliadores);

#endif
