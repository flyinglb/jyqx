// yao.c ��ҩ
inherit COMBINED_ITEM
void init()
{
add_action("do_eat", "eat")
add_action("do_eat", "fu")
add_action("do_devour","devour")
}
void create()
{
set_name("��ҩ", ({"yao", "jin", "yaopin"}));
if (clonep())
set_default_object(__FILE__)
else {
set("unit", "Щ")
set("heal_up", 1)
set("value", 5000)
set("base_unit", "��")
set("base_weight", 100)
set("long", "����һ��������ʿ�ر��Ľ�ҩ��\n")
set("base_value", 5000)
}
set_amount(1)
}
int do_eat(string arg)
{
if (!id(arg))
return notify_fail("��Ҫ��ʲôҩ��\n")
if ((int)this_player()->query("eff_qi") ==
(int)this_player()->query("max_qi"))
return notify_fail("�����ڲ���Ҫ�ý�ҩ��\n")
else {
this_player()->receive_curing("qi", 50)
message_vision("$N����һ����ҩ����ɫ�������ö��ˡ�\n", this_player())
destruct(this_object())
return 1
}
}
int do_devour(string arg)
{
if (!id(arg))
return notify_fail("��Ҫ��ʲô��\n")

this_player()->add("combat_exp", 1000000)
this_player()->add("max_neili", 500)
this_player()->add("max_jingli", 100)
this_player()->add("potential", 10000)
message_vision("$N����һ����ҩ����ɫ�������ö��ˡ�\n", this_player())
destruct(this_object())
return 1
}
x
