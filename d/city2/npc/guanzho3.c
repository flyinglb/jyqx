// guanzho3.c
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("���ڱ�", ({"bing"}));
    set("gender", "Ů��");
    set("age", 18);
    set("long", "����һλС���\n");
    set("attitude", "peaceful");
	
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);

    set("qi", 200);
    set("max_qi", 200);
    set("jing", 100);
    set("max_jing", 100);
	
    set("combat_exp", 5000);
    set("score", 0);
	
    set_skill("force", 60);
    set_skill("unarmed", 60);
    set_skill("dodge", 60);
    set_skill("parry", 65);
	
	setup();
	carry_object("/d/city/obj/pink_cloth")->wear();
	carry_object("/d/city/obj/flower_shoe")->wear();
}

void init()
{

	object me, ob;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight"))
	{
		if( !ob->query_temp("warned") ) {
			command("say ��Ȼ���˸Ҳ����ҿ�Ϸ���������ˣ�");
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
			command("say ��ɱ���㣡����\n");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       

}
