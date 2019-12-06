// netclub.c
// Created by Eatdami@MX (10/15/2000)

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
        string verb,id;

        if (!arg) {
                BAN_D->print_netclub();
                return 1;
        }

        else if (sscanf(arg, "%s %s",verb,id) < 2)
                return notify_fail("指令格式请参照 help netclub \n");

        switch( verb ) {
                case "add"      :BAN_D->add_netclub_id(id);
                                break;
                case "del"      :BAN_D->del_netclub_id(id);
                                break;
                default         :return notify_fail("指令格式请参照 help netclub \n");
        }

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
