// Room: /u/mei/room68.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
����ȥ�˶���ֻ࣬���ͱ�����һ�����ٲ�������£�������ѩ
�ڶ��ɣ���������������һ��������������׳�����ٲ�к��һ���峺
���̵���̶֮�У�̶ˮȴҲ����������������йˮ��ȥ·��
LONG
        );
        set("no_new_clean_up", 0);
        set("exits", ([ 
  "east" : __DIR__"room67",
]));
        set("outdoors", "city");
        set("item_desc", ([
        "�ͱ�" : "�ͱ�����һСɽ��(cave)���ƺ�������(zuan)��ȥ��\n", 
        "cave" : "�������ɽ����Ʈ��һ�����磬�ŵ���ֱ����¡�\n",
        "��̶" : "̶���������С���㡣\n", 
])); 
        set("objects",([
        __DIR__"npc/monkey1":1,
        ]));

        setup();
}
void init()
{
   add_action("do_zuan","zuan");
}

int do_zuan(string arg)
{

    object me = this_player();
//    int dex = this_player()->query_dex();
//    object ob;

    if (arg != "cave" && arg != "out") return notify_fail("����ôû���ϰ��궴ѽ?\n");
    if (me->query("age")>16) return notify_fail("��ôС�Ķ�����ֻ��С��������ý�ȥ!\n");
        message("vision", me->name() + "����һ�����˽�ȥ��\n",
                environment(me), ({me}) );
    me->move(__DIR__"room66");
        message("vision", me->name() + "��ʯ�������˳�����\n",
                environment(me), ({me}) );
    return 1;
}

