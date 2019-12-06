// shuijing

inherit ROOM;

void create()
{
        set("short", "蝴蝶泉");
        set("long", @LONG
        在向前行，一路上嫣红姹紫，遍山遍野都是鲜花。春光烂漫已极。
转过一树花丛，眼前出现一眼泉水，泉水清澈见底，散发出一种沁人心脾的 
清凉。泉水的旁边，飞舞一群群的蝴蝶，或花或白，或黑或紫，翩翩起舞。 
蝴蝶并不畏人，飞近时便在人们的身上停留。
LONG );
        set("exits", ([
                "northwest" : __DIR__"guajia",
        ]));
        set("no_clean_up", 0);
        setup();
//      replace_program(ROOM);
}

void init()
{
        add_action("do_jump", "jump");
        add_action("do_zong", "zong");
}
int do_jump(string arg)
{
        object me;
        if (!arg ||arg !="down") return 1;
        me = this_player();
        message_vision("$N向上走去。\n",me);
        me->move(__DIR__"wuchang3");
        message_vision("$N跳了过来。\n",me);
        return 1;
}
int do_zong(string arg)
{
        object me;
        if (!arg ||arg !="shen") return 1;
        me = this_player();
        message_vision("$N向上走去。\n",me);
        me->move(__DIR__"wuchang2");
        message_vision("$N跳了过来。\n",me);
        return 1;
}

