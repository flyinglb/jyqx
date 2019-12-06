// hubei.c

inherit F_CLEAN_UP;

mapping valid_types = 
([
        "blade":   "����",
        "sword":   "����",
]);

int main(object me, string arg)
{
        mapping smap, pmap;
//        string *skill, basic1, basic2, arg1, arg2, arg3;
        string *skill, basic1, basic2, arg1, arg2;
//        int i, count;
        int i;

        seteuid(getuid());

        smap = me->query_skill_map();

        if( !mapp(smap) || sizeof(smap)==0 )
                return notify_fail("������û��ʹ���κ���Ч���⼼�ܡ�\n");
        pmap = me->query_wprepare();
        if (!pmap) pmap = ([]);

        if( !arg ) 
        {
                if( !mapp(pmap) || sizeof(pmap)==0 )
                        return notify_fail("������û������κ����⼼�ܡ�\n");

                skill = keys(valid_types);
                write("��������Ŀǰ����е�����������ܡ�\n");
                for (i=0; i<sizeof(skill); i++) 
                       {
                        if( !me->query_skill(skill[i]) 
                        || !pmap[skill[i]] ) continue;
                        write(  valid_types[skill[i]] + " (" + skill[i] + ")" 
                                + "   " + to_chinese(pmap[skill[i]]) + "\n");
                       }
                return 1;
        }
        

        if( arg=="none" ) 
        {
                if( !mapp(pmap) || sizeof(pmap)==0 )
                        return notify_fail("������û������κ�����������ܡ�\n");

                skill = keys(pmap);
                for (i=0; i<sizeof(skill); i++) 
                {
                        me->prepare_wskill(skill[i]);
                }

                me->reset_action();
                write("ȡ��ȫ������׼����\n");
                return 1;
        }

        
        if ( sscanf(arg, "%s %s", arg1, arg2) !=2 )
            return notify_fail("hubei ����һ ������\n"); 
        

        if ( sscanf(arg, "%s %s", arg1, arg2) ==2 ) 
        {
                if ( sizeof(pmap) >= 2 ) 
                        return notify_fail("����������������ֱ��������ˡ�\n");
      else
                {
                        if( !me->query_skill(arg1, 1) || !me->query_skill(arg2, 1) )
                                return notify_fail("�����ٲ��������ּ�������֮һ��\n");

                        if( !SKILL_D(arg1)->valid_combine(arg2) )
                                return notify_fail("�����ֱ������ܲ�����ϡ�\n");

                        skill = keys(valid_types);
                        for (i=0; i<sizeof(skill); i++) 
                        {
                                if( smap[skill[i]] == arg1 ) basic1 = skill[i];
                                if( smap[skill[i]] == arg2 ) basic2 = skill[i];
                        }

                        if ( !basic1 || !basic2 ) 
                                return notify_fail("�����ֱ���������δ������Ŀǰ����׼����\n");

                        me->prepare_wskill(basic1, arg1);
                        me->prepare_wskill(basic2, arg2);

                        me->reset_action();
                        write("��ɼ���׼����\n");
                       return 1;
                }               
        }
}

int help(object me)
{
        write(@HELP
ָ���ʽ : hubei [hubei ����һ ������ | none]
 
HELP
        );
        return 1;
}
