//Room: jieyindian.c ������
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","������");
      set("long",@LONG
�������ұ߱��£��ǽ���졣������һ���ʯ����״���ӣ���������ʯ����
������һʯ������ʮ���ɣ��С�����ʯ�����ɴ��������ʼ��������֣����¾�
����ʮ���̡���ϴ��ء�
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "northwest" : __DIR__"bashisipan3",
          "westup"    : __DIR__"wanxingan",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
