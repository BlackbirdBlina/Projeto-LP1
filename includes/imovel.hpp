#ifndef imovel_hpp
#define imovel_hpp
#include <string>
using namespace std;

static int nextIdImovel = 1;
class Imovel{
    private:
    int id;
    // tipo (enum {casa, apartamento, terreno})
    int proprietarioId;
    double lat;
    double lng;
    string endereco;
    double preco;

    public:
    //construtor
    Imovel(int id, int proprietarioId, double lat, double lng, string endereco, double preco);

    //setters
    void setId(int id);
    void setProprietarioId(int proprietarioId);
    void setLat(double lat);
    void setLng(double lng);
    void setEndereco(string endereco);
    void setPreco(double preco);

    // destrutor
    ~Imovel() = default;
        
    //getters
    int getId();
    int getProprietarioId();
    double getLat();
    double getLng();
    string getEndereco();
    double getPreco();

};

#endif