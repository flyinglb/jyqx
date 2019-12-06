// respirate.c

#include <skill.h>


private int respirate_cost;
int respirating(object me);
int halt_respirate(object me);

int main(object me, string arg)
{
        object where = environment(me);

        seteuid(getuid());

        if ((int)me->query("age") < 30)
                return notify_fail("�����ڻ����ᣬ�Ժ������ɣ�\n");

        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

        if (me->is_busy() || me->query_temp("pending/respirate"))
                return notify_fail("��������æ���أ�\n");
        if( me->is_fighting() )
                return notify_fail("ս�������ɣ�����ֻ�����ɲ���������\n");

        if( !arg || !sscanf(arg, "%d", respirate_cost))
                return notify_fail("��Ҫ�����پ����У�\n");

        if (respirate_cost <= 0)
                return notify_fail("�㲻�����ɣ�\n");

        if( (int)me->query("jing") < respirate_cost )
                return notify_fail("�����ھ����㣬�޷����о�����\n");

        if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 70 )
                return notify_fail("����������״��̫���ˣ��޷����о���\n");

        write("������۾���ʼ������\n");
        me->set_temp("pending/respirate", 1);
        me->set_temp("respirate_cost", respirate_cost);
        message_vision("$N��ϥ���£���ʼ����������\n", me);
        me->start_busy((: respirating :), (: halt_respirate :));
        return 1;
}
int respirating(object me)
{
         int jingli_gain;
        int respirate_cost = (int)me->query_temp("respirate_cost");
        mapping fam;

	if( ((fam = me->query("family")) && fam["family_name"] == "����μ�" && me->query("class") == "bonze") )
		jingli_gain = 1 + (int)me->query_skill("buddhism",1) / 6;
	else if( ((fam = me->query("family")) && fam["family_name"] == "������" && me->query("class") == "bonze") )
		jingli_gain = 1 + (int)me->query_skill("buddhism",1) / 6;
	else if( ((fam = me->query("family")) && fam["family_name"] == "������"&& me->query("class") == "bonze") )
		jingli_gain = 1 + (int)me->query_skill("buddhism",1) / 6;
	else if( ((fam = me->query("family")) && fam["family_name"] == "ѩɽ��"&& me->query("class") == "bonze") )
		jingli_gain = 1 + (int)me->query_skill("lamaism",1) / 6;
	else  jingli_gain = 1 + (int)me->query_skill("taoism",1) / 5;


        if (respirate_cost < jingli_gain)
                jingli_gain = respirate_cost;

        me->add("jingli", jingli_gain);
        me->set_temp("respirate_cost", respirate_cost -= jingli_gain);
        me->add("jing",-jingli_gain);

        if (respirate_cost > 0)
                return 1;

        me->set_temp("pending/respirate", 0);
        respirate_cost = 0;
        message_vision("$N������ϣ�����˫�ۣ�վ��������\n", me);
        if((int)me->query("jingli") < (int)me->query("max_jingli") * 2)
                return 0;
        else {
                  if ((int)me->query("max_jingli") > (int)me->query_skill("taoism",1) * 10
                        && (int)me->query("max_jingli") > (int)me->query_skill("buddhism",1) * 10
                        && (int)me->query("max_jingli") > (int)me->query_skill("lamaism",1) * 10)
//                      && (int)me->query("max_jingli") > (int)me->query_skill("mizong-xinfa",1) * 10)

                {
                        write("��ľ�����Ϊ�ƺ��Ѿ��ﵽ��ƿ����\n");
                        me->set("jingli", (int)me->query("max_jingli"));
                        return 0;
                }
                else
                {
                        me->add("max_jingli", 1);
                        me->set("jingli", (int)me->query("max_jingli"));
                        write("��ľ��������ˣ���\n");
                        return 0;
                }
        }
}

int halt_respirate(object me)
{
        respirate_cost = 0;
        if ((int)me->query("jingli") > (int)me->query("max_jingli") * 2)
                me->set("jingli", (int)me->query("max_jingli") * 2);
        me->set_temp("pending/respirate", 0);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : respirate|tuna [<�ķѡ���������>]

�������У����á������������������������项�ķ�������ľ�
ת��ɾ�����

See also: exercise
HELP
        );
        return 1;
}
