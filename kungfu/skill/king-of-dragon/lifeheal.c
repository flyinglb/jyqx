// lifeheal.c
#include <ansi.h>
int exert(object me, object target)
{
    if ( !wizardp (me)) return 0;
    if( !target )
        return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");
    message_vision(
        HIY "$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n\n"
        "���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
        me, target );
    target->set("eff_qi", target->query("max_qi"));
    target->set("qi", target->query("max_qi"));
    return 1;
}
