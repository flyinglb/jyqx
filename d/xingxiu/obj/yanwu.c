// Yanwu.c ����
#include <command.h>
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM"����"NOR, ({ "yanwu"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����������Ƶ���������������(apply)��\n");
                set("unit", "��");
                set("value", 10000);
//              set("no_drop", RED"�ѵ��������������\n"NOR);
        }
}

void init()
{
        add_action("do_apply","apply");
}
int do_apply(string arg)
{
        object me,ob;
        object *inv;
        int i;

        if (arg!="yanwu")
        {
                return 0;
        }

        me=this_player();
        if (me->is_busy())
        {
                notify_fail("������æ����\n");
                return 1;
        }

        inv = all_inventory(environment(me));
        for(i=0; i<sizeof(inv); i++)
        {
                ob=inv[i];
                if (ob==me)
                continue;
                if( (ob->is_character()) && (!ob->is_corpse()) )
                {
                        ob->start_busy(2);
                }
        }
        me->set_temp("no_follow",1);
//      GO_CMD->do_flee(me);
        tell_room(environment(me),HIM"����ͻȻ�ڳ�һ���Һ�ɫ���������ʲôҲ��
�������������֮�С�\n"NOR);

        GO_CMD->do_flee(me);
        destruct(this_object());
        return 1;
}
void owner_is_killed()
{
        write(HIM"ֻ��һ���Һ�ɫ����������...ʬ����ʲô������ʧ�ˡ�\n"NOR);
        destruct(this_object());
}
/*
int query_autoload()
{
        return 1;
}
*/
