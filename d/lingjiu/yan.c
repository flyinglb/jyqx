//room: yan.c
inherit ROOM;

void create()
{
  set("short","ʧ����");
  set("long",@LONG
����ͨ�����չ����ıؾ�֮·��ɽ����һ����ӥ�ͻ���ľ��ҽض�
�����ҹ�ɼ��ˣ�ֻ���м������һ��խխ��ʯ��ͨ��ɽ������һͷ����
С�����������̤����ȥ�����룺���ܹ�ȥ�ɡ�
LONG );
  set("outdoors", "lingjiu");
  set("exits",([
      "northup"  : __DIR__"jian",
      "eastdown" : __DIR__"ya",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
