#include "corretor.h"
#include <iostream>
#include <vector>
using namespace std;

int Corretor::nextId = 1;

Corretor::Corretor(string nome, string telefone, bool avaliador, double lat, double lng):
    id(nextId++), nome(nome), telefone(telefone), avaliador(avaliador), lat(lat), lng(lng){

}

// Criando novas instâncias de corretor
vector<Corretor> lerCorretor(int quantidade, vector<reference_wrapper<Corretor>> &avaliadores){
    vector<Corretor> corretores;
    for (int i = 0; i < quantidade; ++i) {
        string tel, nome;
        int avaliador;
        double lat, lng;
        cin >> tel >> avaliador >> lat >> lng;
        getline(cin >> ws, nome);
        corretores.emplace_back(nome, tel, avaliador, lat, lng);
        if (avaliador){
            avaliadores.push_back(corretores.back());
        }
    }
    return corretores;
}
