// yanfly.c ��˫��

inherit SKILL;

string *dodge_msg = ({
    "$nһ��������˫�ɡ�������$N�Ĺ���Ʈ�𣬴��ݶ����һ�С�\n",
    "$nʹ��һ�С����ഩ�ơ�����Ȼ�������࣬���$N���˸��ա�\n",
    "$n����һҡ���ó�������Ӱ��һ�С�������ˮ�������$N�Ĺ��ơ�\n",
    "$nһ�С�����Ͷ�֡�����Ծ��ٿ��������$N���\n",
    "$n��һҡ����һ�Σ�һ�С�������ૡ�������������\n",
});

int valid_enable(string usage)
{
    return (usage == "dodge") ;
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
                return notify_fail("�������̫���ˣ���������˫�ɡ�\n");
        if (me->query_skill("yan-fly", 1) < 30)
                me->receive_damage("qi", 10);

        me->receive_damage("qi", 20);
        return 1;
}

