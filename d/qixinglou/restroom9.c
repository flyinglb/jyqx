//room: restroom.c
//restroom
inherit ROOM;

void create()
{
  set("short","�Է��");
  set("long",@LONG
���������¸����޹���ǽ�߰���һ���񴲣��������һ��С�������»�����һ˫�廨Ь
������������Ż��㣬�����������С�
LONG );
  set("exits",([
      "west" : __DIR__"liangong9",
  ]));
    set("sleep_room", 1);
    set("no_fight",1);
    set("no_steal",1);
    set("no_beg",1);
    set("no_clean_up", 0);
    setup();
  replace_program(ROOM);
}
