//Room: shanlu4.c ɽ·
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","ɽ·");
      set("long",@LONG
�����ڵ�ɽ��·���ϣ�·�����Ҹ���һ����������������������ɽ��ɽ
��������ȥ����������ľ�е�����������Ļ�С�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"shanlu3",
          "southup"  : __DIR__"taiziyan",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
