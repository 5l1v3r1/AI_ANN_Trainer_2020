##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compile de project
##

SRC_DIR	=	src/

FILES = main.c			\
		operation.c		\
		brain.c			\
		decision.c		\
		prepare_value.c

TEST_DIR = tests/

INC_DIR	=	-Iinclude/

LIB_DIR	=	-L./lib/

TESTS_FILES	=	tests.c

SRC =	$(addprefix $(SRC_DIR), $(FILES))

OBJ = $(SRC:.c=.o)

SRC_TEST = $(addprefix $(TEST_DIR), $(TESTS_FILES))

OBJ_TEST = $(SRC_TEST:.c=.o)

LDFLAGS		=	-lcriterion -lgcov --coverage $(LIB_DIR)samson/ -lsamson

CFLAGS 	=	-Wall -Wextra -W $(INC_DIR)

CC	=	gcc

NAME = ann_trainer

all : $(NAME)

debug: CFLAGS += -g3
debug: fclean $(OBJ)
	make -C ./lib/samson debug
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

tests_run: re
tests_run: $(OBJ_TEST)
		gcc -o unit-tests $(LDFLAGS) $(SRC_TEST) ./lib/samson libsamson.a $(CFLAGS)
		./unit-tests
		gcov *.gcna
		gcov *.gcno


$(NAME) : $(OBJ)
	make -C ./lib/samson
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean :
	make -C ./lib/samson clean
	rm -f $(OBJ)
	rm -f $(OBJ_TEST)

fclean : clean
	make -C ./lib/samson fclean
	rm -f $(NAME)
	rm -f tests.c.gcov
	rm -f tests.gcda
	rm -f tests.gcno
	rm -f unit-tests
	rm -rf vgcore.*

re : fclean all

sweet : all clean
