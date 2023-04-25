CC = g++
FLAGS = -c -Wall -ggdb
INCLUDE_DIR = -Isrc -Isrc/core -Isrc/SDL2 -Itxt





INCLUDE_DIR_SDL = -I/usr/include/SDL2
LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lGL


# Génère l'exécutable
all: bin/Chesstxt bin/"Check Mate Booster" document


bin/Chesstxt: obj/Jeutxt.o obj/ConfigJeu.o obj/Piece.o obj/Vec2.o obj/Joueur.o obj/Classement.o obj/Chrono.o
	$(CC) obj/Jeutxt.o obj/ConfigJeu.o obj/Piece.o obj/Vec2.o obj/Joueur.o obj/Classement.o obj/Chrono.o -o bin/Chesstxt

bin/"Check Mate Booster": obj/ChessSDL2.o obj/ConfigJeu.o obj/Piece.o obj/Vec2.o obj/Joueur.o obj/Classement.o obj/Chessmain.o obj/Chrono.o
	$(CC) obj/ChessSDL2.o obj/ConfigJeu.o obj/Piece.o obj/Vec2.o obj/Joueur.o obj/Classement.o obj/Chessmain.o obj/Chrono.o $(LIBS_SDL) -o bin/"Check Mate Booster" 

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

obj/Chrono.o: src/core/Chrono.cpp src/core/Chrono.h  
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) $(INCLUDE_DIR) src/core/Chrono.cpp -o obj/Chrono.o



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



#genere la documentation
document:
	doxygen -g doc/image.doxy 
	gedit doc/image.doxy
	doxygen doc/image.doxy
	google-chrome doc/html/index.html




# Nettoie les fichiers générés
clean:
ifeq ($(OS),Windows_NT)
	del /s /q bin\*Chess* obj\*.* data\*.txt* doc\*.*
else
	rm -f obj/*.o
	rm -f bin/*
	rm -f data/*.txt
	rm -f doc/*
endif
	