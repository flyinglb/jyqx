// xiaoyuan.c ��ɽСԺ
// by Xiang

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ɽСԺ");
        set("long", @LONG
���Ǻ�ɽ��һ��СԺ�����ü�򵥵�������һ����һ����һ�Ρ�һ���ţ�
��Ҳû�б��ʲ��Ƚ�����עĿ����ǽ�Ϲ���һ�ѽ�����������䵱��ɽ
��ʦ��������������ڡ�
LONG );
        set("exits", ([
                "north" : __DIR__"xiaolu2",
        ]));
        set("objects", ([
                CLASS_D("wudang") + "/zhang" : 1 
        ]));
        create_door("north", "����", "south", DOOR_CLOSED);
//        set("no_clean_up", 0);
        setup();
}
