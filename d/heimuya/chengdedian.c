//room: chengdedian.c
inherit ROOM;

void create()
{
  set("short","�ɵµ�");
  set("long", @LONG
�����������̽���ƽ�շ���ʩ��ĵط��������޴������
�������λε����򣬴��˶˸���һ��������һ��Ӣ���������ˣ�
�������𽭺��Ķ������ܵ��ͷ����ͤ�ˣ� 
LONG );

  set("valid_startroom", 1);
  set("exits",([
      "north" : __DIR__"huoting",
      "westdown":__DIR__"up4",
      "east" : __DIR__"chufang",
  ]));
  set("objects",([
      __DIR__"npc/dizi" : 2,
      __DIR__"npc/yang"    :1,
  ]));
//  set("no_clean_up", 0); 
  setup();
  replace_program(ROOM);
  "/clone/board/riyue_b"->foo();
}
