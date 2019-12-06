inherit NPC;
int ask_zhi();
void create()
{
	set_name("猎户", ({ "liehu" }));
	set("gender", "男性");
	set("age", 35);
	
	set("qi", 200);
	set("max_qi", 200);
	set("jing", 200);
	set("max_jing", 200);

	set("combat_exp", 5000);
	set("attitude", "heroism");

	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 10);
        set("inquiry", ([
                "灵芝" : (: ask_zhi :),
        ]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
int ask_zhi()
{
	object ob;
	ob = this_player ( ) ;
message_vision("猎户打量了$N一下：灵芝？白象山上就有，我不是采药的，你自己去找就是。\n",ob);
	ob->set_temp ("灵芝" , 1 );
	return 1;
}
