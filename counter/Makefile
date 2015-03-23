# Declaratiile de variabile
CC = g++
CFLAGS = -Wall 
SRC = tema1.cpp
EXE = tema1


# Regula de compilare
build:
	$(CC) -o $(EXE) $(SRC) $(CFLAGS) 
 
# Regulile de "curatenie" (se folosesc pentru stergerea fisierelor intermediare si/sau rezultate)
.PHONY : clean
clean :
	rm -f $(EXE) *~

