// /u/beyond/mr/hubian1.c 
// this is made by beyond 
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",GRN"����"NOR);
         set("long", @LONG
�׻�˵ : ��������, �����պ����������Ǵ��������̫���� �����̲�
��Ư��һҶҶ��С��, һ�����ö���С�������ź��ϵ���粻ʱƯ����Ķ�
�С�
LONG
      );
       set("outdoors","mr");
       set("exits", ([
           "west" : __DIR__"hubian",
           "east" : __DIR__"hubian2",
]));
       setup();
       replace_program(ROOM);
}

