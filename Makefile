NAME = push_swap
BONUS_NAME = checker
CFLAGS = -Wall -Werror -Wextra -g
CC = gcc

### INCLUDES ###

INCLUDES = includes/push_swap.h

### SOURCES ###

SRCS_DIR = srcs/
SRCS_FILES = main.c utils.c utils2.c input_check.c init.c stack.c push.c reverse_rotate.c rotate.c swap.c simple_sort.c ft_parse.c get_target_position.c sort.c operations.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS = ${SRCS:.c=.o}

### CHECKER_SOURCES ###

BONUS_DIR = checker_srcs/
BONUS_FILES = main_bonus.c ft_parse_bonus.c input_check_bonus.c utils_bonus.c stack_bonus.c init_bonus.c ft_strncmp.c get_next_line.c get_next_line_utils.c push.c reverse_rotate.c swap.c rotate.c
BONUS = $(addprefix $(BONUS_DIR), $(BONUS_FILES))
OBJS_BONUS = $(BONUS:.c=.o)

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

bonus: $(BONUS_NAME)

$(BONUS_NAME):	$(OBJS_FUNCTIONS) $(OBJS_BONUS) $(INCLUDES)
				$(CC) $(CFLAGS) $(OBJS_FUNCTIONS) $(OBJS_BONUS) -o $(BONUS_NAME)

clean:
		@rm -f $(OBJS) $(OBJS_FUNCTIONS) $(OBJS_BONUS)

fclean : clean
		@rm -f $(NAME)
		@rm -f $(BONUS_NAME)

re : fclean all

.PHONY: all name clean fclean re
