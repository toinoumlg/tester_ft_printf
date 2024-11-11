EXEC = tester.out

SRC_DIR = srcs
INC_DIR = include
OBJ_DIR = srcs/objects
LIBFT_DIR = ../libft
FT_PRINTF_DIR = ..

LIBFT_LIB = $(LIBFT_DIR)/libft.a
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

INCLUDES = -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I$(INC_DIR)

CFLAGS = -Werror -Wall -Wextra
CC = gcc

C_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_FILES))

$(shell mkdir -p $(OBJ_DIR))

all: $(EXEC)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(EXEC): $(OBJECTS) $(LIBFT_LIB) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(FT_PRINTF_LIB) $(LIBFT_LIB) -o $(EXEC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re