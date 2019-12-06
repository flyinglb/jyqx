// powder.c

inherit COMBINED_ITEM;

void init()
{
	add_action("do_pour", "pour");
}

int do_pour(string arg)
{
	string me, what;
	object ob;
	function f;

	if( !arg
	||	sscanf(arg, "%s in %s", me, what)!=2
	||	!id(me) )
		return notify_fail("ָ���ʽ: pour <ҩ��> in <��Ʒ>\n");

	ob = present(what, this_player());
	if( !ob )
		return notify_fail("������û�� " + what + " ����������\n");
	if( !ob->query("liquid/remaining") )
		return notify_fail(ob->name() + "��ʲ��Ҳû�У���װЩˮ�Ʋ����ܻ�ҩ�ۡ�\n");
	// We let call other to call the "master copy" of the object in case the
	// powder object got destructed after used up.
	f = (: call_other, base_name(this_object()), "effect_in_liquid" :);
	ob->set("liquid/drink_func", bind(f, ob));
	message_vision("$N��һЩ" + name() + "����" + ob->name() 
		+ "��ҡ���˼��¡�\n", this_player());
	add_amount(-1);
	return 1;
}



