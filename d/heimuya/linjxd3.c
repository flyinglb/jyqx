// ROOM : linjxd3.c
inherit ROOM;
void create()
{
  set("short","�ּ�С��");
  set("long", @LONG
������һ���������ּ�С���ϣ���������ɭɭ�����֡�һ��
��紵�����ң�����ɳɳ�����������㲻��������
LONG );
  set("exits",([
      "south" : __DIR__"linjxd4",
      "north" : __DIR__"linjxd2",     
      "east"  : __DIR__"linjxd5",
      "west"  : __DIR__"linjxd5",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
