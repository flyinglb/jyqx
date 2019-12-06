// pixie-jian.c ��а����
// Jay 4/5/96

inherit SKILL;

string *dodge_msg = ({
        "ͻȻ֮�䣬��Ӱ���ϣ�$n��󻬳����࣬��ʱ�ֻص���ԭ�أ������$N��һ�С�\n",
        "$n�ֱۻ�ת����$N������һ�ƣ�˳������һ�ԡ�\n",
        "$n�����������$N������Ѹ���ޱȵ�һ����˳������һ�ԡ�\n",
        "$n����Ʈ����������ȣ�ת�˼�ת���Ʋ���$N����󣬶����$N��һ�С�\n",
        "$Nֻ����ǰһ�����ƺ�����$n����һ�ϣ����漴�ּ�$n�ص�ԭ�أ�ȴ�ƴ�δ�뿪��\n",
	"$N�۾�һ����$n��û����Ӱ��ͻȻ$n���������һ��$N��ͷ������Ծ����\n",
	"$n��ȻһЦ������֮����$N����֪����Ǻã�ͣס�˹�����\n",
});

string *parry_msg = ({
        "ͻȻ֮�䣬��Ӱ���ϣ�$n��󻬳����࣬��ʱ�ֻص���ԭ�أ�����$N��һ�С�\n",
        "$n�ֱۻ�ת����$N������һ�ƣ�˳������һ�ԡ�\n",
        "$n�����������$N������Ѹ���ޱȵ�һ����˳������һ�ԡ�\n",
        "$n����Ʈ����������ȣ�ת�˼�ת���Ʋ���$N����󣬼ܹ���$N��һ�С�\n",
        "$Nֻ����ǰһ�����ƺ�����$n����һ�ϣ����漴�ּ�$n�ص�ԭ�أ�ȴ�ƴ�δ�뿪��\n",
	"$N�۾�һ����$n��û����Ӱ��ͻȻ$n���������һ��$N��ͷ������Ծ����\n",
	"$n��ȻһЦ������֮����$N����֪����Ǻã�ͣס�˹�����\n",
});

mapping *action = ({
([      "action":"ͻȻ֮�䣬��Ӱ���ϣ�$N��󻬳����࣬��ʱ�ֻص���ԭ��",
        "force" : 80,
        "dodge" : 40,
        "damage": 40,
        "lvl" : 0,
        "skill_name" : "��Ӱ����",
        "damage_type":  "����"
]),
([      "action":"$N�����������$n������Ѹ���ޱȵ�һ����$n��Щ�����Լ�С��",
        "force" : 90,
        "dodge" : 30,
        "damage": 50,
        "lvl" : 0,
        "skill_name" : "�Լ�С��",
        "damage_type":  "����"
]),
([      "action":"�����$N�����ϣ��ڵ�$n�������Ծ��ԭ��",
        "force" : 80,
        "dodge" : 60,
        "damage": 70,
        "lvl" : 25,
        "skill_name" : "������",
        "damage_type":  "����"
]),
([      "action":"$NͻȻ���з�һ�䣬$w�����������ʽ������ס�$n����֮�з������",
        "force" : 80,
        "dodge" : 40,
        "damage": 50,
        "lvl" : 5,
        "skill_name" : "�з�һ��",
        "damage_type":  "����"
]),
([      "action":"$N����Ʈ����������ȣ�ת�˼�ת���Ʋ���$n�����",
        "force" : 90,
        "dodge" : 40,
        "damage": 90,
        "lvl" : 10,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action":"$Nһ����Ц������Ｒ����ǰ��һ˲֮�䣬��$n����Ѳ���һ�ߣ�$w�漴�ݳ�",
        "force" : 140,
        "dodge" : -5,
        "damage": 100,
        "lvl" : 10,
        "skill_name" : "������ǰ",
        "damage_type":  "����"
]),
([      "action":"$N�ȵ������ã������㼴�γ�$w�����ִ̳�������ת����ȥ",
        "force" : 80,
        "dodge" : 30,
        "damage": 50,
        "lvl" : 0,
        "skill_name" : "���ִ̳�",
        "damage_type":  "����"
]),
([      "action":"$nֻ����ǰһ�����ƺ�����$N����һ�ϣ����漴�ּ�$N�ص�ԭ�أ�ȴ�ƴ�δ�뿪",
        "force" : 140,
        "dodge" : 80,
        "damage": 100,
        "lvl" : 20,
        "skill_name" : "��ǰһ��",
        "damage_type":  "����"
]),
([      "action":"$N����ˣ�$n��׷������ͻȻ��$N����$n��ǰ������$wֱָ$n��$l",
        "force" : 60,
        "dodge" : 10,
        "damage": 40,
        "lvl" : 5,
        "skill_name" : "�����",
        "damage_type":  "����"
]),
([      "action":"$N��س嵽$n��ǰ������$wֱ��$n���ۣ�$n��æ�мܣ�����$N��$wͻȻת��",
        "force" : 200,
        "dodge" : 4,
        "damage": 100,
        "lvl" : 45,
        "skill_name" : "ֱ������",
        "damage_type":  "����"
]),
([      "action":"$N����Ծ��$ņ��һ����������$N����ֱ����£�����$w����$n��$l",
        "force" : 340,
        "dodge" : 20,
        "damage": 105,
        "lvl" : 64,
        "skill_name" : "����Ծ��",
        "damage_type":  "����"
]),
([      "action":"$N��֦�Ͱڣ�$n��ǰ�·�ͻȻ�������߰˸�$N���߰�ֻ$wһ�����$n",
        "force" : 380,
        "dodge" : 60,
        "damage": 130,
        "lvl" : 79,
        "skill_name" : "��֦�Ͱ�",
        "damage_type":  "����"
]),
});


int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "dodge" || usage == "parry"; 
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("pixie-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
        return notify_fail("��а����ֻ��ͨ����ϰ���������䡷��ѧϰ��\n");
}

