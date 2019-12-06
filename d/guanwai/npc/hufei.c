// hufei.c
// modify by Risc 12.23.2000
// modify by Risc 12.24.2000

#include <ansi.h>;
inherit NPC;

string ask_me();
string ask_book();
void do_kill(object ob);
void waiting_book(); // by risc
void waiting_dao();  // by risc

void create()
{
	set_name("���", ({"hu fei", "hu", "fei"}));
	set("gender", "����");
	set("nickname", "ѩɽ��"HIG"��"NOR);
	set("age", 25);
	set("long", 
		"�����Ǻ�һ��֮�ӣ������书��ǿ�����û��\n"
		"�ڽ�����������š�ѩɽ�ɺ�����\n"
		"����һ����ɫ�������������һ�ѿ������ܾɵĵ���\n"
		"��������ף�����������һͷŨ����ȴ����衣\n");
	set("attitude", "peaceful");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("chat_chance", 20);
	set("chat_msg", ({
		"���̾�˿�����������֪ʲôʱ�����ټ����������\n",
		"��쳺޺޵��������˷�����ɱ�����ˣ��ұر��˳𣡡�\n",
		"����гݺ޵������ֻ����������¶����ұ����д�ⲣ���\n",
//		(: random_move :),
	}));
	
	set("qi", 3000);
	set("max_qi", 3000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 190000);
	set("score", 20000);
	 
	set_skill("force", 110);             // �����ڹ�
	set_skill("hujia-daofa", 150);       // ���ҵ���	
	set_skill("blade", 120);             // ��������
	set_skill("hunyuan-yiqi", 120);      // ��Ԫһ����
	set_skill("dodge", 120);             // ��������
	set_skill("shaolin-shenfa", 120);    // ������
	set_skill("parry", 120);             // �����м�
		
	map_skill("force", "hunyuan-yiqi");
	map_skill("blade", "hujia-daofa");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "hujia-daofa");
	set("inquiry",([
		"����":     (: ask_me :),
		"����":     (: ask_book :),
		"���ҵ���": (: ask_book :),
		"�ֻ�":     "�ֻ���������ҷ�ɱ�������ɡ�\n",
		"��һ��":   "�ɶ�������һ�����ҵ��������Ҵ�û��������\n",
		"���˷�":   "���˷���ͼҸ��������Ҹ�ȴ�������Ľ��¡�\n",
		"������":   "��֪ʲôʱ�����ټ����������\n",
		"����":   "��֪ʲôʱ�����ټ����������\n",
		"��������":   "��֪ʲôʱ�����ټ����������\n",
		"������":   "������Ϊ�Ҷ����ġ�\n",
		"�԰�ɽ":   "�������������? \n",
		"Ԭ����":   "���ˣ��������������ˡ�\n"
	]));
	set("is_refresh",1);  //�����Ƿ�Ҫˢ��  1--ˢ��    0--not ˢ��       by risc
	set("refresh_rate",3600);  //ˢ����=3600��=1Сʱ��                      by risc

	set("baodao_count",1);
	set("book_count",1);
	setup();
	carry_object(__DIR__"obj/cwbdao")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

string ask_me()
{
	object ob, me;
	
	me = this_player();
	if((int)me->query("shen") < 0)
	{
		me->set_leader(ob);
		call_out("do_kill",1,this_player());
	}
	else if((int)(me->query("shen")<100000))
		return "����Ŀǰ����Ϊ�ǲ�������ѵ��ġ�\n";

   	else if((int)(me->query("shen") > 100000))
	{
		if(query("baodao_count") > 0)
		{		
	    		if (query("is_refresh"))
	    		  {
	    		     remove_call_out("waiting_dao");
	    		     call_out("waiting_dao",query("refresh_rate"));
	    		  }    // by risc

			add("baodao_count", -1);
    			ob = new (__DIR__"obj/cwbdao");
    			ob->move(me);
			command("rumor "+me->query("name")+"�õ�������������\n");
			return " �ðɣ���Ѵ��������������㣬ϣ����ú���������\n";
			
		}
		else return "�������ˣ�������ѵ��Ѳ��ڴ˴���\n";
	}

}

void do_kill(object ob)
{
	object me, room1;       
	me = this_object();
	room1 = environment(me);
 
	if (file_name(room1)=="/d/guanwai/xiaowu")
           room1->set("no_fight", 0);
        //by risc
	    	
 
	if (interactive(ob))
	{
		command("say ����������Ҵ��ұ��������⣬������������\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
 
}	


int accept_object(object me, object ob)
{
//	int i;
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("��û�����������");
	if ( (string)ob->query("id") == "yan ji") 
	{
		write(HIC "\n���˵������λ" + RANK_D->query_respect(me)+"����˴����£�����ʵ��֪����Ϊ����\n");
		write(HIC "\n��쳴�ϲ�����������벻����Ҳ�н��죡�������䣬���ֻ���Ϊ���Ρ�\n");
		ob->die();
		me->set_temp("marks/hujiadaopu",1);
        }
	return 1;
}

string ask_book()
{
	object ob, me;
	
	me = this_player();
	if (!me->query_temp("marks/hujiadaopu",1)) return "��˵ʲô? \n";
	if((int)(me->query("shen")<10000))
		return "����������С֮�֣��������ֻ��ڶ���\n";

   	else if((int)(me->query("shen") > 100000))
	{
		if(query("book_count") > 0)
		{		
		write(HIC "���˵��ת����ֻ�ʬ�����ѳ�һ���ƾ��鱾�����˸��㡣\n");
	    		if (query("is_refresh"))
	    		  {
	    		     remove_call_out("waiting_book");
	    		     call_out("waiting_book",query("refresh_rate"));
	    		  }    // by risc
			add("book_count", -1);
    			ob = new ("/clone/book/blade_book");
    			ob->move(this_player());
			command("rumor "+me->query("name")+"�õ����ҵ�������\n");
			return "�Ȿ���ױ��⹷����ռ��ʱ�ˣ����ھ�������ɡ�\n";
		}
		else return "�������ˣ����ڵ����Ѳ��ڴ˴���\n";
	}

}


void waiting_dao()
{
   set("baodao_count",1);
}

void waiting_book()
{
   set("book_count",1);
}
