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
    Corretor(int id, string nome, string telefone, bool avaliador, double lat, double lng);
    void setId(int id);
    void setNome(string nome);
    void setTelefone(string telefone);
    void setAvaliador(bool avaliador);
    void setLat(double lat);
    void setLng(double lng);

    ~Corretor() = default;

    int getId();
    string getNome();
    string getTelefone();
    bool getAvaliador();
    double getLat();
    double getLng();

};

#endif
