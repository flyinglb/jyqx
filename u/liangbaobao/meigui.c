// /u/beyond/obj/chahua1.c
// this is made by beyond
// update 1997.6.30
#include <ansi.h>                     
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIR"情人节的玫瑰"NOR,({ "mei gui", "flower" }) );
         set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("value", 0);
                set("material", "plant");
                set("long", "这是一朵情人节送给情人的玫瑰。\n");
                set("wear_msg", "");
                set("unequip_msg", "$N放下手里的$n。\n");
                set("armor_prop/armor", 0);
        }
           
        setup();
}

int wear()
{
        object me = environment();
        int ret;

        message_vision("$N拿出一朵" + this_object()->query("name") + "，抱在手里。", me);
        if (ret=::wear()) {
                if (me->query("gender") == "男性")
                        message_vision("感觉自己好温馨！\n", me);
                else if (me->query("gender") == "女性")
                        message_vision("感觉到情人对自己的关心！\n", me);
                else
                        message_vision("好一个不三不四的家伙！\n", me);
        }
        return ret;
}

