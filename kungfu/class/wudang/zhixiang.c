// zhixiang.c �������

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("�������", ({ "zhixiang daozhang", "zhixiang", "daozhang" }));
        set("long",
                "�������䵱�����������ÿ�����䵱�������̫���ˣ�����\n"
                "�����µļ�����ľ��ʿ��æ�������ˡ�\n"
                "��������ʮ�ꡣ\n");
        set("gender", "����");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "taoist");
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 800);
        set("max_jing", 400);
        set("neili", 700);
        set("max_neili", 700);
        set("jiali", 30);
        set("combat_exp", 50000);
        set("score", 5000);

        set_skill("force", 70);
        set_skill("taiji-shengong", 60);
        set_skill("dodge", 70);
        set_skill("tiyunzong", 70);
        set_skill("unarmed", 70);
        set_skill("taiji-quan", 70);
        set_skill("parry", 70);
        set_skill("sword", 70);
        set_skill("wudang-jian", 60);

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
