//Room: jiulaodong.c ���϶�
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","���϶�");
      set("long",@LONG
����Ƕ��ҵ�һ�󶴣���������ޱȣ������Ѳ⡣��һ�߽������㷢����
�в涴�����Թ�������Ī�⣬�ƺ�����޵ס����ǿ���뿪�ɡ�
LONG);
      set("objects", ([
           __DIR__"npc/bat" : 4,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "out"     : __DIR__"jldongkou",
          "north"   : __DIR__"jldongnei",
          "south"   : __DIR__"jldongnei",
          "east"    : __DIR__"jldongnei",
          "west"    : __DIR__"jldongnei",
      ]));
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
