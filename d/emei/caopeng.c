//Room: caopeng.c ����
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","����");
      set("long",@LONG
���Ƕ���ɽ����һ���򵥵Ĳ�����϶���Щ�ϻ����ܶ���ɽ���οͶ���
������Щ��ɽ��Ʒ��������и��ھ���������һ����ǡ�
LONG);
      set("outdoors", "emei");
      set("objects", ([
               __DIR__"npc/xiao-fan": 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "west"      : __DIR__"majiu1",
          "east"      : __DIR__"qsjie2",
      ]));
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
