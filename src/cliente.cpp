#include "cliente.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

// Artifício para gerar Ids auto-incrementados
int Cliente::nextId = 1;

Cliente::Cliente(string nome, string telefone):
    id(nextId++), nome(nome), telefone(telefone){
}

// Cria novas instâncias de Cliente
vector<Cliente> lerCliente(int quantidade){
    vector<Cliente> clientes;
    for (int i = 0; i < quantidade; ++i) {
        string tel, nome;
        cin >> tel;
        getline(cin >> ws, nome);
        // Popula vetor de clientes a partir das informações passadas
        clientes.emplace_back(nome, tel);
    }
    // Retorna vetor preenchido
    return clientes;
}
