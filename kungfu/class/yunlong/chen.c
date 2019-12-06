// chen.c �½���

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_weiwang();
int ask_tuihui();
string ask_me();

void create()
{
	set_name("�½���", ({ "chen jinnan", "chen","jinnan" }));
	set("title", HIR "��ػ�"HIM"�ܶ���"NOR );
	set("nickname", HIC "Ӣ���޵�" NOR);
	set("long", 
		"\n����һ����ʿ����������������ɫ�Ͱ���\n"
		"������������������ػ��ܶ����½��ϣ�\n"
		"��˵ʮ�˰����գ�������ͨ��\n"
		"ż������߿��������پ���Ŀ����磬Ӣ�����ˡ�\n");
	set("gender", "����");
	set("class", "scholar");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("whip", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);
	set_skill("houquan", 150);
	set_skill("yunlong-xinfa", 200);
	set_skill("yunlong-shengong", 200);
	set_skill("wuhu-duanmendao", 150);
	set_skill("yunlong-jian", 200);
	set_skill("yunlong-shenfa", 150);
	set_skill("yunlong-bian", 150);
	set_skill("yunlong-shou", 150);
	set_skill("yunlong-zhua", 150);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
	create_family("������",1, "��ɽ��ʦ");
	set("book_count", 1);
        set("inquiry", ([
		"��ػ�" :  "\nֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
		"���" :  "\nֻҪ������ػᣬ�������λ����ѧ���ա�\n",
                "���帴��" : "ȥ�ײĵ�ͻش�����ϸ���ưɣ�\n",
                "����" : "�����£�\n",
                "�п�" : "�����£�\n",
                "����" :  (: ask_weiwang :),
                "��������" : (: ask_weiwang :),
		"��������" : (: ask_me :),
		"�˻�" : (: ask_tuihui :),
		"tuihui"   : (: ask_tuihui :),
	]) );
	set("env/wimpy", 60);
	set("chat_chance_combat", 70);  
	set("chat_msg_combat", ({
		"\n�½���ҡͷ̾�����۵��������������������������Ǻο���?\n",
		(: command("smile") :),
		(: command("poem") :),
		(: command("nomatch") :),
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
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "blade.duan" :),
                (: perform_action, "blade.duan" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
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
	carry_object("/d/city2/obj/jinduan")->wear();
	carry_object("/d/city2/obj/yaodai")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city2/obj/hlbian");
	carry_object("/d/city/obj/gangdao");
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
        ob = new("/clone/book/yljianpu");
        ob->move(this_player());
        return "�ðɣ��Ȿ���������ס����û�ȥ�ú����С�";
}

void init()
{
	::init();
	add_action("do_skills","skills");
	add_action("do_skills","cha");
	add_action("do_join","join");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("yunlong-shengong", 1) < 50)
	{
		command("say �����������ڼ��书���������ڹ��ķ���"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ�����������϶��µ㹦��");
		return;
	}
	if ((int)ob->query("weiwang") <60)
	{
		command("say ���������书�����޵У��������ţ�\n�ش����������������壬Ϊ���²���ı������\n"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ���ȳ�ȥ��һ�������������춯�صĴ��£�");
		return ;
	}
	if ((int)ob->query("shen") >0&&(int)ob->query("shen") < 5000) {
		command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return ;
	}
	if(ob->query("weiwang")<80)
	{
		if((int)ob->query("shen")<0)
 command("say "+ RANK_D->query_respect(ob) +"��Ȼ��а�����ˣ���Ҳ������Щ���¡�\n");
		command("chat ����ػ�������Ϊ����һ����ǰ����δ��֮�¡�\n");
		command("chat ���¿������ң��������ţ������Ȼ���ֺ����ۣ�\n");
		command("chat �����������ɣ���\n");
		command("chat �벻����һ������ҵ�������������˴��ˣ�����������������\n");
		message_vision(HIC "$N�Ľ�����������ˣ�\n" NOR,this_player());
		ob->set("weiwang",80);
	}
	command("recruit " + ob->query("id"));
	if((!(string)ob->query("class")) || ((string)ob->query("class") != "fighter"))
		ob->set("class","fighter");
}

int do_skills(string arg)
{
	object ob ;
	ob = this_player () ;
	if( !arg || arg!="chen" )
		return 0;
	if(wizardp(ob))  return 0;
	if (ob->query("party/party_name") != HIR "��ػ�" NOR )
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
		command("tell "+ob->query("id")+" ������ػ���Ӳ��ܲ쿴��\n"); 
		return 1;
	}

	command("tell "+ob->query("id")+" �����еĻ����书���£�\n"+
	"  �������� (blade)                         - ��ɲ� 200/   \n"+
	"  ����צ�� (claw)                          - ��ɲ� 200/   \n"+
	"  �����Ṧ (dodge)                         - ��ɲ� 200/    \n"+
	"  �����ڹ� (force)                         - ��ɲ� 200/    \n"+
	"  �����ַ� (hand)                          - ��ɲ� 200/    \n"+
	"  ����ȭ�� (unarmed)                       - ��ɲ� 200/    \n"+
	"  �����޷� (whip)                          - ��ɲ� 200/    \n"+
	"  �����м� (parry)                         - ��ɲ� 200/    \n"+
	"  �������� (sword)                         - ��ɲ� 200/    \n"+
	"  �����ķ� (yunlong-xinfa)                 - ��ɲ� 200/    \n"+
	"  ����д�� (literate)                      - ��ɲ� 100/    \n");
	command("tell "+ob->query("id")+" �����еĸ����书���£�\n"+
	"����ȭ (houquan)                           - ��ɲ� 150/    \n"+
	"���廢���ŵ� (wuhu-duanmendao)             - ��ɲ� 150/    \n"+
	"�������� (yunlong-shengong)              - ��ɲ� 150/    \n"+
	"�������� (yunlong-shenfa)                - ��ɲ� 150/    \n"+
	"���������� (yunlong-jian)                  - ��ɲ� 200/    \n"+
	"�������� (yunlong-bian)                    - ��ɲ� 150/    \n"+
	"�������� (yunlong-shou)                    - ��ɲ� 150/    \n"+
	"������צ (yunlong-zhua)                    - ��ɲ� 150/    \n");
	return 1;
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
	say("\n�½���˵�������������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
	+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
	say("�½�����˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
	return 1;
}
int ask_tuihui()
{
	object ob;
	ob=this_player();

	if(ob->query("party/party_name") != HIR "��ػ�" NOR )
	{
message_vision("�½���Ц��Ц����$N˵�����㻹û��������ػ��أ���ʲô�ˣ�\n", ob);
		return 1;
	}
	if(ob->query("family/family_name") == "������" )
	{
message_vision("�½��ϰ�������$N˵�������Ѿ����������ŵ��ӣ�������˻᣿\n", ob);
		return 1;
	}
	command("look "+ob->query("id"));
	command("sigh ");
	command("say ���帴������Ҫ����־ʿ����ȥ��! ");
	ob->delete("party");
	ob->delete("rank");
	ob->delete("level");
	return 1;
}                                           

#include "/kungfu/class/yunlong/tiandihui.h";
