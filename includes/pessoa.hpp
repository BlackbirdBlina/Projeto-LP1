#ifndef pessoa_hpp
#define pessoa_hpp
#include <string>
using namespace std;

class Pessoa{
    private:
    int id;
    string nome;
    string telefone;

    protected:
    void setId(int id);
    void setNome(string nome);
    void setTelefone(string telefone);

    public:
    Pessoa(int id, string nome, string telefone);

    ~Pessoa() = default;

    int getId();
    string getNome();
    string getTelefone();

};

#endif

