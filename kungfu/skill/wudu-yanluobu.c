 // wudu-yanluobu �嶾���ܲ�
 // inherit F_CLEAN_UP;
 inherit SKILL;
 mapping *action = ({
  ([      "action" : "$n���Ų�æ��һʽ����ˮ������������ٿ����һ��ƽ������,���������$N�Ĺ��ơ�\n",
         "dodge"  : 20
 ]),
 ([      "action" : "$n��������Ȱ�һ�Σ�ɲ�Ǽ���Զȥ����֮�⣬$N��ʱ���˸��ա�\n",
         "dodge"  : 40
 ]),
 ([      "action" : "$n���к��ļӿ죬��һ�����̰�����$N�ɿ���ת������$Nһ��ͷ���ۻ���\n��æ����������\n",
         "dodge"  : 60
 ]),
  ([      "action" : "$n���Ų�æ��һʽ����ˮ������������ٿ����һ��ƽ������,���������$N�Ĺ��ơ�\n",
         "dodge"  : 80
 ]),
 ([      "action" : "$n�����ж�ʱ�������һ����������$N����ʽ���Ұڶ�����ʹ��$N������ա�\n",
         "dodge"  : 100
 ]),
 });

 mapping query_action(object me, object weapon)
 {
         int zhaoshu, level;

         zhaoshu = sizeof(action);
         level   = (int) me->query_skill("wudu-yanluobu");


         return action[random(zhaoshu)];
 }

 int valid_enable(string usage)
 {
         return usage == "dodge" || usage == "move";
 }

 int valid_learn(object me)
 {
         return 1;
 }

 string query_dodge_msg(string limb)
 {
         object me, ob;
         mapping action;

         me = this_player();
         action = query_action(me, ob);

         return action["action"];
 }

 int practice_skill(object me)
 {
         if( (int)me->query("qi") < 40 )
                 return notify_fail("�������̫���ˣ��������嶾���ܲ���\n");
         me->receive_damage("qi", 20);
         return 1;
 }
 int valid_effect(object me, object weapon, string action_name, int skill)
 {
         message_vision("�������̫���ˣ��������嶾���ܲ���\n",me);
 }
 string perform_action_file(string action)
 {
         return __DIR__"wudu-yanluobu/" + action;
 }
