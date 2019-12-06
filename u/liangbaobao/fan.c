// nianyefan 年夜饭


inherit ITEM;

void create()
{
        set_name("大年三十的年夜饭,", ({"nianye fan", "fan"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是巫师连夜赶作的新年给大家的礼物.。\n");
                set("unit", "只");
                set("no_get", 1);
                set("no_give", 1);
           
        }
}
void init()
{
add_action("do_eat","eat");
}
int do_eat(string arg)
{object me;
me = this_player();
if (!arg || (arg!="nianye fan"&&arg!="fan")) return 0;
if( this_object()->query("gift_to_id") != me->query("id") ) 
        return notify_fail("这东西好象不是你的吧？\n");
if(!me->query("marks/nianyefan_2001"))
{
message_vision("$N唏哩哗啦的一口就把年夜饭吞下了肚里，看来$N是急坏了。\n",me);
me -> add("combat_exp",20000);
me -> add("potential",2000);
tell_object(me,"你吃了年夜饭后觉得精神百倍。\n");
me->set("marks/nianyefan_2001",1);
}
else tell_object(me,"你已经吃过一次年夜饭了，还想吃？\n");
destruct(this_object());
return 1;
}

