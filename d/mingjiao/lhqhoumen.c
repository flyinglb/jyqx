//lhqhoumen.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "�һ������");
        set("long", @LONG
��������һ���ĺ��ţ�������������ܶ����ڣ���������
���ڳ���׷ס����ڵش���Ҫ������Ĺط�Ҳ�����ܡ�
LONG );
        set("exits", ([
                "northup"   : __DIR__"zhandao1",
                "southdown" : __DIR__"lhqyuan",
        ]));
        set("objects", ([
                __DIR__"npc/tuoba" : 1,

        ]));
        set("outdoors", "mingjiao");
        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
        me = this_player();
        if ((me->query("party/party_name")!=HIG "����" NOR) &&
            (dir=="northup") &&
            (objectp(present("tuoba", environment(me)))))
            return notify_fail("�ذ���ס��˵���˴��������صأ���ֹ����\n");
        return ::valid_leave(me, dir);
}
