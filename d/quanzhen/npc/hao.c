// hao.c �´�ͨ
// By Lgg,1998.10

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�´�ͨ", ({"hao datong", "hao"}));
        set("gender", "����");
        set("age", 34);
        set("class", "taoist");
        set("nickname",HIG"������"NOR);
        set("long",
                "������ȫ�������еĺ´�ͨ�����ˡ������΢�֣��������ģ\n"
                "�������ϴ��ĵ���˫����ޡ�\n" );
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 30);
        set("int", 29);
        set("con", 29);
        set("dex", 29);

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

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 100);

        set("combat_exp", 500000);
        set("score", 300000);

        set_skill("force", 130);
        set_skill("xiantian-qigong", 130);    //��������
        set_skill("sword", 130);
        set_skill("quanzhen-jian",130);  //ȫ�潣
        set_skill("dodge", 110);
        set_skill("jinyan-gong", 120);   //���㹦
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

