CC= g++-4.8
CFLAGS= -std=c++11
LFLAGS= -lbcm2835

OBJ= ./bin

all: rect tftdriver tftdraw test_draw main_layout

rect: rect.c
	$(CC) -c rect.c $(CFLAGS) -o $(OBJ)/$@.o

tftdriver: tftdriver.c
	$(CC) -c tftdriver.c $(CFLAGS) -o $(OBJ)/$@.o

tftdraw: tftdraw.c
	$(CC) -c tftdraw.c $(CFLAGS) -o $(OBJ)/$@.o

test_draw: test_draw.c rect tftdriver tftdraw
	$(CC) -c test_draw.c $(CFLAGS) -o $(OBJ)/$@.o
	$(CC) -o test_draw.exe $(OBJ)/* $(LFLAGS)

main_layout: main_layout.c rect tftdriver tftdraw
	$(CC) -c main_layout.c $(CFLAGS) -o $(OBJ)/$@.o
	$(CC) -o main_layout $(OBJ)/* $(LFLAGS)

clean:
	rm -rf $(OBJ)/*.o *.exe
