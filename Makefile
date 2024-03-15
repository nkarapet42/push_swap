NAME = push_swap
BONUS_NAME = checker

SRCS = src/main.c \
	   src/ft_ss.c \
	   src/ft_pab.c \
       src/ft_rr.c \
	   src/ft_rrr.c \
	   src/ft_putstr_fd.c \
	   src/ft_putchar_fd.c \
	   src/ft_pars.c \
	   src/ft_util_list.c \
	   src/ft_validnums.c \
	   src/ft_sort.c \
	   src/ft_sort_second_part.c \
	   src/ft_atoi.c \
	   src/ft_split.c \

BONUS_SRCS = src/checker.c \
			 src/get_next_line.c \
			 src/get_next_line_utils.c \
			 src/ft_ss.c \
	         src/ft_pab.c \
             src/ft_rr.c \
	         src/ft_rrr.c \
	         src/ft_putstr_fd.c \
	         src/ft_putchar_fd.c \
	         src/ft_util_list.c \
	         src/ft_validnums.c \
			 src/ft_pars.c \
	         src/ft_atoi.c \
	         src/ft_split.c \
 
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)	

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

%.o: %.c Includes/push_swap.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all bonus

.PHONY: all clean fclean re