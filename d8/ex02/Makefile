NAME = MutantStack

# Paths

SRC_PATH = ./src/
OBJ_PATH = ./obj/
TEST_PATH = ./test/

# Names

SRC_NAME =	main.cpp\

OBJ_NAME = $(SRC_NAME:.cpp=.o)

TEST_SRC_NAME =	test_main.cpp \

TEST_HEADER_NAME =	test_utils.h \

# Files
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
DEP_NAME := $(patsubst %.o,%.d,$(OBJ))
TEST_SRC = $(addprefix $(TEST_PATH),$(TEST_SRC_NAME))
TEST_HEADER = $(addprefix $(TEST_PATH), $(TEST_HEADER_NAME))

# Flags
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98
MAKE_DEP_FLAGS = -MMD
TEST_FLAGS	= -pthread -lgtest

ifeq ($(MAKECMDGOALS),test)
	CPPFLAGS += -g -D TESTING
endif

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Build $(NAME)"
	@$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) -I$(SRC_PATH) $(MAKE_DEP_FLAGS) -c $< -o $@

clean:
	@echo "Delete $(OBJ_PATH)"
	@rm -rf $(OBJ_PATH) db

fclean:	clean
	@echo "Delete $(NAME)"
	@rm -f $(NAME) db

test: $(OBJ) $(SRC) $(TEST_SRC) $(TEST_HEADER)
	$(CXX) -g -D TESTING $(OBJ) $(TEST_SRC) $(MAKE_DEP_FLAGS) $(TEST_FLAGS) -I./$(SRC_PATH) $(TEST_FLAGS) -lm -o $(NAME)_test

-include $(DEP_NAME)

re:	fclean all

.PHONY: all clean fclean re mlx libft db
