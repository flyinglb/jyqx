// ma.c ����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
//inherit F_UNIQUE;
//int do_join(string arg);
int ask_weiwang();
string ask_me();

void create()
{
	set_name("����", ({ "ma chaoxing", "ma"}));
	set("title", HIR "��ػ�"HIW"�Һ�������"NOR);
	set("gender", "����");
	set("long", "\n��������ػ�Һ����������������ֵĸ�����ʹһ���󵶡�\n");
	set("class", "fighter");
	set("age", 45);

	set("int", 30);
	set("qi", 1500);
	set("max_qi", 1500);
	set("jing", 500);
	set("max_jing", 500);
	set("shen_type", 1);

	set("combat_exp", 250000);
	set("attitude", "friendly");

	set_skill("force", 80);
	set_skill("unarmed",80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("sword", 70);
	set_skill("blade", 100);
	set_skill("whip", 70);
	set_skill("yunlong-shengong", 70);
	set_skill("yunlong-shenfa", 70);
	set_skill("wuhu-duanmendao", 80);
	set_skill("houquan", 50);
	set_skill("yunlong-jian", 50);
	set_skill("yunlong-bian", 50);
	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);
	set_temp("apply/damage", 25);

	map_skill("force", "yunlong-shengong");
	map_skill("dodge", "yunlong-shenfa");
	map_skill("parry", "wuhu-duanmendao");
        map_skill("blade","wuhu-duanmendao");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");
        map_skill("unarmed","houquan");

	create_family("������",2, "����");
      set("class", "yunlong-xinfa");
	set("book_count", 1);
        set("inquiry", ([
		"�½���" :  "\n��������ֵ�ﵽ70�Ϳ��԰��ܶ���Ϊʦ��\n",
		"��ػ�" :  "\nֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
		"���" :  "\nֻҪ��������ػᣬ��������и�λ����ѧ�书��\n",
                "���帴��" : "ȥҩ�̺͹ײĵ���ϸ���ưɣ�\n",
                "����" :  (: ask_weiwang :),
                "��������" : (: ask_weiwang :),
		"������" : (: ask_me :),
	]) );
	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
		(: command("smile") :),
		(: command("haha") :),
		(: command("chat ��λ" + RANK_D->query_respect(this_player())+",������ԩ�޳𣬺α����?\n") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "blade.duan" :),
                (: perform_action, "blade.duan" :),
                (: perform_action, "blade.duan" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "unarmed.zhen" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("wield blade") :),
		(: command("wield blade") :),
		(: command("wield blade") :),
		(: command("wield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
                      }) );
	setup();
	carry_object("/d/shaolin/obj/changbian")->wield();
	carry_object("/clone/weapon/changjian");
	carry_object("/d/city2/obj/dadao");
	carry_object("/clone/misc/cloth")->wear();
        add_money("silver",20);
}

void init()
{
	::init();
	remove_call_out("greeting");
	call_out("greeting", 1, this_player());
	add_action("do_join","join");
	add_action("do_skills","skill");
	add_action("do_skills","cha");
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
	say("\n����˵�������������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
	+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
	say("������˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
	return 1;
}

string ask_me()
{
        mapping fam; 
        object ob;

        if (!(fam = this_player()->query("family")) 
	    || fam["family_name"] != "������")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count") < 1)
                return "�������ˣ����ɵ������澭���ڴ˴���";
        add("book_count", -1);
        ob = new("clone/book/yljing1");
        ob->move(this_player());
        return "�ðɣ��Ȿ�������������û�ȥ�ú����С�";
}

void attempt_apprentice(object ob)
{
/*
	if((string)ob->query("gender")=="Ů��")
	{
		command("say Ů�˵����������ߣ��������Ŷ������أ����������أ���");
		return;
	}
*/
	if((string)ob->query("gender")=="����")
	{
		command("say �����Ŷ������أ��������������ķ��ˣ���");
		return;
	}
	if (ob->query("party/party_name") != HIR "��ػ�" NOR )
	{
		command("say �㲻�Ǳ�����֣��Ҳ������㣡");
		return;
	}
	if ((int)ob->query_skill("shenlong-xinfa",1) < 60 )
	{
		command("say ��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!");
		command("say �ðɣ���Ȼ" + RANK_D->query_respect(ob) + "Ҳ��" +
		"�ұ����ˣ������������ɡ�");
		command("recruit " + ob->query("id"));
		if((!(string)ob->query("class")) || ((string)ob->query("class") != "fighter"))
		ob->set("class","fighter");
	}
}
void greeting(object ob)
{
      if(random(5)>2) say( "����Ц������λ" + RANK_D->query_respect(ob)+ "������ʲô��ƽ֮��ô��\n");
}

int do_skills(string arg)
{
	object ob ;
	ob = this_player () ;
	if( !arg || arg!="ma" )
		return 0;
	if(wizardp(ob))  return 0;
	if (ob->query("party/party_name") != HIR "��ػ�" NOR )
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
		command("tell "+ob->query("id")+" ������ػ���Ӳ��ܲ쿴��\n"); 
		return 1;
	}
	command("tell "+ob->query("id")+" �����еĻ����书���£�\n"+
	"  �������� (blade)                         - ��ɲ� 100/    \n"+
	"  �����Ṧ (dodge)                         - �Ƿ��켫  80/    \n"+
	"  �����ڹ� (force)                         - �Ƿ��켫  80/    \n"+
	"  �����м� (parry)                         - �Ƿ��켫  80/    \n"+
	"  �������� (sword)                         - �����뻯  70/    \n"+
	"  ����ȭ�� (unarmed)                       - �Ƿ��켫  80/    \n"+
	"  �����޷� (whip)                          - �����뻯  70/    \n"+
	"���廢���ŵ� (wuhu-duanmendao)             - �Ƿ��켫  80/    \n"+
	"����ȭ (houquan)                           - �������  50/    \n"+
	"�������� (yunlong-bian)                    - �������  50/    \n"+
	"���������� (yunlong-jian)                  - �������  50/    \n"+
	"�������� (yunlong-shenfa)                - �����뻯  70/    \n"+
	"�������� (yunlong-shengong)              - �����뻯  70/    \n");
	 return 1;
}
#include "/kungfu/class/yunlong/tiandihui.h";
