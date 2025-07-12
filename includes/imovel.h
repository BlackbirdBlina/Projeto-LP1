#ifndef IMOVEL_HPP
#define IMOVEL_HPP
#include <string>
#include <vector>
using namespace std;

class Imovel{
    public:
    // Enumeração para definir os tipos possíveis de imóvel
    enum TipoImovel {Casa, Apartamento, Terreno};

    private:
    // Declaração de auto-incremento para controle de IDs
    static int nextId;

    // Atributos
    int id;
    TipoImovel tipo;
    int proprietarioId;
    double lat;
    double lng;
    double preco;
    string endereco;

    public:
    // Construtor
    Imovel(TipoImovel tipo, int proprietarioId, double lat, double lng, double preco, string endereco);

    // Destrutor
    ~Imovel() = default;

    // Getters
    int getId();
    TipoImovel getTipo();
    int getProprietarioId();
    double getLat();
    double getLng();
    string getEndereco();
    double getPreco();

    // Setters
    void setTipo(TipoImovel tipo);
    void setProprietarioId(int proprietarioId);
    void setLat(double lat);
    void setLng(double lng);
    void setEndereco(string endereco);
    void setPreco(double preco);

};

// Função que lê uma quantidade de imóveis e retorna um vetor com eles
vector<Imovel> lerImovel(int quantidade);

#endif
