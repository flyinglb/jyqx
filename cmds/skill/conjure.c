// conjure.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string spells, spl, trg;
        object target;

        seteuid(getuid());

        if( me->is_busy() )
                return notify_fail("( ����һ��������û����ɣ�����ʩչ��ͨ��)\n");

        if( environment(me)->query("no_magic") )
                return notify_fail("�����޷�ʹ����ͨ��\n");

        if( !arg || arg == "" ) return notify_fail("ָ���ʽ��conjure <��ͨ> [on <Ŀ��>]\n");
        if( sscanf(arg, "%s on %s", spl, trg)==2 ) {
                target = present(trg, environment(me));
      if((spl=="spattack" || spl=="mpattack") && target->query("age")<16)
         return notify_fail("�����˼Ұɣ�û�����˼һ���ôС����\n");
                if( !target ) target = present(trg, me);
                if( !target ) return notify_fail("����û�� " + trg + "��\n");
                spl = arg;
                target = 0;
        }

        if( !spl ) spl = arg;
        spl = replace_string( spl, " ", "_");

        if( stringp(spells = me->query_skill_mapped("magic")) )
                return (int)SKILL_D(spells)->conjure_magic(me, spl, target);

        return notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ���ͨϵ��\n");
}

int help (object me)
{
        write(@HELP
ָ���ʽ��conjure <��������> [on <����>]

ʩ    ���������Ҫָ��<��������>��<����>����п��ޡ�
����ʹ��ĳһ������֮ǰ����������� enable|jifa ָ����ָ����Ҫʹ�õķ���ϵ��

HELP);
        return 1;
}

