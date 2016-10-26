FALTA="falta treure hora actual tota l'estona, posar-hi entorn gràfic, etc ..."
ECHO=echo
CC=g++
RM=rm
all:
	$(CC) rellotge.cpp -o rellotge -lmpg123 -lao
clean:
	$(RM) rellotge
falta:
	$(ECHO) $(FALTA)
help:
	$(ECHO) "all <- build sources clean <- drop main program (rellotge) falta <- show what is not done "
