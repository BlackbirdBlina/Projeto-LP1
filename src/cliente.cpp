#include "cliente.hpp"
using namespace std;

int Cliente::nextId = 1;

Cliente::Cliente(string nome, string telefone):
    id(nextId++), nome(nome), telefone(telefone){

}
