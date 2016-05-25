SRCS_TXT = Mario.c Monster.c Niveau.c Position.c Jeu.c txtJeu.c winTxt.c mainTxt.c
FINAL_TARGET_TXT = Classic_Mario_txt

SRCS_SDL = MarioSdl.c MonsterSdl.c NiveauSdl.c PositionSdl.c  sdlJeu.c JeuS.c mainSdl.c
FINAL_TARGET_SDL = Classic_Mario_sdl


LIBS = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
INCLUDELIBS_DIR = -I/usr/include/SDL2

CC				= gcc
LD 				= gcc
LDFLAGS  			=   -ggdb
CPPFLAGS 			=  -ggdb   #-O2   # pour optimiser
INCLUDE_DIR	 		= -Isrc $(INCLUDELIBS_DIR)
OBJ_DIR 			= obj
SRC_DIR 			= src
BIN_DIR 			= bin
SDL				=Classic_Mario_Sdl
TXT				=Classic_Mario_Txt


default: make_dir $(BIN_DIR)/$(FINAL_TARGET_TXT)  $(BIN_DIR)/$(FINAL_TARGET_SDL)
make_dir:
	mkdir -p $(OBJ_DIR)

$(BIN_DIR)/$(FINAL_TARGET_TXT): $(SRCS_TXT:%.c=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@  $(LIB_DIR) $(LIBS)


$(BIN_DIR)/$(FINAL_TARGET_SDL): $(SRCS_SDL:%.c=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@  $(LIB_DIR) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(TXT)/%.c
	$(CC) -c $(CPPFLAGS)  $(INCLUDE_DIR) $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(SDL)/%.c
	$(CC) -c $(CPPFLAGS)  $(INCLUDE_DIR) $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/$(FINAL_TARGET_TXT)  $(BIN_DIR)/$(FINAL_TARGET_SDL)
