//#pragma optimize all
//#pragma optimize

#include "/adm/simul_efun/atoi.c"
#include "/adm/simul_efun/chinese.c"
#include "/adm/simul_efun/file.c"
#include "/adm/simul_efun/gender.c"
#include "/adm/simul_efun/object.c"
#include "/adm/simul_efun/path.c"
#include "/adm/simul_efun/wizard.c"
#include "/adm/simul_efun/tail.c"

// This must be after gender.c
#include "/adm/simul_efun/message.c"

// This must be after atoi.c and chinese.c
#include "/adm/simul_efun/ftime.c"

void create()
{
	seteuid(getuid());
	write("simul_efun loaded successfully.\n");
}
