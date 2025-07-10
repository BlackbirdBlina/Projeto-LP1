#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <functional>

#include "calcDistance.h"
#include "corretor.h"
#include "imovel.h"
#include "agenda.h"

using namespace std;

int Corretor::nextId = 1;

Corretor::Corretor(string nome, string telefone, bool avaliador, double lat, double lng):
    id(Corretor::nextId++), nome(nome), telefone(telefone), avaliador(avaliador), lat(lat), lng(lng){

}

// Métodos getters necessários
int Corretor::getId(){
    return id;
}
string Corretor::getNome(){
    return nome;
}
bool Corretor::getAvaliador(){
    return avaliador;
}
double Corretor::getLat(){
    return lat;
}
double Corretor::getLng(){
    return lng;
}
vector<Agenda>& Corretor::getAgendas(){
    return agenda;
}

// Criando novas instâncias de corretor
vector<Corretor> lerCorretor(int quantidade){
    vector<Corretor> corretores;
    for (int i = 0; i < quantidade; ++i) {
        string tel, nome;
        int avaliador;
        double lat, lng;
        cin >> tel >> avaliador >> lat >> lng;
        getline(cin >> ws, nome);
        corretores.emplace_back(nome, tel, avaliador, lat, lng);
    }
    return corretores;
}


void agendamento(vector<reference_wrapper<Corretor>> &avaliadores, vector<Imovel> &imoveis){
    // Distribuição round-robin
    int indice = 0;
    for (Imovel& imovel : imoveis) {
        if (!avaliadores.empty()) {
            avaliadores[indice].get().getAgendas().emplace_back(imovel);
            indice = (indice + 1) % avaliadores.size();
        }
    }

    for (reference_wrapper<Corretor> corretores : avaliadores) {
        double latAtual = corretores.get().getLat();
        double lngAtual = corretores.get().getLng();
        int hora = 9;
        int minuto = 0;

        vector<Agenda>& agendas = corretores.get().getAgendas();
        vector<reference_wrapper<Agenda>> restantes;
        for (Agenda &agenda : agendas) {
            restantes.push_back(agenda);
        }


        while (!restantes.empty()) {
            auto iterador1 = restantes.begin();
            double distanciaMinima = haversine(latAtual, lngAtual, iterador1->get().getImovel().get().getLat(), iterador1->get().getImovel().get().getLng());

            for (auto iterador2 = restantes.begin() + 1; iterador2 != restantes.end(); ++iterador2) {
                double distancia = haversine(latAtual, lngAtual, iterador2->get().getImovel().get().getLat(), iterador2->get().getImovel().get().getLng());
                if (distancia < distanciaMinima) {
                    iterador1 = iterador2;
                    distanciaMinima = distancia;
                }
            }

            int deslocamento = static_cast<int>(distanciaMinima * 2);
            minuto += deslocamento;
            hora += minuto / 60;
            minuto %= 60;

            stringstream buffer;
            buffer << setfill('0') << setw(2) << hora << ":" << setw(2) << minuto;
            iterador1->get().setHora(buffer.str());

            minuto += 60;
            hora += minuto / 60;
            minuto %= 60;

            reference_wrapper<Imovel> escolhido = iterador1->get().getImovel();
            latAtual = escolhido.get().getLat();
            lngAtual = escolhido.get().getLng();
            restantes.erase(iterador1);
        }
    }
}
