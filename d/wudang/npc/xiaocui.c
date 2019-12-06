// d/wudang/npc/xiaocui.c
// By Marz 04/01/96

inherit NPC;

void greeting(object ob);
void init();
int accept_object(object who, object ob);
void serve_tea(object who);
void delete_served();

void create()
{
	set_name("С��", ({"cui", "xiao cui"}) );
	set("nickname", "�Ų��ͯ");
	set("gender", "Ů��" );
	set("age", 12+random(6));
	set("long",
	  "���Ǹ������䲻���С��������ɵĵ���Ҳ�ڲ�ס�����緢�������塣\n"
	  "һ���������ɣ������������ݡ���������΢ʾ�⣬���ȥ�Ӳ赹ˮ��\n");
	set("attitude", "friendly");
        set("shen_type", 1);
        set("class", "taoist");

        set("str", 20);
        set("int", 28);
        set("con", 24);
        set("dex", 20);

        set("max_qi", 150);
        set("max_jing", 100);
        set("neili", 150);
        set("max_neili", 150);

        set("combat_exp", 1000+random(800));
        set("score", 1000);
        set("tea_count", 5);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 15+random(10));
        set_skill("parry", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 3);

        create_family("�䵱��", 5, "����");

        set("inquiry", ([
            "Ů����" : "�⡸Ů���㡹���úܣ����δ����Ķ���Ҳ���������ţ�\n"
               	+ "����������ܴ������԰��������ŪЩ��Ů���㡹��Ҷ����\n"
                + "�ҵ��ǿ���Ϊ����һ����������������ȥ����Ų�����Ϊ��\n"
        ]));

        setup();
        carry_object("/d/wudang/obj/greenrobe")->wear();
        carry_object("/d/city/obj/necklace");
}

void init()
{
        object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if ( !ob || (environment(ob) != environment()) ) return;
	say("С��Ц������˵������λ" + RANK_D->query_respect(ob) 
		+ "��������������͸����ϲ衣\n");
}

int accept_object(object who, object ob)
{
	object obn;

	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, who) ) return notify_fail("��û�����������");
	if ( query("tea_count") < 1) return notify_fail("����ֻʣ������ˡ�");
	if (  (string)ob->query("name") == "��Ҷ"
		|| (string)ob->query("name") == "������"  ) 
	{
		if ( (string)ob->query("name") == "������" ) 
		{
			command("kiss " + (string)who->query("id")); 
			command("wear lace");
//			carry_object("/d/city/obj/necklace")->wear();
		}

		if ( who->query_temp("marks/sit") )
		{
			if ((int)who->query_temp("tea_cup") > 0)	
	   		{
				command("smile " + who->query("id"));
			} else 
			{
	    		say("С�����˸�Ҿ����" + RANK_D->query_respect(who)
	       		+ "���Ժ�СŮ����͸�������衣\n");
			}

			who->set_temp("tea_cup", 5);
			remove_call_out("serve_tea");
			call_out("serve_tea", 1, who);

		} else 
		{
			who->set_temp("tea_cup", 5);
	    	say("С����˸��򸣣�" + RANK_D->query_respect(who)
	       	+ "������������СŮ����͸���ȥ����衣\n");
		}

		return 1;
	}

	if ((string)ob->query("name") == "��Ů���㡹��Ҷ") 
	{
		if ( who->query_temp("marks/sit") )
		{
			command("dance " + who->query("id"));
		} else 
		{
			message_vision("С����$N�����߷羰��õ��������£�\n", who);
		}

		who->set_temp("tea_cup", 10);
		who->set_temp("marks/sit", 1);
	 	obn = new(__DIR__"../obj/nuerxiang");
		obn->move(who);
		add("tea_count",-1);

		return 1;
	}


	command("? " + who->query("id"));
//	command("smile cui");
	return 1;
}


void serve_tea(object who)
{
//        object obt, obc, obn;
        object obn;
	object room;

	if( !who || environment(who) != environment() ) return;

	if( !who->query_temp("marks/sit") ) return;
	
	if( !objectp(room = environment()) ) return;

	if ( (int)who->query_temp("tea_cup") <= 0 || query("tea-count") < 1 )
	{
	 	obn = new("d/wudang/obj/dawancha");
		obn->move(room);
		message_vision("С�������������������ϵĴ���赹����\n",
			who);
	} else 
	{
		who->add_temp("tea_cup", -1);
	 	obn = new("d/wudang/obj/xiangcha");
		add("tea_count",-1);
		obn->move(room);
		message_vision("С���ó�������С��������˱���裬�������ϣ�\n",
			who);
	}

 	obn = new("d/wudang/obj/mitao");
	obn->move(room);
	message_vision("С���ó�һ�����ʵ�ˮ���ң��������ϣ�\n", who);
	
	return;
}
