// Room: hnme.c
// Date: Sep.6 1997

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
      set("short", "���¸�");
      set("long",
"�����ǡ����¸󡯣��ǽ������˾��ϵļҡ����ڲ��ù��ӵ��ţ�\n"
"����һ˿���������ڼҾ���Ȼ���࣬�����Ե�ǡ���ô���������עĿ\n"
"��������һ����ɫ����ĺ�ľ�����������˸����ɵ��书�ܼ���\n"
"������һ�Ŵ󴲣����߲輸�ϻ���һ�ױ��µĲ�ߣ�����Ĳ���ð��\n"
"������ʹ�������������ŵ����Ĳ��㡣ǽ������һ����������Ŀ�ݣ�\n"
BLU"        �п�ͥǰ��������\n"
"        ���������ƾ�����\n"NOR
);
      set("exits", ([ /* sizeof() == 1 */
          "south" : __DIR__"jiaowai7",
      ]));
      set("valid_startroom","1");

      set("no_fight", 1);
      set("no_clean_up", 0);
      set("sleep_room", 1);
      setup();
      create_door("south", "��С��", "north", DOOR_CLOSED);
}


