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
   "northwest" : __DIR__"zhanglao2",
   "southeast" : __DIR__"zhanglao",
   "west"      : __DIR__"dating3",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
