//      cedian1.c ���
//      Designed by secret (����)
//      97/04/09

#include <room.h>
inherit ROOM;

void create()
{
        set("short","���");
        set("long",@LONG
������ѩɽ�µĶ�����������̬�����ʮ���޺�
���񣬽�����⣬����ׯ�ϡ�
LONG );
        set("exits",([
                "up"   : __DIR__"zoulang1",
                "west" : __DIR__"dadian",
        ]));
        set("objects",([
                CLASS_D("xueshan")+"/jiamu" : 1,
                __DIR__"npc/xiang-ke"       : 3,
        ]));
//        set("no_clean_up", 0);
        setup();

}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam=(mapping)me->query("family");
        if( (!myfam || myfam["family_name"] !="ѩɽ��") && dir=="up"
        && !wizardp(me)
        && objectp(present ("jiamu huofo", environment(me))))
                return notify_fail("��ľ���˵��: ���ѩɽ�µ���, �������ڡ�\n");
        return ::valid_leave(me,dir);
}


