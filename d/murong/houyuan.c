// /u/beyond/mr/houyuan.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"��Ժ"NOR);
         set ("long",@long
����һ�������εĹ���, ������һ��С¥֮ǰ��С¥����һ���Ҷ�, д
��: "�ƽ�¥" ����ī�̺���, ¥��ǰ�������ֵĶ��ǲ軨������Щ�軨��
��������������ɫ, ���⾫�µ�¥��ͤ����, δ�ⲻ�ġ���������һ����
�ȣ��������ƽ�¥��
long);
         set("outdoors","mr");
         set("exits",([
             "south" : __DIR__"yunjinlou",
             "west" : __DIR__"cl3",
             "east" : __DIR__"cl4-2",
             "north" : __DIR__"xiaojing8",
]));
set("objects",([
__DIR__"npc/puren" : 1,
]));
         setup();
         replace_program(ROOM);
}

