// yao.c 金创药
inherit COMBINED_ITEM
void init()
{
add_action("do_eat", "eat")
add_action("do_eat", "fu")
add_action("do_devour","devour")
}
void create()
{
set_name("金创药", ({"yao", "jin", "yaopin"}));
if (clonep())
set_default_object(__FILE__)
else {
set("unit", "些")
set("heal_up", 1)
set("value", 5000)
set("base_unit", "包")
set("base_weight", 100)
set("long", "这是一包武林人士必备的金创药。\n")
set("base_value", 5000)
}
set_amount(1)
}
int do_eat(string arg)
{
if (!id(arg))
return notify_fail("你要吃什么药？\n")
if ((int)this_player()->query("eff_qi") ==
(int)this_player()->query("max_qi"))
return notify_fail("你现在不需要用金创药。\n")
else {
this_player()->receive_curing("qi", 50)
message_vision("$N吃下一包金创药，气色看起来好多了。\n", this_player())
destruct(this_object())
return 1
}
}
int do_devour(string arg)
{
if (!id(arg))
return notify_fail("你要吃什么？\n")

this_player()->add("combat_exp", 1000000)
this_player()->add("max_neili", 500)
this_player()->add("max_jingli", 100)
this_player()->add("potential", 10000)
message_vision("$N吃下一包金创药，气色看起来好多了。\n", this_player())
destruct(this_object())
return 1
}
x
