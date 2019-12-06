// Room: /d/xiakedao/road7.c
  
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�б�ʯ");
        set("long", @LONG
������Ǽб�ʯ���˴�ɽ�ƶ��ͣ����˵����޲��ľ���������
�Ҵ���˵����ֻ��ƽ����ȥ����ɽ����һ����С�ģ������ױ���
�鵽�¹�֮�С�
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
                "southup"   : __DIR__"road8",
                "northdown" : __DIR__"road6",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xiakedao");
        setup();
}

void init()
{
        object me = this_player();

        if( random((int)me->query_skill("dodge",1)) <= 15)
        {
                me->receive_damage("qi", 50);
                me->receive_wound("qi",  50);
                message_vision(HIR"$Nһ��С�Ľ���̤�˸��գ�... ��...!\n"NOR, me);
                me->move(__DIR__"road3");
                tell_object(me, HIR"���ɽ�Ϲ���������ֻ���û����޴����ۣ������˼����ˡ�\n"NOR);
                message("vision", HIR"ֻ��" + me->query("name") + "��ɽ�Ϲ�µµ�ع������������ڵ��ϰ�����������!\n"NOR, environment(me), me);
        }
}
