// Room: /u/mei/room29.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "���ɽ��");
        set("long", @LONG
����������������ͨ��ѩ�ף�Ө�ⴿ�������񽳵�ֻҪ�ҵ�СС��һ��
������Ȼ������Ų�������֪���ﾹ������һ������ɽ�塣̧ͷ������ֻ��
�Ŀ����������Ǿ�����������̾����֮�档
LONG
        );
        set("no_new_clean_up", 0);
        set("outdoors", "room29");
        set("item_desc", ([
        "����ɽ��":   
"     ���ϲ�������ۼ��������ƺ�������(climb)��ȥ��\n",
]));
        set("exits", ([ /* sizeof() == 2 */
        "south" : __DIR__"room27",
]));
        setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
    object me;
    me = this_player();
    if( !arg || arg!="up") return notify_fail("��Ҫ���ĸ���������\n");
        me->move(__DIR__"room30");
        message("vision",
        me->name() + "սս�����أ������������������\n",
                environment(me), ({me}) );
        message("vision",
        me->name() + "�������������������\n",
                environment(me), ({me}) );
    return 1;
}
