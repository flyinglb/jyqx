#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
//         object ob;
        mapping my;
 
        seteuid(getuid(me));
 
        if(!me->query("weapon"))
                return notify_fail("�㻹û�����Ƶ�������\n");
 
        my = me->query("weapon");
 
    printf(" ��������  �� %12s  ����ʱ�� �� %s\n" , my["name"], my["time"]);
    printf(" ��    ��  �� %12s  ��    �� �� %s\n" , my["or"], my["type"]);
    printf(" Ŀǰ���𡡣� %d/%d\n" ,my["lv"], my["value"]);
        return 1;
}
 
int help(object me)
{
        write(@HELP
ָ���ʽ : exam
 
���ָ�������ʾ�����Ƶ���������ϸ���ϡ�

HELP
    );
    return 1;
}

