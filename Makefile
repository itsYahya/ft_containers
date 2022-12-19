# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 16:39:26 by yel-mrab          #+#    #+#              #
#    Updated: 2022/12/19 16:47:12 by yel-mrab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INC = -I ./inc
BUILD = build
OUT = containers

HEADERSFILES = iterators/base_iterator iterators/iterator_traits iterators/iterator iterators/reverse_iterator \
				vector/vector
				
HEADERS := $(addprefix inc/, $(HEADERSFILES:=.hpp))

FILES = main

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