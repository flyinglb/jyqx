// heal.c
#include <ansi.h>
int exert(object me, object target)
{
    if ( !wizardp(me)) return 0 ;
    write( HIY "��ȫ����ɣ���������ʼ�˹����ˡ�\n" NOR);
    message("vision",
        HIY + me->name() + "�³�һ�ڽ�Ӳӵ�Ѫ����ɫ���ָ̻���������\n" NOR,
        environment(me), me);
    me->set("eff_qi", (int)me->query("max_qi"));
    me->set("qi", (int)me->query("max_qi"));
    me->set("eff_jing", (int)me->query("max_jing"));
    me->set("jing", (int)me->query("max_jing"));
    me->set("neili", (int)me->query("max_neili"));
    me->set("jingli", (int)me->query("max_jingli"));
    return 1;
}
