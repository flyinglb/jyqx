// Room: nanyan0.c ���ҹ�������
// Date: Oct.5 1997
#include <login.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "���ҹ�������");
        set("long", @LONG
����һ������ྻ�ĵ����ң��ı��ù⻬�Ĵ���ʯ���ͣ�ʮ��֧����
�յ�����ͨ��͸����
LONG );
        set("objects", ([
           CLASS_D("wudang") +"/xiaosong": 1,
        ]));

        set("exits", ([
                "up"     : __DIR__"nanyangong",
                "east"   : __DIR__"nanyan1",
                "west"   : __DIR__"nanyan2",
                "south"  : __DIR__"nanyan3",
                "nortn"  : __DIR__"nanyan4",
        ]));
//        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
    if ( dir == "up" )
    {
       if ( me->query_skill("taiji-shengong", 1) < 80 )
          {
              return notify_fail("�����������ƶ��ϵ�ש�ǣ����ֱ�������˿������\n"
              + "���������군�ˡ�\n");
          }
          message_vision( HIY
            "$Nȫ������̫���񹦣���������ٵ�һ��������˫�������ͻ���ֻ��\n"
            "һ�ɰ�����$N���Ķ�����Ѹ���ޱȵػ��ж��ϵ�ש�ǡ�������һ��\n"
            "���죬ש�Ǳ��������С��Ƭ��ɢƮ�ɡ�¶��һ�����ϵĶ�������\n" NOR, me );
     }
     return ::valid_leave(me, dir);
}
