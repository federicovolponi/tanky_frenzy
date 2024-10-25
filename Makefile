default:
	g++ ./src/*.cpp -o game.out -I ./include/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
debug:
	g++ -g ./src/*.cpp -o debug-game.out -I ./include/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
