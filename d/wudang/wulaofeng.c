//Room: wulaofeng.c ���Ϸ�
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","���Ϸ�");
      set("long",@LONG
ֻ���������ͻأ�������ޱȣ����˶಻�ҷŵ��ڴ����ͷ羰��
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"sanlaofeng",
          "southup"  : __DIR__"hutouyan",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
