//room: changlang2.c
inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ�����
������������ͼ�����������ɣ�����ʤ�ա��ذ岻֪����ʲô�������ģ�
�������������Ϣ����ֻ�е���������ģ��ǳ������һ�����������
������
LONG );
  set("exits",([
      "east" : __DIR__"changl3",
      "west" : __DIR__"huayuan",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
