Driver: Driver.o stage.o sprite.o ball.o paddle.o ball.o brick.o
	g++ Driver.o stage.o sprite.o ball.o paddle.o brick.o -std=c++11 -L/usr/X11R6/lib/ -lGL -lGLU -lglut

Driver.o: Driver.cpp
	g++ -c Driver.cpp -std=c++11 -L/usr/X11R6/lib/ -lGL -lGLU -lglut

stage.o: stage.cpp
	g++ -c stage.cpp -std=c++11 -L/usr/X11R6/lib/ -lGL -lGLU -lglut

sprite.o: sprite.cpp
	g++ -c sprite.cpp -std=c++11 -L/usr/X11R6/lib/ -lGL -lGLU -lglut

ball.o: ball.cpp
	g++ -c ball.cpp -std=c++11 -L/usr/X11R6/lib/ -lGL -lGLU -lglut

paddle.o: paddle.cpp
	g++ -c paddle.cpp -std=c++11 -L/usr/X11R6/lib/ -lGL -lGLU -lglut

brick.o: brick.cpp
	g++ -c brick.cpp -std=c++11 -L/usr/X11R6/lib/ -lGL -lGLU -lglut

