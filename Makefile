CC = g++
LIBRERIE = -lssl

ifeq ($(NAME), )
	NAME = md5Brute
endif

compile: $(NAME)

%.o: %.cpp
	$(CC) -c $< -o $@

$(NAME): md5.o main.o
	@echo "inizio compilazione..."
	$(CC) -o $@ $^ $(LIBRERIE)

clear: md5.o main.o
	rm $^
