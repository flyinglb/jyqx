// poison.c ��������
// Modified by Java Mar.1998
inherit SKILL;

void create() { seteuid(getuid()); }
string type() { return "knowledge"; }
int valid_learn(object me)
{
    mapping myfam;
    myfam = (mapping)me->query("family");
    if (!myfam || (myfam["family_name"] != "������"))
       return notify_fail("�㲻�����޵��ӣ���������������\n");

    if ((me->query_skill("taoism",1) > 1) ||
        (me->query_skill("mahayana",1) > 1) ||
        (me->query_skill("buddhism",1) > 1))
        return notify_fail("������"+RANK_D->query_respect(me)
      +"�Ѿ�ѧ���������ɵ��ķ�����ôȴ��ѧ���ǲ��ܵĶ�����\n");

    return 1;
}
void skill_improved(object me)
{
    if ((me->query_skill("poison",1) == 50) ||
        (me->query_skill("poison",1) == 60) ||
        (me->query_skill("poison",1) == 70) ||
        (me->query_skill("poison",1) == 80) ||
        (me->query_skill("poison",1) == 90) ||
        (me->query_skill("poison",1) >= 100))
    {
        tell_object(me, "�����ڵĶ��ʿ�ʼ���������ˣ�������ɢ���ˡ�\n");
        me->apply_condition("poison_sandu",1000);
    }
}

