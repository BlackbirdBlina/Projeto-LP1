#ifndef corretor_hpp
#define corretor_hpp
#include <string>
using namespace std;

static int nextIdCorretor = 1;
class Corretor{
    private:
    bool avaliador;
    double lat;
    double lng;

    public:
    Corretor(string nome, float salarioBase, int id, int quantidadeDeProjetos);

    ~Corretor() = default;

    int getId();

};

#endif
