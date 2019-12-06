// yu-zu.c

inherit NPC;

void close_door(object room);

void create()
{
	set_name("����", ({ "yu zu", "zu" }) );
	set("long",
		"����һ������ʮ���׶�����䣬�������⣬��������Ź�ɱ����\n");
	set("attitude", "peaceful");
	set("chat_chance", 1);
	set("chat_msg", ({
		"����ٺٺٵ���Ц������������������ע��������ʱ��Ťͷ��ݺݵ�����һ�ۡ�\n",
		"�����ͳ�һ��ѩ����ذ�ף������������Լ��ֺ��ֳ�����ָ�ף��������ʲ�ᡣ\n"
	}) );
	set("age", 50);
	set("combat_exp", 20000);
	set("max_jing", 500);
	set("max_qi", 500);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 20);
	setup();
}

int accept_object(object who, object ob)
{
	object room;

	if (ob->query("money_id") && ob->value() >= 1000) 
	{
		tell_object(who, "����˵������ˮ����������࣬����ȥ��ֻ���ɱ�˻����˺ǣ�\n\n");
		message_vision("��������������һ�£�͵͵��$N��ͨ���ϱߵ�С�š�\n", who);

		if(!( room = find_object("d/shaolin/jianyu1")) )
			room = load_object("d/shaolin/jianyu1");

		room->set("exits/south", "d/shaolin/andao1");

		remove_call_out("close_door");
		call_out("close_door", 10, room);
		
		return 1;
	}

	return 0;
}

void close_door(object room)
{
	message("vision","����ɿ��վ������ǰһ�°�С�Ź���������\n", room);
	room->delete("exits/south");
}	

