// liquid.c

#include <dbase.h>
#include <name.h>

void init()
{
//        if(environment(this_object()) != this_player()) return;
	add_action("do_drink", "he");
	add_action("do_drink", "drink");
	add_action("do_fill", "fill");
	add_action("do_fill", "zhuang");
}

string extra_long()
{
	int amount, max;
	string str;

	if( amount = query("liquid/remaining") ) {
		max = query("max_liquid");
		if( amount == max )
			str = "����װ����" + query("liquid/name") + "��\n";
		else if( amount > max/2 )
			str = "����װ���ߡ��˷�����" + query("liquid/name") + "��\n";
		else if( amount >= max/3 )
			str = "����װ���塢��������" + query("liquid/name") + "��\n";
		else if( amount > max/2 )
			str = "����װ�������" + query("liquid/name") + "��\n";
		return str;
	}
	else return 0;
}

int do_drink(string arg)
{
	if( !this_object()->id(arg) ) return 0;
	if ((int)this_player()->query("hunmi")) return notify_fail("ʲ�᣿\n");
	//if ((int)this_player()->query("sleeps")) return notify_fail("ʲ�᣿\n");
	if( this_player()->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");
	if( !query("liquid/remaining") )
                return notify_fail( name() + (query("liquid/name") ? "�Ѿ����ȵ�һ��Ҳ��ʣ�ˡ�\n":"�ǿյġ�\n"));
	if( (int)this_player()->query("water") >= (int)this_player()->max_water_capacity() )
		return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

	add("liquid/remaining", -1);
	message_vision("$N����" + name() + "������غ��˼���" + query("liquid/name")
		+ "��\n", this_player());
	this_player()->add("water", 30);
	if( this_player()->is_fighting() ) this_player()->start_busy(2);
	if( !query("liquid/remaining") )
		write("���Ѿ���" + name() + "���" + query("liquid/name")
			+ "�ȵ�һ��Ҳ��ʣ�ˡ�\n");

	// This allows customization of drinking effect.
	if( query("liquid/drink_func") ) return 1;

	switch(query("liquid/type")) {
		case "alcohol":
			this_player()->apply_condition("drunk",
				(int)this_player()->query_condition("drunk") 
				+ (int)query("liquid/drunk_apply"));
			break;
	}
	
	return 1;
}

int do_fill(string arg)
{
	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");
	if( !environment(this_player())->query("resource/water") )
		return notify_fail("����û�еط�����װˮ��\n");

	if( query("liquid/remaining") )
		message_vision("$N��" + name() + "��ʣ�µ�" + query("liquid/name") + "������\n", this_player());
	message_vision("$N��" + name() + "װ����ˮ��\n", this_player());

	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	set("liquid/type", "water");
	set("liquid/name", "��ˮ");
	set("liquid/remaining", query("max_liquid"));
	set("liquid/drink_func", 0);

	return 1;
}
