NAME = libftprintf.a

LIBFT_DIR = libft
FT_PRINTF_SRCS_DIR = srcs

OBJ_DIR = obj
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I$(LIBFT_DIR)

FT_PRINTF_SRCS = ft_printf.c ft_putptr_fd.c count_hexdigits.c ft_puthex_fd.c ft_puthex_upper_fd.c \
				handle_char.c handle_hex_upper.c handle_hex.c handle_int.c handle_pointer.c handle_string.c \
				handle_unsigned_int.c
				
LIBFT_SRCS = ft_strlen.c ft_toupper.c ft_tolower.c ft_isalpha.c \
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
		ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
		ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putstr_fd.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c


FT_PRINTF_OBJS  := $(addprefix $(OBJ_DIR)/,$(FT_PRINTF_SRCS:.c=.o))
LIBFT_OBJS =  $(LIBFT_SRCS:%.c=$(LIBFT_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(FT_PRINTF_OBJS)
	ar rcs $@ $(LIBFT_OBJS) $(FT_PRINTF_OBJS) 

$(OBJ_DIR)/%.o: $(FT_PRINTF_SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libft: $(LIBFT_OBJS)
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(FT_PRINTF_OBJS) $(LIBFT_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft