CC=g++
C_BUILD=-std=c++11 -I 
LIBS=-lmpg123 -lao  
C_BUILD_DIRECTORI=/home/marc/Programació/c++/rellotge
SOURCE_rellotge=rellotge.cpp
OUTPUT_rellotge=-o rellotge
RM=rm
RELLOTGE_COMPILAT=rellotge
ECHO=@echo #echoing
RELLOTGE=COMPILACIÓ DEL RELLOTGE:
rellotge:
	$(ECHO)  $(RELLOTGE) 
	$(CC) $(C_BUILD)$(C_BUILD_DIRECTORI) $(SOURCE_rellotge) $(OUTPUT_rellotge) $(LIBS)
clean:
	$(RM) $(RELLOTGE_COMPILAT)
