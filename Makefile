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
