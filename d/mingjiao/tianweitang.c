//tianweitang.c
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "��΢��");
        set("long", @LONG
����������̵���΢�ã�������������Զ������Ұ�������ǰ�üӥ
���Ķ��Ӻͽ������޼ɵľ˾ˡ����ڳ��������ݻ�����Ȼ������������
�����ڽ��������������Ǹ�ִ���У��ƺ������ܶ����ʿ��
LONG );
        set("exits", ([
                "east"      : __DIR__"tianshitang",
                "west"      : __DIR__"ziweitang",
                "southdown" : __DIR__"zhandao2",
                "north"     : __DIR__"square",
        ]));
        set("objects",([
             __DIR__"npc/yinyewang":1,
             __DIR__"npc/yinwufu":1,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        me = this_player();
        if ((me->query("party/party_name")!=HIG "����" NOR) &&
            (dir=="north") &&
            (objectp(present("yin yewang", environment(me)))))
        return notify_fail("��Ұ����ס��˵���˴��������صأ���ֹ����\n");
        return ::valid_leave(me, dir);
}
