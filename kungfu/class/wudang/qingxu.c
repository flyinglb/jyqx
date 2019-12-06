// qingxu.c ����

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("�������", ({ "qingxu daozhang", "qingxu","daozhang" }));
        set("long",
                "��������Զ�ŵĵ������������\n"
                "��������ʮ���꣬�����䵱�ɺ�ɽ�����¡�\n");
        set("gender", "����");
        set("age", 38);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "taoist");
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 1000);
        set("max_jing", 800);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 30);
        set("combat_exp", 60000);
        set("score", 8000);

        set_skill("force", 50);
        set_skill("taiji-shengong", 50);
        set_skill("dodge", 50);
        set_skill("tiyunzong", 40);
        set_skill("unarmed", 60);
        set_skill("taiji-quan", 60);
        set_skill("parry", 50);
        set_skill("sword", 60);
        set_skill("wudang-jian", 40);
        set_skill("taoism", 50);
        set_skill("literate", 50);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "wudang-jian");
        map_skill("sword", "wudang-jian");

        create_family("�䵱��", 3, "����");
        set("class", "taoist");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("guarded") < 1) {
                command("say " + RANK_D->query_respect(ob) +
                        "������䵱�ɾ��˶����������м��������أ�");
                return;
        }
        if ((int)ob->query("guarded") < 5) {
                command("say " + RANK_D->query_respect(ob) +
                        "�������䵱���£��㻹��Ҫ���Ŭ�����ĲŶԡ�");
                return;
        }
        if ((int)ob->query("shen") < 0) {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
        command("say �ðɣ�ƶ�����������ˡ�");
        command("recruit " + ob->query("id"));
}
