//Room: milin1.c ����
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","����");
      set("long",@LONG
���Ǻ�ɭɭ��һƬ���֣��ľ���죬Ũ�����ա����ﶫ�¶����Ǳ����£�
�����ּ�������һ�����
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northeast"  : __DIR__"bgs",
          "west"       : __DIR__"fhs",
      ]));
      set("outdoors", "emei");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
