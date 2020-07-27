#g++ (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609
MODEL = -DMODULE_STR=bv -DMODULE_PREFIX=pybv -DNDEBUG -DPY_MAJOR_VERSION=3
OPENCV = `pkg-config opencv --cflags --libs`
py3 = `python3-config --includes --ldflags`
np = -I/usr/local/lib/python3.5/dist-packages/numpy/core/include
local = -I .
LIBS = $(OPENCV)  -L/workspace/autohome/project/faceAntiSpoof_PYWARP/libs -lSeetaAuthorize -lSeetaFaceAntiSpoofingX600 -ltennis
INCS = ${py3} ${np} ${local}
CFLAGS = -fPIC

SRCS = bv.cpp src/bvmodule.cpp src/bvmodule.hpp src/FaceAntiSpoofing.h src/seeta/Common/Struct.h src/seeta/Common/CStruct.h
bv.so:${SRCS}
	g++ -std=gnu++0x -shared -rdynamic -g -O3 -Wall -fPIC  -o build/bv.so ${SRCS} ${MODEL} ${LIBS} ${INCS} 
	#g++  -shared -rdynamic -g -O3 -Wall -fPIC  -o build/bv.so ${SRCS} ${MODEL} ${LIBS} ${INCS} 
clean :
	rm -rf  build/*.so 
