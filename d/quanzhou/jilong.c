// Room: /d/quanzhou/jilong.c
// Date: May 7, 96   Jay
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����Ϊ̨�山�����ۡ�Ⱥɽ�����ĸۿڸ��ع����
�̳��ܣ��С�̨���������֮�Ƶĳ����������ڴ˿�����
ɣ��������Ϣ���Ű�������
LONG );
	set("exits", ([
                "south" : __DIR__"chiqian",
	]));
	set("objects", ([
		__DIR__"npc/wokou": 2,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

