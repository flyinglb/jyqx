#include <ansi.h>

inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object ob;

        if( ((time() - (int)me->query_temp("last_finger_time")) < 60 )
        && !wizardp(me) )
                return notify_fail("��ľ����޷����С�\n");
        if( !arg ) {
                if( (int)me->query("jing") < 100 )
                        return notify_fail("��ľ����޷����С�\n");
                if( !wizardp(me) )
                        me->receive_damage("jing", 100);
                write( FINGER_D->finger_all() );
        } else {
                if( (int)me->query("jing") < 15 )
                        return notify_fail("��ľ����޷����С�\n");
                if( !wizardp(me) )
                        me->receive_damage("jing", 15);
                write( FINGER_D->finger_user(arg) );
                ob=find_player(arg);
                if (ob&&ob->visible(me)&&(me!=ob)) {
                        if(!wizardp(me)) tell_object(ob,HIY"���Ȼ����һ����ս...\n"NOR);
                        message("channel:sys", HIR +"��ϵͳ�� "+ me->query("name") + "(" + me->query("id") + ") finger " + ob->query("name") + "(" + ob->query("id") + ")��\n"NOR, users());
                }
        }
        me->set_temp("last_finger_time", time());
        return 1;
}

int help(object me)
{
  write(@HELP

ָ���ʽ : finger [ʹ��������]

���ָ��, ���û��ָ��ʹ��������, ����ʾ�����������������
����������. ��֮, �����ʾ�й�ĳ����ҵ�����, Ȩ�޵�����.

see also : who
HELP
    );
    return 1;
}
