//zhangwuji.c

#include <ansi.h>

inherit F_MASTER;
inherit F_UNIQUE;
inherit NPC;

void greeting(object ob);
void create()
{
    seteuid(getuid());
    set_name("���޼�", ({ "zhang wuji", "zhang", "wuji" }));
    set("long", "���̽������޼ɣ�ͳ������ʮ����ڣ��������ƣ�߳��ǧ�\n"
               +"�������񹦡�����Ǭ����Ų�ơ��������£��ǽ����в�������\n"
               +"����Ӣ�ۡ�\n");
    set("title",HIG "����"HIM"����"NOR);
    set("gender", "����");
    set("age", 20);
    set("shen_type",1);
    set("attitude", "friendly");
    set("class", "fighter");

    set("per", 28);
    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);

    set("qi", 3050);
    set("max_qi", 3050);
    set("jing", 3050);
    set("max_jing", 3050);
    set("neili", 5000);
    set("max_neili", 5000);
    set("jiali", 120);

    set("combat_exp", 2900000);
    set("score", 455000);
    
    set_skill("force", 250);
    set_skill("unarmed", 200);
    set_skill("dodge", 200);
    set_skill("parry", 220);
    set_skill("hand",200);
    set_skill("sword",250);
    set_skill("blade", 200);
    set_skill("jiuyang-shengong", 250);
    set_skill("qiankun-danuoyi", 250);
    set_skill("qishang-quan", 250);
//  set_skill("wuxue-xinfa", 485);
    set_skill("taiji-quan",200);
    set_skill("taiji-jian",200);
    set_skill("taiji-dao",200);
    set_skill("shenghuo-ling",200);

    map_skill("force", "jiuyang-shengong");
    map_skill("dodge", "qiankun-danuoyi");
    map_skill("unarmed", "qishang-quan");
    map_skill("hand", "taiji-quan");
    map_skill("sword","shenghuo-ling");
    map_skill("parry","shenghuo-ling");
    map_skill("blade","taiji-dao");

    create_family("����",34, "����");

    set("chat_chance",2);
    set("chat_msg",({
 "���޼ɷ�Ȼ˵�������ɷ��Թ�Ϊ��, ����ɳ��, ��Ԫ��ҵδ��, ͬ������Ŭ��!��\n",
        "���޼�̾��������ʧһ֪��, ����λ�, �������, ����, ��������?��\n",
        "���޼ɵ����ҽ��ֵ�����: ��������, ���˼�Ϊ��, ��������, ������ħ!��\n",
//        	(: random_move :)
    }));

    set("inquiry",([
	  "����" :     "�������ڱ�д֮�У�����Ժ�\n",
          "��ëʨ��" : "�������常л������ְ˾��\n",
          "лѷ" :     "���������常�Ĵ�š�\n",
          "�Ŵ�ɽ" :   "�������Ҹ���������? \n",
          "������" :   "����������������΢������\n",
          "������" :   "��̫ʦ�������ɺ�? \n",
          "����" :     "����ʧһ֪��, ����λ�, �������, ����, ��������?\n",
          "С��" :     "С���ҿ�һֱ�������ĺô���\n",
          "������" :   "������ȥ����ɽ, �������ҡ�\n",
    ]));
    setup();
    carry_object("/d/mingjiao/obj/yitianjian");
    carry_object("/clone/book/shenghuo-ling")->wield();
//    	carry_object("/d/mingjiao/obj/jiaozhumingpao")->wear();
    add_money("silver",70);
}

void init()
{
	object ob;

	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}       
	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return;
	if((int)ob->query("shen")<-50000)
	{
//      command("say
	command("wield yitian jian");
	command("hit"+(string)ob->query("id"));
        command("unwield yitian jian");
	}
	else if((int)ob->query("shen")<-5000)
	{
		command("say ħ����������ѧ������������Ȱ���������������سɷ�.");
	}
	else if((int)ob->query("shen")<-100)
	{
		command("say ��λ���ѣ����н��������е����������߽�аħ���.");
	}
	else if((int)ob->query("shen")>=0)
	{
		command("say �������������ߣ�Ȱ����ӱ���.");
	}
	else if((int)ob->query("shen")>10000)
	{
		command("say �������ϣ����޼�һ�񣬴������ձ�Ϊ�����̳�.");
	}
	return;
}

void attempt_apprentice(object ob)
{
	if((int)ob->query("int")<20)
	{
		command("say �������̫���ˣ����ʺ�ѧϰ�ҵĹ���");
		return 0;
	}
	if((string)ob->query("gender")=="����")
	{
		command("say ���������㣬ϰ�ҹ���ֽ��߻���ħ��");
		return 0;
	}
	if((int)ob->query("shen") <= 15000)
	{
		command("say ��Ӧ������Щ����������£��������ġ�");
		return 0;
	}
	command("say �ã��Ҿ���������λ��ͽ�ܣ�");
	command("say ���ְ˾���Ǳ��̵Ĺ���ʹ�ߡ�");
	command("recruit " + ob->query("id"));
	ob->set("title", HIR"����ʹ��"NOR);
	return;
}

int accept_fight(object ob)
{
    if(((int)ob->query("combat_exp")<30000)&&((int)ob->query("shen")>0))
    {
        message_vision("�������������ǿ���ݣ��㲻���ҵĶ��֣���ȥ�ɡ�\n",ob);
        return 0;
    }
    message_vision("���޼�һ����˵������λ"+RANK_D->query_respect(ob)+
	"����������ˡ�\n", ob);
    return 1;
}

