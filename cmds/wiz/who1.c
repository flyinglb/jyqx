// who1.c

inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string str)
{
    object where, ob, *ob_list;
    int i;
//    string stri;
    seteuid(getuid());

    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());
    str = HIG"   �������           ��        ��       ��      ����     ����ֵ Ǳ��\n"NOR;
    str += "��������������������������������������������������������������������������\n";
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        where = environment(ob);

        str += sprintf(WHT"%-16s:  ",ob->name()+"("+ob->query("id")+")");
        str += sprintf(RED"%-4d/%-4d ", ob->query("jing"), ob->query("max_jing"));
        str += sprintf(YEL"%-4d/%-4d ", ob->query("qi"), ob->query("max_qi"));
        str += sprintf(GRN"%-7d ", ob->query("shen"));
        str += sprintf(BLU"%-4d/%-4d ", ob->query("neili"), ob->query("max_neili"));
        str += sprintf(MAG"%-7d ", ob->query("combat_exp"));
        str += sprintf(CYN"%-3d \n"NOR, ob->query("potential")-ob->query("learned_points"));
    }
    str += "��������������������������������������������������������������������������\n";
    str = sprintf("%s���� %d λʹ���������С�\n", str, sizeof(ob_list));
    me->start_more(str);
    return 1;
}
int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	if( wizardp(ob2) && !wizardp(ob1) ) return 1;
	if( wizardp(ob1) && wizardp(ob2) )
		return (int)SECURITY_D->get_wiz_level(ob2) 
			- (int)SECURITY_D->get_wiz_level(ob1);
	
	return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}
int help(object me)
{
        write(@HELP
ָ���ʽ��who1

�����Ϣ��ѯ��
HELP
        );
        return 1;
}
