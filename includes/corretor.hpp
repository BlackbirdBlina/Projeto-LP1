#ifndef corretor_hpp
#define corretor_hpp
#include <string>
using namespace std;

static int nextIdCorretor = 1;
class Corretor{
    private:
    int id;
    string nome;
    string telefone;
    bool avaliador;
    double lat;
    double lng;

    public:
    Corretor(string nome, float salarioBase, int id, int quantidadeDeProjetos);
    void setId(int id);
    void setNome(string nome);
    void setTelefone(string telefone);

    ~Corretor() = default;

    int getId();
    string getNome();
    string getTelefone();

};

#endif
