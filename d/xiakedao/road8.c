// Room: /d/xiakedao/road8.c


#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "һ����");
        set("long", @LONG
�������һ���졣�˴�ɽ�����Ƕ��ͣ����Զ����޵׵���Ԩ��
�м���һ�����ƾ�ʮ�ȵ�����ɽ·�����˵����޲��ľ�������ֻ��
���Լ��Ľţ�����һ��С�ĵ�����Ԩ��
LONG );
        set("exits", ([
                "southup"   : __DIR__"wangyun",
                "northdown" : __DIR__"road7",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xiakedao");
        setup();
}

void init()
{
        object me = this_player();

        if( random((int)me->query_skill("dodge",1))<= 30)
        {
                me->receive_damage("qi", 50);
                me->receive_wound("qi",  50);
                message_vision(HIR"$Nһ��С�Ľ���̤�˸��գ�... ��...!\n"NOR, me);
                me->move(__DIR__"road5");
                tell_object(me, HIR"���ɽ�Ϲ���������ֻ���û����޴����ۣ������˼����ˡ�\n"NOR);
                message("vision", HIR"ֻ��" + me->query("name") + "��ɽ�Ϲ�µµ�ع������������ڵ��ϰ�����������!\n"NOR, environment(me), me);
        }
}
