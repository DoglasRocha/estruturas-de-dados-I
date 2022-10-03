all := main.cpp $(wildcard ./src/*.cpp) $(wildcard ./sequential-list/src/*.cpp) $(wildcard ./common/src/*.cpp)                                                                                        

main: $(all)
	g++ -o main $(all)

clean:
	rm -f main
