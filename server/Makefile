##
## EPITECH PROJECT, 2022
## Zappy
## File description:
## Makefile
##

SRC			=	src/core/fdsets.c \
				src/core/init.c \
				src/core/input.c \
				src/core/loop.c \
				src/core/tick.c \
				src/graphical/command.c \
				src/graphical/map.c \
				src/graphical/team_name.c \
				src/graphical/player.c \
				src/objects/clients.c \
				src/objects/players.c \
				src/objects/teams.c \
				src/player/command.c \
				src/player/info.c \
				src/player/join.c \
				src/util/arguments/args.c \
				src/util/arguments/check.c \
				src/util/arguments/handlers.c \
				src/util/arguments/names.c \
				src/util/arrays.c \
				src/util/buffer.c \
				src/util/util.c \
				src/server.c

MAIN		=	src/main.c

TESTS		=	tests/test_server.c

INC			=	include/

NAME		=	zappy_server
TEST		=	unit_tests

OBJ			=	$(SRC:.c=.o)
OBJ_M 		=	$(MAIN:.c=.o)
OBJ_T		=	$(TESTS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Wpedantic
CPPFLAGS	=	-iquote $(INC)

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_M)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_M)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_M)
	$(RM) $(OBJ_T)

debug: CPPFLAGS += -g3
debug: re

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(TEST)
	find -name "*.gcda" -delete -o -name "*.gcno" -delete

re:	fclean all

tests_run: CFLAGS += --coverage
tests_run: LDLIBS += -lcriterion
tests_run: clean $(OBJ) $(OBJ_T)
	$(CC) -o $(TEST) $(OBJ) $(OBJ_T) $(LDLIBS) --coverage
	$(MAKE) clean
	./$(TEST)

.PHONY: all clean fclean re tests_run
