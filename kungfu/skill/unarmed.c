// unarmed.c
inherit SKILL;
void skill_improved(object me)
{
    if (me->query_skill("unarmed",1)%10==0) {
        tell_object(me, HIW "������������գ������������ˡ�\n" NOR);
    }
}
