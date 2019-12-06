// mianju.c
// modified by cleansword 1996/2/3

inherit ITEM;

void create()
{
        set_name("���", ({ "mian ju", "mask" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "���ƺ���һ������Ƥ�Ƴɵ���ߡ�\n");
		set("no_drop", "�������������뿪�㡣\n");
		set("no_get", "�������������뿪�Ƕ���\n");
        }
        setup();
}

void init()
{
	add_action("do_pretend", "pretend");
}

int do_pretend(string arg)
{
	object who;
	if (!arg)
		return notify_fail("�����װ˭��\n");
	if (arg == "none" || arg == "cancel") {
		this_player()->delete_temp("apply/name");
//		this_player()->delete_temp("apply/id");
		this_player()->delete_temp("apply/short");
		this_player()->delete_temp("apply/long");
		message_vision("$N������ȡ����һ����Ƥ��ߡ�\n", this_player());
		return 1;
	}
	if(!objectp(who = present(arg, environment(this_player()))) || 
		!living(who))
		return notify_fail("�����װ˭��\n");
	write("�㿪ʹ��װ" + who->name() + "��\n");
//	message_vision("$N������һ�������Ƴɵ���Ƥ��ߡ�\n", this_player());
	this_player()->set_temp("apply/name", ({who->name()}));
//	this_player()->set_temp("apply/id", ({who->id()}));
	this_player()->set_temp("apply/short", ({who->short()}));
	this_player()->set_temp("apply/long", ({who->long()}));
	return 1;
}
