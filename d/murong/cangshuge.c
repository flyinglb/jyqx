// /u/beyond/mr/cangshuge.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"�����"NOR);
         set ("long",@long
������������ɽׯ�Ĳ����, �����书���������, ��������,���� "����
��" �Ĳ�����ٵС� ��������ȫ��һ���Ÿߴ����ܡ�
long);
set("no_fight", 1);
set("exits",([
"down" : __DIR__"yunjinlou",
]));
	setup();
	replace_program(ROOM);
}

