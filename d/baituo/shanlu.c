//shanlu.c
inherit ROOM;

void create()
{
  set("short","ɽ·");
  set("long","������ɽ�ϵ���·��\n");
  set("exits",([
      "northwest" : __DIR__"shanlu1",
      "southeast" : __DIR__"guangchang",
     ]));
  set("outdoors", "baituo");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

