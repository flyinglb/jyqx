//Room: bailongdong.c ������
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","������");
      set("long",@LONG
��������˵�ǡ����ߴ����еİ�������������֮���������ľ���죬����
�е���������ͦ���Σ�֦Ҷ����������������ӵ�𣬴�Ϊ��ʱһ��ɮ��������
��������һ�֣�ֲ��һ�꣬��ֲ�����ǧ�߰���ʮ���꣬ʱ�ƹŵ��֡����ﱱ
���������֣�������������
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "east"      : __DIR__"gudelin1",
          "west"      : __DIR__"gudelin2",
          "northup"   : __DIR__"wannianan",
          "southeast" : __DIR__"qingyinge",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
