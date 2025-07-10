#include "imovel.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Imovel::nextId = 1;

Imovel::Imovel(TipoImovel tipo, int proprietarioId, double lat, double lng, double preco, string endereco):
    id(nextId++), tipo(tipo), proprietarioId(proprietarioId), lat(lat), lng(lng), preco(preco), endereco(endereco){

}

// Métodos getters necessários
int Imovel::getId(){
    return id;
}
double Imovel::getLat(){
    return lat;
}
double Imovel::getLng(){
    return lng;
}

vector<Imovel> lerImovel(int quantidade){
    vector<Imovel> imoveis;
    for (int i = 0; i < quantidade; ++i) {
        string tipo, endereco;
        int propId;
        double lat, lng, preco;
        cin >> tipo >> propId >> lat >> lng >> preco;
        getline(cin >> ws, endereco);
        Imovel::TipoImovel capturaTipo;

        if(tipo == "Casa"){
            capturaTipo = Imovel::TipoImovel::Casa;
        } else if(tipo == "Apartamento"){
            capturaTipo = Imovel::TipoImovel::Apartamento;
        } else if(tipo == "Terreno"){
            capturaTipo = Imovel::TipoImovel::Terreno;
        }

        imoveis.emplace_back(capturaTipo, propId, lat, lng, preco, endereco);
    }
    return imoveis;
}

