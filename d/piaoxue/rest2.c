inherit ROOM;

void create()
{
  set("short","��Ϣ��");
  set("long",
      "�����Ǽ���Ϣ�ң��������Ŵ󴲡�������˯���ǳ������û����\n"
  "���š�������Ʈѩɽׯ��������ǲ��ľ�ˣ������ǲ�����\n"
     );

  set("exits",([
      "north" : __DIR__"game2",
      "south" : __DIR__"foodroom2",
      "east" : __DIR__"piaoxie",
     ]));

  set("sleep_room", 1);
  set("no_fight",1);
  set("no_steal",1);
  set("no_clean_up", 0);

 setup();
}