// yanling-shenfa.c ������

inherit SKILL;

string *dodge_msg = ({
        "$nһʽ�������Ϸɡ�����Žż�����ҽ���շ�����������������ˮ�㻬�����ࡣ\n",
             "$nһʽ��һҶ��Ŀ����������ת��˫�Űϵض��𣬶�ʱ������$N���������ơ�\n",
            "$nһʽ��˫��ַɡ�������˫������߳����ţ���ʱ�䵽$N���Ͽա�\n",
           "$nһʽ�����ӳ�������ͻȻ������ǰ�ˣ���������ĳ���$N����$N������롣\n",
          "$nһʽ����������������������ȫ��Χ��$N������ת����$N��æ���ң�$n���䵽����Զ�ĵط���\n",
         "$nһʽ������������˫����յ�أ������ݷ����У���$Nͷ����Ծ������\n",
         "$nһʽ�����ӻ�ͷ����˫�����������ƣ�����������Ʈ����ʱ����$N���������ơ�\n",
         "$nһʽ�����Ϲ鳲�������������ݰ㼱ת�������γ�һ�������У���$N������䡣\n",
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jing") < 40 )
            return notify_fail("�������̫���ˣ���������������\n");
        me->receive_damage("jing", 30);
        return 1;
}

 

