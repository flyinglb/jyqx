// Room: practice
// Date: Feb.14 1998 by Java

#include <room.h>
inherit ROOM;

void create()
{
      set("short", "��ݲ�����");
      set("long", @LONG
���������ʯ���������󵶳�����ɳ�����ȵȣ����м���������
�Ƶ���Ƥ�ˣ�����ݵ����ճ������ĵط���
LONG );

      set("exits", ([ /* sizeof() == 1 */
          "down"   : __DIR__"wuguan",
      ]));
//      set("no_clean_up", 0);
      set("objects", ([
          __DIR__"npc/xiangpi-ren" : 5,
      ]));
      setup();
      replace_program(ROOM);
}
