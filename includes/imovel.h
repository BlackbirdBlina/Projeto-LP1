#ifndef IMOVEL_HPP
#define IMOVEL_HPP
#include <string>
#include <vector>
using namespace std;

class Imovel{
    public:
    // declaração enum
    enum TipoImovel {Casa, Apartamento, Terreno};

    private:
    // declaração de auto-incremento
    static int nextId;

    // atributos
    int id;
    TipoImovel tipo;
    int proprietarioId;
    double lat;
    double lng;
    double preco;
    string endereco;

    public:
    // construtor
    Imovel(TipoImovel tipo, int proprietarioId, double lat, double lng, double preco, string endereco);

    // destrutor
    ~Imovel() = default;

    // getters
    int getId();
    TipoImovel getTipo();
    int getProprietarioId();
    double getLat();
    double getLng();
    string getEndereco();
    double getPreco();

    // setters
    void setTipo(TipoImovel tipo);
    void setProprietarioId(int proprietarioId);
    void setLat(double lat);
    void setLng(double lng);
    void setEndereco(string endereco);
    void setPreco(double preco);

};

vector<Imovel> lerImovel(int quantidade);

#endif
