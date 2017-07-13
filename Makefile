
NAME = J2T3

CLI = client$(NAME)

SRV = server$(NAME)

CC  = gcc

CFLAGS = -Wall -Wextra -Werror -I./incs/

CLISRCS	 = $(foreach dir,$(shell find cli -type d),$(wildcard $(dir)/*.c))

SRVSRCS	 = $(foreach dir,$(shell find serv -type d),$(wildcard $(dir)/*.c))


OBJS_CLI = $(CLISRCS:.c=.o)

OBJS_SRV = $(SRVSRCS:.c=.o)

all:     $(NAME)

$(NAME): $(CLI) $(SRV)

$(CLI):  $(OBJS_CLI)
	 $(CC) -o $(CLI) $(OBJS_CLI) $(CFLAGS)

$(SRV):  $(OBJS_SRV)
	 $(CC) -o $(SRV) $(OBJS_SRV) $(CFLAGS)

clean:
	rm -f $(OBJS_CLI) $(OBJS_SRV)

fclean:	clean
	rm -f $(CLI) $(SRV)

re:	fclean all

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

-include $(DEPS)

.PHONY: all clean fclean re
