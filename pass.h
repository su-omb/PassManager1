#ifndef PASS_H_INCLUDED
#define PASS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


# define TRUE 1
# define FALSE 0

typedef	struct	user
{
	char is_new;
	char name[256];
	char pass[256];
	char confirmed_pass[256];
	FILE *f;
}				user;

void	display_choices(char *choices);
int		create_file(user *user);

#endif // PASS_H_INCLUDED
