// guanfuzi.c �ذ��� 

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int ask_weiwang();
int do_skills(string arg);

void create()
{
	set_name("�ذ���", ({ "guan anji", "guan" }));
	set("title", HIR "��ػ�"HIG"��ľ��"NOR"����");
//	set("title", "����ϰ�");
	set("nickname", "�ط���");
	set("shen_type", 1);

	set("gender", "����");
	set("age", 35);
	set("long",
		"\nֻ���������ĺ���Ʈ����ǰ��ģ���������ϡ�����˳ƹط��ӡ�\n");

	set_skill("unarmed", 60);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("sword", 80);
	set_skill("force", 70);
	set_skill("zixia-shengong", 50);
	set_skill("huashan-jianfa", 70);
	set_skill("huashan-shenfa",60);
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("force", "zixia-shengong");

	set_temp("apply/attack", 35);
	set_temp("apply/attack", 35);
	set_temp("apply/damage", 25);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("chat_chance", 1);
	set("chat_msg", ({
	"�ذ�����Ȼ˵�����õ�����˭���������ֲ�����˵����\n",
	"�ذ�����Ȼ˵�������ҵ�Ƣ������ã���ҿ�ҪС���ˡ�\n",
	}));
        set("inquiry", ([
		"�½���" :  "\n����ܶ����ɲ����װ���\n",
		"��ػ�" :  "\nֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
		"���" :  "\nֻҪ��������ػᣬ��������и�λ����ѧ���ա�\n",
                "���帴��" : "ȥ���׳��͹ײĵ���ϸ���ưɣ�\n",
                "����" :  (: ask_weiwang :),
                "��������" : (: ask_weiwang :),
       ]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
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

void init()
{
add_action("do_skills","skills");
add_action("do_skills","cha");
add_action("do_join","join");
}

int do_skills(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="guan" )
     return 0;
   if(wizardp(ob))   return 0;
  if (ob->query("weiwang")<50)
  {
   message_vision("$Nҡ��ҡͷ��\n",this_object());
   command("tell "+ob->query("id")+" ������ػ���Ӳ��ܲ쿴��\n"); 
   return 1;
   }
   command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �����Ṧ (dodge)                         - �����뻯  70/    \n"+
"  �����ڹ� (force)                         - �����뻯  70/    \n"+ 
"����ɽ���� (huashan-jianfa)                - ����似  70/    \n"+
"����ɽ�� (huashan-shenfa)                - ����似  60/    \n"+
"  �����м� (parry)                         - �����뻯  70/    \n"+
"  �������� (sword)                         - �Ƿ��켫  80/    \n"+
"  ����ȭ�� (unarmed)                       - ����似  60/    \n"+
"����ϼ�� (zixia-shengong)                - �������  50/    \n");
   return 1;
}

void die()
{
message_vision("\n$N��ŭ��������ҿ����ӣ��ֵ��ǻ����ұ���ģ���˵�굹�����ˡ�\n", this_object());
::die();
}

int ask_weiwang()
{
command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
say("\n�ذ���˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
say("�ذ�����˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
return 1;
}
#include "/kungfu/class/yunlong/tiandihui.h";
