//room: /d/btshan/liangong.c
inherit ROOM;
void create()
{
  set("short","������");
  set("long",
      "�����ǰ���ɽ���ӵ���������������һ���������������Ǹ����ȣ�\n"
  "��������һ�����ȣ������������ǳ����ɡ�����ɼ�ΡΡ������\n"
    );
  set("exits",([
      "east" : __DIR__"fang",
      "north" : __DIR__"menlang",
      "west" : __DIR__"changlang",
      "south" : __DIR__"dating",
     ]));

 set("objects",([
     __DIR__"npc/li" : 1,
     ]));
// set("no_clean_up", 0);

 set("outdoors", "baituo");
 setup();

 replace_program(ROOM);
}
