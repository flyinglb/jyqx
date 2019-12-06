// lu.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);
string ask_me();

void create()
{
	set_name("½����", ({ "lu gaoxuan", "lu" ,"gaoxuan"}));
	set("title", HIY"������"NOR"��ʦ");
	set("nickname",HIC "�������" NOR);
	set("long", "����ͥ����,������Բ,��ò��ΪӢ��.\nȻ���������,ǡ����̼����ɱ��֮��һ��.\n" );
	set("gender", "����");
	set("age", 37);
	set("str", 35);
	set("dex", 20);
	set("max_qi",1500);
        set("qi",1500);
	set("max_jing",500);
        set("jing",500);
	set("combat_exp", 300000);
	set("score", 40000);
	set("shen_type", -1);
	set("attitude", "peaceful");

        set_skill("force", 70);
	set_skill("shenlong-xinfa", 70);
        set_skill("dodge", 70);
	set_skill("yixingbu", 70);
        set_skill("hand", 70);
	set_skill("shenlong-bashi", 70);
        set_skill("parry", 70);
        set_skill("staff", 70);
	set_skill("shedao-qigong", 70);
	set_skill("literate", 70);

	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "shenlong-bashi");
	map_skill("parry", "shedao-qigong");
        map_skill("staff", "shedao-qigong");
	prepare_skill("hand", "shenlong-bashi");

	create_family("������",2,"����");

	set_temp("apply/damage", 60);
	set("book_count", 1);
	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 100);
        set("inquiry", ([
		"������" :  "һ�������벻���������̵�(join shenlongjiao).\n",
		"���" :  "һ�������벻���������̵�(join shenlongjiao).\n",
		"�鰲ͨ" :  "����Ƣ������,Ҫ�������Ĳźá�\n",
		"����" :  "����Ƣ������,Ҫ�������Ĳźá�\n",
		"�ں�" : "���겻��!�����ɸ�!��������!������ʥ!\n",
		"�ؼ�" : (: ask_me :),
	]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 10);
}

void init()
{
	add_action("do_join","join");
}

void attempt_apprentice(object ob)
{
	if (ob->query("party/party_name") != HIY "������" NOR ) {
		command("say �㲻�Ǳ��̽���, ����������!");
		return;
	}
	if ((int)ob->query_skill("literate",1) < 40 ) {
		command("say ���ѧ��̫����,����ŬŬ�������һ�°�!");
		return;
	}
	if ((int)ob->query("shen") > -0  ) {
		command("say �������������������������������ְ׵�����򽻵�������ذɣ�");
		return;
	}
	command("say �ܺã��ܺá�");
	command("recruit " + ob->query("id"));
}
string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (query("book_count") < 1)
		return "�������ˣ����̵��ؼ����ڴ˴���";
	add("book_count", -1);
	if (random(2) == 0) ob = new("/clone/book/shoufa");
	else ob = new("/clone/book/bufa");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ�"+ob->query("name")+"����\n");
	return "�ðɣ��Ȿ��"+ob->query("name")+"�����û�ȥ�ú����С�";
}
#include "/kungfu/class/shenlong/shenlong.h"; 
