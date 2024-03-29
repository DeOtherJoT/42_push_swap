#EXEC NAME#

NAME		= push_swap
BNS_NAME	= checker
GIMME_NUM	= gimme_numbr

#FLAGS#

GCC			= gcc -Wall -Wextra -Werror
FSAN		= -fsanitize=address -g
RM			= rm -rf

#PATH LIB#

LIBFT		= libft
INC			= -Iincludes -I$(LIBFT)
LIB			= libft/libft.a
SRC_DIR		= sources/
SIM_DIR		= $(SRC_DIR)sort_simple/
DRV_DIR		= $(SRC_DIR)driver/
INP_DIR		= $(SRC_DIR)input/
OPR_DIR		= $(SRC_DIR)operation/
STK_DIR		= $(SRC_DIR)stacks/
CPLX_DIR	= $(SRC_DIR)sort_complex/
JFF_DIR		= gimme_numbers/
GNL_DIR		= get_next_line/
MAIN		= $(DRV_DIR)main.c
BNS_MAIN	= $(SRC_DIR)bonus/checker.c

#SOURCE FILES#

SRCS		= $(addprefix $(SIM_DIR), sort_simple.c) \
			  $(addprefix $(INP_DIR), check_input.c input_utils.c process_input.c temp_sort.c parse_input.c) \
			  $(addprefix $(OPR_DIR), move_elem.c op_ins_1.c op_ins_2.c op_ins_3.c op_utils.c) \
			  $(addprefix $(STK_DIR), stacks_init.c) \
			  $(addprefix $(DRV_DIR), driver_utils.c sort_stacks.c) \
			  $(addprefix $(CPLX_DIR), sort_complex.c begin_sort.c process_data.c process_helper.c process_utils.c filter_list.c) \
			  $(addprefix $(GNL_DIR), get_next_line_utils.c get_next_line.c)
JFF_SRCS	= $(addprefix $(JFF_DIR), gimme_numbers.c)
OBJS		= $(SRCS:.c=.o)

#RECIPES#

all		: $(NAME)

bonus	: $(NAME)
	$(GCC) $(INC) -o $(BNS_NAME) $(BNS_MAIN) $(OBJS) $(LIB)

$(NAME)	: $(OBJS)
	$(MAKE) all -C $(LIBFT)
	$(GCC) $(INC) -o $(NAME) $(MAIN) $(OBJS) $(LIB)

%.o		: %.c
	$(GCC) $(INC) -c $< -o $@

clean	:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT)

fclean	: clean
	$(RM) $(NAME) $(GIMME_NUM) $(BNS_NAME)
	$(RM) push_swap.dSYM gimme_numbr.dSYM checker.dSYM
	$(MAKE) fclean -C $(LIBFT);

norm	:
	norminette $(SRC_DIR)
	norminette includes/

fsan	: fclean $(OBJS)
	$(MAKE) all -C $(LIBFT)
	$(GCC) $(INC) -o $(NAME) $(MAIN) $(OBJS) $(LIB) $(FSAN)

gimme	:
	$(MAKE) all -C $(LIBFT)
	$(GCC) $(INC) -o $(GIMME_NUM) $(LIB) $(JFF_SRCS)

re		: fclean all

.PHONY : all clean fclean norm re fsan gimme bonus