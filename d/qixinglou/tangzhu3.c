#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","ˮ����");
    set("long",@LONG
��������¥��ޱ������ŷ��������Ϣ�ĵط�!����������������ɴ,�ڷ�������Ʈ��!
��ߵİ�������һ����֪�����Ƿ�Ʒ!����ǽ��б����ŷ����������������!��������������
�ı���!���Ѿ����ò�����!
LONG
    );
    set("sleep_room","1");
    set("exits", ([ /* sizeof() == 2 */
	"south" : __DIR__"liangong11",
        "northeast" : __DIR__"chang5",
    ]));
    set("no_fight",1);
    set("no_sleep_room",1);
    set("no_steal",1);
    set("no_beg",1);
    setup();
}
