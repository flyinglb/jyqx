                 // tong-box.c

inherit ITEM;

void create()
{
        set_name("铜盒", ({"tong he", "he"}));
        set_weight(50000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","这铜盒样子很怪，表面看来似乎是很多机关的组合，而且非常重。\n");
                set("unit", "个");
        }
}

void init()
{
        if(environment()!=this_player()) return;
        add_action("do_open","open");
}

int do_open(string arg)
{
        object me, obj;
        me = this_player();

        if(!arg || (arg != "tong he" && arg != "he")) return 0;
        message_vision(HIY "$N将铜盒放在了地上，按动了几个开关，只听一阵机关响动，铜盒居然变成了个铜人。\n" NOR, me);
        obj = new("/d/npc/tong-ren");
        obj->move(environment(me));
        this_object()->move(VOID_OB);
        destruct(this_object());
        return 1;
}
