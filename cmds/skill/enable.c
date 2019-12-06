// enable.c

#include <ansi.h>

inherit F_CLEAN_UP;

mapping valid_types = ([
        "unarmed":      "ȭ��",
        "sword":        "����",
        "blade":        "����",
        "stick":        "����",
        "staff":        "�ȷ�",
	"hammer":       "����",
        "club" :        "����",
        "throwing":     "����",
        "force":        "�ڹ�",
        "parry":        "�м�",
        "dodge":        "�Ṧ",
        "magic":        "����",
        "array":        "��",
//      "spells":       "����",
//      "move":         "�ж�",
        "axe":        "����",
//      "array":        "��",
        "whip":         "�޷�",
        "dagger":       "�̱�",

//      shaolin skills

        "finger":   "ָ��",
        "hand":     "�ַ�",
        "cuff":     "ȭ��",
        "claw":     "צ��",
        "strike":   "�Ʒ�",

//      "club":     "����",
]);

int main(object me, string arg)
{
        mapping map;
//        string *types, *skill, ski, map_to;
        string *skill, ski, map_to;
        int i, modify;

        seteuid(getuid());

        if( !arg ) {
                map = me->query_skill_map();
                if( !mapp(map) || sizeof(map)==0 )
                        return notify_fail("������û��ʹ���κ����⼼�ܡ�\n");

                skill = keys(valid_types);
                write("��������Ŀǰʹ���е����⼼�ܡ�\n");
                for (i=0; i<sizeof(skill); i++) {
                        if( undefinedp(valid_types[skill[i]]) ) {
                                map_delete(map, skill[i]);
                                continue;
                        }
                        if( !me->query_skill(skill[i]) ) continue;
                        modify = me->query_temp("apply/" + skill[i]);
                        printf("  %-20s�� %-20s  ��Ч�ȼ���%s%3d\n" NOR,
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(map[skill[i]]) ? "��" : to_chinese(map[skill[i]]),
                                (modify==0 ? "" : (modify>0 ? HIC : HIR)),
                                me->query_skill(skill[i]));
                }
                return 1;
        }

        if( arg=="?" ) {
                write("�����ǿ���ʹ�����⼼�ܵ����ࣺ\n");
                skill = sort_array(keys(valid_types), (: strcmp :) );
                for(i=0; i<sizeof(skill); i++) {
                        printf("  %s (%s)\n", valid_types[skill[i]], skill[i] );
                }
                return 1;
        }

        if( sscanf(arg, "%s %s", ski, map_to)!=2 )
                return notify_fail("ָ���ʽ��enable|jifa [<��������> <��������>
|none]\n");

        if( undefinedp(valid_types[ski]) )
                return notify_fail("û������������࣬�� enable ? ���Բ鿴����Щ
���ࡣ\n");

        if( map_to=="none" ) {
                me->map_skill(ski);
                me->reset_action();
write(HIY"���������ȡ��"HIG+CHINESE_D->chinese(ski)+HIY"�����⼼�ܡ�\n"NOR);
                return 1;
        } else if( map_to==ski ) {
                write("��" + to_chinese(ski) + "��������" + valid_types[ski] + "
�Ļ���������Ҫ enable��\n");
                return 1;
        }

        if( !me->query_skill(map_to, 1) )
                return notify_fail("�㲻�����ּ��ܡ�\n");

//      if( !me->query_skill(ski, 1) )
//              return notify_fail("������" + to_chinese(ski) + "����ûѧ�ᣬ
//              ����" + to_chinese(map_to) + "�ˡ�\n");

        if( !SKILL_D(map_to)->valid_enable(ski) )
                return notify_fail("������ܲ��ܵ���������;��\n");

        me->map_skill(ski, map_to);
        me->reset_action();
write(HIY"�����������"HIR+CHINESE_D->chinese(map_to)+HIY"��Ϊ"HIG+CHINESE_D->chinese(ski)+HIY"�����⼼�ܡ�\n"NOR);

        if( ski=="magic" ) {
                write("�������һ�ַ���ϵ�������������¶�����\n");
                me->set("jingli", 0);
                me->receive_damage("jing", 0);
        }
        else if( ski=="force" ) {
                write("�������һ���ڹ��������������¶�����\n");
                me->set("neili", 0);
                me->receive_damage("qi", 0);
//      } else if( ski=="spells" ) {
//              write("�������һ������ϵ��������������������\n");
//              me->set("mana", 0);
//              me->receive_damage("sen", 0);
        }

        return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : enable|jifa [<��������> <��������> | none]
           enable|jifa ?

���ָ������ָ����Ҫ�õļ��ܣ���ָ����������ͼ������ơ�������Ӳ�
�������ʾ���������༰��Ŀǰ��ʹ�õļ������� �������һ�������г�
������ʹ�����⼼�ܵļ������ࡣ

HELP
        );
        return 1;
}
