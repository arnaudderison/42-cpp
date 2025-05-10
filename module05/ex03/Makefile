CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -MD -MP -I./include/core/ -I./include/utils/

SRCDIR = src
INCDIR = include
OBJDIR = build

SRC = $(shell find $(SRCDIR) -name "*.cpp")
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEPS = $(OBJS:.o=.d)
NAME = prog 

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
