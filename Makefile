IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -O0 -std=c++11


ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = User.o ReservationSystem.o Date.o Display.o Reservation.o Time.o Officer.o Member.o Coach.o Court.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


all: ReservationSystem

ReservationSystem: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f  ReservationSystem
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append  
