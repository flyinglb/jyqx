// hufei.c

inherit NPC;
string ask_me();
void do_kill(object ob);

void create()
{
	set_name("���", ({"hu fei", "hu", "fei"}));
	set("gender", "����");
	set("nickname", "ѩɽ�ɺ�");
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
		"���̾�˿�����:����֪ʲôʱ�����ټ����������\n",
		"��쳺޺޵��������˷�����ɱ�����ˣ��ұر��˳𣡡�\n",
		(: random_move :),
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
	set_skill("hujia-daofa", 150);    // ���ҵ���	
	set_skill("blade", 120);           // ��������
	set_skill("hunyuan-yiqi", 120);   // ��Ԫһ����
	set_skill("dodge", 120);           // ��������
	set_skill("shaolin-shenfa", 120);   // ������
	set_skill("parry", 120);             // �����м�
		
	map_skill("force", "hunyuan-yiqi");
	map_skill("blade", "hujia-daofa");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "hujia-daofa");
   	set("inquiry",([
		"����": (: ask_me :),
             	]));
	set("baodao_count",1);
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
//		me->set_leader(ob);
		call_out("do_kill",1,this_player());
	}
	else if((int)(me->query("shen")<100000))
	    return "����Ŀǰ����Ϊ�ǲ�������ѵ��ġ�\n";

   	else if((int)(me->query("shen") > 100000))
	{
		if(query("baodao_count") > 1){		
    		call_out("waiting",0,me,ob);
			add("baodao_count", -1);
    		ob = new ("/clone/weapon/cwbdao");
    		ob->move(this_player());
			return " �ðɣ���Ѵ��������������㣬ϣ����ú���������\n";
		}
		else return "��������, ������ѵ��Ѳ��ڴ˴���\n";
	}

}

void do_kill(object ob)
{
	object me, room1;       
    me = this_object();
    room1 = environment(me);
 
    if (room1->query("no_fight"))
	    room1->set("no_fight", 0);
 
    if (interactive(ob))
    {
        command("say ����������Ҵ��ұ���������, ������������\n");
        me->set_leader(ob);
        remove_call_out("kill_ob");
        call_out("kill_ob", 1, ob);
    }
 
}	

