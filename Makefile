
NAME := libftprintf.a
OBJS := ./main/ft_printf.o ./parser/ft_parser.o ./parser/ft_flags_parser.o \
		./parser/ft_width_parser.o  ./parser/ft_precision_parser.o ./processor/ft_processor.o \
		./processor/ft_proc_dec.o ./processor/ft_proc_char.o ./processor/ft_proc_string.o \
		./processor/ft_proc_unsigned.o ./processor/ft_proc_dec_uns.o ./processor/ft_proc_string_x.o \
		./processor/ft_proc_x_big.o ./processor/ft_proc_x_small.o ./processor/ft_proc_ptr.o \
		./processor/ft_proc_ptr_2.o ./processor/ft_proc_percent.o \
		./processor/ft_chcek_get_empty_string_and_free.o

LIBFT := libft.a
LIBFT_DIR := ./libft/
FLAGS := -Wall -Wextra -Werror
GCC := gcc
INCLUDES := includes/

all: ${NAME}

$(NAME): ${OBJS}
	make -C $(LIBFT_DIR)
	cp ${LIBFT_DIR}${LIBFT} ./
	ar rc ${LIBFT} ${OBJS}
	mv ${LIBFT} ${NAME}

%.o: %.c
	${GCC} ${FLAGS} -I ${INCLUDES} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME} ${LIBFT}

re:	fclean all

.PHONY: all clean fclean re
