// buddhism.c
inherit SKILL;
void create() { seteuid(getuid()); }
string type() { return "knowledge"; }
int valid_learn(object me) 
{
    if( (int)me->query("guilty") > 0 )
        return notify_fail("���ŷ�ɮ�����䣬����֮��̫�أ��޷����������ķ���\n");
    return 1;
}
int practice_skill(object me)
{   
    return notify_fail("�����ķ�ֻ�ܿ�ѧ(learn)����ߡ�\n");
}
