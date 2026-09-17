CC = gcc
CFLAGS = -g -Wall

ifeq ($(OS),Windows_NT)
	include makefile_windows.variables
else
	UNAME = $(shell uname)
	ifeq ($(UNAME),Linux)
		include makefile_linux.variables
	else
		include makefile_mac.variables
	endif
endif

raylibfolder = ./raylib
unityfolder = ./unity
codefolder = .

# --------------------------
# initiales Spiel bauen
# --------------------------
wordsalad_initial:
	$(CC) -o wordsalad_initial -L. $(BINARIES)/libwordsalad_complete.a $(BINARIES)/libraylib.a $(LDFLAGS)

# --------------------------
# Normales Spiel bauen
# --------------------------
wordsalad: main.o input.o game.o graphicalGame.o $(BINARIES)/libraylib.a
	$(CC) $(CFLAGS) -o wordsalad main.o input.o game.o graphicalGame.o $(BINARIES)/libraylib.a $(LDFLAGS)

main.o: $(codefolder)/main.c
	$(CC) -c $(CFLAGS) $(codefolder)/main.c

input.o: $(codefolder)/input.c
	$(CC) -c $(CFLAGS) $(codefolder)/input.c

game.o: $(codefolder)/game.c
	$(CC) -c $(CFLAGS) $(codefolder)/game.c

graphicalGame.o: $(codefolder)/graphicalGame.c
	$(CC) -I$(raylibfolder) -c $(CFLAGS) $(codefolder)/graphicalGame.c


# --------------------------
# Unit Tests
# --------------------------
TEST_BIN = runTests

test: input.o game.o $(codefolder)/unit_tests.c $(unityfolder)/unity.c
	$(CC) -Wall -I$(unityfolder) -o $(TEST_BIN) input.o game.o $(codefolder)/unit_tests.c $(unityfolder)/unity.c
# --------------------------
# Clean
# --------------------------
clean:
ifeq ($(OS),Windows_NT)
	del /f *.o *.exe
else
	rm -f *.o wordsalad $(TEST_BIN)
endif