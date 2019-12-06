// yue-buqun.c lasted updated by cocacola on 2.19 for adding chushi
// ����Ⱥ
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
int do_xunshan();
/*
mixed out_master(mixed arg);
mixed out_master(mixed arg)
{
	object me;
	me = this_player();
	if( (string)me->query("family/family_name")!="��ɽ��")
	{
		tell_object(me,"����Ⱥ�ɻ�ض���˵:�ۿ�!��û�и��!\n");
		return 1;
	}
	if(me->query("gender")=="Ů��"){
		tell_object(me,"��λС����,���������˵�ͽ��,��ó�������ʦ����!\n");
		return 1;
	}
	if(me->query("combat_exp") <= 100000) {
		tell_object(me,"����Ⱥ��"+me->query("name")+
		"ŭ��:����ûѧ���Ҿ����ȥ����.\n");
		return 1;
	}

	tell_object(me,"����Ⱥ������һ��,��"+me->query("name")+"˵��:Ҫ���ʦ,
		�����������в���(accept test).\n");
	add_action("do_accept","accept");
	return 1;
}
int do_accept(string arg)
{
        mapping guild;

        if( arg== "test" ) {

		say("\n����Ⱥ���˵�ͷ��˵�����ܺã�С���ˡ������ǵ�һ��....\n\n");
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		if( (int)this_player()->query("kee") < 0
			|| !present(this_player(), environment()))
		{
		say("����Ⱥ̾�˿�����˵��������������һ�ж��Ų����������Բ�����....\n");
                       return 1;
                }
                say("\n����Ⱥ�ȵ����ڶ���....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0
                || !present(this_player(), environment())) {
			say("����Ⱥ̾���������ӻ����ʦ,��.....\n");
			return 1;
                }
                say("\n����Ⱥŭ���������У���ȥ����!....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0
                || !present(this_player(), environment())) {
			say("����ȺЦ�����ٺ٣������ӽ������ϵ���,��.....\n");
                        return 1;
	}
	say("\n����Ⱥ��Ц������ϲ,���ʦ��.����ʦͽһ����ʦ��ûʲô���͵� .
	\nΪʦ�����������:��������,��������!ͽ��,�,��...���������Ϊ֪.\n\n");
	this_player()->set("betrayer",this_player()->query("betrayer")-1);
	this_player()->set("title","��ʿ");
	this_player()->set("family/family_name","��ɽ��");
	this_player()->set("family/generation",13);
	this_player()->set("family/master_name",0);
	command("chat " + this_player()->query("name")+"�����뻪ɽ���պ�һ�н���
           ��Թ���뱾���޹�.\n");
                return 1;
        }
        return 0;
}
*/
void create()
{
        set_name("����Ⱥ", ({ "yue buqun", "yue" }) );
        set("title", "��ɽ������");
        set("nickname", "���ӽ�");
        set("gender", "����");
        set("class", "swordsman");
        set("age", 55);
        set("long",
                "����Ⱥ����ִ�ƻ�ɽ�ɣ��˵���������һ��һ�ĸ��֡�\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 2400);
        set("max_neili", 2400);
        set("jiali", 30);
        set("max_qi",2000);
        set("max_jing",1200);

        set("combat_exp", 1000000);
        set("shen", -200000);
        set("xunshan", 1);
        set("apprentice_available", 3);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
        }) );
        set("inquiry", ([
//            "��ʦ": (: out_master :),
            "Ѳɽ": (: do_xunshan :),
        ]) );

        set_skill("unarmed", 80);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("literate", 100);
        set_skill("huashan-sword", 100);
        set_skill("zixia-shengong", 100);
        set_skill("huashan-ken", 80);
        set_skill("feiyan-huixiang", 100);
        set_skill("pixie-sword",80);
        set_skill("zhengqijue",100);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");

        create_family("��ɽ��", 13, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/book/zixia_book");
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say �Ϸ�����Ѿ������������ӣ���������ͽ�ˡ�");
        }
}

void do_recruit(object ob)
{
        if( (int)ob->query("int") < 20 )
                command("say �һ�ɽ���Խ���Ϊ�������ҿ�"+RANK_D->query_respect(ob)+"���ʺ���ѧ������");
        else {
                command("say �ã��ã��ã��ܺá�");
                command("recruit " + ob->query("id") );
        }
}
/*
void die()
{
message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+this_player()->query("name")+"������ϼ��ܸ����\n"NOR, users());
	::die();
}
*/
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        add("apprentice_availavble", -1);
}
void reset()
{
//        delete_temp("learned");
        set("apprentice_available", 3);
}
int do_xunshan()
{
        object me = this_player();
        if ( me->query_temp("xunshan"))
        {
               if (!me->query_temp("xunshan/chaoyang"))
               {
                      message_vision("$N����$n˵���㳯����ûȥ����������Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/lianhua"))
               {
                      message_vision("$N����$n˵����������ûȥ����������Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/yuntai"))
               {
                      message_vision("$N����$n˵������̨��ûȥ����������Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/sheshen"))
               {
                      message_vision("$N����$n˵������ôûȥ�����£�����Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/siguo"))
               {
                      message_vision("$N����$n˵���㵽��˼����ȥ�ˣ�����Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/yunu"))
               {
                      message_vision("$N����$n˵���㵽��Ů����滪ɽС��ȥ�����ˣ�����Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               message_vision("$N����$n˵�����������ˡ������ȥ��Ϣȥ�ɡ�\n", this_object(), me);
               me->delete_temp("xunshan");                      
               me->add("combat_exp", random(100));
               return 1;
        }
        else
        {
               if ( query("xunshan") < 1)
               {
                      message_vision("$N����$n˵�������Ѿ�����Ѳɽȥ�ˡ������������ɡ�\n", this_object(), me);
                      return 1;
               }
               if( me->query("family/family_name") != "��ɽ��")
               {
                      message_vision("$N����$n���һ�������ɵ��Ӳ���Ѳɽ�����������ļ�ϸ���ݹ��ҽ��²����飡\n", this_object(), me);
                      this_object()->kill_ob(me);
                      return 1;
               }
               else
               {
                      add("xunshan", -1);
                      message_vision("$N����$n˵�����ɵ�������Ѳɽ���㣬�ܺã��ܺã����ȥ�ɡ�\n", this_object(), me);
                      me->set_temp("xunshan/start", 1);
                      me->set_temp("xunshan/time", time());
                      return 1;
               }
        }
}
