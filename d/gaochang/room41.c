// Room: /u/mei/room41.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "СϪ");
        set("long", @LONG
ɳ����Ȼ������ϡϡ��������ݣ��ٱ�һ�󣬵�����ݽ��ࡣת��֮�䣬
��ǰ����һ��СϪ (bourn)������Ϫ�ߣ�����һ��ˮ���£�ֻ��һ��������ֱ͸
�ķΡ���ˮ����֮�л�����΢΢��������س���һ�����ѵ�Ȫˮ��Ϫˮ������С
���������ײ������������������������ˣ��������֡�
LONG
        );
        set("resource/water", 1);
        set("item_desc", ([
                "bourn" : "
     Ϫ��С�����������������ʢ(fill)��������Ϫˮ��������̬���ţ����
ſ�º�(drink)�ɡ�\n",
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
            message("vision", me->name()+"ſ��Ϫ�ߣ�����һ��Ϫˮ���£�ֻ��һ��������ֱ͸�ķΡ�\n"
            , environment(me), ({me}) );
            write("������һ��Ϫˮ���£�ֻ��һ��������ֱ͸�ķΡ�\n");
        }
        else write("�������ƶ��Ӱ�������\n");
        return 1;
}
