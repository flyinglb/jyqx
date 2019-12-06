// bandage.c

inherit ITEM;
inherit F_EQUIP;

void create()
{
	set_name("����", ({ "cloth piece", "cloth", "piece" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_type", "bandage");
		set("armor_prop/attack", -10);
		set("armor_prop/defense", -10);
		set("armor_prop/unarmed", -10);
	}
}

void init()
{
	add_action("do_bandage", "bandage");
}

int wear() { return 0; }

int do_bandage(string arg)
{
	object ob;

	if( (int)query("blood_soaked") >= 2 )
		return notify_fail( name() + "�Ѿ�����Ѫ��͸�����������ˡ�\n");

	if( query("equipped") )
		return notify_fail( name() + "�Ѿ���������˿����ˣ������Ҫ�����������ˣ������Ȱ�����������\n");

	if( !arg ) ob = this_player();
	else {
		ob = present(arg, environment(this_player()));
		if( !ob || !userp(ob))
			return notify_fail("��Ҫ��˭���ˣ�\n");
	}

	if( this_player()->is_fighting()
	||	ob->is_fighting() )
		return notify_fail("ս���в��ܹ��ˡ�\n");

	if( (int)ob->query("eff_qi") == (int)ob->query("max_qi") )
		return notify_fail( (ob==this_player()? "��" : ob->name())
			+ "��û���ܵ��κ����ˡ�\n");

	if( ob->query_temp("armor/bandage") )
		return notify_fail( ob->name() + "���ϵ����Ѿ��������������ˡ�\n");

	if( !move(ob) ) return 0;

	if( ob==this_player() )
		message_vision("$N��" + name() + "���Լ����ˡ�\n", this_player());
	else
		message_vision("$N��" + name() + "��$n���ˡ�\n", this_player(), ob);

	::wear();
	ob->apply_condition("bandaged", 40);
	add("blood_soaked", 1);

	return 1;
}

void remove(string euid)
{
	::remove(euid);
	if( query("equipped") && environment() )
		environment()->apply_condition("bandaged", 0);
}

string query_autoload()
{
	if( query("equipped") ) return query("name");
}

void autoload(string arg)
{

	set("name", arg);
	set("blood_soaked", 3);
	::wear();
}

