//room: restroom.c
//restroom
inherit ROOM;

void create()
{
  set("short","��Ϣ��");
  set("long",@LONG
����������¥��������������Ϣ�ĵط�����һ�Ŵ󴲣��ǳ�����ġ�
LONG );
  set("exits",([
      "south" : __DIR__"liangong7",
  ]));
    set("sleep_room", 1);
    set("no_fight",1);
    set("no_steal",1);
    set("no_beg",1);
    set("no_clean_up", 0);
    setup();
  replace_program(ROOM);
}
