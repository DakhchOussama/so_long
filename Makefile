CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
B_NAME = so_long_bonus
BONUS_NAME = so_long_bonus


SRC = src/functions.c \
	  src/functions2.c \
 	  src/error.c \
	  src/showmap2.c \
	  src/showmap.c \
 	  src/direction.c \
	  src/moveplayer.c \
	  src/analyzing.c \
	  src/getnextline.c \
	  src/main.c

SRC_B = bonus/analyzing_bonus.c \
		bonus/moveplayer_bonus.c \
		bonus/functions_bonus.c \
		bonus/functions2_bonus.c \
		bonus/functions3_bonus.c \
		bonus/showmap_bonus.c \
		bonus/direction_bonus.c \
		bonus/showmap2_bonus.c \
		bonus/error_bonus.c \
		bonus/getnextline.c \
		bonus/main_bonus.c \
		

OBJECTS = $(SRC:.c=.o)
OBJECTS_B = $(SRC_B:.c=.o)

all:$(NAME)

bonus:$(B_NAME)

$(B_NAME) : $(OBJECTS_B)
	$(CC) $(CFLAGS) $^ -o $@ -framework AppKit -framework OpenGL -lmlx

$(NAME):$(OBJECTS)
	@echo "$(_YELLOW)[Compilation ongoing ...]"
	@echo "$(_GREEN)[Compilation finished]"
	ar rcs $(NAME) $?
	$(CC) $(OBJECTS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
clean:
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_B)
fclean: clean
	rm -f $(NAME)
	rm -f $(B_NAME)
re: fclean all

.PHONY: all clean fclean re