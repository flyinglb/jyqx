//room: changl6.c
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
      "north" : __DIR__"changl5",
      "west" : __DIR__"chufang",
      "east" : __DIR__"changl7",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
