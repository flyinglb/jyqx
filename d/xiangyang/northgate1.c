// Room: /d/xiangyang/northgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "��������");
	set("long", 
"�����������ǵı����ŵ��ڳ��ţ�ֻ�������Ϸ���������
�֡�"HIB"

                      ������
\n"NOR
"�������ɹ��Ŵ��ַ������ǣ�����������൱���ܣ�һЩ�ٱ�
�������̲�Ҫ�������ǵ��ˡ��������ϳ�ͷ��ʯ�ף����Ͻ���
������\n"
 );
        set("outdoors", "xiangyang");

	set("exits", ([
		"eastup" : __DIR__"walln1",
		"westup" : __DIR__"walln2",
		"south"  : __DIR__"northjie",
		"north"  : __DIR__"northgate2",
	]));
	set("objects", ([
		__DIR__"npc/pi"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
	replace_program(ROOM);
}

