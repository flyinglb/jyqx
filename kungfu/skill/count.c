
// count.c

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{}

int valid_learn(object me)
{

        mapping myfam;
        myfam = (mapping)me->query("family");
        if(!myfam || myfam["family_name"] != "�һ���"|| myfam["master_id"] != "huang yaoshi")
                return notify_fail("ֻ�л�ҩʦ�ĵ��Ӳ���ѧ�������ԡ�\n");
        if( (int)me->query_skill("literate",1) < 50 )
                return notify_fail("��Ķ���д��̫�ͣ�û�а취ѧ�������ԡ�\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("��������ֻ����ѧ(learn)�������������ȡ�\n");
}
