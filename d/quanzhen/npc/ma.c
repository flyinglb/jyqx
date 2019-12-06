// ma.c ����
// By Lgg,1998.10

#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name("����", ({"ma yu", "ma"}));
        set("gender", "����");
        set("age", 42);
        set("class", "taoist");
        set("nickname",MAG"������"NOR);
        set("long",
                "�������������Ĵ���ӣ�ȫ������֮�ף����������������ˡ�\n"
                "����ü��Ŀ���Ͱ����ף���Ц�ſ����㡣\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 28);
        set("int", 32);
        set("con", 31);
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
        set_skill("sword", 140);
        set_skill("quanzhen-jian",140);  //ȫ�潣
        set_skill("dodge", 120);
        set_skill("jinyan-gong", 140);   //���㹦
        set_skill("parry", 150);
        set_skill("unarmed",140);
        set_skill("haotian-zhang", 140);    //�����
        set_skill("literate",100);
        set_skill("strike",120);
        set_skill("taoism",110);

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
                "���㹦" : (: ask_me :),
                "����ͼ��" : (: ask_me :),
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
        command("pat " + ob->query("id"));
        command("say �ðɣ��Ҿ����������ͽ���ˡ�");
        command("recruit " + ob->query("id"));
}

string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "ȫ���")
                return RANK_D->query_respect(this_player()) +
                "�뱾�̺��޹ϸ��ҽ̵��书�伮�ɲ��ܽ����㡣";
        if (query("book_count") < 1)
                return "�������ˣ�����ͼ���Ѿ�����ȡ���ˡ�";
        add("book_count", -1);
        ob = new("/clone/book/jinyantu");
        ob->move(this_player());
        return "�ðɣ��Ȿ������ͼ�ס����û�ȥ�ú��ж���";

}
