// qiankundanuoyi.c Ǭ����Ų��
// by King 97.05
inherit SKILL;
string *parry_msg = ({
    "$Nһ�л���$n���ϣ�ȴ��$n����Ǭ����Ų�ƣ�����������������¡�\n",
    "$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n",
    "$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n",
    "$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n",
    "$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�\n",
    "$n��ǣ������$N��������������ת�˺ü���Ȧ��\n",
    "$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n",
    "$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������\n",
});
string *dodge_msg = ({
    "$Nһ�л���$n���ϣ�ȴ��$n����Ǭ����Ų�ƣ�����������������¡�\n",
    "$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n",
    "$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n",
    "$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n",
    "$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�\n",
    "$n��ǣ������$N��������������ת�˺ü���Ȧ��\n",
    "$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n",
    "$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������\n",
});
int valid_enable(string usage) 
{ 
    return (usage == "parry") || (usage == "dodge");
}
string query_parry_msg(object me,object weapon)
{
       me->set_temp("fight/parry", (int)me->query_skill("qiankundanuoyi",1));
       return parry_msg[random(sizeof(parry_msg))];
}
string query_dodge_msg(string limb,object me)
{
        me->set_temp("fight/dodge",me->query_skill("qiankundamuoyi",1));
        return dodge_msg[random(sizeof(dodge_msg))];
}
int valid_learn(object me)
{
    return notify_fail("Ǭ����Ų��ֻ��ͨ����<<Ǭ����Ų��>>�ķ���ߡ�\n");
}
int practice_skill(object me)
{
    return notify_fail("Ǭ����Ų��ֻ��ͨ����<<Ǭ����Ų��>>�ķ���ߡ�\n");
}
string perform_function_file(string func)
{
        return __DIR__"qiankundanuoyi/" + func;
}
