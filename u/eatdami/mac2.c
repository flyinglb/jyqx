#include <weapon.h>
#include <ansi.h>
inherit SWORD;
object ob;
void create()
{
seteuid(getuid());
	set_name(HIG"圣诞老人的麦克风"NOR, ({"magic mac", "mac"}));
set_weight(250);
if ( clonep ())
	set_default_object(__FILE__);
	else
{
	set("unit", BLINK"把"NOR);
	set("value", 1000);
	set("material", "gold");
	set("long", HIW"这是巫师为了大家而千辛万苦从刘德华天王手中偷来的MAC\n"NOR);
	set("wield_msg", HIY"天边闪过一道金光"NOR+HIG"圣诞老人从天而降"NOR+HIW"$N\n"NOR
HIB"		睁眼一看Wa...一把"NOR+BLINK"魔神坛之剑"NOR+HIB"飘落手中!\n"NOR);
	set("unwield_msg", HIC"$N小心的将圣诞礼物收好!\n"NOR);
}
init_sword(100);
setup();
}
void init ()
{
add_action("do_mac", "mac");
}
int query_autoload()
{ return 1; }
int do_mac(string str)
{
//int i;
if (!str) {
	return notify_fail("你想说什么\n");
}
message("channel:music", HIG"【圣诞快乐】"+this_player()->query("id")+"高兴得说: "+str+"\n"NOR,users(
));
return 1;
}
