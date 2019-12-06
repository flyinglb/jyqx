// lin.c �ֳ�Ӣ
// modified by wind

#include <ansi.h>

inherit NPC;

string ask_yunv();

void create()
{
	set_name("�ֳ�Ӣ", ({"lin chaoying", "lin"}));
	set("gender", "Ů��");
	set("age", 42);
	set("long", 
		"�����ǹ�Ĺ�ɵĿ�ɽ��ʦ�ֳ�Ӣ����Ȼ�Ѿ�����ʮ���ˣ���֮ȴ\n"
                "����ͬ��ʮ��ͷ����������ȫ���������������һ�Գ��İ��£�\n"
                "ֻ��ϧ��Ե�޷ݣ�ֻ�ö��������Ĺ���ľӡ�\n");
	set("attitude", "friendly");
	
	set("str", 37);
	set("int", 42);
	set("con", 45);
	set("dex", 42);

        set("chat_chance_combat", 6);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
        }) );
	set("chat_chance", 1);
	set("chat_msg", ({
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
	}));

	set("qi", 6000);
	set("max_qi", 6000);
	set("jing", 2400);
	set("max_jing", 2400);
	set("neili", 9000);
	set("max_neili", 9000);
	set("jiali", 100);
	
	set("combat_exp", 2000000);
	set("score", 0);
	 
	set_skill("force", 220);
	set_skill("yunv-xinfa", 200);    //��Ů�ķ�
	set_skill("sword", 200);             
	set_skill("yunv-jian", 200);     //��Ů��
	set_skill("quanzhen-jian",150);  //ȫ�潣
	set_skill("dodge", 200);
	set_skill("yunv-shenfa", 220);   //��Ů��
	set_skill("parry", 200);
	set_skill("unarmed",180);
	set_skill("meinv-quan", 150);    //��Ůȭ��
	set_skill("literate",150);
	set_skill("taoism",140);
	
	map_skill("force", "yunv-xinfa");
	map_skill("sword", "yunv-jian");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "meinv-quan");

	create_family("��Ĺ��", 1, "��ɽ��ʦ");

	set("book_count",1);
        set("inquiry", ([
		"������" :  "�󵨺�С�ӣ�Ҳ��ֱ��������ʦ֮����\n",
                "������ʦ" : "������ȫ��̵��ƽ̣��Ժš������ˡ���\n",
		"��Ĺ��" :  "�ǰ������������һ�ִ��µĹ�Ĺ��\n",
		"��Ů�ľ�" : (: ask_yunv :),
        ]) );

	setup();
	
        carry_object("/clone/weapon/changjian")->wield();
	carry_object(__DIR__"obj/qingyi")->wear();

}

void attempt_apprentice(object ob)
{
	if (ob->query_int() < 30) {
        	command("say �ҹ�Ĺ�ɵĹ����һ�����֣�������ʲ�����");
		return;
    	}
    	if ((int)ob->query_skill("yunv-xinfa",1) < 70 ) {
        	command("say �����Ů�ķ������,�������Ը�������书��");
		return;
    	}
	command("say �ðɣ�����Ҳ���������ˣ��Ҿ����������ͽ���ˡ�");
	command("recruit " + ob->query("id"));
}

string ask_yunv()
{
        mapping fam; 
        object ob;
	int lvl_yunv;

        if (!(fam = this_player()->query("family")) 
	    || fam["family_name"] != "��Ĺ��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾�ɺ��޹ϸ𣬺��������ɵ��ľ���";
	if (!(lvl_yunv = this_player()->query_skill("yunv-xinfa",1))
	    || lvl_yunv < 55)
		return RANK_D->query_respect(this_player()) +
                "����Ů�ķ�����㣬�Ҳ��ܽ���Ů�ľ�������";
        if (query("book_count") < 1)
                return "�������ˣ����ɵ���Ů�ľ��Ѿ�����ȡ���ˡ�";
        add("book_count", -1);
        ob = new("/clone/book/yunvjing2");
        ob->move(this_player());
        return "�ðɣ��Ȿ����Ů�ľ������û�ȥ�ú��ж���";
}
