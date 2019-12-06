// hong.c �鰲ͨ

#include <ansi.h>;
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;

void create()
{
	set_name("�鰲ͨ", ({ "hong antong", "hong" }));
	set("title",  HIY"������"NOR"����" );
	set("nickname", HIR "�����ɸ�" NOR);
	set("long", "�������书����������˵�̸֮ɫ��������̽����鰲ͨ��\n");
	set("gender", "����");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	
	set("qi",4000);
	set("max_qi", 4000);
	set("jing",3000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jingli",4000);
	set("max_jingli",4000);
	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 400000);

        set_skill("force", 200);
	set_skill("shenlong-xinfa", 200);
        set_skill("dodge", 180);
	set_skill("yixingbu", 160);
        set_skill("hand", 200);
	set_skill("shenlong-bashi", 200);
        set_skill("strike", 200);
	set_skill("huagu-mianzhang", 180);
        set_skill("parry", 150);
        set_skill("staff", 200);
        set_skill("sword", 200);
	set_skill("shedao-qigong", 180);
	set_skill("literate", 90);

	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "shenlong-bashi");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "shedao-qigong");
        map_skill("staff", "shedao-qigong");
	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("hand", "shenlong-bashi");

	create_family("������",1,"����");

        set("inquiry", ([
		"������" :  "\nһ�������벻���������̵�(join shenlongjiao)��\n",
		"���" :  "\nһ�������벻���������̵�(join shenlongjiao)��\n",
		"�鰲ͨ" :  "\n�㲻������ǲ���?\n",
		"����" :  "\n�Ҿ��������̽�����\n",
		"�ں�" : "\n���겻��!�����ɸ�!��������!������ʥ!\n",
       ]) );
	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
		(: command("smile") :),
		(: command("haha") :),
		(: command("chat ƾ����" + RANK_D->query_rude(this_player())+",Ҳ����̫��үͷ�϶���?\n") :),
		(: command("say ���ò��ͷ�����������\n") :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "staff.chang3" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                      }) );
	setup();
//	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}

int recognize_apprentice(object me)
{
        if( me->query("learnhong")) return 1;
        if ((int)me->query("shen") > -1000) {
                command("say ��Խ����Խ��׵������Ե׵ġ�");
			this_object()->set_leader(me);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, me); 
                return 0;
        }
        if( me->query_temp("pending/flatter") ) {
                command("say ����˲����ҷ�����������������㣿!");
			this_object()->set_leader(me);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, me); 
                return 0;
        } else {
                command("say �Һ鰲ͨ�������������ʥ����ô������");
                message_vision("�鰲ͨ΢��˫�ۣ������룬һ����������(flatter)�����ӡ�\n",
                this_player());
                me->set_temp("pending/flatter", 1);
	return 0;
        }
}

int do_flatter(string arg)
{
        if( !this_player()->query_temp("pending/flatter") )
                return 0;
        if( !arg ) return notify_fail("��˵��ʲô��\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N����˵����" + arg + "\n", this_player());
        if( strsrch(arg, "���겻��") >=0 && (strsrch(arg, "�����ɸ�") >=0
         || strsrch(arg, "��������") >=0 || strsrch(arg, "������ʥ") >=0 )) {
                command("smile");
                command("say �⻹��ࡣ\n");
                this_player()->set("learnhong", 1);
                command("recruit " + this_player()->query("id"));
        } else {
                command("say ����˲����ҷ�����������������㣿!");
			this_object()->set_leader(this_player());
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, this_player()); 
        }
        return 1;
}

// ���겻��,�����ɸ�,��������,������ʥ

void die()
{
message_vision("\n$N���������,��Ȼ������ɱ����,....��˵���������۵������ˡ�\n", this_object());
	::die();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
	add_action("do_flatter", "flatter");
}

void greeting(object ob)
{
	object obj;
        if ( objectp(ob) && interactive(ob) )
        {
	if (obj = present("usedgao", ob))          
	   set("combat_exp",500000);
	   set("qi",10);
	   set("jing",10);
	}
	return;
}

void attempt_apprentice(object ob)
{
    if (ob->query("party/party_name") != HIY "������" NOR ) {
        command("say �㲻�Ǳ��̽���, ����������!");
	return;
    }
    if ((int)ob->query_skill("shenlong-xinfa",1) < 60 ) {
        command("say ��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!");
	return;
    }
    if ((int)ob->query_skill("shedao-qigong",1) < 60 ) {
        command("say ��ı����ȷ�̫����,����ŬŬ�������һ�°�!");
	return;
    }
    if ((int)ob->query("shen") > -10000  ) {
        command("say �������������������������������ְ׵�����򽻵�������ذɣ�");
	return;
    }
    command("say �ܺã��ܺá�");
    command("recruit " + ob->query("id"));
}
 
