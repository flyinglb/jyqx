// taxue-wuheng.c

inherit SKILL;

string *dodge_msg = ({
        "$nһ�С�Ϧ����ѩ���������ɵر��˿�ȥ��\n",
        "ֻ��$n��Ӱһ�Σ�һʽ�����Ƽ������ѱ����߳�֮�⡣\n",
        "$nʹ�����������졹���������ɵ�������\n",
        "$n����һ�㣬һ�С������ƶˡ��ڿն��𣬱��˿�ȥ��\n",
        "����$nʹһ�С�̤ѩ�޺ۡ�����������Ʈ�˿�ȥ��\n",
        "$n��Ӱ΢�����Ѿ���һ�С������������������\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge" || usage=="move");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취��̤ѩ�޺ۡ�\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 10 )
                return notify_fail("�����������������������̤ѩ�޺ۡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
        return 1;
}
int effective_level() { return 14;}

int learn_bonus() {	return 16; }

int practice_bonus() { return 13; }

int study_bonus() { return 13; }