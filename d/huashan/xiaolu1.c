//Room: xiaopath1.c Сɽ·
//Date: Oct. 2 1997 by Venus
inherit ROOM;

void create()
{
      set("short","Сɽ·");
      set("long",@LONG
�����ǻ�ɽ��һ��Сɽ·�����ƽ�Ϊƽ�������������ط���ô��
����������������ܾ����ĵģ�������߽���һ��������Դ��
LONG);
      set("outdoors", "xx");
      set("exits",([ /* sizeof() == 1 */
          "southwest"     : __DIR__"yunu",
          "northeast"     : __DIR__"xiaolu2",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
