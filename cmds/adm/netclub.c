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
                return notify_fail("ָ���ʽ����� help netclub \n");

        switch( verb ) {
                case "add"      :BAN_D->add_netclub_id(id);
                                break;
                case "del"      :BAN_D->del_netclub_id(id);
                                break;
                default         :return notify_fail("ָ���ʽ����� help netclub \n");
        }

        return 1;
	
}

int help(object me)
{
	write(@HELP
ָ���ʽ��netclub [add|del id]

�����������������Ӻ�ɾ������ID��
HELP
	);
	return 1;
}
