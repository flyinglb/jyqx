//zhulin.c
inherit ROOM;
void create()
{
  set("short","����");
  set("long",
  "�����������֣������߳�û���ϱ�����ݴԡ�������һ�����Ҷ���\n"
      );
  set("exits",([
      "northup" : __DIR__"cave",
      "south" : __DIR__"cao2",
     ]));
  set("objects",([
      __DIR__"npc/qingshe" : random(2),
      __DIR__"npc/snake" : random(3),
      ]));
//  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

