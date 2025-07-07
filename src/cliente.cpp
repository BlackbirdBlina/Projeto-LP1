#include "cliente.h"
#include <iostream>
using namespace std;

int Cliente::nextId = 1;

Cliente::Cliente(string nome, string telefone):
    id(nextId++), nome(nome), telefone(telefone){
}

vector<Cliente> lerCliente(int quantidade){
    vector<Cliente> clientes;
    for (int i = 0; i < quantidade; ++i) {
        string tel, nome;
        cin >> tel;
        getline(cin >> ws, nome);
        clientes.emplace_back(tel, nome);
    }
    return clientes;
}
