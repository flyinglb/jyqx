//Room: xiaolu2.c С·
//Date: Oct.2.1997 by That

inherit ROOM;

void create()
{
      set("short", "С·");
      set("long", @LONG
�����Ĵ�������Ľ��硣һ�������ĵ�С��·�����������������ũ���
���·�����˺��٣����ҴҸ�·��
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "south" : __DIR__"qsjie1",
          "east"  : __DIR__"xiaolu1",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
