##
## EPITECH PROJECT, 2018
## PSU_nmobjdump_2018
## File description:
## Makefile
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
