// ROOM : linjxd6.c
inherit ROOM;
void create()
{
  set("short","�ּ�С��");
  set("long", @LONG
������һ���������ּ�С���ϣ���������ɭɭ�����֡�һ��
��紵�����ң�����ɳɳ�����������㲻��������
LONG );
  set("exits",([
      "south" : __DIR__"linjxd1",
      "north" : __DIR__"linjxd4",     
      "east"  : __DIR__"linjxd3",
      "west"  : __DIR__"dating2",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
