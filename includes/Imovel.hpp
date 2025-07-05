#ifndef imovel_hpp
#define imovel_hpp
#include <string>
using namespace std;

static int nextIdImovel = 1;
class Imovel{
    private:
    int id;
    string nome;
    string telefone;
    bool avaliador;
    double lat;
    double lng;

    public:
    Imovel(string nome, float salarioBase, int id, int quantidadeDeProjetos);
    void setId(int id);
    void setNome(string nome);
    void setTelefone(string telefone);

    ~Imovel() = default;

    int getId();
    string getNome();
    string getTelefone();

};

#endif