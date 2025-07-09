#ifndef IMOVEL_HPP
#define IMOVEL_HPP
#include <string>
#include <vector>
#include <functional>

class Imovel{    
    public:
    // Declaração enum
    enum TipoImovel {Casa, Apartamento, Terreno};
    
    private:
    // Declaração de auto-incremento
    static int nextId;
    
    // Atributos
    int id;
    TipoImovel tipo;
    int proprietarioId;
    double lat;
    double lng;
    std::string endereco;
    double preco;

    public:
    // Construtor
    Imovel(TipoImovel tipo, int proprietarioId, double lat, double lng, double preco, std::string endereco);

    // Destrutor
    ~Imovel() = default;

    // Getters
    int getId();
    TipoImovel getTipo();
    int getProprietarioId();
    double getLat();
    double getLng();
    std::string getEndereco();
    double getPreco();

    // Setters
    void setTipo(TipoImovel tipo);
    void setProprietarioId(int proprietarioId);
    void setLat(double lat);
    void setLng(double lng);
    void setPreco(double preco);
    void setEndereco(std::string endereco);

};

std::vector<Imovel> lerImovel(int quantidade);

#endif