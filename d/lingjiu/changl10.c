//room: changl10.c
inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ�����
������������ͼ�����������ɣ�����ʤ�ա��ذ岻֪����ʲô�������ģ�
�������������Ϣ����ֻ�е���������ģ��ǳ������
LONG );
  set("exits",([
      "east" : __DIR__"changl14",
      "west" : __DIR__"changl13",
      "south" : __DIR__"changl3",
      "north" : __DIR__"caifeng",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
