SRC				:= src/main.c \
				   src/utils/utils.c \
				   src/utils/list.c

OBJ				:= $(SRC:.c=.o)
CFLAGS			:= -Wall -Wextra -Werror -Iincludes -fPIE
NAME			:= bin/nuk3asm

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	gcc $(CFLAGS) -o $@ $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:			clean
	$(RM) $(NAME)

re: fclean $(LIBFT) $(NAME) 

.PHONY:			all clean fclean re