//Room: milin2.c ����
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","����");
      set("long",@LONG
���Ǻ�ɭɭ��һƬ���֣��ľ���죬Ũ�����ա����������Ǳ����£�����
�ּ�������һ�����
LONG);
      set("exits",([ /* sizeof() == 1 */
          "eastdown"  : __DIR__"fhs",
          "westup"    : __DIR__"jietuopo",
      ]));
      set("outdoors", "emei");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
