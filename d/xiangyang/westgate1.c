// Room: /d/xiangyang/westgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "�׻�����");
	set("long", 
"�����������ǵ������ŵ��ڳ��ţ�ֻ�������Ϸ���������
�֡�"HIW"

                      �׻���
\n"NOR
"�������ɹ��Ŵ��ַ������ǣ�����������൱���ܣ�һЩ�ٱ�
�������̲�Ҫ�������ǵ��ˡ��������ϳ�ͷ��ʯ�ף��򶫽���
������\n"
 );
        set("outdoors", "xiangyang");

	set("exits", ([
		"southup" : __DIR__"wallw2",
		"northup" : __DIR__"wallw1",
		"east"    : __DIR__"westjie3",
		"west"    : __DIR__"westgate2",
	]));
	set("objects", ([
		__DIR__"npc/pi"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
	replace_program(ROOM);
}

