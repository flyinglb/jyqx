//Room: lingyunti.c ������
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","������");
      set("long",@LONG
���������ݣ�������һλ�а��Ŷ����������ڴ˸�ľ��ʯ���Զ����ˣ�
�ֽС���ɮ�ݡ���·����÷���£��ɼ�������÷�綹������֦��Ҷ�ж������ˣ�
���С���÷ֹ�ʡ�֮���á����ݱ�ͨϴ��أ������׶�ƺ��
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"xixiangchi",
          "southup"    : __DIR__"leidongping",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
