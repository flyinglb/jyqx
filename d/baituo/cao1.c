//room:cao1.c
inherit ROOM;

void create()
{
  set("short","�ݴ�");
  set("long",
      "�������Ҳݴԡ��������ȹ�����С���š�\n"
  "�������涼�������ߵ���ݣ������߳�û��\n"
    );
  set("exits",([
      "west" : __FILE__,
      "north" : __DIR__"cao2",
      "east" : __DIR__"ximen",
      "south" : __FILE__,
     ]));
 set("objects",([
      __DIR__"npc/jinshe" : random(2),
      __DIR__"npc/snake" : random(2),
      ]));
// set("no_clean_up", 0);
 set("outdoors","baituo");
 setup();
 replace_program(ROOM);
}




