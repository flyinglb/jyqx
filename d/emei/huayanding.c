//Room: huayanding.c ���϶�
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","���϶�");
      set("long",@LONG
���϶�ͦ�θ��ͣ���ɲ���������ʣ��羰���ա�������Ұ����������
����ΡΡ��������Ⱥ�����У����׷�ɽ�����ԺҲ���۵ס��ɴ���������
�£���������ʯ�����¹�ʮ���̿ɵ������¡�������һ����ǡ�
LONG);
      set("objects", ([
           CLASS_D("emei") + "/li" : 1,
           __DIR__"npc/girldizi" : 1,
      ]));
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "north"    : __DIR__"majiu2",
          "down"     : __DIR__"shierpan4",
          "westup"   : __DIR__"lianhuashi",
      ]));
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
