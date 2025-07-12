#include <iostream>
#include <vector>
#include <functional>

#include "corretor.h"
#include "cliente.h"
#include "imovel.h"
#include "agenda.h"

using namespace std;

int main() {
    int numCorretores;
    cin >> numCorretores;
    vector<Corretor> corretores = lerCorretor(numCorretores);

    vector<reference_wrapper<Corretor>> avaliadores;
    for (auto &corretor : corretores) {
        if (corretor.getAvaliador()) {
            avaliadores.push_back(corretor);
        }
    }

    int numClientes;
    cin >> numClientes;
    vector<Cliente> clientes = lerCliente(numClientes);

    int numImoveis;
    cin >> numImoveis;
    vector<Imovel> imoveis = lerImovel(numImoveis);

    agendamento(avaliadores, imoveis);

    for (reference_wrapper<Corretor> &avaliador : avaliadores){
        cout << "Corretor " << avaliador.get().getId() << endl;
        for (Agenda &agenda : avaliador.get().getAgendas()){
            cout << agenda.getHora() << " Imóvel " << agenda.getImovel().get().getId() << endl;
        }
        cout << endl;
    }

    return 0;
}