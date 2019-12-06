// lonely-sword.c ���¾Ž�

inherit SKILL;

string *parry_msg = ({
        "ȴ��$n̤ǰһ������ʽбָ����ұۣ���Ҫʹ$P������ˡ�\n",
        "$n�Թ�Ϊ�أ��Խ�Ϊ�ˣ�����������$P�͹����ػӳ���λ�����̩ɽ���������������\n",
        "$n����ͻ�䣬�����������������ڽ�ز����ʹ��ɽ�����ġ�������������ͼ��ʹ$P���С�\n",
        "$nͻȻһ������$P��$l����һ��ȴ�����������ţ�$P�����޴룬���Ʋ�������ͣ��������\n"
        "$n�������ܣ��ٽ������ʹ�������両�ࡹ����$P��$l���뵲������С�\n",
        "$nͻȻʹ��������ɷ罣���ġ����ڤڤ�������Ƿ�λȴ����ƫ���������$Pһ�ʣ���\nͼͻ��$P�Ĺ��ƣ�\n"
        "$nͦ��һ�����ǡ����Ƴ�ᶡ��ش�$P��$l����ͼ��$P�Ĺ��ƻ��⡣\n",
        "ֻ��$n���˷���������Ʈ�磬�����һʽ�������������������޶�����׽���ص�ס��$P��\n������\n",
        "$n���˷�����ʹ����ɽ���С�������롹��ɭɭ�����������ܣ��ܿ���$P������\n",
});

mapping *action = ({
([      "action" : "����$Nͦ����ϣ�$wһ����һ�з·�̩ɽ�����ġ�������Ȫ��ֱ��$n
��$l��",
        "force" : 10,
        "dodge" : 5,
        "damage": 60,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N������$n�ӳ���Ȫ��ܽ�ء����������ϸǡ�����ʯ������������
�����������������ף�ڡ���ɽ���񽣣�",
        "force" : 10,
        "dodge" : 0,
        "damage": 60,
        "lvl" : 7,
        "damage_type" : "����"
]),
([
        "action" : "$N������ת�������̳�ʮ�Ž�����Ȼ�ǻ�ɽ����Ůʮ�Ž����������
����ʮ�Ž�����һ�У��ַ�֮�죬ֱ�Ƿ�����˼��",
        "force" : 10,
        "dodge" : 5,
        "damage": 80,
        "lvl" : 14,
        "damage_type" : "����"
]),
([      "action" : "$N���ƺ��������裬�������������������ɽ����Ϊһ������$n����
��ȥ��",
        "force" : 20,
        "dodge" : 15,
        "damage": 80,
        "lvl" : 21,
        "damage_type" : "����"
]),
([      "action" : "$N����ͻ������ɭ�ϣ�����ǧ�������۶�������ǹ��ꪣ���ɳǧ��
��������ɽ���ƻ���$n��$l��",
        "force" : 20,
        "dodge" : 0,
        "damage": 100,
        "lvl" : 28,
        "damage_type" : "����"
]),
([      "action" : "ȴ��$N���潣�ߣ����һ�գ��ұ�һ�䣬����Ҳ��ԽתԽ�Ӻ�������
����̩ɽʮ���̡�Ϊһ������$n��",
        "force" : 30,
        "dodge" : 10,
        "damage": 110,
        "lvl" : 35,
        "damage_type" : "����"
]),
([      "action" : "$N����ͻ�䣬ʹ����ɽ�ġ�һ������㡹������$n��$l����֪������
;��ͻȻת�򣬴��$n����֮�⣡",
        "force" : 40,
        "dodge" : 5,
        "damage": 120,
        "lvl" : 42,
        "damage_type" : "����"
]),
([      "action" : "$N����������һ�����ǡ�������ɽ��������$w����ն�䣬ֱ����$n��
$l��",
        "force" : 50,
        "dodge" : 0,
        "damage": 160,
        "lvl" : 49,
        "damage_type" : "����"
]),
([      "action" : "$N����$wԽתԽ�죬ʹ�ľ�Ȼ�Ǻ�ɽ�ġ��ٱ�ǧ������ʮ��ʽ������
ʽ�����ƾ���ӿ���Թ��߲��ɵ�ĿΪ֮ѣ��",
        "force" : 60,
        "dodge" : 20,
        "damage": 140,
        "lvl" : 56,
        "damage_type" : "����"
]),
([      "action" : "$N��Ц����������ׯ�ϣ�$w��ӣ����ڡ���Ħ����Ϊһʽ������ش�
��$n��",
        "force" : 70,
        "dodge" : 0,
        "damage": 180,
        "lvl" : 63,
        "damage_type" : "����"
]),
([      "action" : "$N����$w��ʹ��̫���������⣬�������СС������ԲȦ�������޾�
ԴԴ�����ز���$n��",
        "force" : 80,
        "dodge" : 20,
        "damage": 160,
        "lvl" : 70,
        "damage_type" : "����"
]),
([      "action" : "$N�������أ�$w�����������Һ�ɨ��Ю�������֮�Ʊ���$n������Ħ
�����Ľ����¶���ţ�",
        "force" : 90,
        "dodge" : 5,
        "damage": 180,
        "lvl" : 77,
        "damage_type" : "����"
]),
([      "action" : "ȴ��$NͻȻ�鲽������ʹ�������䵱�����ѵ�ˮ����һ�У�",
        "force" : 100,
        "dodge" : 15,
        "damage": 120,
        "lvl" : 84,
        "damage_type" : "����"
]),
([      "action" : "$N�˽���磬��������з���$n��$l�����Ա�$n���أ��������ǡ���
ħ�����ġ�����ʽ����",
        "force" : 120,
        "dodge" : 0,
        "damage": 190,
        "lvl" : 91,
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ�˽����һ�ֹ���ġ������罣��������Ȼ��$n�����Ҵ���
����",
        "force" : 140,
        "dodge" : -10,
        "damage": 240,
        "lvl" : 98,
        "damage_type" : "����"
]),
([      "action" : "$N�������ߣ�����һ��������һ������$nĪ������ֲ���$N������
��ʵ��",
        "force" : 160,
        "dodge" : 30,
        "damage": 100,
        "lvl" : 105,
        "damage_type" : "����"
]),
([      "action" : "$N��������ת��$n����������µ���$n�̳�һ������֪ʹ����ʲ
ô������",
        "force" : 180,
        "dodge" : 5,
        "damage": 160,
        "lvl" : 112,
        "damage_type" : "����"
]),
([      "action" : "$NͻȻһ������$n��$l����һ��ȴ�����������ţ�$n�����޴룬��֪
����Ǻã�",
        "force" : 200,
        "dodge" : 0,
        "damage": 190,
        "lvl" : 119,
        "damage_type" : "����"
]),
([      "action" : "$N��Ю���ƣ��󿪴��ص��ҿ�һͨ�������нԻ���$n���Ƶ���������
��$n���ò��أ�",
        "force" : 220,
        "dodge" : -10,
        "damage": 200,
        "lvl" : 126,
        "damage_type" : "����"
]),
([      "action" : "$N���ֺὣ����$n��$l���������������е�һ����������Ȼ���$n
���Կ��彣�����ƣ�",
        "force" : 240,
        "dodge" : -15,
        "damage": 240,
        "lvl" : 133,
        "damage_type" : "����"
]),
([      "action" : "$N�ٽ���ӣ�Ѹ���ޱȵص���$n��$l��ȴ���˿�������������ʲô��
ʽ��",
        "force" : 260,
        "dodge" : 0,
        "damage": 200,
        "lvl" : 140,
        "damage_type" : "����"
]),
([      "action" : "$N����һ��ָ��$n���������$n���������ڣ��˵����������ף�����
˼�飡",
        "force" : 280,
        "dodge" : 40,
        "damage": 120,
        "lvl" : 147,
        "damage_type" : "����"
]),
([      "action" : "$N����ͻ��Ц�ݣ��ƺ��ѿ���$n���书��ʽ�����г����һ������$n
��$l��",
        "force" : 300,
        "dodge" : 20,
        "damage": 240,
        "lvl" : 154,
        "damage_type" : "����"
]),
([
    "action" : "$N��$w����һ�ڣ�����$n�Լ���$wײ����������֮����ʵ�����Ѳ⣡",
        "force" : 400,
        "dodge" : 50,
        "damage": 330,
        "lvl" : 180,
    "damage_type" : "����"
])
});

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
        object ob;

        mapping myfam;
        myfam = (mapping)me->query("family");
        if(!myfam || myfam["family_name"] != "��ɽ��"|| myfam["master_id"] != "feng qingyang")
                return notify_fail("���¾Ž�ֻ�����������ǰ��ѧϰ��\n");
        if( (int)me->query("max_neili") < 600 )
                return notify_fail("�������������û�а취�����¾Ž���\n");
        if( (int)me->query_skill("zixia-shengong",1)<100)
                return notify_fail("�����ϼ�񹦵ȼ�������\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");
        if ((int)me->query_skill("lonely-sword",1) > 120)
                return notify_fail("���׽����Ҿͽ̵�������Ժ��Ҫ�����Լ����ˡ�\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("���¾Ž�ֻ��ͨ�����ܾ�ʽ����������\n");
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
        return __DIR__"lonely-sword/" + action;
}

