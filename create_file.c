# include "pass.h"

void	get_password(char *pass)
{
	char c;
	int i;

	i = 0;
	while (i >= 0)
	{
		c = getch();
		//printf("\ni = %d and c = %c | %d \n", i, c, c);
		if (c == ENTER)
			break ;
        else if (c == BKSP)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            pass[i++] = c;
            printf("*");
        }
	}
	pass[i] = 0;
}

void    make_path(user *user)
{
    user->path[0] = 0;
    strcat(user->path, "./data/");
    strcat(user->path, user->name);
    strcat(user->path, ".pm");
}

void	gather_info(user *user)
{
	int p;
	int len;

	printf("\n Entrez les données suivantes:\n");
	do {
        p = 1;
        printf("\n User_Name : ");
        scanf("%s",user->name);
        make_path(user);
        puts(user->path);
        if (fopen(user->path, "r") != NULL)
        {
            printf("\nErreur : User_Name non disponible :\n");
            p = 0;
        }
        if (strlen(user->name) > 30)
        {
            printf("\nErreur : User_Name Trop longue [Max = 30 Caracteres]:\n");
            p = 0;
        }
	}while (p == 0);
	do {
		printf("\n Mot de passe pour votre archive : ");
		get_password(user->pass);
		len = strlen(user->pass);
		if (len < 8 || len > 20)
		{
			printf("\n Erreur : Longueur du mot de passe :\n\t===> [ 8 < Nombre des caracteres < 20 ]\n");
			continue ;
		}
		if (strcmp(user->pass, user->name) == 0)
		{
			printf("\n Erreur : Condition du mot de passe :\n\t===> [ Different de User_Name ]\n");
			continue ;
		}
		printf("\n Confirmez le mot de passe : ");
		get_password(user->confirmed_pass);
		p = strcmp(user->pass, user->confirmed_pass);
		if (p != 0)
            printf("\n Erreur : Les deux mots de passe ne sont pas identiques !\n");
	} while (p != 0);
}

int     check_extension(char *file_name, char *extension)
{
        int lf;
        int le;

        lf = strlen(file_name);
        le = strlen(extension);
        while (le--)
                if (file_name[--lf] != extension[le])
                        return (0);
        return (1);
}

void	create_file(user *user)
{
	gather_info(user);
    make_path(user);
	user->f = fopen(user->path, "w");
	fprintf(user->f, "%s", user->pass);
	fclose(user->f);
}
