inherit ROOM;

void create()
{
  set("short","休息室");
  set("long",
"这是间整洁的厢房，因门窗常闭着，光线很昏暗。房里
别无他物，只有中间放着一张收拾得舒舒服服的大床，看着
就让人想睡觉。\n"
     );

  set("exits",([
      "west" : __DIR__"lgong",
     ]));

  set("sleep_room", 1);
  set("no_fight",1);
  set("no_steal",1);
  set("no_clean_up", 0);

 setup();
}

