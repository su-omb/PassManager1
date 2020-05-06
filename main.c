#include "pass.h"

int 	main(void)
{
	user user;

	user.f = NULL;
	user.is_new = is_new();
	if (user.is_new == 'n' || user.is_new == 'N')
		create_file(&user);
	return (0);
}
