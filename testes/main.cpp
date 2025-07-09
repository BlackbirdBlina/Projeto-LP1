#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <functional>
#include "corretor.h"
#include "cliente.h"
#include "imovel.h"
#include "calcDistance.h"
using namespace std;

int main() {
    int numCorretores;
    cin >> numCorretores;
    vector<reference_wrapper<Corretor>> avaliadores;
    vector<Corretor> corretores = lerCorretor(numCorretores, avaliadores);


    int numClientes;
    cin >> numClientes;
    vector<Cliente> clientes = lerCliente(numClientes);


    int numImoveis;
    cin >> numImoveis;
    vector<Imovel> imoveis = lerImovel(numImoveis);


    // // Distribuição round-robin
    // int idx = 0;
    // for (Imovel& im : imoveis) {
    //     if (!avaliadores.empty()) {
    //         avaliadores[idx]->agenda.push_back(&im);
    //         idx = (idx + 1) % avaliadores.size();
    //     }
    // }

    // for (Corretor* c : avaliadores) {
    //     cout << "Corretor " << c->id << endl;
    //     double curLat = c->lat, curLng = c->lng;
    //     int hora = 9, minuto = 0;

    //     vector<Imovel*> restantes = c->agenda;

    //     while (!restantes.empty()) {
    //         auto it = restantes.begin();
    //         double minDist = haversine(curLat, curLng, (*it)->lat, (*it)->lng);

    //         for (auto jt = restantes.begin() + 1; jt != restantes.end(); ++jt) {
    //             double d = haversine(curLat, curLng, (*jt)->lat, (*jt)->lng);
    //             if (d < minDist) {
    //                 it = jt;
    //                 minDist = d;
    //             }
    //         }

    //         Imovel* escolhido = *it;
    //         restantes.erase(it);

    //         int deslocamento = static_cast<int>(round(minDist * 2));
    //         minuto += deslocamento;
    //         hora += minuto / 60;
    //         minuto %= 60;

    //         cout << setfill('0') << setw(2) << hora << ":"
    //              << setw(2) << minuto << " Imóvel " << escolhido->id << endl;

    //         minuto += 60;
    //         hora += minuto / 60;
    //         minuto %= 60;

    //         curLat = escolhido->lat;
    //         curLng = escolhido->lng;
    //     }
    //     cout << endl;
    // }
    return 0;
}
