//room: 
inherit ROOM;

void create()
{
  set("short","����");
  set("long", @LONG
�����Ƿǳ����ɵĳ��ȡ�����ȴûʲô��������ϱ�����
���õĴ�����
LONG  );

  set("exits",([
      "north" : __DIR__"chlang1",
      "south" : __DIR__"qing",
  ]));			   
  set("objects",([
      __DIR__"npc/shinu1"   :1,
  ]));
  set("no_fight",0);
  set("no_steal",0);
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

