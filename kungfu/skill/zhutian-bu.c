// zhutian-bu.c ���컯��
// modified by Venus Oct.1997
// written by That

inherit SKILL;

string *dodge_msg = ({
    "ֻ��$nһ�С���ع����������ڿգ�˫�����ϣ���ֱ���������࣬�����$N��һ�С�\n",
    "$n������ת��һʽ�����ͷ��ͷ��ǰͦ�������ո���ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
    "$n˫��ץ�أ�����΢�Σ�һ�С�ӥצ�ɡ��о����յرܿ���$N��һ�С�\n"
    "����$n����Ʈ����һʽ���������������һ�ݣ����ѱܿ���\n",
    "$nһ������������������ݳ�����֮Զ���ܿ���$N���������ƣ��������۽�$N���ԡ�\n",
    "$nʹ�������¿ۡ���˫���繳��һ��ƮȻ�ݳ��������ŵء�\n"
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move");
 }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
      if((int)me->query("qi") < 40 )
  return notify_fail("�������̫���ˣ����������컯����\n");
      me->receive_damage("qi", 30);
      return 1;
}
