// lilishi.c ������

#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int ask_weiwang();
int ask_zhu();
int do_skills(string arg);

void create()
{
	set_name("������", ({ "li lishi", "li" }));
	set("title", HIR "��ػ�"HIG"��ľ��"NOR"����");
	set("gender", "����");
	set("age", 45);
	set("str", 25);
	set("dex", 20);
	set("long", "����һ����İ�С����������������ˣ����ϵ�\n"+
"�·��������ƣ������������ƣ�����ȥ������˪��\n");
	set("combat_exp", 35000);
	set("score", 5000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 50);
	set_skill("force", 60);
	set_skill("blade", 90);
	set_skill("dodge", 70);
	set_skill("parry", 50);
	set_skill("wuhu-duanmendao", 90);
	set_skill("yunlong-shenfa", 60);
	map_skill("blade", "wuhu-duanmendao");
	map_skill("dodge", "yunlong-shenfa");

	set("neili", 150); 
	set("max_neili", 150);
	set("jiali", 10);
	set("chat_chance", 2);
	set("chat_msg", ({
	"������˵��������һ��ð����͵�����ȥ��\n",
	"������ͻȻߺ�ȵ�: ����ܽ������ֻ���ƽ�һ����˭��˭�򰡣�\n",
	"������ͻȻߺ�ȵ�: �����˲�����ֻ���ƽ�һ����˭��˭�򰡣�\n",
        "������ɦ��ɦͷ��˵������ô�õ�������ôû��Ҫ����\n",
        "������ͻȻ˵���������Ž����֣��������ı����ġ�\n",
	}));
        set("inquiry", ([
		"�½���" :  "\n����ܶ����ɲ����װ���\n",
		"��ػ�" :  "\nֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
		"���" :  "\nֻҪ��������ػᣬ��������и�λ����ѧ���ա�\n",
                "���帴��" : "ȥ�ײĵ�ͻش�����ϸ���ưɣ�\n",
                "����" : "�����£�\n",
                "�п�" : "�����£�\n",
                "����" : (: ask_zhu :),
                "����ܽ����" : (: ask_zhu :),
                "�����˲���" : (: ask_zhu :),
                "����" :  (: ask_weiwang :),
                "��������" : (: ask_weiwang :),
       ]) );
	setup();
	carry_object("/d/city2/obj/tudao")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 20);
}

int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 10000) 
	{
		message_vision("\n��������$NһҾ����˵������λ�͹٣�Ҫʲô����˵��\n",this_player());
		who->set_temp("money_paid",1);
		return 1;
	}
	return 0;
}

int ask_weiwang()
{
command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
say("\n������˵�������������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
say("������˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
return 1;
}


int ask_zhu()
{
if (this_player()->query_temp("money_paid"))
{
this_player()->delete_temp("money_paid");
this_player()->set("huanggong\\canenter",1);
say("������˵���������ڿ���������\n");
return 1;
}
say("������˵����ʲôҲ���Ƚ�Ǯ����\n");
return 1;
} 


void init()
{
::init();
add_action("do_skills","skills");
add_action("do_skills","cha");
add_action("do_join","join");
}

int recognize_apprentice(object ob)
{
    if (ob->query("weiwang")<50)
    {
    message_vision("$Nҡ��ҡͷ��\n",this_object());
    command("tell "+ob->query("id")+" ������ػ�����Ҳ��̡�\n"); 
    return 0;
    }
	return 1;
}

int do_skills(string arg)
{
	object ob ;
	ob = this_player () ;
	if( !arg || arg!="li" )
		return 0;
	if(wizardp(ob))  return 0;
	if (ob->query("party/party_name") != HIR "��ػ�" NOR )
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
		command("tell "+ob->query("id")+" ������ػ���Ӳ��ܲ쿴��\n"); 
		return 1;
	}
    command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �������� (blade)                         - һ����ʦ  90/    \n"+
"  �����Ṧ (dodge)                         - ����似  60/    \n"+
"  �����ڹ� (force)                         - ����似  60/    \n"+
"  �����м� (parry)                         - �������  50/    \n"+
"  ����ȭ�� (unarmed)                       - �������  50/    \n"+
"�������� (yunlong-shenfa)                - ����似  60/    \n"+ 
"���廢���ŵ� (wuhu-duanmendao)             - һ����ʦ  90/    \n");
   return 1;
}
#include "/kungfu/class/yunlong/tiandihui.h";
