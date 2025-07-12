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

// Artifício para gerar Ids auto-incrementados
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
        // Populando o vetor de corretores a partir das informações passadas
        corretores.emplace_back(nome, tel, avaliador, lat, lng);
    }
    return corretores;
}

// Implementação da função de agendamento
void agendamento(vector<reference_wrapper<Corretor>> &avaliadores, vector<Imovel> &imoveis){
    // Distribuição round-robin (sem hora definida ainda!)
    int indice = 0;
    for (Imovel& imovel : imoveis) {
        if (!avaliadores.empty()) {
            avaliadores[indice].get().getAgendas().emplace_back(imovel);
            // Índice circular. Faz com que um imóvel seja atribuído a um avaliador mesmo que a quantidade de avaliadores seja menor.
            indice = (indice + 1) % avaliadores.size();
        }
    }

    /* Percorrendo vetor de referências para corretor (avaliadores), verificando a latitude e longitude de cada um deles,
    com o objetivo de definir a hora de visitação do imóvel*/
    for (reference_wrapper<Corretor> avaliador : avaliadores) {
        // Capturando a posição dos avaliadores
        double latAtual = avaliador.get().getLat();
        double lngAtual = avaliador.get().getLng();
        // Estabelecendo início do horário exigido
        int hora = 9;
        int minuto = 0;

        // Salvando em agendas as informações que referenciam o vetor de agenda (sem hora definida ainda!)
        vector<Agenda>& agendas = avaliador.get().getAgendas();
        // Vetor auxiliar para salvar as agendas (será limpado após a definição da hora)
        vector<reference_wrapper<Agenda>> restantes;
        for (Agenda &agenda : agendas) {
            // Salvando no vetor de agendas os imóveis a partir da localização dos corretores e avaliadores
            restantes.push_back(agenda);
        }

        // Laço para definir a hora em que cada corretor/avaliador precisa visitar o imóvel
        while (!restantes.empty()) {
            // Criando iterador para remover elementos de forma segura enquanto está iterando/percorrendo o vetor de agendas restantes
            vector<reference_wrapper<Agenda>>::iterator iterador1 = restantes.begin();
            double distanciaMinima = haversine(latAtual, lngAtual, iterador1->get().getImovel().get().getLat(), iterador1->get().getImovel().get().getLng());

            // Verificando e capturando a menor distância entre o corretor/avaliador e o imóvel
            for (vector<reference_wrapper<Agenda>>::iterator  iterador2 = restantes.begin() + 1; iterador2 != restantes.end(); ++iterador2) {
                double distancia = haversine(latAtual, lngAtual, iterador2->get().getImovel().get().getLat(), iterador2->get().getImovel().get().getLng());
                if (distancia < distanciaMinima) {
                    iterador1 = iterador2;
                    distanciaMinima = distancia;
                }
            }

            // Calculando o tempo que será gasto para chegar no imóvel (qual horá o corretor/avaliador deve chegar no imóvel)
            int deslocamento = static_cast<int>(distanciaMinima * 2);
            minuto += deslocamento;
            hora += minuto / 60;
            minuto %= 60;

            // Formatando a hora calculada em formato exigido
            stringstream buffer;
            buffer << setfill('0') << setw(2) << hora << ":" << setw(2) << minuto;
            /* Salvando em iterador1 (vetor de referência que aponta para uma referência que referencia a agenda de um corretor)
            a hora que o corretor/avaliador deve chegar ao imóvel*/
            iterador1->get().setHora(buffer.str());

            // Tempo de visita
            minuto += 60;
            hora += minuto / 60;
            minuto %= 60;

            // Atualizando a posição do corretor para calcular o local e hora do próximo imóvel a ser visitado
            reference_wrapper<Imovel> escolhido = iterador1->get().getImovel();
            latAtual = escolhido.get().getLat();
            lngAtual = escolhido.get().getLng();
            // Exclui do vetor o imóvel já visitado
            restantes.erase(iterador1);
        }
    }
}
