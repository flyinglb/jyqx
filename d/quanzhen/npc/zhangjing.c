// zhangjing.c �ƾ�����
// By Lgg,1998.10

inherit NPC;
string ask_me();
string ask_zhipu();

void create()
{
        set_name("�ƾ�����", ({"zhangjing"}));
        set("gender", "����");
        set("age", 36);
        set("class", "taoist");
        set("long",
                "��λ��ȫ������ƹܾ���ĵ���������ǰ�ǳ�������һ��˽��\n"
                "�ķ��ӣ���Ϊ��Ľ������Űݵ���ȫ�����¡������Ͼ���Ϊ��\n"
                "����ˣ�����ĸ������ò��Σ���Ҳ�������⣬���԰�������\n"
                "���ж������ˡ�\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 18);
        set("int", 18);
        set("con", 20);
        set("dex", 21);

        set("qi", 500);
        set("max_qi", 500);
        set("jing", 350);
        set("max_jing", 350);
        set("neili", 900);
        set("max_neili", 900);
        set("jiali", 0);

        set("combat_exp", 20000);
        set("score", 15000);

        set_skill("force", 40);
        set_skill("xiantian-qigong", 40);    //��������
        set_skill("sword", 40);
        set_skill("quanzhen-jian",40);  //ȫ�潣
        set_skill("dodge", 50);
        set_skill("jinyan-gong", 40);   //���㹦
        set_skill("parry", 50);
        set_skill("unarmed",50);
        set_skill("strike",50);
        set_skill("haotian-zhang", 50);    //�����
        set_skill("literate",100);
        set_skill("taoism",80);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 4, "����");

        set("book_count",1);
        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",
                "���¾�" : (: ask_me :),
                "һ��ָ" : (: ask_zhipu :),
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

string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "ȫ���")
                return RANK_D->query_respect(this_player()) +
                "�뱾�̺��޹ϸ����⻰�ɽ���Ū�������ˡ�";
        if (query("book_count") < 1)
                return "�������ˣ����¾��Ѿ�����ȡ���ˡ�";
        add("book_count", -1);
        ob = new(__DIR__"obj/daodejing-i");
        ob->move(this_player());
        return "�ðɣ��Ȿ�����¾������û�ȥ�ú��ж����п������ĵط������ҡ�";

}

string ask_zhipu()
{
        object me=this_player();
        if(me->query_temp("tmark/ָ")==2) {
                me->add_temp("tmark/ָ",2);
                return("һ��ָ��ָ�������������ɱ�����ʦ�����մ棬�Ӳ��⴫��\n")
;
        }
        else {
                me->set_temp("tmark/ָ",0);
                return("��˵һ��ָ��������������ָ������Ҳû�м�����\n");
        }
}

