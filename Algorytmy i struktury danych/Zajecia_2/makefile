CFLAGS = -pthread -g - Wall -Werror - pedantic-errors
SOURCES = main.c list.c 
OBJECTS = $(SOURCES:.c=.o)
NAME = list

all: $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) 

$(OBJECTS):
	$(CC) -c $(CFLAGS) $(SOURCES)

clean: 
	rm -f $(NAME)
	rm -f $(OBJECTS)
