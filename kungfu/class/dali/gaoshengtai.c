// gaoshengtai.c ����̩

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void upgrade_title(object me,string arg);
string clear_title(string arg);
int ask_me();
void create()
{
	set_name("����̩", ({ "gao shengtai", "gao" }));
	set("title",  "�����Ʋ���" );
	set("long", "�������ү������λ���۴�����������ӣ����Ƴ��ף���ò���š�\n");
	set("gender", "����");
	set("age", 33);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 25);
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 25);
	
	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 80);
	set("combat_exp", 800000);
	set("score", 150000);

	set_skill("force", 110);
	set_skill("dodge", 110);
	set_skill("parry", 100);
	set_skill("cuff", 110);
	set_skill("strike", 110);
	set_skill("sword", 120);
	set_skill("staff", 120);
	set_skill("kurong-changong", 110);
	set_skill("tiannan-step", 120);
	set_skill("jinyu-quan", 110);
	set_skill("wuluo-zhang", 110);
	set_skill("duanjia-sword", 110);
	set_skill("literate", 60);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");

	set("inquiry", ([
		"ָ���书" : (: ask_me :),
	]));
	setup();
	carry_object(__DIR__"obj/magcloth")->wear();
	carry_object(__DIR__"obj/tiedi")->wield();
	add_money("silver", 20);

	create_family("����μ�",19,"�佫");
}

void attempt_apprentice(object ob)
{
        string sta = ob->query("dali_family_status") ;
	if( !stringp(sta) ) {
	        command("say ���Ǻ��ˣ���˴󵨣���ð�Ҹ������ͣ�");
	        return ;
	}
	if ((int)ob->query_skill("kurong-changong",1) < 30 )
	{
		command("say ��ı����ڹ��ķ�̫���ˣ�����ŬŬ�������һ�°ɡ�");
		return;
	}
	if ((int)ob->query("shen") < 10000  )
	{
		command("say �Ҵ�����������������壬����ذɣ�");
		return;
	}
	command("say �ܺã���Ȼ���������͵�����Ϊū������ʹ��");
	command("recruit " + ob->query("id"));
}
 
int ask_me()
{
        string sta;
	object ob = this_player();

	if( !stringp(sta =ob->query("dali_family_status")) ) {
	        command("say ����ȥͶ�����Ҵ���ɡ�\n");
	        return 1;
	}
	if( sta != ("��ʿ") ) {
		command("say ֻ����ʿ�������佫��\n");
		return 1;
	}
	if ((int)ob->query_skill("kurong-changong",1) < 80)
	{
		command("say ����书�����ǲ���ʤ���佫��нٺ���������깦��ɡ�\n");
		return 1;
	}
	ob->set_temp("fight_ok",1);
	command("say �ã���Ȼ������д裬�ǾͿ���ı�������ˡ�\n");
	return 1;
}

int accept_fight(object ob)
{
        object me  = this_object();
        if ( !ob->query_temp("fight_ok") ) return 0;

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        ob->delete_temp("fight_ok");
        return 1;
}

int checking(object me, object ob)
{
	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting()) 
	{
		call_out("checking",2, me, ob);
		return 1;
	}

	if ( !present(ob, environment()) ) return 1; 

	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
	{
		command("say ������ʤ����������Ǵ���μҵĺõ��� ! ��ϲ���� !\n");
		command("say ����Ѿ�����ʤ�δ����佫 !\n");
		set("dali_family_status","�佫");
		return 1;
	}
	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
	{
		command("say ����" + RANK_D->query_respect(ob) + 
			"���ö����ϰ�������ڴ���μ��������г���ͷ�� !\n");
		return 1;
	}
	return 1;  
}
