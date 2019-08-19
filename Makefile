# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/07 18:32:39 by kmira             #+#    #+#              #
#    Updated: 2019/08/19 02:15:05 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -O2

INCLUDES = includes
LIBRARY = libft/libft.a

CONVERSION_FILES = \
		c_conversion \
		d_conversion \
		f_conversion \
		f_l_conversion \
		f_utils \
		i_conversion \
		o_conversion \
		p_conversion \
		perc_conversion \
		s_conversion \
		u_conversion \
		x_conversion

MAIN_FILES = \
		apply_flags \
		args_tools \
		conversion_parser \
		global_structs \
		main \
		utils \


SRCS_PATH = $(MAIN_FILES)
SRCS_PATH += $(addprefix conversions/, $(CONVERSION_FILES))

SRCS = $(addprefix srcs/, $(addsuffix .c, $(SRCS_PATH)))
OBJS = $(addsuffix .o, $(MAIN_FILES))
OBJS += $(addsuffix .o, $(CONVERSION_FILES))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

# ar -x $(LIBRARY)
# extracts the o files from an .a file
$(NAME): $(LIBRARY) $(OBJS)
	@echo "$(GREEN)Making your printf.a"
	@ar -rcs $(NAME) libft/*.o $(OBJS)
	@echo "$(GREEN)DONE"

$(LIBRARY):
	make -C libft/

$(OBJS):
	@gcc $(FLAGS) -I$(INCLUDES) -c $(SRCS)

clean:
	@echo "$(RED)Cleaning your .o files"
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C libft/
	@echo "$(RED)Removing ft_printf.a"
	@rm -f $(NAME)

re: fclean all

quick: clean
	@rm -f $(NAME)
	make all
	@make clean
	@clear

test: quick
	@gcc -I$(INCLUDES) -o test.out minimain.c $(NAME)
