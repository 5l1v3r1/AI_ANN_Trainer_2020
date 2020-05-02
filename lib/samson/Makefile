##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile de lib:
##

SRC =	my_putchar.c				\
	my_isneg.c						\
	my_put_nbr.c					\
	my_swap.c						\
	my_putstr.c						\
	my_strlen.c						\
	my_getnbr.c						\
	my_sort_int_array.c				\
	my_compute_power_rec.c			\
	my_compute_square_root.c		\
	my_is_prime.c					\
	my_find_prime_sup.c				\
	my_strcpy.c						\
	my_strncpy.c					\
	my_revstr.c						\
	my_strstr.c						\
	my_strcmp.c						\
	my_strncmp.c					\
	my_strupcase.c					\
	my_strlowcase.c					\
	my_strcapitalize.c				\
	my_str_isalpha.c				\
	my_str_isnum.c					\
	my_str_islower.c				\
	my_str_isupper.c				\
	my_str_isprintable.c			\
	my_showstr.c					\
	my_showmem.c					\
	my_strcat.c						\
	my_strncat.c					\
	my_mallocer.c					\
	my_tab_char_isneg.c				\
	my_transform_char_into_digit.c	\
	my_transform_str_to_digit.c		\
	my_strdup.c						\
	my_transform_int_into_str.c		\
	my_nbrlen.c						\
	my_error.c						\
	my_put_unsint.c					\
	my_put_double.c					\
	my_getnbr_v2.c					\
	my_str_to_word_array.c			\
	my_file_to_dbl_array.c			\
	my_biggest_word.c				\
	my_count_wrd_into_buff.c		\
	exp.c							\
	fs_cat_x_bytes.c				\
	fs_get_number_from_first_line.c	\
	fs_open_file.c					\
	fs_print_first_line.c			\
	fs_understand_return_of_read.c	\
	fs_nb_char_into_file.c			\
	fs_write_control_file.c			\
	random_gen.c					\
	power_ten.c						\
	open_csv.c						\
	int_encoder.c					\
	clean_array.c					\
	neuron.c						\
	layer.c							\
	model.c							\
	move_into_model.c				\
	print_model.c					\
	compile_model.c					\
	compute.c						\
	linker.c						\
	get_linker_info.c				\
	training.c						\
	get_next_line.c					\
	my_int_to_str.c					\
	my_hidenp.c						\
	my_str_to_float.c				\
	rl_back_prop.c

OBJ = $(SRC:.c=.o)

NAME = libsamson.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp samson.h ../../include

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

debug: CFLAGS += -g3
debug: re