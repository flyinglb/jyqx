// sroad8.c
// Modified by Java Apr.27 1998
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","��ѩɽɽ��");
        set("long",@LONG
һ�����ɽ��, Ⱥɽ����, ɽ����ȫ�ǰ������Ļ�ѩ, ɽ���Ϸ�������ɽ����
LONG );
        set("exits",([
                "enter"  : __DIR__"shandong1",
                "north"  : __DIR__"wangyougu",
                "northup": __DIR__"sroad7",
        ]));
        set("outdoors", "xueshan");
        set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
