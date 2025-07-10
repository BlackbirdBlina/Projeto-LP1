CXX = g++
CXXFLAGS = -Iincludes -std=c++11 -Wall -Wextra -pedantic

SRCS = src/corretor.cpp src/imovel.cpp src/cliente.cpp src/calcDistance.cpp src/agenda.cpp testes/main.cpp 

imobiliaria: $(SRCS)
	$(CXX) $(CXXFLAGS) -o imobiliaria $(SRCS)

clean:
	rm -f imobiliaria
