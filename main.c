#include "pass.h"

int 	main(void)
{
	user user;

	user.f = NULL;
	user.is_new = is_new();
	if (user.is_new == 'n')
		create_file(&user);
	return (0);
}
