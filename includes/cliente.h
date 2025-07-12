#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <string>
#include <vector>
using namespace std;

class Cliente{
    private:
    int id;
    static int nextId;
    string nome;
    string telefone;

    public:
    // Construtor
    Cliente(string nome, string telefone);

    // Destrutor
    ~Cliente() = default;

    // Métodos setters e getters a serem implementados se necessário
    // void setId(int id);
    // void setNome(string nome);
    // void setTelefone(string telefone);

    // int getId();
    // string getNome();
    // string getTelefone();

};

// Função de leitura para cliente se necessário
vector<Cliente> lerCliente(int quantidade);

#endif
