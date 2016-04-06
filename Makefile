CC= g++
CFLAGS= -std=c++11
LFLAGS= -lbcm2835

OBJ= ./bin

all: rect tftdriver tftdraw test_draw

rect: rect.c
	$(CC) -c rect.c $(CFLAGS) -o $(OBJ)/$@.o

tftdriver: tftdriver.c
	$(CC) -c tftdriver.c $(CFLAGS) -o $(OBJ)/$@.o

tftdraw: tftdraw.c
	$(CC) -c tftdraw.c $(CFLAGS) -o $(OBJ)/$@.o

test_draw: test_draw.c rect tftdriver tftdraw
	$(CC) -c test_draw.c $(CFLAGS) -o $(OBJ)/$@.o
	$(CC) -o test_draw.exe $(OBJ)/* $(LFLAGS)

clean:
	rm -rf $(OBJ)/*.o *.exe
