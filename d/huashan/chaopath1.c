// Roon: chaoyangpath1.c ������С·
//Date: Oct. 2 1997 by Venus
inherit ROOM;

void create()
{
      set("short","������С·");
      set("long",@LONG
�����ǳ�����С·��ɽ�ƶ��ͣ�����������ȣ�һ��С�Ķ����
����ȥ��
LONG);
      set("outdoors", "xx");
      set("no_clean_up", 0);
      set("exits",([ /* sizeof() == 1 */
          "northeast": __DIR__"chaopath2",
          "southeast": __DIR__"square",
      ]));
      setup();
      replace_program(ROOM);
}

