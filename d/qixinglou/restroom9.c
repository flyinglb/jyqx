//room: restroom.c
//restroom
inherit ROOM;

void create()
{
  set("short","卧凤阁");
  set("long",@LONG
这里是新月格格的寝宫，墙边摆着一张玉床，上面放着一床小被，床下还放着一双绣花鞋
整个房间充满着花香，让人陶醉其中。
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
