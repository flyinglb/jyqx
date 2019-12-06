// Room: /u/mei/room41.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "小溪");
        set("long", @LONG
沙丘间忽然出现了稀稀落落的铁草，再奔一阵，地下青草渐多。转眼之间，
面前出现一条小溪 (bourn)，俯身溪边，掬了一口水喝下，只觉一阵清凉，直透
心肺。那水甘美之中还带有微微香气，想必出自一处绝佳的泉水。溪水中无数小
块碎冰互相撞击，发出清脆声音，叮叮咚咚，宛如仙乐。
LONG
        );
        set("resource/water", 1);
        set("item_desc", ([
                "bourn" : "
     溪虽小，如果有容器，可以盛(fill)点清凉的溪水。不怕仪态不雅，你就
趴下喝(drink)吧。\n",
        ]));

        set("exits", ([ 
        "north" : __DIR__"room42",
        "south" : __DIR__"room15",
]));
        set("outdoors", "room41");

        setup();
}
void init()
{
        add_action("do_drink", "drink");
}
int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;
        me = this_player();
        current_water = me->query("water");
        max_water = me->max_water_capacity();
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"趴在溪边，掬了一口溪水喝下，只觉一阵清凉，直透心肺。\n"
            , environment(me), ({me}) );
            write("你掬了一口溪水喝下，只觉一阵清凉，直透心肺。\n");
        }
        else write("不怕涨破肚子啊！！！\n");
        return 1;
}
