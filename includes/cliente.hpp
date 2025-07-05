#ifndef cliente_hpp
#define cliente_hpp
#include <string>
using namespace std;

static int nextIdCliente = 1;
class Cliente{
    private:
    int id;
    string nome;
    string telefone;

    public:
    Cliente(int id, string nome, string telefone);
    void setId(int id);
    void setNome(string nome);
    void setTelefone(string telefone);

    ~Cliente() = default;

    int getId();
    string getNome();
    string getTelefone();

};

#endif
