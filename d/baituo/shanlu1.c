//shanlu1.c
inherit ROOM;

void create()
{
  set("short","ɽ·");
  set("long","������ɽ�ϵ���·��\n");
  set("exits",([
      "north" : __DIR__"shulin",
      "southeast" : __DIR__"shanlu",
     ]));
  set("outdoors", "baituo");
  set("objects" ,([
      __DIR__"npc/qiaofu" : 1 ,
      ]) );
//  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

