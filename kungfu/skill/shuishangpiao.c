// shuishangpiao.c based on zhaixinggong.c
// by zqb

inherit SKILL;

string *dodge_msg = ({
	"$n���һ֧��ȫ�������һ�С����㵹�����������ܳ����࣬�����$N�Ĺ�����\n",
	"$n�����Ȼ�����޹ǣ�����ҡ�ڣ�ʹ��һ�С����ƯƼ�����ܹ���$N�Ĺ�����\n",
	"$nʹ�����ﻻ���ơ���������һ��ת����$N���Բ����������������$N���\n",
        "$nһ�С���Ҷ��硹��������һƬ��Ҷһ��Ʈ�˳�ȥ������֮������Ѹ�ٵ��˼�����\n"
});

int valid_enable(string usage) 
{ 
	return (usage == "dodge") || (usage == "move"); 
}

int valid_learn(object me) { return 1; }

string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jing") < 40 )
                return notify_fail("�������̫���ˣ�������ˮ��Ư��\n");
	if (me->query_skill("shuishangpiao", 1) < 30)
	        me->receive_damage("jing", 10);
	else if (me->query_skill("shuishangpiao", 1) < 60)
		me->receive_damage("jing", 20);
	else 
		me->receive_damage("jing", 30);
        return 1;
}


