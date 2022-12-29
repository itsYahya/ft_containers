# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 16:39:26 by yel-mrab          #+#    #+#              #
#    Updated: 2022/12/27 16:50:34 by yel-mrab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -ggdb
INC = -Iinc/algorithme -Iinc/iterators -Iinc/vector -Iinc/type_traits -Iinc/pair -Iinc/stack
BUILD = build
OUT = containers

HEADERSFILES = iterators/base_iterator iterators/iterator_traits iterators/random_iterator iterators/reverse_iterator \
				vector/vector pair/pair stack/stack
				
HEADERS := $(addprefix inc/, $(HEADERSFILES:=.hpp))

FILES = stack_tests

OBJS := $(addprefix $(BUILD)/, $(FILES:=.o))

all : $(OUT)
	
$(OUT) : $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(OUT)

$(BUILD)/%.o : src/%.cpp $(HEADERS)
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INC)

clean :
	rm -rf $(BUILD)

fclean : clean
	rm -rf $(OUT)

re : fclean all

.PHONY : re fclean clean all