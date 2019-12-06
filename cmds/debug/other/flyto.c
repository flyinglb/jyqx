// flyto.c
#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string home;
        int goto_inventory = 0;
        object obj;
        string msg;
        if( !arg ) return notify_fail("��Ҫ���Ķ��ɣ�\n");

        if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

        if( !arg ) return notify_fail("��Ҫ�ɵ��Ķ�ȥ��\n");

        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
        if(!obj || !me->visible(obj)) {
                arg = resolve_path(me->query("cwd"), arg);
                if( !sscanf(arg, "%*s.c") ) arg += ".c";
                if( !(obj = find_object(arg)) ) {
                        if( file_size(arg)>=0 )
                                return me->move(arg);
                        return notify_fail("û�������ҡ������ط���\n");
                }
        }

        if(!goto_inventory && environment(obj))
                obj = environment(obj);

        if( !obj ) return notify_fail("������û�л������� flyto��\n");
         tell_object(me,"�ף���ô��������أ�����\n");
         tell_object(me,"�ǺǺǺǣ����˷��ˣ�СС��ʦ��ѽ�ɡ�����\n");
         me->move(obj);

        tell_object(me,"���ˣ����ˣ�����ඣ�����\n");
        return 1;
}

int help(object me)
{write(@HELP
ָ���ʽ : flyto [-i] <Ŀ��>
HELP);
    return 1;
}
