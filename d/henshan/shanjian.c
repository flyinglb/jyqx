// Room: /d/henshan/shanjian.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
˳ɽ��Ư�����£���Ϫ�鲼��ϡ��ľ��Ȫʯ����ľ�����ݼ����;�
�����ˡ����������۵���й���£�����ɽ�ȡ�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "down"     : __DIR__"heishatan",
           "northup"  : __DIR__"fangguangsi",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

