CC = g++
FLAGS = -c -Wall -ggdb
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS_GTK = `pkg-config --libs gtk+-3.0`
INCLUDE_DIR = -Isrc -Isrc/core -Isrc/SDL2 -Itxt




ifeq ($(OS),Windows_NT)
	INCLUDE_DIR_SDL = 	-Isrc/SDL2 \
                        -Iextern/x86_64-w64-mingw32/include/

	LIBS_SDL = -Lextern \
			-Lextern/SDL2_mingw-cb20/SDL2-2.0.12/x86_64-w64-mingw32/lib \
			-Lbin \
			-lSDL2main -lSDL2.dll -lSDL2_ttf.dll -lSDL2_image.dll -lSDL2_mixer.dll 

else
	INCLUDE_DIR_SDL = -I/usr/include/SDL2
	LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lGL
endif



ifeq ($(OS),Windows_NT)
    EXEFILE=Chess.exe
    ICONOBJECT=iconwindows.o
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        EXEFILE=Chess
        ICONOBJECT=iconlinux.o
    endif
endif

SOURCES=Chessmain.cpp $(ICONOBJECT)



# Génère l'exécutable
all: bin/Chesstxt


bin/Chesstxt: obj/Jeutxt.o obj/ConfigJeu.o obj/Piece.o obj/Vec2.o obj/Joueur.o obj/Classement.o
	$(CC) obj/Jeutxt.o obj/ConfigJeu.o obj/Piece.o obj/Vec2.o obj/Joueur.o obj/Classement.o -o bin/Chesstxt

obj/Chessmain.o: src/SDL2/Chessmain.cpp 
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) $(INCLUDE_DIR) src/SDL2/Chessmain.cpp -o obj/Chessmain.o
obj/ChessSDL2.o: src/SDL2/ChessSDL2.cpp src/SDL2/ChessSDL2.h
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) $(INCLUDE_DIR) src/SDL2/ChessSDL2.cpp -o obj/ChessSDL2.o 


obj/Piece.o: src/core/Piece.cpp src/core/Piece.h  
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) $(INCLUDE_DIR) src/core/Piece.cpp -o obj/Piece.o

obj/Joueur.o: src/core/Joueur.cpp src/core/Joueur.h  
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) $(INCLUDE_DIR) src/core/Joueur.cpp -o obj/Joueur.o

obj/Classement.o: src/core/Classement.cpp src/core/Classement.h  
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) $(INCLUDE_DIR) src/core/Classement.cpp -o obj/Classement.o

obj/ConfigJeu.o: src/core/ConfigJeu.cpp src/core/ConfigJeu.h
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) $(INCLUDE_DIR) src/core/ConfigJeu.cpp -o obj/ConfigJeu.o

obj/Jeutxt.o: src/txt/Jeutxt.cpp 
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) $(INCLUDE_DIR) src/txt/Jeutxt.cpp -o obj/Jeutxt.o

obj/Vec2.o: src/core/Vec2.cpp src/core/Vec2.h  
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) $(INCLUDE_DIR) src/core/Vec2.cpp -o obj/Vec2.o

iconwindows.o: icon/iconwindows.cpp
	$(CC) icon/iconwindows.cpp -o obj/$@

iconlinux.o: icon/iconlinux.cpp
	g++ `pkg-config --cflags gtk+-3.0` icon/iconlinux.cpp `pkg-config --libs gtk+-3.0` -o obj/iconlinux.o



val: bin/${EXEFILE}
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes bin/Chess


# Exécute le jeu
run:
ifeq ($(OS),Windows_NT)
	bin\${EXEFILE}
else
	./bin/${EXEFILE}
endif

Chess:
ifeq ($(OS),Windows_NT)
	bin\${EXEFILE}
else
	./bin/${EXEFILE}
endif


runtxt:
ifeq ($(OS),Windows_NT)
	bin\${EXEFILE}
else
	./bin/${EXEFILE}
endif

Chesstxt:
ifeq ($(OS),Windows_NT)
	bin\Chesstxt
else
	./bin/Chesstxt
endif


# Nettoie les fichiers générés
clean:
ifeq ($(OS),Windows_NT)
	del /s /q bin\*Chess* obj\*.* data\*.txt*
else
	rm -f obj/*.o
	rm -f bin/*
	rm -f data/*.txt
endif
	