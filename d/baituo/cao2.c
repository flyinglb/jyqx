//room:cao2.c

inherit ROOM;

void create()
{
  set("short","�ݴ�");
  set("long",
      "�������Ҳݴԡ������������֡��������涼�������ߵ���ݣ�\n"
  "�����߳�û��\n"
     );
  set("exits",([
      "west" : __FILE__,
      "north" :__DIR__"zhulin",
      "east" : __DIR__"cao1",
      "south" : __DIR__"cao1",
     ]));
 set("objects",([
      __DIR__"npc/qingshe" : random(2),
      __DIR__"npc/jinshe" : random(2),
      __DIR__"npc/snake" : random(2),
      ]));
// set("no_clean_up", 0);
 set("outdoors","baituo");
 setup();
 replace_program(ROOM);
}


