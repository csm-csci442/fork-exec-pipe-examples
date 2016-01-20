SRC = *.cpp
NAME = $(shell basename $(SRC) .cpp).out

all: $(NAME)

$(NAME): $(SRC)
	g++ $(SRC) -o $(NAME)

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(NAME)
