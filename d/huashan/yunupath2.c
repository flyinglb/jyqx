//Room: yunupath2.c ��Ů��ɽ·
//Date: Oct. 2 1997 by Venus
inherit ROOM;

void create()
{
      set("short","��Ů��ɽ·");
      set("long",@LONG
��������Ů���ɽ��һ��ɽ·��·�߳����˴���ÿ��΢�����
����Ҷ��ɳɳ���죬�Ե÷�����ľ���
LONG);
      set("outdoors", "xx");
      set("no_clean_up", 0);
      set("exits",([ /* sizeof() == 1 */
          "southup"   : __DIR__"siguoya",
          "northdown" : __DIR__"yunupath1",
      ]));
      setup();
      replace_program(ROOM);
}
