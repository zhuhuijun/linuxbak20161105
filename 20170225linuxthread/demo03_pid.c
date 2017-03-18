#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
int main(int argc,char *argv[])
{
	printf("pid>>>>%d\n", getpid());
	printf("pid>>>>%d\n", getppid());
	char* loginid = getlogin();
	struct passwd *ps = getpwnam(loginid);
	printf("username =%s\n", ps->pw_name);
	printf("uid = %d\n",ps->pw_uid );
	printf("home_dir=%s\n",ps->pw_dir );
	printf("%d\n",system("ls -l"));
	return EXIT_SUCCESS;
}