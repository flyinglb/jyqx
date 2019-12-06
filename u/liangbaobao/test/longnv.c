// longnv.c С��Ů

// 1998.9 by Lgg

#include <ansi.h>

inherit NPC;

string ask_yunv();
string ask_yangguo();
string ask_yang();
string ask_me();

void create()
{
        set_name("С��Ů", ({"long nv", "long"}));
        set("gender", "Ů��");
        set("age", 18);
        set("long",
                "��һ���������£���������������ѩ���������֮�������䣬\n"
                "ʵ��������������¡������ݡ�\n");
        set("attitude", "friendly");

        set("per", 30);
        set("str", 30);
        set("int", 37);
        set("con", 36);
        set("dex", 38);

        set("chat_chance_combat", 9);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
        }) );
        set("chat_chance", 1);
        set("chat_msg", ({
                "С��Ů���ĵص�������֪����������������п����Ҵ��������ϵ��֣���\n", 
                "С��Ů�૵�������Ů����ȫ�潣�ϱڣ��ǿ������޵С�����...����ȥ����һ�����أ���\n",
                "С��Ů�����̾�˿�����ת��ͷȥ��\n",
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
        }));

        set("qi", 3500);
        set("max_qi", 3500);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);

        set("combat_exp", 800000);
        set("score", 0);

        set_skill("force", 150);
        set_skill("yunv-xinfa", 150);    //��Ů�ķ�
        set_skill("sword", 150);
        set_skill("yunv-jian", 150);     //��Ů��
        set_skill("quanzhen-jian",140);  //ȫ�潣
        set_skill("dodge", 160);
        set_skill("yunv-shenfa", 160);   //��Ů��
        set_skill("parry", 150);
        set_skill("hubo", 120);          //˫�ֻ���
        set_skill("unarmed",150);
        set_skill("meinv-quan", 160);    //��Ůȭ��
        set_skill("literate",120);
        set_skill("qufeng",200);         //����֮��

        map_skill("force", "yunv-xinfa");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quan");
        map_skill("unarmed", "meinv-quan");

        create_family("��Ĺ��", 3, "����");

        set("book_count", 1);
        set("count",1);

        set("inquiry", ([
                "����" : (: ask_yangguo :),
                "����" : (: ask_me :),
                "���" : (: ask_yang :),
                "��Ů����" : "��Ů������ȫ�潣���ϱڣ������޵У�\n",
                "��Ĺ��" : "�ҵ�����ʦүү������������ʦ��һ����ˣ�����...\n",
                "��Ů�ľ�" : (: ask_yunv :),
        ]) );

        set("env/wimpy", 40);
        setup();

//        carry_object(__DIR__"obj/shunvjian")->wield();
//        carry_object(__DIR__"obj/baipao")->wear();

}

void attempt_apprentice(object ob)
{
	if(ob->query("per") < 20)
	{
        	command("say ����ʵ�ڲ��ҹ�ά������ѧ������Ů�ķ���\n");
	}
	else
	{
	        command("say �ðɣ��Ҿ����������ͽ���ˡ�\n");
        	command("recruit " + ob->query("id"));
	}
}

string ask_yunv()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "��Ĺ��")
                return RANK_D->query_respect(this_player()) +
                "�뱾�ɺ��޹ϸ𣬺��������ɵ��ľ���";
        if (query("book_count") < 1)
                return "�������ˣ����ɵ���Ů�ľ��Ѿ�����ȡ���ˡ�";
        add("book_count", -1);
        ob = new("/clone/book/yunvjing1");
        ob->move(this_player());
        return "�ðɣ��Ȿ����Ů�ľ������û�ȥ�ú��ж���";
}

string ask_yang()
{
        object me=this_player();
        me->set_temp("tmark/��",1);
        return("��֪��������������?\n");
}

string ask_yangguo()
{
        object me=this_player();

        if( me->query_temp("tmark/��") > 1 ) 
                return("�������ڹ�Ĺ��ɽ���ȥ���Ұɡ�\n");
        me->add_temp("tmark/��",1);
        return("��Ҳ���ҹ�������������������䣬������ҡ�\n");
}

string ask_me()
{
        object ob;

        if(query("count") < 1)
                return "��֪�����������䣿";

        add("count", -1);
        ob=new(__DIR__"obj/junzijian");
        ob->move(this_player());
        return "������ӽ��͸��������������������ʱ���뽻������";
}

int recognize_apprentice(object ob)
{
        mapping myfam;
        myfam = (mapping)ob->query("family");
        if ( myfam["family_name"] == "��Ĺ��") return 1 ;
        if ((int)ob->query_temp("tmark/��") == 1 )
        message_vision("С��Ů̾�˿���������$N��˵�������ǵ�Ե���Ѿ�����,\n"
                          "��Ҳûʲô�����ɽ�����ˡ�\n", ob);
        if (!(int)ob->query_temp("tmark/��"))
                return 0;
        ob->add_temp("tmark/��", -1);
        return 1;
}

int accept_object(object who, object ob)
{

        if ( (string) ob->query("id") =="yufeng" ) {
                remove_call_out("destroying");
                call_out("destroying", 1, this_object(), ob);
                if (!(int)who->query_temp("tmark/��")) who->set_temp("tmark/��",0);
                message_vision("С��Ů������䣬���ĵ�̾�˿�����˵����\n"
                               "�ѵ��㻹�����ҵ����ҵ�����ͻ��������\n"
                               "�Դ�������ѧ�㹦��\n", who);
                who->add_temp("tmark/��", 80);
                //ob->die();
                return 1;
        }
        return 0;
}

void destroying(object me, object obj)
{
      me->add_encumbrance(-obj->query_weight());
        destruct(obj);
        return;
}
