// mizong-xinfa.c �����ķ�
// by secret

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int practice_skill(object me)
{	
        return notify_fail("�����ķ�ֻ��ͨ��ѧϰ(learn)�����!\n");
}
