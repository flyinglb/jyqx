//Room: mozhenjing.c ĥ�뾮
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","ĥ�뾮");
      set("long",@LONG
�ഫ���������ɽ�������վ�˼�飬ż��һ�ϸ���������ĥ����ĥ��
Ϊ�Σ�����ĥ�롣������������ĥ�룿���ƹ�����Ȼ�ɡ������ɴ�����
�����������ɡ�������ĥ�뾮������Ϊ�����ǰ��������һ������
������ĸͤ��ͤ�����о�(jing)��
LONG);
      set("exits",([ /* sizeof() == 1 */
          "west"     : __DIR__"shanlu1",
      ]));
      set("item_desc",([ 
          "jing"     : "���ع��ӣ�ˮɫ����������װƿ���á�\n",
      ]));
      set("resource/water", 1);
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
