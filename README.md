<center>

# Check Mate Booster (Jeu d'échecs en C++ Solo avec une IA ou en 1 VS 1)

</center>

![Image du jeu d'échecs en C++](data/plateau_readme.png)

<center>

## Présentation du jeu

</center>

Ce jeu d'échecs a été développé en C++ dans le cadre de l'UE LIFAP4 à l'Université lyon 1 Claude Bernard. Le but de ce projet était de mettre en pratique les concepts de la programmation orientée objet et le travail en équipe.
Il faisait office de premier gros projet pour nous en C++.


<center>

## Explication des règles

</center>

Le jeu d'échecs est un jeu de stratégie pour deux joueurs. Le plateau de jeu est composé de 64 cases, alternativement claires et foncées, réparties sur un damier de 8 lignes et 8 colonnes. Chaque joueur dispose de 16 pièces (1 roi, 1 reine, 2 tours, 2 fous, 2 cavaliers et 8 pions) qui sont placées sur les cases de la première et deuxième rangée de son côté du plateau. Le but du jeu est de mettre le roi de l'adversaire en échec et mat.

Les règles du jeu d'échecs sont relativement simples. Chaque joueur déplace une pièce à son tour sur le plateau de jeu. Les pièces se déplacent selon des mouvements spécifiques. Par exemple, le cavalier se déplace en "L", la tour se déplace en ligne droite, etc.

Le but du jeu est de mettre le roi de l'adversaire en échec et mat. Lorsqu'un roi est en échec, cela signifie qu'il est menacé d'être capturé par une pièce adverse. Si le joueur ne peut pas protéger son roi en déplaçant une autre pièce ou en capturant la pièce menaçante, le roi est en échec et mat et le joueur perd la partie.

<center>

## Fonctionnement

</center>

Le jeu d'échecs développé dans ce projet permet de jouer en solo contre une IA qui utilise l'algorithme Min-Max pour prendre des décisions de jeu. Il est également possible de jouer en duo grâce au menu.

L'IA utilise une recherche en profondeur pour explorer les différents coups possibles et déterminer la meilleure option. Elle attribue une note au plateau et choisis en fonction de celle-ci le coup que l'IA doit adopter.

Pour jouer un coup, vous devez simplement cliquer sur la pièce de votre choix. Les coups possibles sont alors mis en évidence en bleu (en vert pour les coups qui mangent une pièce adverse) et vous devez simplement cliquer sur la case voulu (un clic à coté comptera comme une annulation de la pièce choisie)

![Image du menu du jeu d'échecs en C++](data/menu_readme.png)

<center>

## Comment jouer ?

</center>

## Linux:

Vous devez vous mettre dans le répertoire du jeu.
Une fois dans le répertoire, si ce n'est pas déjà fait sur votre machine, entrez la commande suivante :
`sudo apt-get install make libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev`


Ensuite vous devez compilez en entrant la commande:
`make`


Une fois compilé, vous pouvez lancer le jeu soit en vous mettant dans le dossier bin et simplement cliquer sur le fichier Check Mate Booster ou alors vous pouvez simplement rester dans ce répertoire et taper :

`make run`

ou :

`make "Check Mate Booster"`


## Windows : 

Pour pouvoir jouer sur Windows, il vous faudra utiliser Visual Studio (ne pas confondre avec Visual Studio Code) et installer les librairies SDL2 pour Visual Studio (Vc).
Créer un projet Solution et mettez les fichiers headers (.h) dans les fichiers d'en tête et les sources (.cpp) dans les fichiers souces avec l'explorateur de solutions. Mettre les répertoires d'inclusions de SDL2 dans les propriétés de projets(dossier include), dans l'editeur de liens (dossier lib) et dans les dépendances supplémentaires (.lib). Mettre si cela ne fonctionne pas en plus les .dll de SDL2 dans le dossier contenant l'executable.


<center>

## Contact

</center>

LAHCENE Nael Licence 2 Informatique Lyon 1 
Numéro éudiant : 12107990
Adresse mail : nael.lahcene@etu.univ-lyon1.fr

HOFMANN Pierre Licence 2 Informatique Lyon 1 
Numero étudiant : 12108996
Adresse mail : pierre.hofmann@etu.univ-lyon1.fr
