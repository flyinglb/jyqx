// midao8.c �ܵ�

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ܵ�");
        set("long", @LONG
����һ���������ܵ��������ʯ�����ǻҳ�������ܾ�û�������ˡ�
LONG );
        set("exits", ([
                "southdown" : __DIR__"midao7"
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        object me = this_player();
        if( random((int)me->query_skill("dodge",1)) <= 80 && !wizardp(me) )
        {
                me->receive_damage("qi", 50);
                me->receive_wound("qi",  50);
                message_vision(HIR"$Nһ��С�Ĳȵ����ϵ�һ����Ŧ��... ��...��\n"NOR, me);
                me->move(__DIR__"road3");
                tell_object(me, HIR"���ɽ�Ϲ���������ֻ���û����޴����ۣ������˼����ˡ�\n"NOR);
                message("vision", HIR"ֻ��" + me->query("name") + "��ɽ�Ϲ�µµ�ع������������ڵ��ϰ�������������\n"NOR, environment(me), me);
        }
}
