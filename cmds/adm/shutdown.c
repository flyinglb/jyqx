// shutdown.c
// modified by wind

#include <net/daemons.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string wiz_status;
	object *user, link_ob;
	int i;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if(query_wiz_level(wiz_status) < query_wiz_level("(arch)"))
		return notify_fail("只有 (arch) 以上的巫师才能重新启动" + MUD_NAME + "\n");

	message( "system", "游戏重新启动，请稍候一分钟再 login 。\n", users() );
                write_file(REBOOTFILE,sprintf("%s（%s）:%d",me->query("name"),me->query("id"),time()),1);

	user = users();
	for(i=0; i<sizeof(user); i++) {
		if( !environment(user[i]) ) continue;
		user[i]->save();
		link_ob = user[i]->query_temp("link_ob");
		if( objectp(link_ob) ) link_ob->save();
	}

	if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();

	shutdown(0);
	return 1;
}
int help (object me)
{
        write(@HELP
指令格式: shutdown
 
马上重新起动游戏。
 
HELP
);
        return 1;
}
 
