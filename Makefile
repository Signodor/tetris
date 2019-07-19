##
## EPITECH PROJECT, 2018
## Makefile infinadd
## File description:
## Make File for infinite add project
##

#	CONFIGURATIONS

NAME		=		tetris

MAIN		=		main.c

ROOT		=		.

SRC_DIR		=		$(ROOT)/src

TESTS_DIR	=		$(ROOT)/tests

LIB_DIR		=		$(ROOT)/libraries

BUILD_DIR	=		$(ROOT)/builds

ASM_DIR		=		$(ROOT)/asm

INCLUDE_DIR	=		$(ROOT)/include

HEADERS		:=		$(shell find $(INCLUDE_DIR)/ -type f -name '*.h')

SRC			:=		$(shell find $(SRC_DIR)/ -type f -name '*.c')

SRC_TESTS	:=		$(shell find $(SRC_DIR) $(TESTS_DIR) -type f -name '*.c' -not -path $(SRC_DIR)/$(MAIN) 2> /dev/null)

LIBRARIES	:=		$(shell find $(LIB_DIR) -type d -maxdepth 1 -not -path "$(LIB_DIR)" 2> /dev/null)

OBJ			=		$(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

OBJ_TESTS	=		$(SRC_TESTS:$(ROOT)/%.c=$(BUILD_DIR)/%.o)

ASM			=		$(SRC:$(SRC_DIR)/%.c=$(ASM_DIR)/%.s)

WARN		=		-W -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable -Wunreachable-code

CFLAGS		=		-D _GNU_SOURCE -Iinclude/

LDFLAGS		=		-L$(LIB_DIR) $(addprefix -l,$(notdir $(LIBRARIES))) -lncurses

DEB			=		$(WARN) -D_DEBUG -g3 -O0 

PROD		=		-DNDEBUG

CC			=		gcc

V			=		@

#	COLORS

GREEN		=		\e[1;32m

WHITE		=		\e[0m

ORANGE		=		\e[38;5;208m

RED			=		\e[38;5;196m

BLUE		=		\e[1;34m

PINK		=		\e[38;5;198m

#	PERCENTAGE

THIS		=		$(firstword $(MAKEFILE_LIST))	

ifndef ECHO
T			:=		$(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
      				-nrRf $(THIS) \
      				ECHO="COUNTTHIS" | grep -c "COUNTTHIS")
N			:=		x
C			=		$(words $N)$(eval N := x $N)
ECHO		=		echo -ne "$(PINK)\r[`expr $C '*' 100 / $T`%]"
endif

ifeq ($(BUILD), debug)
CFLAGS		+=		$(DEB)
else
CFLAGS		+=		$(PROD)
endif

all:	$(NAME)
	@$(ECHO) "$(GREEN)All done$(WHITE)"

debug:
	$(V)$(MAKE) --no-print-directory -s $(THIS) all BUILD=debug

compile_lib:	$(LIBRARIES)
	$(V)printf "$(BLUE)Compile libraries : $(GREEN)success$(WHITE)\n"

$(NAME):	compile_lib	$(OBJ)
	$(V)printf "$(BLUE)Compile sources : $(GREEN)success$(WHITE)\n"
	$(V)printf "$(BLUE)Linking [ $(GREEN)$(subst $(BUILD_DIR)/,,$(OBJ)) $(LDFLAGS)$(BLUE) -> $(RED)$(notdir $@)$(BLUE) ]\n$(WHITE)"
	$(V)$(CC) $(COMPILE_RULES) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
	$(V)printf "$(BLUE)Linking obj and Libraries : $(GREEN)success$(WHITE)\n"

$(BUILD_DIR)/%.o:	$(SRC_DIR)/%.c	$(HEADERS)
	$(V)mkdir -p $(dir $@)
	@$(ECHO) "$(BLUE)Compiling [ $(GREEN)$(notdir $<)$(BLUE) -> $(ORANGE)$(notdir $@)$(BLUE) ]$(WHITE)"
	$(V)$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

asm:	$(ASM)
	$(V)printf "$(BLUE)Assembling sources :$(GREEN) success$(WHITE)\n"

$(LIBRARIES):
	$(V)printf "$(BLUE)Compile library : $(ORANGE)$(notdir $@)$(WHITE)\n"
	$(V)make --no-print-directory -C $@

$(ASM_DIR)/%.s:	$(SRC_DIR)/%.c	$(HEADERS)
	$(V)mkdir -p $(dir $@)
	$(V)printf "$(BLUE)Sourcing [ $(GREEN)$(notdir $<)$(BLUE) -> $(ORANGE)$(notdir $@)$(BLUE) ]\n$(WHITE)"
	$(V)$(CC) -o $@ -S $< $(CFLAGS) $(LDFLAGS)

$(BUILD_DIR)/%.o:	$(ROOT)/%.c	$(HEADERS)
	$(V)mkdir -p $(dir $@)
	$(V)printf "$(BLUE)Compiling (test) [ $(GREEN)$(notdir $<)$(BLUE) -> $(ORANGE)$(notdir $@)$(BLUE) ]\n$(WHITE)"
	$(V)$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

tests_run:	compile_lib	$(OBJ_TESTS)
	$(V)printf "$(BLUE)Compile sources and tests : $(GREEN)success$(WHITE)\n"
	$(V)$(CC) $(CFLAGS) $(OBJ_TESTS) $(LIB) -o unit_test -Iinclude -lcriterion --coverage $(LDFLAGS)
	$(V)printf "$(BLUE)Linking obj and Libraries : $(GREEN)success$(WHITE)\n"
	$(V)printf "$(BLUE)Launching tests...$(WHITE)\n"
	$(V)./unit_test
	$(V)gcovr --branches --exclude tests
	$(V)rm -f unit_test

clean:
	$(V)find $(ROOT) -name \*.o -type f -delete
	$(V)rm -rf $(BUILD_DIR)
	$(V)printf "$(ORANGE)Removing object files.$(WHITE)\n"
	$(V)find $(ROOT) -name \*.gcda -type f -delete
	$(V)find $(ROOT) -name highscore.txt -type f -delete
	$(V)find $(ROOT) -name \*.gcno -type f -delete
	$(V)find $(ROOT) -name \*.s -type f -delete
	$(V)rm -rf $(ASM_DIR)
	$(V)printf "$(ORANGE)Removing assembly files.$(WHITE)\n"

fclean:	clean
	$(V)find $(ROOT) -name \*.a -type f -delete
	$(V)printf "$(ORANGE)Removing compiled libraries file.$(WHITE)\n"
	$(V)rm -f $(NAME)
	$(V)printf "$(ORANGE)Removing binary file.$(WHITE)\n"

run:
	$(V)./$(NAME)

re:
	$(V)$(MAKE) --no-print-directory -s $(THIS) fclean
	$(V)$(MAKE) --no-print-directory -s $(THIS) all

.PHONY:	all	$(NAME)	fclean	clean	run	re	tests_run	asm	compile_lib	$(LIBRARIES)	debug
