//Room: gudelin2.c �ŵ���
//Date: Oct. 2 1997 by That

inherit ROOM;
string look_shibei();

void create()
{
      set("short","�ŵ���");
      set("long",@LONG
����һƬ���ܵ��ľ�֣�������ͦ���Σ�֦Ҷ����������������ӵ�𣬾�
˵��������֮�࣬Ҫ�ǲ���Ϥ���κ�������·��������һƬ�յأ���ֻ�ľ׮
�ų�÷��ģ����
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "south"     : __DIR__"bailongdong",
          "southeast" : __DIR__"gudelin1",
          "southwest" : __DIR__"gudelin1",
          "northeast" : __DIR__"gudelin1",
          "northwest" : __DIR__"gudelin1",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
