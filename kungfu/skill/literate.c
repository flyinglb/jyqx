// literate.c
inherit SKILL;
string type() { return "knowledge"; }
void skill_improved(object me)
{
    int s;
    s = me->query_skill("literate", 1);
    if (s%10==0){
        tell_object(me, HIW "��������ѧ����������������ˡ�\n" NOR);
    }
}
