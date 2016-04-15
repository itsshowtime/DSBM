CC= g++-4.8
CFLAGS= -std=c++11 -Wall -O1
LFLAGS= -lbcm2835

OBJ= ./bin

all: rect tftdriver tftdraw whoread ad_driver test_draw main_layout test_draw_v2 clearscreen jfons test_ad

rect: rect.c
	$(CC) -c rect.c $(CFLAGS) -o $@.o

whoread: whoread.c
	$(CC) -c whoread.c $(CFLAGS) -o $@.o

ad_driver: ad_driver.c
	$(CC) -c ad_driver.c $(CFLAGS) -o $@.o

tftdriver: tftdriver.c
	$(CC) -c tftdriver.c $(CFLAGS) -o $@.o

tftdraw: tftdraw.c rect.o tftdriver.o
	$(CC) -c tftdraw.c $(CFLAGS) -o $@.o

test_draw: test_draw.c rect.o tftdriver.o tftdraw.o
	$(CC) -c test_draw.c $(CFLAGS) -o $@.o
	$(CC) -o test_draw.exe $@.o rect.o tftdriver.o tftdraw.o $(LFLAGS)

test_draw_v2: test_draw_v2.c rect.o tftdriver.o tftdraw.o
	$(CC) -c test_draw_v2.c $(CFLAGS) -o $@.o
	$(CC) -o test_draw_v2.exe $@.o rect.o tftdriver.o tftdraw.o $(LFLAGS)

main_layout: main_layout.c rect.o tftdriver.o tftdraw.o whoread.o
	$(CC) -c main_layout.c $(CFLAGS) -o $@.o
	$(CC) -o main_layout.exe $@.o rect.o tftdriver.o tftdraw.o whoread.o $(LFLAGS)

clearscreen: clearscreen.c tftdriver.o tftdraw.o rect.o
	$(CC) -c clearscreen.c $(CFLAGS) -o $@.o
	$(CC) -o clearscreen.exe $@.o tftdriver.o tftdraw.o rect.o $(LFLAGS)

jfons: test_jfons.c tftdriver.o tftdraw.o rect.o
	$(CC) -c test_jfons.c $(CFLAGS) -o $@.o
	$(CC) -o test_jfons.exe $@.o tftdriver.o tftdraw.o rect.o $(LFLAGS)

test_ad: test_ad.c ad_driver.o
	$(CC) -c test_ad.c $(CFLAGS) -o $@.o
	$(CC) -o test_ad.exe $@.o ad_driver.o $(LFLAGS)

clean:
	rm -rf *.o *.exe
