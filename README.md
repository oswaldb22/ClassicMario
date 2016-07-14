# LIF7_ClassicMario
Classic Mario C/SDL2
						   ###  ###  ######## README ########  ###  ###
						****************************************
						* PROJET LIF7: CLASSIC_MARIO : *
						****************************************


		**********************
		* Comment compiler ? *
		**********************
		Vous devez d'abord installer(ou télecharger) Ncurses,  SDL, SDL_image, SDL_ttf, SDL_mixer
		que vous soyer sur Linux ou Windows. 
		Ensuite si vous êtes sur Windows copiez le chemin d'accés au librairies SDL et Ncurses que 
		vous aurez télechargé dans le makefile réspectivement aux lignes 26 et 32 apres le LIBS = 

		Une fois le dossier décompréssé, supprimez tous les programmes dans bin/Debug , les fichiers .o
		dans obj/Debug/src pour celà vous pouvez ouvrir un terminal rentrer dans le dossier et taper
	    la commande make clean. 
	    
	    Pour compiler ensuite vous avez le choix, Si vous voulez vous visualisez la version graphique 
	    et si non l'interface TXT vous devez:
	    - A partir du makefile vous pouver compiler les deux version en meme temps 
		puis:
		
		Pour executer les programmes vous pouvez ensuite utiliser les commandes suivantes
		En rentrant dans le dossier bin: 
		$ cd bin && ./Classic_Mario_txt pour le modele txt
		Ou bien sans rentrer dans bin:
		$ cd bin && ./Classic_Mario_txt_testy pour le test de regression de la version txt
		mais pour le test de regression tous les code de test regression son en commentaire il faudra des decommenter
	
		Ou bien sans rentrer dans bin:
		$ cd bin && ./Classic_Mario_sdl pour le modele sdl



						***********************
						Classic_Mario_sdl: SDL*
						***********************
	    Si vous vouler visualiser la version graphique après avoir lancé la commande precedente sur la version SDL
		qui execute ./Classic_Mario_sdl et ensuite vous pouvez naviguer dans le jeux en utisants les commandes
		suivantes:
		-les fleches du clavier pour monter et descendre dans le menu d'acueil
		-et la touche entrer pour choisir entre(JOUER,A PROPOS, QUITTER)
		
		

        	*****************************
		* Quel est le but du jeu  ? *
		*****************************
		L'utilisateur fait ainsi avancer Mario à travers des niveaux de plus en plus difficile et face à de
		nombreux ennemis tel que les Monsters et autres. Le personnage peut ainsi se deplacer
		(avancer,reculer), sauter tout au long de l'aventure.Le but du jeu est d'eviter les monstres et de
		pouvoir réussir à atteindre la fin de la carte de chaque niveau.
		
		************
		* Doxygene *
		************
		Vous trouverez dans doc/ un fichier doxy et dans doc/html un fichier index.html que vous 
		pouvez ouvrir avec votre navigateur web. Vous trouverez dans cette page web les 
		explications concernant les fonctions qu'on utilise, ce qu'elles font et quels parametres
		prennent elles. Vous trouverez aussi les informations concernant tous les fichier qu'on 
		a utilisé ainsi que les structures qu'on a utilisés. 
