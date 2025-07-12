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
    // Populando o vetor de corretores
    vector<Corretor> corretores = lerCorretor(numCorretores);

    // Populando vetor de referências para corretores que também são avaliadores
    vector<reference_wrapper<Corretor>> avaliadores;
    for (Corretor &corretor : corretores) {
        if (corretor.getAvaliador()) {
            avaliadores.push_back(corretor);
        }
    }

    int numClientes;
    cin >> numClientes;
    // Popula vetor de clientes se necessário
    vector<Cliente> clientes = lerCliente(numClientes);

    int numImoveis;
    cin >> numImoveis;
    // Populando vetor de imoveis
    vector<Imovel> imoveis = lerImovel(numImoveis);

    // Chamando a função para "casar" avaliador -> imóvel gerando a agenda para cada um deles
    agendamento(avaliadores, imoveis);

    // Exibindo os resultados
    for (reference_wrapper<Corretor> &avaliador : avaliadores){
        cout << "Corretor " << avaliador.get().getId() << endl;
        for (Agenda &agenda : avaliador.get().getAgendas()){
            cout << agenda.getHora() << " Imóvel " << agenda.getImovel().get().getId() << endl;
        }
        cout << endl;
    }

    return 0;
}
