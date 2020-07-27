OPENCV = `pkg-config opencv --cflags --libs`
SF6=-L${PWD}/libs -lSeetaFaceAntiSpoofingX600 -lSeetaAuthorize -ltennis
LIBS = $(OPENCV) 
LIBS+= ${SF6}

test:main.o
	g++ -std=gnu++0x -o test main.o $(LIBS)
main.o:main.cpp
	g++ -std=gnu++0x -fPIC -shared main.cpp -o main.o $(LIBS)
clean :
	rm -fr test *.so *.o
