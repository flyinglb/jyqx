//Room: slxl1.c ����С·
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","����С·");
      set("long",@LONG
����ɽ�������е�С·�����߳�������ĺ�������ֻ�ܿ���һ����ա�
·���е�ʿ�ڷ�������������ͨ���䵱ɽ�ţ����߿�ͨ���⽣�ҡ�
LONG);
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
          "west"      : __DIR__"xuanyuegate",
          "eastdown"  : __DIR__"jiejianyan",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

