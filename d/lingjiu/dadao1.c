//room: dadao1.c
inherit ROOM;

void create()
{
  set("short","��ʯ���");
  set("long",@LONG
����һ����ʯ�̳ɵĿ������ÿ����ʯ���ǳ�Լ�˳ߣ���Լ���ߣ�
�������룬�����ɶ��칤�������������де������֣���ʱ���Կ���һ
��ֻ����ı�������Ծ���������������ȥ��һ���޴��ʯ��ΡȻ��
����
LONG );
  set("outdoors", "lingjiu");
  set("exits",([
      "north" : __DIR__"dadao2",
      "westdown" : __DIR__"xianchou",
  ]));
  set("objects",([
      __DIR__"npc/songshu" : 2,
  ]));
//  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
