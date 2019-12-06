// shouyuan.c ��԰����

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("��԰����", ({ "shouyuan daozhang", "shouyuan", "daozhang" }));
        set("long",
                "�������������԰������԰������\n"
                "��������ʮ�꣬��Щ��԰���¡�\n");
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "taoist");
        set("str", 21);
        set("int", 21);
        set("con", 21);
        set("dex", 21);

        set("max_qi", 600);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 30);
        set("combat_exp", 30000);
        set("score", 4000);

        set_skill("force", 50);
        set_skill("taiji-shengong", 40);
        set_skill("dodge", 50);
        set_skill("tiyunzong", 40);
        set_skill("unarmed", 50);
        set_skill("taiji-quan", 50);
        set_skill("parry", 50);
        set_skill("sword", 50);
        set_skill("wudang-jian", 40);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "wudang-jian");
        map_skill("sword", "wudang-jian");

        create_family("�䵱��", 4, "����");
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
        if ((int)ob->query("guarded") < 15) {
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
