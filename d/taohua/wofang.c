
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "�Է�");
	set("long", @LONG
���߽���һ���Է���һ���������޵������˱Ƕ������ٽ��黭��
����ǽ�ϡ�����ɴ�֣������⡣С������Ҥ����ƿ�ڵ��һ�����ʢ
��������һ�Ŵ�����ͷ���������Ʊ���
LONG );
    set("exits", ([
        "east" :__DIR__"dating",
    ]));
    set("objects", ([
        CLASS_D("taohua")+"/rong" : 1,
        __DIR__"npc/binu" : 2,
    ]) );
//    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
