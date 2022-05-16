NAME = megaphone

# Paths

SRC_PATH = ../ex00/
OBJ_PATH = ../../obj/

# Names

SRC_NAME =	megaphone.cpp\

OBJ_NAME = $(SRC_NAME:.cpp=.o)

# Files
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

# Flags

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Build $(NAME)"
	@$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) -I$(SRC_PATH) -o $@ -c $<

clean:
	@echo "Delete $(OBJ_PATH)"
	@rm -rf $(OBJ_PATH) db

fclean:	clean
	@echo "Delete $(NAME)"
	@rm -f $(NAME) db

re:	fclean all

.PHONY: all clean fclean re mlx libft db
