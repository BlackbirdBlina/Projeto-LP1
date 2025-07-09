#include <iostream>
// #include "cliente.hpp"
// #include "corretor.hpp"
#include "imovel.hpp"
#include <vector>
using namespace std;

int main() {


    Imovel casa1 (Imovel::Casa, 1, -3.75, -38.50, 300000.0, "RuaA123");
    Imovel apartamento1 (Imovel::Apartamento, 2, -3.77, -38.47, 200000.0, "RuaB456");
    Imovel terreno1 (Imovel::Terreno, 1, -3.76, -38.53, 150000.0, "RuaC789");

    // casa
    cout << "ID: " << casa1.getId() << endl;
    cout << "TIPO IMOVEL: " << casa1.getTipo() << endl;
    cout << "ID Proprietario: " << casa1.getProprietarioId() << endl;
    cout << "Latitude - Longitude: " << casa1.getLat() << ", " << casa1.getLng() << endl;
    cout << "Endereço " << casa1.getEndereco() << endl;
    cout << "Valor: " << casa1.getPreco() << endl;

    cout << "ID incrementado: " << terreno1.getId() << endl;
    casa1.setPreco(123456.7);
    cout << "Preço alterado: " << casa1.getPreco() << endl;

    return 0;
}