// Room: /d/mingjiao/nanshe.c
// Jan.5 1997 by Venus

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "��������");
    set("long", @LONG
�߽�������ᣬһ�󺹳���Ѭ���棬�����Ӹϲ�ȥ���������
���ֺ��ӹ���������񣬺����쳣�غ�����ϯ�����Ͼ�ˮ���죬��
���Ǽ�����Ȼ���ȵò���ˡ�
LONG );
    set("exits", ([
        "out" : __DIR__"mjtianmen1",
    ]));
    set("no_clean_up", 0);
    set("sleep_room", 1);
    set("no_fight", 1);
    setup();
    replace_program(ROOM);
}
