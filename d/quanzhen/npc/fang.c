// fang.c ��־��
// By Lgg,1998.10

inherit NPC;

void create()
{
        set_name("��־��", ({"fang zhiqi", "fang"}));
        set("gender", "����");
        set("age", 24);
        set("class", "taoist");
        set("long",
                "������ȫ��̵����������еĺ��֣��𴦻��Ķ����ӡ�\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 26);
        set("int", 25);
        set("con", 25);
        set("dex", 26);

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

        set("qi", 1500);
        set("max_qi", 1500);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 60);

        set("combat_exp", 160000);
        set("score", 100000);

        set_skill("force", 80);
        set_skill("xiantian-qigong", 80);    //��������
        set_skill("sword", 80);
        set_skill("quanzhen-jian",70);  //ȫ�潣
        set_skill("dodge", 70);
        set_skill("jinyan-gong", 70);   //���㹦
        set_skill("parry", 80);
        set_skill("strike",80);
        set_skill("unarmed",80);
        set_skill("haotian-zhang", 70);    //�����
        set_skill("literate",60);
        set_skill("taoism",60);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 3, "����");

        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
        command("say �ðɣ��Ҿ����������ͽ���ˡ�");
        command("recruit " + ob->query("id"));
}

