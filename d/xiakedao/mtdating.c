//room: mtdating.c
inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG
�����Ħ�����ˡ������ͺͺ�ģ���һ��С��Ҳû�У��嶥��
Ҳʮ�ֿ������������������ƣ������������ƶ�֮�У�ʹ���ľ���
����������һ��Сľ�ݣ��ű�����һ�����ɫʯ��(bei)��
LONG );
        set("outdoors", "xiakedao");
        set("exits",([
                "east" : __DIR__"mtxiaowu",
                "down" : __DIR__"mtyadi",
        ]));
        set("item_desc",([
                "bei" : "   ��Ħ���¡�  \n�ޡ�������߽��룡\n",
        ]));
        set("objects",([
                __DIR__"npc/xieyan" : 1,
        ]));
        setup();
}
void init()
{
        add_action("do_pai", "pai");
}
int do_pai(string arg)
{
        object me;
        if (!arg ||arg !="beice") return 1;
        me = this_player();
        message_vision("$N������ȥ��\n",me);
        me->move(__DIR__"mtxiaowu2");
        message_vision("$N���˹�����\n",me);
        return 1;
}

int valid_leave(object me, string dir)
{
        if (  (dir == "east")
                && (!present("xuan tie",me))
                && objectp(present("xie yanke", environment(me))) )
        return notify_fail
                ("л�̿Ͱ���һ������û�С�����������ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
}
