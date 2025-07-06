#include "corretor.hpp"
using namespace std;

int Corretor::nextId = 1;

Corretor::Corretor(string nome, string telefone, bool avaliador, double lat, double lng):
    id(nextId++), nome(nome), telefone(telefone), avaliador(avaliador), lat(lat), lng(lng){

}
