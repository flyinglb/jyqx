//room: restroom.c
//restroom
inherit ROOM;

void create()
{
  set("short","休息室");
  set("long",@LONG
这里是七星楼弟子练功累了休息的地方，有一张大床，非常舒服的。
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
