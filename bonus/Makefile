##
## EPITECH PROJECT, 2022
## B-MUL-200-MPL-2-1-mydefender-hippolyte.aubert
## File description:
## Makefile
##

################### Color ########################
BLUE			=	/bin/echo -e "\x1b[34;01m$1\x1b[0m"
GREEN			=	/bin/echo -e "\x1b[32;01m$1\x1b[0m"

#################### Make ########################
#MAKE_LIB		=	make -C lib/my/ -s

CC			=	@gcc
CFLAGS		=	-I./ -g
LDFLAGS		=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm
DEBUG		=	-g3

#################### Rules #######################
SRC		=	$(wildcard *.c) \
			$(wildcard alias/*.c) \
			$(wildcard audio/*.c) \
			$(wildcard cd/*.c) \
			$(wildcard env/*.c) \
			$(wildcard execute/*.c) \
			$(wildcard lib/*.c) \
			$(wildcard parsing/*.c) \
			$(wildcard redirection/*.c) \
			$(wildcard repeat/*.c) \
			$(wildcard separators/*.c) \
			$(wildcard error_handle/*.c) \
			$(wildcard variables/*.c) \
			$(wildcard where/*.c)

OBJ		=	$(SRC:.c=.o)

BIN		=	42sh

all:	$(OBJ)
#@$(MAKE_LIB)
		@$(CC) $(CFLAGS) $(OBJ) -o $(BIN) $(LDFLAGS)
		@$(call BLUE,"Build [OK] 🏗️")
		@$(call GREEN,"42sh [OK] 👨‍💻")

clean:
	@rm -rf $(OBJ)
#@$(MAKE_LIB) clean

fclean: clean
	@rm -f $(BIN)
	@$(call BLUE,"Fclean [OK] 🧹")
#@$(MAKE_LIB) fclean

re: fclean all

################# My Commands ####################
g3:
	$(eval CFLAGS += $(DEBUG))
	@$(call BLUE,"Build -g3 [OK] 🔎")

my: re clean

##SRC		=	$(wildcard *.c)
