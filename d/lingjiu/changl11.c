//room: changl11.c
inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ�����
������������ͼ�����������ɣ�����ʤ�ա��ذ岻֪����ʲô�������ģ�
�������������Ϣ����ֻ�е���������ģ��ǳ��������������ɽͯ�ѹ�
Ѻ���˵ĵط��������Ǳ��ɽ��أ�û��ͯ�ѵ���ɣ�˭Ҳ���ܽ�ȥ��
LONG );
  set("exits",([
      "east" : __DIR__"changl9",
      "west" : __DIR__"men1",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
