//Room: fhs.c ������
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","������");
      set("long",@LONG
����������ɽ��һ��ɲ�������ڸߴ����ľ�ּ䣬�����ľ���죬���
ʮ�����ꡣ����������ׯ�ϣ���ģ��ʢ�����ÿ����ƶ�Ρ�롣��ɲ���ڸ���
����Ũ��֮�У�������ȴ��һƬ��Ҷ���������Ͻ����±��ǹ����á�
LONG);
      set("objects", ([
           __DIR__"npc/boydizi" : 1,
           __DIR__"npc/girldizi" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "east"    : __DIR__"milin1",
          "westup"  : __DIR__"milin2",
      ]));
      set("outdoors", "emei");
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
