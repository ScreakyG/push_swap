NAME = push_swap
CFLAGS = -Wall -Werror -Wextra -g
CC = gcc

### INCLUDES ###

INCLUDES = includes/push_swap.h

### SOURCES ###

SRCS_DIR = srcs/
SRCS_FILES = main.c utils.c utils2.c input_check.c init.c stack.c push.c reverse_rotate.c rotate.c swap.c simple_sort.c radix_sort.c ft_parse.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS = ${SRCS:.c=.o}

### EXTRA FUNCTIONS ###

FUNCTIONS_DIR = functions/
FUNCTIONS_FILES = ft_split.c ft_strlcpy.c ft_strlen.c ft_substr.c
FUNCTIONS = $(addprefix $(FUNCTIONS_DIR), $(FUNCTIONS_FILES))
OBJS_FUNCTIONS = ${FUNCTIONS:.c=.o}

all: $(NAME)

%.o: %.c
			@${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS_FUNCTIONS) $(OBJS) $(INCLUDES)
		@${CC} $(CFLAGS) $(OBJS_FUNCTIONS) $(OBJS) -o $(NAME)

clean:
		@rm -f $(OBJS) $(OBJS_FUNCTIONS)

fclean : clean
		@rm -f $(NAME)

re : fclean all

.PHONY: all name clean fclean re
