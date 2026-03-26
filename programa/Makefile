
programa: build/main.o build/Circulo.o build/Ponto.o
	g++ -std=c++11 -Wall build/main.o build/Ponto.o build/Circulo.o -o programa

build/main.o: src/main.cpp include/Ponto.hpp include/Circulo.hpp
	g++ -std=c++11 -Wall -Iinclude -c src/main.cpp -o build/main.o

build/Ponto.o: src/entidades/Ponto.cpp include/Ponto.hpp
	g++ -std=c++11 -Wall -Iinclude -c src/entidades/Ponto.cpp -o build/Ponto.o

build/Circulo.o: src/entidades/Circulo.cpp include/Circulo.hpp
	g++ -std=c++11 -Wall -Iinclude -c src/entidades/Circulo.cpp -o build/Circulo.o

clean:
	rm -f build/*.o programa