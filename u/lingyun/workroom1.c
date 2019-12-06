#include <ansi.h>
inherit ROOM;

void create()
{
set("short", HIW "凌云会客室" NOR);
set("long", @LONG
你走进一个很大的房间，这里是凌云的客厅，凌云都在这里接待客人，
客厅放着两排椅子（chair），中央放着一张桌子（desk），楼上是凌云的
工作室，这里放着一本很厚的留言簿。
LONG    );
        set("exits", ([
                "up" : "/u/lingyun/workroom",
                "wz" : "/d/wizard/wizard_room",
                "kd" : "/d/city/kedian",
        ]));
        set("item_desc", ([
                "desk" : "一张典雅的酸枝木桌子，上面放着一套功夫茶具。\n",
                "chair" : "一只酸枝木的太师椅，坐在上面有点冰凉，很舒服。\n",
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
                return notify_fail("那里只有巫师才能进去。\n");
        return ::valid_leave(me, dir);
}
