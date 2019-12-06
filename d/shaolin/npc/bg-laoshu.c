// laoshu.c ����

inherit NPC;

void create()
{
	set_name("����", ({ "lao shu", "shu", "mouse" }) );
	set("race", "Ұ��");
	set("age", 2);
	set("long", "һֻ�������С����\n");
	set("attitude", "peaceful");
	
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 100);
	set("shen_type", -1);
	set("env/wimpy", 70);

	set("chat_chance", 15);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
	}) );
	
	set_temp("apply/attack", 5);
//	set_temp("apply/damage", 20);
	set_temp("apply/dodge", 20);
	set_temp("apply/armor", 1);

	setup();
}

int random_move()
{
        mapping exits;
        string *dirs;
	int i;

        if( !mapp(exits = environment()->query("exits")) ) return 0;
        dirs = keys(exits);
	i = random(sizeof(dirs));
        //command("say " + "I am going to " + dirs[i] + ".");
	if(exits[dirs[i]][11..15] == "bagua")
        	command("go " + dirs[i]);
}


void die()
{
        object ob;
        message_vision("$N��ҵĺ��˼��������ˡ�\n", this_object());
        ob = new(__DIR__"shurou");
        ob->move(environment(this_object()));
        destruct(this_object());
}

