CFLAGS = -pthread -g -Wall -Werror -pedantic-errors
SOURCES = main.c list.c 
OBJECTS = $(SOURCES:.c=.o)
NAME = list

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)

$(OBJECTS):
	$(CC) -c $(CFLAGS) $(SOURCES)

clean: 
	rm -f $(NAME)
	rm -f $(OBJECTS)
