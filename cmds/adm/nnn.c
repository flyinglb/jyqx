// netclub.c
// Created by Eatdami@MX (10/15/2000)

void create()
{
	seteuid(getuid());
}

int main(object me, string site)
{

        object *usr;
        int i,ip_count,max_multilogin;

        
        site = query_ip_number(me);
        max_multilogin =  5;

        usr = children(USER_OB);
        for( i = sizeof(usr)-1,ip_count = 0; i >=0; i-- ) {

                CHANNEL_D->do_channel(this_object(),"sys",sprintf("id:%s,curr:%s\n"
                ,usr[i]->query("id"),usr[i]->query_temp("current_from")));

                if( site == query_ip_number(usr[i])
                ||( site == usr[i]->query_temp("current_from")) )
                        ip_count ++;
                }
                CHANNEL_D->do_channel(this_object(),"sys",sprintf("cn:%d\n"
                ,ip_count));

        if( ip_count > max_multilogin )
                return 0;
        return 1;
	
}

int help(object me)
{
	write(@HELP
指令格式：netclub [add|del id]

这条命令是用来增加和删除网吧ID。
HELP
	);
	return 1;
}
