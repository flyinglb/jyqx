// Room: /d/xiangyang/guofugate.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "��������");
	set("long", 
"һ���������ӵĴ�լԺ�����������ǰ��ֻ����¥������
������������"HIY"
                     ��   ��
"NOR"
    ȫ��̵ڶ�������Ү����ͼ����Ҷ�վ����ǰ�Ӵ�ǰ����
�������ĸ�����ʿ��\n"
 );
        set("outdoors", "xiangyang");
	set("exits", ([
		"south" : __DIR__"westjie1",
		"north" : __DIR__"guofuyuan",
	]));
	set("objects", ([
		__DIR__"npc/yelvqi" : 1,
		__DIR__"npc/jiading" : 2,
	]));
	setup();
	replace_program(ROOM);
}

