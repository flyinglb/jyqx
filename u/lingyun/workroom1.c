#include <ansi.h>
inherit ROOM;

void create()
{
set("short", HIW "���ƻ����" NOR);
set("long", @LONG
���߽�һ���ܴ�ķ��䣬���������ƵĿ��������ƶ�������Ӵ����ˣ�
���������������ӣ�chair�����������һ�����ӣ�desk����¥�������Ƶ�
�����ң��������һ���ܺ�����Բ���
LONG    );
        set("exits", ([
                "up" : "/u/lingyun/workroom",
                "wz" : "/d/wizard/wizard_room",
                "kd" : "/d/city/kedian",
        ]));
        set("item_desc", ([
                "desk" : "һ�ŵ��ŵ���֦ľ���ӣ��������һ�׹����ߡ�\n",
                "chair" : "һֻ��֦ľ��̫ʦ�Σ����������е�������������\n",
        ]));
        set("valid_startroom", 1);
        set("no_steal", 1);
        set("no_fight", 1);
        set("no_sleep", 1);

        setup();
        call_other("/u/lingyun/lingyun_b", "???");
}
int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me) )
                return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
}
