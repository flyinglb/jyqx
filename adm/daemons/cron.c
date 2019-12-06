// TIEYU@FY3
// This is a daemon that calls itself every minte. it checks
// all major daemons to make sure that they are up and running.

#include <ansi.h>
#include <command.h>
#include <net/daemons.h>
#include <net/macros.h>

int LAST_HARD_DIS= 0;
void init_cron();
void autosave();
void check_dns();
void check_whonature();
void create()
{
 	seteuid( ROOT_UID );
	init_cron();
}
int query_last_hard_dis()
{
	return LAST_HARD_DIS;
}
int set_last_hard_dis()
{
	LAST_HARD_DIS = time();
	return time();
}
void init_cron()
{
	mixed *local;
	local = localtime(time());
// every 45 mins, autosave every player
//	if ( !((local[1])%45)) autosave();
// On average tasks get renewed every 30 mins
//        if ( !random(30)) 
//	TASK_D->init_dynamic_quest();
// Check pets that's lost heartbeat
	if( !(local[1]%5)) 
       if(!find_object(VOID_OB))
                call_other(VOID_OB,"???");
       if(!find_object("/d/wizard/start_room")) call_other("/d/wizard/start_room","???");
       if(!find_object("/u/robin/workroom")) call_other("/u/robin/workroom","???");
// if dns_master not working, every 15 mins re-initalize it
	if ( !(local[1]%15)) 
	{
	check_dns();
// if WHO_D,NATURE_D dies restart them
//        check_whonature();
	STATUS_D->write_list();
	}
	call_out("init_cron", 60);	
}
void autosave()
{
 object *user ;
 int i;
         user = users();
        message("system", HIR "\n �Զ��浵������", users());
        for(i=0; i<sizeof(user); i++) 
        user[i]->save();
	message("system", HIG "�������浵��� \n" NOR, users()); 
}
void check_dns()
{
	mapping mud_list;
	mixed *muds;
	object dns;

	if(!dns = find_object(DNS_MASTER))
	// dns not started, not our problem
	return;
	mud_list = (mapping) DNS_MASTER->query_muds();
	muds=keys(mud_list);
	if(sizeof(muds)<= 1)
	{ destruct(dns);
	call_other(DNS_MASTER,"???");
	}
	return;
}

void check_whonature()
{
	mixed *info;
	int i;
	object ob;
	int who=0, nature=0;
	info = call_out_info();
	for(i=0; i<sizeof(info); i++)
	{
	if( "/"+sprintf("%O",info[i][0]) == WHO_D ) who =1;
	if( "/"+sprintf("%O",info[i][0]) == NATURE_D ) nature=1;
	}
	if(!who)
	{
		if(ob=find_object(WHO_D)) destruct(ob);
		call_other(WHO_D,"???");	
	}
        if(!nature)
        {
                if(ob=find_object(NATURE_D)) destruct(ob);
                call_other(NATURE_D,"???");
        }
        return;
}

