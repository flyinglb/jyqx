// taoism.c
inherit SKILL;
void create() { seteuid(getuid()); }
string type() { return "knowledge"; }
int valid_learn(object me) 
{
    int lvl;
    
    lvl = (int)me->query_skill("taoism", 1);
    
    if(me->query("gender") == "����" && lvl > 39)
        return notify_fail("�����һ�������������Ժ���ԭ����û������֮�����޷��������������仯֮����\n");
        
    if(me->query("class") == "bonze")
        return notify_fail("������"+RANK_D->query_respect(me)
            +"������ţ���ôȴ��ѧ�����ķ���\n");

    return 1;
}
int practice_skill(object me)
{   
    return notify_fail("��ѧ�ķ�ֻ�ܿ�ѧϰ����ߡ�\n");
}
