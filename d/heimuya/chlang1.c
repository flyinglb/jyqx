//room: 
inherit ROOM;

void create()
{
  set("short","����");
  set("long", @LONG
�����Ƿǳ����ɵĳ��ȡ�����վ����ʮ�������֣�����ɭ�ϣ�
͸������ɱ����
LONG );

  set("exits",([
      "north" : __DIR__"dating3",
      "south" : __DIR__"chlang2",
  ]));
  set("objects",([
     __DIR__"npc/jiaotu"   :1,
  ]));
//  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

