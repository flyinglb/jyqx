// shou.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);

void create()
{
	set_name("��ͷ��", ({ "shou toutuo", "shou" ,"toutuo"}));
	set("title", "�������һ���");
	set("nickname",HIR "�ɶ�������" NOR);
	set("long", "��ͷ������氫,�����ֵó���,�����˾ͻ�������һ���󶬹�.\n��������Դ��ϵ���һ��ͭ�����,���ӷǳ�����.\n" );
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
	set_skill("unarmed", 80);
	set_skill("staff", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("yixingbu", 80);
	//set_skill("shenlong-quanfa", 60);
	set_skill("shenlong-xinfa", 70);
	set_skill("shedao-qigong", 60);

	map_skill("force", "shenlong-xinfa");
	map_skill("staff", "shedao-qigong");
	map_skill("unarmed", "shenlong-bashi");
	//map_skill("parry", "shenlong-quanfa");
	map_skill("parry", "shedao-qigong");
	map_skill("dodge", "yixingbu");

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

int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="shenlongjiao" )
	return notify_fail("��Ҫ����ʲô��֯��\n"); 
   if(ob->query("shenlongjiao")) 
	{
	message_vision(HIC "��ͷ��˵�������Ѿ��������̵����ˡ�\n" NOR,this_player());
	return 1;
	}
   if ((int)ob->query("shen")>-1000)
        {
	message_vision(HIC "��ͷ�Ӷ�$N��ŭ�����������?һ����Ͳ��Ǻ���!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
   if (ob->query("combat_exp")<20000)
        {
	message_vision(HIC "��ͷ�Ӷ�$Nҡͷ�������ʵս����̫�͡�\n" NOR,this_player());
  	return 1;
  	}
  if ( ob->query_skill("bibo-shengong",1)
	|| ob->query_skill("hamagong",1)
	|| ob->query_skill("huagong-dafa",1))
   {
    ob->set("shenlongjiao",1);
    command("tell "+this_player()->query("id")+" �����ھ��������̵�����.\n");
    return 1;	
   }
   else 
   {
   message_vision(HIC "��ͷ�Ӷ�$N��ŭ�����������?һ����Ͳ��Ǻ���!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
}

void attempt_apprentice(object ob)
{
    if ((int)ob->query("shen") > 0  ) {
        command("say �������������������������������ְ׵�����򽻵�������ذɣ�");
		return;
	}
    command("say �ܺã��ܺá�");
    command("recruit " + ob->query("id"));
}
 
