go: build run

build: src/main.cpp
	g++ -I include -c src/main.cpp src/camera.cpp src/map.cpp src/player.cpp
	g++ main.o camera.o map.o player.o -o app -lsfml-graphics -lsfml-window -lsfml-system
run:
	 ./app

objdel:
	rm main.o camera.o player.o map.o

del:
	rm app