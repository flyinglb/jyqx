// Room: /d/mingjiao/mjtianmen1.c
// Jan.5 1997 by Venus

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "�ſ�");
    set("long", @LONG
ǰ��������̵ġ������š��ˣ��������������е�������
�ĵط������ſڿ���ȥ�����������ľ�����ơ��˴�����Ů��
������롣
LONG );
    set("exits", ([
        "enter" : __DIR__"nanshe",
        "southeast" : __DIR__"mjtianmen",
    ]));
    set("outdoors", "mingjiao");
    set("no_clean_up", 0);
    setup();
//    replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
    me = this_player();
    if ((me->query("gender")!="����") && (dir=="enter"))
      return notify_fail("�������أ����ⲻ�⣡\n");
    else  return 1;
}
