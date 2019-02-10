##
## EPITECH PROJECT, 2017
## File Name : Makefile
## File description:
## Project Name : linked_lists
##

MODULES	=	lib		\
			nm		\
			objdump	\

RULES	=	all			\
			clean		\
			fclean		\
			re			\
			debug		\
			test_run	\
			test_debug	\

$(RULES):
	for module in $(MODULES); do\
		$(MAKE) --directory=$$module $@;\
	done

nm:
	$(MAKE) --directory=lib
	$(MAKE) --directory=nm

objdump:
	$(MAKE) --directory=lib
	$(MAKE) --directory=objdump

.PHONY: $(RULES) nm objdump
