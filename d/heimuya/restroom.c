//room: /d/btshan/restroom.c
//restroom
inherit ROOM;

void create()
{
  set("short","��Ϣ��");
  set("long", @LONG
�����Ǽ���Ϣ�ң��������Ŵ󴲡�������˯���ǳ������û
���ܴ��š����������ɵĳ��ȡ�
LONG );
  set("exits",([
      "east" : __DIR__"huoting",
  ]));
  set("sleep_room", 1);
  set("no_fight",1);
  set("no_steal",1);
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

