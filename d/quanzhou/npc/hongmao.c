// hongmao.c

inherit NPC;

void create()
{
	set_name("��ë��", ({ "hongmao gui", "gui"}));
	set("gender", "����");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "�������쳯����̨��ĺ�����ë�������϶���һ֧��ǹ��ǹ�ڻ�ð�����̡�\n");
	set("combat_exp", 25000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 30);

	setup();
//      carry_object(__DIR__"obj/huoqiang")->wield();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
        if( !environment() ) return;
        if( environment()->query("sleep_room")
        || environment()->query("no_fight") ) {
        message_vision("$N����ææ���뿪�ˡ�",this_object());
        destruct(this_object());
        return;
        }
	if( environment(ob) != environment() ) return;
	say("��ë��̧�־���һǹ���飡ǹ��һ�Ż��������\n");
	ob->receive_damage("qi",50);
	ob->receive_wound("qi",50);
}

