// ROOM : linjxd1.c
inherit ROOM;
void create()
{
  set("short","�ּ�С��");
  set("long", @LONG
������һ���������ּ�С���ϣ���������ɭɭ�����֡�һ��
��紵�����ң�����ɳɳ�����������㲻���������������ߺ���
��һ��ɽ�ȡ� 
LONG );
  set("exits",([
      "south" : __DIR__"linjxd2",
      "north" : __DIR__"linjxd5",     
      "east"  : __DIR__"road1",
      "west"  : __DIR__"guang",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
