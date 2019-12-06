inherit ROOM;

void create()
{
  set("short","休息室");
  set("long",
      "这里是间休息室，里面有张大床。在这里睡觉非常舒服，没人能\n"
  "打扰。北面是飘雪山庄供客人消遣的木人，南面是餐厅。\n"
     );

  set("exits",([
      "north" : __DIR__"game2",
      "south" : __DIR__"foodroom2",
      "east" : __DIR__"piaoxie",
     ]));

  set("sleep_room", 1);
  set("no_fight",1);
  set("no_steal",1);
  set("no_clean_up", 0);

 setup();
}