//Room: taizipo.c ̫����
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","̫����");
      set("long",@LONG
�˴��ش�����֮����������Ҫ���ഫ���ֹ�̫��(��������)��ɽ�޵�
ʱ�����ڴ���ס���飬������̫���£�����һ���ˮܽ�أ�ӿ���̲�����
������������Զ�����·ת���������𣬾�������֮�С�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"shanlu1",
          "southdown"  : __DIR__"shiliang",
          "east"       : __DIR__"fuzhenguan",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
