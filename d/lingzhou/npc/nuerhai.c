// nuerhai.c

inherit NPC;
#include <ansi.h>;
void create()
{
	set_name("Ŭ����", ({ "nu erhai", "nu" }));
	set("title", HIM"����һƷ��"HIG"����ʹ"NOR);
	set("gender", "����");
	set("age", random(10) + 20);
	set("str", 25);
	set("dex", 16);
	set("per", 13);
	set("long", "һ�����μ��ߡ����Ӽ����������������ĺ��ӡ�\n");

	set("combat_exp", 100000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 50);

	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 100);

	setup();
	carry_object("/d/city/npc/obj/tiejia")->wear();
}

void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;
	::init();
	add_action("do_join","join");
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

string ask_me()
{
	return "�������º��ܡ����������һƷ��(join yipintang)��";
}

int do_join(string arg)
{
	object ob;
//        mapping party;

	ob = this_player () ;
	if( !arg || arg!="yipintang" )
		return notify_fail("Ŭ�����ʵ�������Ҫ����ʲô��֯����\n"); 
   	if( (int)ob->query("yipin/joined") )
		return notify_fail("Ŭ������ֵ�˵�������㿪ʲô��Ц�����Ѿ����������ˡ���\n"); 
   	if( (int)ob->query("combat_exp") < 1000 )
		return notify_fail("Ŭ��������һ����Ц������������ֻҪ�����еĳ���Ӣ�ۡ�����ʲô���ϣ���\n"); 
	command("gongxi "+ob->query("id"));
	message_vision("Ŭ��������$NЦ�������Ǻã��������ھ���һ��֮����һ�����ˣ���\n",ob);
	ob->set("yipin/joined",1);
	return 1;
}
