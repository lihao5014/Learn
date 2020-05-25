#include "permission.h"

int main()
{
	enum Permission superUser = SuperUser;
	
	fprintf(stdout,"super user has read permission? -- %d\n",isPermission(superUser,READ));
	fprintf(stdout,"super user has cut permission? -- %d\n",isPermission(superUser,CUT));
	showPermission(superUser);
	
	return 0;
}