//room: changl5.c
inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ�����
������������ͼ�����������ɣ�����ʤ�ա��ذ岻֪����ʲô�������ģ�
�������������Ϣ����ֻ�е���������ģ��ǳ���������������Ǳ����⡣
LONG );
  set("exits",([
      "east" : __DIR__"changl1",
      "west" : __DIR__"wuqiku",
      "north" : __DIR__"changl9",
      "south" : __DIR__"changl6",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
