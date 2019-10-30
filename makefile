all: main.cpp Sources/Funcs.cpp
	g++ main.cpp -o EXEC Sources/Funcs.cpp

run: EXEC
	./EXEC

rm: EXEC
	rm EXEC
