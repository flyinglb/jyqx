//room: didao4.c
inherit ROOM;

void create()
{
  set("short","�ص���ͷ");
  set("long", @LONG
�����ǰ����һ���⣬���Ǳ��ж��죬ǰ��������еط���
LONG  );
  set("exits",([
      "east"   :__DIR__"didao1",
      "west"  :__DIR__"didao3",
      "south" : __DIR__"didao4",
      "southup" : __DIR__"didao6",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
