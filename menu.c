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
		printf("\n[n/N] Nouveau Utilisateur.\n[o/O] Utilisateur déja inscrit.\n\nVotre choix : ");
		b = getchar();
		getchar();
	} while (b != 'n' && b != 'o' && b != 'N' && b != 'O');
	return (b);
}


