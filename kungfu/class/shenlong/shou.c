// shou.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);

void create()
{
	set_name("��ͷ��", ({ "shou toutuo", "shou" ,"toutuo"}));
	set("title", HIY"������"NOR"�һ���");
	set("nickname",HIR "�ɶ�������" NOR);
	set("long", "��ͷ������氫, �����ֵó���, �����˾ͻ�������һ���󶬹�.\n��������Դ��ϵ���һ��ͭ�����, ���ӷǳ�����.\n" );
	set("gender", "����");
	set("age", 44);
	set("str", 35);
	set("dex", 20);
	set("max_qi",2000);
        set("qi",2000);
	set("max_jing",1000);
        set("jing",1000);
	set("combat_exp", 400000);
	set("score", 30000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("force", 70);
	set_skill("hand", 80);
	set_skill("strike", 80);
	set_skill("staff", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("yixingbu", 80);
	set_skill("shenlong-bashi", 60);
	set_skill("huagu-mianzhang", 60);
	set_skill("shenlong-xinfa", 70);
	set_skill("shedao-qigong", 60);

	map_skill("force", "shenlong-xinfa");
	map_skill("staff", "shedao-qigong");
	map_skill("hand", "shenlong-bashi");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "shenlong-bashi");
	map_skill("dodge", "yixingbu");
	prepare_skill("hand", "shenlong-bashi");
	prepare_skill("strike", "huagu-mianzhang");

	create_family("������",2,"����");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 50);
	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 100);
        set("inquiry", ([
		"������" :  "һ�������벻���������̵�(join shenlongjiao).\n",
		"���" :  "һ�������벻���������̵�(join shenlongjiao).\n",
		"�鰲ͨ" :  "����Ƣ������,Ҫ�������Ĳźá�\n",
		"����" :  "����Ƣ������,Ҫ�������Ĳźá�\n",
		"�ں�" : "���겻��!�����ɸ�!��������!������ʥ!\n",
	]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 30);
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
	if ((int)ob->query("shen") > 0  ) {
		command("say �������������������������������ְ׵�����򽻵�������ذɣ�");
		return;
	}
	command("say �ܺã��ܺá�");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/shenlong/shenlong.h"; 
