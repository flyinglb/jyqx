#include <weapon.h>
#include <ansi.h>
inherit SWORD;
object ob;
void create()
{
seteuid(getuid());
	set_name(HIG"ʥ�����˵���˷�"NOR, ({"magic mac", "mac"}));
set_weight(250);
if ( clonep ())
	set_default_object(__FILE__);
	else
{
	set("unit", BLINK"��"NOR);
	set("value", 1000);
	set("material", "gold");
	set("long", HIW"������ʦΪ�˴�Ҷ�ǧ���������»���������͵����MAC\n"NOR);
	set("wield_msg", HIY"�������һ�����"NOR+HIG"ʥ�����˴������"NOR+HIW"$N\n"NOR
HIB"		����һ��Wa...һ��"NOR+BLINK"ħ��̳֮��"NOR+HIB"Ʈ������!\n"NOR);
	set("unwield_msg", HIC"$NС�ĵĽ�ʥ�������պ�!\n"NOR);
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
	return notify_fail("����˵ʲô\n");
}
message("channel:music", HIG"��ʥ�����֡�"+this_player()->query("id")+"���˵�˵: "+str+"\n"NOR,users(
));
return 1;
}
