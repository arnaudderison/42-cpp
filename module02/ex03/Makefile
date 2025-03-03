CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MD -MP -I./include

OBJ_DIR = obj
INC_DIR = include

SRCS = main.cpp \
	     Fixed.cpp \
			 Point.cpp \
			 bsp.cpp

OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)
EXEC = fixed 

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

$(OBJ_DIR)/%.o:%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
