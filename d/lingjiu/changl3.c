//room: changl3.c
inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ�����
������������ͼ�����������ɣ�����ʤ�ա��ذ岻֪����ʲô�������ģ�
�������������Ϣ����ֻ�е���������ģ��ǳ���������ȶ��������
�������չ�������Ϣ�ĵط���
LONG );
  set("exits",([
      "east" : __DIR__"restroom",
      "west" : __DIR__"changl2",
      "north" : __DIR__"changl10",
      "south" : __DIR__"changl4",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
