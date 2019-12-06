// guidao.c
// by cleansword
// 96-02-16 YZC disabled NPC killing, & "unknown" problem when revealed

#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("����", ({ "wang wu", "wang" }) );
	set("title", "�ƿ�");
	set("gender", "����" );
	set("shen_type", -1);
	set("age", 40);
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);
	set("long",
		"���Ǹ��ȵ��������ľƹ����������еľƱ��૵���߶��ʲ�ᡣ\n" );

	set("combat_exp", 20000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"����˵��: �㵱����˱��ӵ��� ? �Ҹ���ү���� ! \n",
		"�����Ȼ�ӳ�һ�����������棬��������;ȴ�ּ�æ���С�\n",
		"����˵��: ��� ! �������˻����� ?....\n"
	}) );

	set("inquiry", ([
		"������" : "������! ��Ȥ��Ȥ����ϧ���ϴ����ˡ�" ,
		"��"   : (: ask_me :),
	]) );

	set_skill("blade", 50);
	set_skill("dodge", 40);
	set_skill("unarmed", 30);
	set_skill("parry", 50);
	
	setup();
	
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}

string ask_me(object who)
{
	int i;
	object *ob;

	if( query("revealed") ) {
                if( is_killing(who->query("id")) ) return "���Ȼ֪�����ҵ���֣��������������\n";
		else {
			kill_ob(who);
			who->fight_ob(this_object());
			return "���Ӿ��ǹ����壬��������������ӣ��������ɣ�\n";
		}
	}

	if( (random(10) < 5) || is_fighting() )
		return "�ҡ���֪����\n";

	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage",  20);

//	set("title", "�̿�");
//	set("nickname", HIR "��" NOR);
	set("title", HIR "��" NOR);

	message("vision",
		HIY "��������ͻȻ�ų������Ĺ�â������˵��������...�㶼֪���ˣ�\n"
		"������һ�����е�����Ȼ��ˣ����ӽ��췴�����ȥ������ƴ�ˡ�\n" 
		"����ʹ���������������棬���ͺ������͸ղŵ�����ֱ�������ˡ�\n" NOR,
		environment(), this_object() );

	set("pursuer", 1);
	set("attitude", "aggressive");
	set("vendetta/authority", 1);
	set("chat_msg_combat", ({
		(: random_move :)
	}) );
	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :)
	}) );
	set("bellicosity", 10000);
	set("combat_exp", 80000);
	set_skill("blade", 80);
	set_skill("dodge", 70);
	set_skill("unarmed", 60);
	set_skill("parry", 80);
	ob = all_inventory(environment());
	for(i=sizeof(ob)-1; i>=0; i--) {
		if( !userp(ob[i]) ) continue;
		kill_ob(ob[i]);
		ob[i]->fight(this_object());
	}
//	carry_object("/d/city/obj/mianju.c");
	add_money("silver", 5);
	set("revealed", 1);
	return "���Ӿ��ǹ����壬��������������ӣ��������ɣ�\n";
}
