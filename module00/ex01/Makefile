CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++98 -I./include

OBJ_DIR = obj
INC_DIR = include

SRCS = main.cpp \
       phoneBook.cpp \
       contact.cpp

OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

EXEC = phonebook

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

$(OBJ_DIR)/%.o:%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
