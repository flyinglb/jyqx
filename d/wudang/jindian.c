//Room: jindian.c ���
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","���");
      set("long",@LONG
����м乩��������ͭ���������㣬��̬�����������н�ͯ��Ů������
�Ϲ�����ˮ�������������ׯ�ϡ���ǰ������Ϊͭ��������͵���ͭ�񡢹�
��í��һ�壬������ȷ�����ɸ߳���
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north"     : __DIR__"zijincheng",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
