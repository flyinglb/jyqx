// dodge.c
#include <ansi.h>
inherit SKILL;
string *dodge_msg = ({
        "���Ǻ�$p$lƫ�˼��硣\n",
        "���Ǳ�$p����ض㿪�ˡ�\n",
        "����$n����һ�࣬���˿�ȥ��\n",
        "���Ǳ�$p��ʱ�ܿ���\n",
        "����$n����׼�������Ų�æ�Ķ㿪��\n",
});
string query_dodge_msg(string limb,object me)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
void skill_improved(object me)
{
    if (me->query_skill("dodge",1)%10==0) {
        tell_object(me, HIW "������������գ������������ˡ�\n" NOR);
    }
}

