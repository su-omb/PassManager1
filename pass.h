#ifndef PASS_H_INCLUDED
#define PASS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <conio.h>


# define TRUE 1
# define FALSE 0
# define ENTER 13
# define BKSP 8

typedef	struct	user
{
	char is_new;
	char name[64];
	char pass[64];
	char confirmed_pass[64];
	char path[256];
	FILE *f;
}				user;

void	display_choices(char *choices);
int		create_file(user *user);
void    str_bzero(char *s, int len);


#endif // PASS_H_INCLUDED
