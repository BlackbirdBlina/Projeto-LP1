#include "imovel.hpp"
#include <iostream>
using namespace std;

// Gerar IDs únicos
int Imovel::nextId = 1; 

// Construtor
Imovel::Imovel(TipoImovel tipo, int proprietarioId,
    double lat, double lng, double preco, string endereco): 
    id(nextId++), tipo(tipo), proprietarioId(proprietarioId),
    lat(lat), lng(lng), preco(preco), endereco(endereco)
{
}

vector<Imovel> lerImovel(int quantidade){
    vector<Imovel> imoveis;
    for (int i = 0; i < quantidade; i++){
        string tipo, endereco;
        int propriedadeId;
        double lat, lng, preco;
        cin >> tipo >> propriedadeId >> lat >> lng >> preco;
        getline(cin >> ws, endereco);
        Imovel::TipoImovel capturaTipo;

        if (tipo == "Casa"){
            capturaTipo = Imovel::TipoImovel::Casa;
        } else if (tipo == "Apartamento"){
            capturaTipo = Imovel::TipoImovel::Apartamento;
        } else if (tipo == "Terreno"){
            capturaTipo = Imovel::TipoImovel::Terreno;
        }

        imoveis.emplace_back(capturaTipo, propriedadeId, lat, lng, preco, endereco);
    }
    return imoveis;
}

// Getters
int Imovel::getId(){
    return id;
}

Imovel::TipoImovel Imovel::getTipo(){
    return tipo;
}

int Imovel::getProprietarioId(){
    return proprietarioId;
}

double Imovel::getLat(){
    return lat;
}

double Imovel::getLng(){
    return lng;
}

string Imovel::getEndereco(){
    return endereco;
}

double Imovel::getPreco(){
    return preco;
}

// Setters
void Imovel::setTipo(TipoImovel tipo){
    this->tipo = tipo;
}

void Imovel::setProprietarioId(int ProprietarioId){
    this->proprietarioId = proprietarioId;
}

void Imovel::setLat(double lat) {
    this->lat = lat;
}

void Imovel::setLng(double lng) {
    this->lng = lng;
}

void Imovel::setPreco(double preco) {
    this->preco = preco;
}

void Imovel::setEndereco(string endereco) {
    this->endereco = endereco;
}