// yunlong-xinfa.c �����ķ�
inherit SKILL;
void create() { seteuid(getuid()); }
string type() { return "knowledge"; }
int practice_skill(object me)
{   
    return notify_fail("�����ķ�ֻ�ܿ�ѧ(learn)����ߡ�\n");
}
