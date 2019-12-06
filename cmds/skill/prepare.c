// prepare.c
#include <ansi.h>
inherit F_CLEAN_UP;

mapping valid_types = 
([
        "finger":   "ָ��",
        "hand":     "�ַ�",
        "cuff":     "ȭ��",
        "claw":     "צ��",
        "strike":   "�Ʒ�",
        "blade":    "����",
        "sword":    "����",
        "staff":    "�ȷ�",
        "club":     "����",
        "throwing": "����",
        "unarmed":  "ȭ��",
]);

int main(object me, string arg)
{
        mapping smap, pmap;
        string *skill, basic1, basic2, arg1, arg2, arg3;
//        int i, count;
        int i;

        seteuid(getuid());

        smap = me->query_skill_map();

        if( !mapp(smap) || sizeof(smap)==0 )
                return notify_fail(HIR"������û��ʹ���κ���Ч���⼼�ܡ�\n"NOR);

        pmap = me->query_skill_prepare();
        if (!pmap) pmap = ([]);

        if( !arg ) 
        {
                if( !mapp(pmap) || sizeof(pmap)==0 )
                        return notify_fail(HIR"������û������κ�����ȭ�����ܡ�\n"NOR);

                skill = keys(valid_types);
                write(HIC"��������Ŀǰ����е�����ȭ�����ܡ�\n"NOR);
                for (i=0; i<sizeof(skill); i++) {
                        if( !me->query_skill(skill[i]) 
                        || !pmap[skill[i]] ) continue;
                        write(  valid_types[skill[i]] + " (" + skill[i] + ")" 
                                + "   " + to_chinese(pmap[skill[i]]) + "\n");
                }
                return 1;
        }

        if( arg=="?" ) 
        {
                write(HIG"�����ǿ���ʹ������ȭ�����ܵ����ࣺ\n"NOR);
                skill = sort_array(keys(valid_types), (: strcmp :) );
                for(i=0; i<sizeof(skill); i++) {
                        printf("  %s (%s)\n", valid_types[skill[i]], skill[i] );
                }
                return 1;
        }

        if( arg=="none" ) 
        {
                if( !mapp(pmap) || sizeof(pmap)==0 )
                        return notify_fail(HIB"������û������κ�����ȭ�����ܡ�\n"NOR);

                skill = keys(pmap);
                for (i=0; i<sizeof(skill); i++) {
                        me->prepare_skill(skill[i]);
                }

                me->reset_action();
                write(WHT"ȡ��ȫ������׼����\n"NOR);
                return 1;
        }

        if ( sizeof(pmap) >= 2 ) 
                return notify_fail(HIW"�������Ѿ�������������⼼�ܡ�\n"NOR);

        if ( sscanf(arg, "%s %s %s", arg1, arg2, arg3) >= 3)
                return notify_fail("ָ���ʽ��prepare|bei [<��������һ>|<�������ƶ�>]\n");
                
        if ( sscanf(arg, "%s %s", arg1, arg2) ==2 ) 
        {
                if ( sizeof(pmap) == 1 ) 
                        return notify_fail(HIM"����׼����һ�ּ����ˡ�\n"NOR);
                else
                {
                        if( !me->query_skill(arg1, 1) || !me->query_skill(arg2, 1) )
                                return notify_fail(BLU"�����ٲ��������ּ�������֮һ��\n"NOR);

                        if( !SKILL_D(arg1)->valid_combine(arg2) )
                                return notify_fail(MAG"������ȭ�����ܲ�����ϡ�\n"NOR);

                        skill = keys(valid_types);
                        for (i=0; i<sizeof(skill); i++) {
                                if( smap[skill[i]] == arg1 ) basic1 = skill[i];
                                if( smap[skill[i]] == arg2 ) basic2 = skill[i];
                        }

                        if ( !basic1 || !basic2 ) 
                                return notify_fail(YEL"������ȭ����δ������Ŀǰ����׼����\n"NOR);

                        me->prepare_skill(basic1, arg1);
                        me->prepare_skill(basic2, arg2);

                        me->reset_action();
                        write(HIY"��ɼ���׼����\n"NOR);
                        return 1;
                }               
        }

        if ( sscanf(arg, "%s", arg1) ==1 && sizeof(pmap) <= 1 ) 
        {
                if( !me->query_skill(arg1, 1) )
                        return notify_fail(MAG"�㲻�����ּ��ܡ�\n"NOR);

                skill = keys(pmap);

                if( sizeof(pmap) == 1 
                && !SKILL_D(arg1)->valid_combine(pmap[skill[0]]) )
                        return notify_fail(HIB"���ּ��ܲ���������м�����ϡ�\n"NOR);

                skill = keys(valid_types);
                for (i=0; i<sizeof(skill); i++) {
                        if( smap[skill[i]] == arg1 ) basic1 = skill[i];
                }

                if ( !basic1 ) 
                        return notify_fail(HIC"���ּ�����δ������Ŀǰ����׼����\n"NOR);

                me->prepare_skill(basic1, arg1);
                me->reset_action();
                write(HIY"��ɼ���׼����\n"NOR);
        
                return 1;
        }
        
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : prepare|bei [<ȭ����������>|<ȭ����������> | none]
           prepare|bei ?

���ָ������ָ����Ҫ�õ�ȭ�����ܣ� ��ָ��һ�����ϵ���Ӧ�������ơ�
������Ӳ��������ʾ���������༰��Ŀǰ��ʹ�õļ������� �������һ
��"?"������г�������ʹ������ȭ�����ܵļ������ࡣ
 
HELP
        );
        return 1;
}
