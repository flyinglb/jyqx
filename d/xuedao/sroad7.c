// sroad7.c
// Modified by Java Apr.27 1998
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","��ѩɽ��");
        set("long",@LONG
Ⱥɽ���ƣ����ܻ�ѩ���겻�����ϱ߲�Զ����һ��ɽ�ȡ�
LONG );
        set("exits",([
                "eastdown"  : __DIR__"sroad6",
                "southup"   : __DIR__"sroad8",
        ]));
        set("objects",([
                __DIR__"npc/caiyaoren": 1,
        ]));
        set("outdoors", "xueshan");
        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "southup")
        {
message_vision(HIW"ͻȻ��¡һ�����죬$N����̤�˸��գ�... ��...ѩ���ˣ�\n"NOR, me);
                me->receive_damage("qi", 70);
                me->receive_wound("qi",  70);
                if( random(me->query_dex()) >= 7) 
                {
                        me->move(__DIR__"sroad8");
tell_object(me,HIW"ֻ����Ƭ�Ļ�ѩ��ɽ���ϱ��ڶ��£���������ǵص��˹�������;���д��˲�����ʯ���Ͻ������ɣ�\n"NOR);
message("vision",HIW"ֻ����Ƭ�Ļ�ѩ��ɽ���ϱ��ڶ��£���"+me->query("name")+"����ǵص��˹�������;���д��˲�����ʯ���Ͻ������ɣ�\n"NOR,environment(me),me);
                        return notify_fail("");
                }
		else 
                {
                        me->move(__DIR__"sroad5");
tell_object(me,HIW"ֻ����Ƭ�Ļ�ѩ��ɽ���ϱ��ڶ��£���������ǵص��˹�������;���д��˲�����ʯ���Ͻ������ɣ�\n"NOR);
message("vision",HIW"ֻ����Ƭ�Ļ�ѩ��ɽ���ϱ��ڶ��£���"+me->query("name")+"����ǵص��˹�������;���д��˲�����ʯ���Ͻ������ɣ�\n"NOR,environment(me),me);
                        return notify_fail("");
                }
        }
        else if( random(me->query("dex")) <= 10) 
        {
                me->move(__DIR__"sroad5");
tell_object(me,HIW"ֻ����Ƭ�Ļ�ѩ��ɽ���ϱ��ڶ��£���������ǵص��˹�������;���д��˲�����ʯ���Ͻ������ɣ�\n"NOR);
message("vision",HIW"ֻ����Ƭ�Ļ�ѩ��ɽ���ϱ��ڶ��£���"+me->query("name")+"����ǵص��˹�������;���д��˲�����ʯ���Ͻ������ɣ�\n"NOR,environment(me),me);
                return notify_fail("");
        }
        return ::valid_leave(me,dir);
}
