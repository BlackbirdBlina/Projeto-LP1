#include "imovel.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Gera automaticamente IDs sequenciais para cada imóvel, começando em 1
int Imovel::nextId = 1;

// Construtor
Imovel::Imovel(TipoImovel tipo, int proprietarioId, double lat, double lng, double preco, string endereco):
    id(nextId++), tipo(tipo), proprietarioId(proprietarioId), lat(lat), lng(lng), preco(preco), endereco(endereco){

}

// Métodos getters necessários
int Imovel::getId(){
    return id; // ID único do imóvel
}
double Imovel::getLat(){
    return lat;
}
double Imovel::getLng(){
    return lng;
}

// Criando novas instâncias de imovel
vector<Imovel> lerImovel(int quantidade){
    vector<Imovel> imoveis;
    for (int i = 0; i < quantidade; ++i) {
        string tipo, endereco;
        int propId;
        double lat, lng, preco;
        cin >> tipo >> propId >> lat >> lng >> preco;
        getline(cin >> ws, endereco);

        Imovel::TipoImovel capturaTipo;

        // Converte a string 'tipo' para o enum correspondente
        if(tipo == "Casa"){
            capturaTipo = Imovel::TipoImovel::Casa;
        } else if(tipo == "Apartamento"){
            capturaTipo = Imovel::TipoImovel::Apartamento;
        } else if(tipo == "Terreno"){
            capturaTipo = Imovel::TipoImovel::Terreno;
        }
        
        // Cria um novo objeto Imovel com os dados capturados e adiciona ao vetor
        imoveis.emplace_back(capturaTipo, propId, lat, lng, preco, endereco);
    }

    // Retorna o vetor com todos os imóveis lidos
    return imoveis; 
}