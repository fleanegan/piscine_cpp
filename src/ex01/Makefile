NAME = phonebook

# Paths

SRC_PATH = ../ex01/
OBJ_PATH = ../../obj/
TEST_PATH = test/

# Names

SRC_NAME =	megaphone.cpp\

OBJ_NAME = $(SRC_NAME:.cpp=.o)

TEST_SRC_NAME =	test_main.cpp \

TEST_HEADER_NAME =	test_utils.h \

# Files
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
TEST_SRC = $(addprefix $(TEST_PATH),$(TEST_SRC_NAME))
TEST_HEADER = $(addprefix $(TEST_PATH), $(TEST_HEADER_NAME))

# Flags

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -g
TEST_FLAGS	= -pthread -lgtest

ifeq ($(MAKECMDGOALS),test)
	CFLAGS += -g -D TESTING
endif
ifeq ($(MAKECMDGOALS),testinc)
	CFLAGS += -g -D TESTING
endif

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

test: PRE $(OBJ) $(SRC) $(TEST_SRC) $(TEST_HEADER)
	$(CXX) -g -D TESTING -o $(NAME)_test $(OBJ) $(TEST_SRC) $(TEST_FLAGS) -I./$(SRC_PATH) $(TEST_FLAGS) -lm

re:	fclean all

.PHONY: all clean fclean re mlx libft db
