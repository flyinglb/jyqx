//room: restroom.c
//restroom
inherit ROOM;

void create()
{
  set("short","���");
  set("long",@LONG
���������չ�����˯���ĵط���һ���ž��ŵ�һ�����Ƶ�������ֻ��
���е���һ֧�����,�յ���������,��������ɴ�����ӣ���ɫ�б�������
һֻ��ɫ�ķ�ˣ����Ϲ���һ��������Ůͼ������һ�ż��Ϲ���һ��������
������ͣ��һֻ�����ġ�
LONG );
  set("exits",([
      "west" : __DIR__"changl3",
  ]));
  set("sleep_room", 1);
  set("no_fight",1);
  set("no_steal",1);
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
