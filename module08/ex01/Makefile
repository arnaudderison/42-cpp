NAME = Span
SRC = ./src/Span.cpp ./src/main.cpp 
OBJ_DIR = obj
OBJS = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
CC = c++# Cherche les fichie# Cherche les fichiers sources (récursivement)s sources (récursivement)
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MD -MP -I./include

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(OBJS:.o=.d)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
