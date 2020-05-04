#include "pass.h"

void	display_choices(char *choices)
{
	printf("\n=======> Choix invalide !\nChoix possibles : ");
	while (*choices)
		printf("[%c] ", *choices++);
	puts("");
}

char	is_new()
{
	char b = 'o';

	puts("\n----------- Bienvenue dans PassManager ---------\n");
	do
	{
		if (b != 'n' && b != 'o')
			display_choices("no");
		printf("\n[n] Nouveau Utilisateur.\n[o] Utilisateur déja inscrit.\n\nVotre choix : ");
		b = getchar();
		getchar();
	} while (b != 'n' && b != 'o');
	return (b);
}

int 	main(void)
{
	user user;

	user.f = NULL;
	user.is_new = is_new();
	if (user.is_new == 'n')
		create_file(&user);
	return (0);
}
