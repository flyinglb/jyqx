// qimen-wuxing
inherit SKILL;
void create() { seteuid(getuid()); }
string type() { return "knowledge"; }
int practice_skill(object me)
{   
    return notify_fail("���������ܿ�ѧ(learn)����ߡ�\n");
}
