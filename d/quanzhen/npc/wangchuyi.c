// wangchuyi.c ����һ
// By Lgg,1998.10

#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name("����һ", ({"wang chuyi", "wang"}));
        set("gender", "����");
        set("age", 35);
        set("class", "taoist");
        set("nickname",RED"������"NOR);
        set("long",
                "������ȫ������֮������һ�����ˡ�������޳����������࣬\n"
                "��縺���Ʈ����ǰ����̬������\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 32);
        set("int", 30);
        set("con", 32);
        set("dex", 30);

        set("title","ȫ������֮��");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
        }));

        set("chat_chance", 8);
        set("chat_msg", ({
                "����һ��̾һ���������ɺ�������ҵ�ҩȫ���������ˡ�\n",
                "����һ����˭�ܰ����һ�ҩ������һ�����س�л����\n",
        }));

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 100);

        set("combat_exp", 500000);
        set("score", 300000);

        set_skill("force", 150);
        set_skill("xiantian-qigong", 150);    //��������
        set_skill("sword", 150);
        set_skill("quanzhen-jian",150);  //ȫ�潣
        set_skill("dodge", 120);
        set_skill("jinyan-gong", 150);   //���㹦
        set_skill("parry", 140);
        set_skill("unarmed",150);
        set_skill("haotian-zhang", 150);    //�����
        set_skill("literate",100);
        set_skill("strike",120);
        set_skill("taoism",100);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 2, "����");

        set("book_count",1);
        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",
                "�ϵ�" : (: ask_me :),
                "�λ�ү" : (: ask_me :),
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
        if ((int)ob->query_skill("xiantian-qigong",1) < 50 ) {
                command("say ��ı����ڹ��ķ������,�������Ը�������书��");
                return;
        }
        if ((int)ob->query("shen")<5000) {
                command("say �����������ұ�ѧ���˵Ļ���Ʒ�ʣ������ܶ���Щ����֮
�£���һ������Ϊͽ��\n");
                return;
        }
        command("say �ðɣ��Ҿ����������ͽ���ˡ�");
        command("recruit " + ob->query("id"));
}

int accept_object(object who, object ob)
{
//        object obj1,obj2,obj3,obj4;
        object me=this_player();

        if( !who || environment(who) != environment() ) return 0;
        if ( !objectp(ob) ) return 0;
        if ( !present(ob, who) ) return notify_fail("��û�����������\n");

        if (  (string)ob->query("name") != HIR"�ܵ�"NOR
                && ob->query("name") != HIY"����"NOR
                && ob->query("name") != HIW"ûҩ"NOR
                && ob->query("name") != RED"Ѫ��"NOR )
                    return 0;

        remove_call_out("destroying");
        call_out("destroying", 1, me, ob);
        message_vision("����һ���˿�$N��ȥ��ҩ�����˵�ͷ������Ϊ���ˣ�\n"
                      "�ҿ��Խ���㹦��\n", who);

        who->add_temp("tmark/��", 60);
        return 1;

}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

string ask_me()
{
        object me=this_player();

        if(me->query_temp("tmark/ָ")==1) {
                me->add_temp("tmark/ָ",1);
                return("ȥ��ʦ��ȥ���λ�ү�����˵�λ�ү������������һ��ָ����
���ڸ���ʦ���ˡ�\n");
        }
        else {
                me->set_temp("tmark/ָ",0);
                return("�λ�ү������һ���������£����ڳ������˺����ˣ�����");
        }
}

int recognize_apprentice(object ob)
{
        mapping fam;
        if (!(fam = this_player()->query("family")))
                return notify_fail("����һ������ɻ�û�ݹ�ʦ����Ҫѧ�������Ȱ�
��ʦ����˵�ɡ�\n");
        if (!(int)ob->query_temp("tmark/��"))
                return 0;
        if ( fam["family_name"] == "ȫ���") return 1 ;
        if ((int)ob->query_temp("tmark/��") == 1 )
        message_vision("����һ����$N��˵�������ܽ���Ķ�������Ϊֹ��\n"
                          "��Ҳ��Ҫ������ѧ�����ˡ�\n", ob);
        ob->add_temp("tmark/��", -1);
        return 1;
}

