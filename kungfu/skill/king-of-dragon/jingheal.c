// jingheal.c
#include <ansi.h>
int exert(object me, object target)
{
    if ( !wizardp(this_player()) )
        return notify_fail("����Ȩ���о������ƣ�\n");
    if( !target )
        return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");
    message_vision(
        HIY "$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n\n"
        "���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
        me, target );
    target->set("eff_jing", target->query("max_jing"));
    target->set("jing",target->query("max_jing"));
    return 1;
}
