//jinshe.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIW "��ɫѪ��" NOR, ({ "yinshe" }) );
	set("race", "Ұ��");
	set("age", 1);
	set("long", "һ��ϸС�����˿�����ë���Ȼ����ɫѪ�ߡ�\n");
	set("attitude", "peaceful");
	set("str", 20);
	set("cor", 20);
	set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 1500+random(200));

	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 18);
	set_temp("apply/defence",15);
	setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(this_player()))
	{
		if (!(ob = present("linzhilan", this_player())))          
		{
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, this_player());
		}
	}
}


int hit_ob(object me, object ob, int damage)
{
    if ((int)ob->query("combat_exp") > 10000) return 1 ;
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("snake_poison") < 10 ) {
		ob->apply_condition("snake_poison", 20);
        tell_object(ob, HIG "����ñ�ҧ�еĵط�һ����ľ��\n" NOR );
	}
}
