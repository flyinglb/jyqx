// yu-zu.c

#include <ansi.h>

inherit NPC;

string *death_msg = ({
	HIB "����˵����ι�������ģ����ʲô���֣�\n\n" NOR,
	HIB "������������۹ⶢ���㣬����Ҫ�������һ���Ƶġ�\n\n" NOR,
	HIB "���䡸�ߡ���һ�����������ͳ�һ�����ʲ�Ķ�����������\n\n" NOR,
	HIB "������ϲ��ӣ�˵�����㣡�������ᣬ�������˰���\n\n" NOR,
	HIB "����˵�����㻹�������ʲô����������ҹ������֣�\n\n"
		"һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n" NOR,
});

void create()
{
	set_name("����", ({ "yu zu", "zu" }) );
	set("long",
		"����������������ͷ�����㣬��ڵ����Ͽ������κ�ϲŭ���֡�\n");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	set("chat_msg", ({
//		(: random_move :),
		"���䷢��һ����������������������������ע��������ʱ�򣬵�����һ�ۡ�\n",
		"����ѳ�������ͷ��������������������Լ��ֺ��ֳ�����ָ��\n"
	}) );
	set("age", 50);
	set("combat_exp", 20000);
	set("max_jing", 900);
	set("max_qi", 900);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_temp("apply/armor", 60);
	set_temp("apply/damage", 20);
	setup();
}

void init()
{
	::init();
	if( !previous_object()
	||	!userp(previous_object()) )
		return;
	call_out( "death_stage", 10, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
	if( !ob || !present(ob) ) return;

//	if( !ob->is_ghost() ) {
//		command("say ι��������������ʲô��");
//		kill_ob(ob);
//		ob->fight_ob(this_object());
//		return;
//	}

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 60, ob, stage );
		return;
	}
//	else
//		ob->reincarnate();

	ob->move("/d/shaolin/woshi1");
	message("vision",
		"���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
		"�ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);
}
