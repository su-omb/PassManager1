# include "pass.h"

void	get_password(char *pass)
{
	char c;
	int i;

	i = -1;
	while (++i < 255)
	{
		c = getch();
		if (c == '\r')
			break ;
		pass[i] = c;
		printf("*");
	}
	pass[i] = 0;
}

void	gather_info(user *user)
{
	int p;
	int len;

	printf("\nEntrez les donn�es suivantes:\n\nUser_Name : ");
	scanf("%s",user->name);
	p = 1;
	do {
		printf("\nMot de passe pour votre archive : ");
		get_password(user->pass);
		len = strlen(user->pass);
		if (len < 8 || len > 20)
		{
			printf("\nErreur : Longueur du mot de passe :\n\t===> [ 8 < Nombre des caracteres < 20 ]\n");
			continue ;
		}
		if (strcmp(user->pass, user->name) == 0)
		{
			printf("\nErreur : Condition du mot de passe :\n\t===> [ Different de User_Name ]\n");
			continue ;
		}
		printf("\nConfirmez le mot de passe : ");
		get_password(user->confirmed_pass);
		p = strcmp(user->pass, user->confirmed_pass);
		if (p != 0)
			printf("\nErreur : Les deux mots de passe ne sont pas identiques !\n");
	} while (p != 0);
}

int		create_file(user *user)
{
	gather_info(user);

	user->f = fopen(user->name, "w");
	fprintf(user->f, "%s", user->pass);
}
