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
    "northwest"  : __DIR__"shizhe",
    "northeast"  : __DIR__"shizhe2",
    "west"       : __DIR__"dating2",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
