#include "lem_in.h"

static char *error_messages[] = {
		"MALLOC",
		"NO_VALID",
		"START",
		"END",
		"VAL_LINK",
		"INT",
		"NO_LINK",
		"PATH",
		"ANT",
		"ROOM",
};

void print_error(int id) {
	ft_putstr(error_messages[id]);
	ft_putstr(" ERROR ");
	ft_putstr("\n");
	exit(0);
}
