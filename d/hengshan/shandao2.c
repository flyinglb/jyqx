// Room: /d/hengshan/huixiantai.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���Է�ɽ��");
        set("long", @LONG
�����ڼ��Է�ɽ��С·�ϣ�����ɽ��������ӹģ���ǰ����Ư
����ԶԶ����ǰ����Ƿ嶥�ˡ�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southdown"  : __DIR__"beiyuedian",
           "eastup"     : __DIR__"square",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

