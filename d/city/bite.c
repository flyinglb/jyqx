// Room: bite.c
// Date: Sep.6 1997

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
      set("short", "������");
      set("long",
"�����ǡ������ӡ��������봺����С���ڵļҡ��Ҿ߰�������\n"
"���ʣ��Ĵ���ֲ��ɫ�滨��ݣ����Ž��أ��������㡣�����Բ���\n"
"�ݶ�Ͷ���������ʰ��ã������쳣�����˻��������ɾ�������һ\n"
"�Ŵ󴲣���ͷ������ɫ����һ�������ԧ����һ�ԡ�\n"
"    ����ǽ���������д��֣�\n"
HIR"      ���᱾����\n"
"      �������̨\n"
"      ������һ��\n"
"      �δ�Ⱦ����\n"NOR
"�ּ��ݾ�ͦ�Σ������������������֮��������̾Ϊ��ֹ��\n"
);
      set("exits", ([ /* sizeof() == 1 */
          "west" : __DIR__"jiaowai1",
          "south": "/u/java/room/house",
      ]));
      set("valid_startroom","1");

      set("no_fight", 1);
      set("no_clean_up", 0);
      set("sleep_room", 1);
      setup();
      create_door("west", "����С��", "east", DOOR_CLOSED);
}
int valid_leave(object me, string dir)
{
      if (dir=="south")
      return notify_fail(GRN"�����˼�Ů���ӵ��鷿�������ͱ��ȥ�ˡ�\n"NOR);
      return ::valid_leave(me, dir);
}               

