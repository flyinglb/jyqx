//room: changl14.c
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
    "south" : __DIR__"fulouzhu",
    "north" : __DIR__"louzhu",
    "east"  : __DIR__"dating3",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
