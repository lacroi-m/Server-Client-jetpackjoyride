
NAME = J2T3

CLI = client

SRV = server

CC  = gcc

CFLAGS = -Wall -Wextra -Werror -I./incs/ -g3

CLISRCS	 = $(foreach dir,$(shell find cli -type d),$(wildcard $(dir)/*.c))

SRVSRCS	 = $(foreach dir,$(shell find serv -type d),$(wildcard $(dir)/*.c))


OBJS_CLI = $(CLISRCS:.c=.o)

OBJS_SRV = $(SRVSRCS:.c=.o)

all:     $(NAME)

$(NAME): $(CLI) $(SRV)

$(CLI):  $(OBJS_CLI)
	 $(CC) -o $(CLI)$(NAME) $(OBJS_CLI) $(CFLAGS)

$(SRV):  $(OBJS_SRV)
	 $(CC) -o $(SRV)$(NAME) $(OBJS_SRV) $(CFLAGS)

clean:
	rm -f $(OBJS_CLI) $(OBJS_SRV)

fclean:	clean
	rm -f $(CLI)$(NAME) $(SRV)$(NAME)

re:	fclean all

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

-include $(DEPS)

.PHONY: all clean fclean re
