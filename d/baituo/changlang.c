//room: /d/btshan/changlang.c
inherit ROOM;

void create()
{
  set("short","����");
  set("long",
      "�����Ƿǳ����ɵĳ��ȡ������Ǽ���Ϣ�ҡ��ϱ��м�ҩ�������洫��\n"
  "һ�������������������������ȹ�����С���š���������������\n"
     );

  set("exits",([
      "west" : __DIR__"ximen",
      "north" : __DIR__"restroom",
      "east" : __DIR__"liangong",
      "south" : __DIR__"yaofang",
     ]));
//  set("no_clean_up", 0);

 setup();
 replace_program(ROOM);
}

