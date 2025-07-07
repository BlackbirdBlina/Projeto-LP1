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
    Cliente(string nome, string telefone);
    void setId(int id);
    void setNome(string nome);
    void setTelefone(string telefone);

    ~Cliente() = default;

    int getId();
    string getNome();
    string getTelefone();

};

vector<Cliente> lerCliente(int quantidade);

#endif
