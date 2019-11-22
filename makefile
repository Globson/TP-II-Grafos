all: main.cpp Sources/ListaAdjacencia.cpp Sources/AlgoritmoFleury.cpp
	g++ main.cpp -o EXEC Sources/ListaAdjacencia.cpp Sources/AlgoritmoFleury.cpp

run: EXEC
	./EXEC

rm: EXEC
	rm EXEC
