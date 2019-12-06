// kang.c ������

#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
int ask_meili();

void create()
{
	set_name("������", ({ "kang qinwang", "kang"}));
	set("gender", "����");
	set("age", 42);
	set("str", 25);
	set("dex", 20);
	set("long", "\nֻ����һ����£�Ц�����棬��˭��������������������\n"+
		"��������Ϊ��֮�������Ʋ��Թ�ɫ�����������ĵûʵۻ��ġ�\n");
	set("combat_exp", 50000);
	set("score", 5000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 10);
	set_temp("apply/damage", 25);
	set("qi", 500);
	set("max_qi", 500);
	set("jing", 300);
	set("max_jing", 300);
	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 50);
        set("inquiry", ([
		"����" :  "\n�������˺��аԵ�����������������\n",
		"������" :  "\n����Ҫ�Ҿ�������ɣ��������ɲ�һ������㡣\n",
                "����" :  (: ask_meili :),
                "����" : (: ask_meili :),
       ]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 5);
}

int ask_meili()
{
command("tell "+this_player()->query("id")+" �����ڵ�����ֵ�� " +(string)(this_player()->query("meili")));
say("\n������Ц����Ҫ�뵱���������߿ɲ��а���\n");
say("��������˵���������Թ��ǽ�����������Ȼ����ߵġ�\n");
return 1;
}

void init()
{
object ob;
ob=this_player();
::init();
remove_call_out("greeting");
call_out("greeting", 1, ob);
}

void greeting(object ob)
{
        object man;
	if( !ob || environment(ob) != environment() ) return;
	if (file_name(environment(ob)) != "/d/city2/shufang") return;
        if((int)ob->query("meili")<20)
	{
        if(userp(ob))
        message_vision("\n������һ��$N, ��ʱ��Ȼ��ŭ���е��������˰��������˸������£���\n",ob);
        if(!present("shi", environment(ob)))
	 {
         message_vision("��ʱ�����������������ӵ���$Nֱ�˹�����\n",ob);
	 man=new("/d/huanggon/npc/shiwei2");
	 man->move(environment(ob));
	 man=new("/d/huanggon/npc/shiwei2");
	 man->move(environment(ob));
	 man=new("/d/huanggon/npc/shiwei2");
	 man->move(environment(ob));
	 }
        return ;
	}
	switch( random(5) ) {
		case 0:
        message_vision("\n$N��һ����, ������������ӭ�˳�����Ц��������λ" + RANK_D->query_respect(ob)+
	"����������\n",ob);
	if(ob->query("meili")<60)
    	{
    	ob->add("meili",10);
        message_vision(HIC "$N������ֵ����ˣ�\n" NOR,ob);
        command("tell "+ob->query("id")+" �����ڵ�����ֵ�� " +(string)(ob->query("meili")));
	}
	break;
	default:
	say( "������Ц������֪��λ" + RANK_D->query_respect(ob)
		+ "�����ٺ����кι�ɣ�\n");
	break;
	}
}
