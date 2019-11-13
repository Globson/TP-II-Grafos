all: main.cpp Sources/MatrizAdjacencia.cpp
	g++ main.cpp -o EXEC Sources/MatrizAdjacencia.cpp

run: EXEC
	./EXEC

rm: EXEC
	rm EXEC
