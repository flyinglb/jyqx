inherit ROOM;

void create()
{
  set("short","青龙堂休息室");
  set("long",
"这里是间休息室，里面有若干张大床。
在这里睡觉非常舒服，没人能打扰。\n"
     );

  set("exits",([
      "north" : __DIR__"qldian",
     ]));

  set("sleep_room", 1);
  set("no_fight",1);
  set("no_steal",1);
  set("no_clean_up", 0);

 setup();
}