NAME_CLIENT = client
NAME_SERVER = server
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
SRCS_DIR = srcs
OBJ_DIR = obj
CC = cc
CFLAGS = -Wall -Wextra -Werror 
INCLUDES = -I./includes -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)/includes

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CLIENT_OBJS  := $(addprefix $(OBJ_DIR)/,$(CLIENT_SRCS:.c=.o))
SERVER_OBJS  := $(addprefix $(OBJ_DIR)/,$(SERVER_SRCS:.c=.o))

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(SERVER_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $@

$(NAME_CLIENT): $(CLIENT_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $@

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
