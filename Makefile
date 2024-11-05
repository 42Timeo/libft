NAME = libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror -Iinclude

CRITERION_FLAGS = -Icriterion/include -Lcriterion/lib -rpath $(PWD)/criterion/lib -lcriterion

SRCS = $(wildcard src/*.c)
OBJS = ${SRCS:.c=.o}
TESTS = $(wildcard tests/*.c)
HEADERS = $(wildcard include/*.h)

REQUIRE_LIBFT_H = src/ft_substr.o src/ft_strjoin.o src/ft_strtrim.o


all: $(NAME)

$(NAME): Makefile $(OBJS)
	ar rcs $(NAME) $(OBJS)

# %.o: %.c Makefile
# 	$(CC) -c $(CFLAGS) $< -o $@

# $(REQUIRE_LIBFT_H): %.o: %.c include/libft.h Makefile
# 	$(CC) -c $(CFLAGS) $< -o $@

$(REQUIRE_LIBFT_H): include/libft.h

test: Makefile $(TESTS) $(NAME) $(HEADERS)
	$(CC) $(CFLAGS) $(CRITERION_FLAGS) -g3 $(TESTS) $(NAME) -o test

clean:
	rm -f $(OBJS) test

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
