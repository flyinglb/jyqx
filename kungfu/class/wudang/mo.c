// mo.c Ī����

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("Ī����", ({ "mo shenggu", "mo" }));
        set("nickname", "�䵱����");
        set("long",
                "���������������С���ӡ��䵱����֮ĩ��Ī���ȡ�\n"
                "��һ���ɸɾ����Ļ�ɫ���ۡ�\n"
                "��������ʮ��ͷ��ͣ��Ե�����δ�ѣ�����ݳ���ü������\n");
        set("gender", "����");
        set("age", 21);
        set("attitude", "peaceful");
        set("class", "swordsman");
        set("shen_type", 1);
        set("str", 26);
        set("int", 26);
        set("con", 26);
        set("dex", 26);

        set("max_qi", 1800);
        set("max_jing", 800);
        set("neili", 1800);
        set("max_neili", 1800);
        set("jingli", 1800);
        set("max_jingli", 1800);
        set("jiali", 50);
        set("combat_exp", 200000);
        set("score", 60000);

        set_skill("force", 80);
        set_skill("taiji-shengong", 90);
        set_skill("dodge", 90);
        set_skill("tiyunzong", 90);
        set_skill("unarmed", 80);
        set_skill("taiji-quan", 85);
        set_skill("parry", 90);
        set_skill("sword", 90);
        set_skill("liangyi-jian", 90);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");
	set("chat_chance", 20);
        set("chat_msg", ({
            "Ī��������˵������ʯ����ڿ��Դ����ջ�ġ�\n",
            "Ī����б����һ�ۣ�����аħ����Ͳ�����ڵ��ˡ�\n",
            "Ī����͵͵�����㣺�����һ��Ҫע�����ܵġ�\n",
            "Ī�����Ժ���˵����ֻ�����䵱�������µ����ڡ�\n",
            "Ī���ȶ�����������������Ա�������Ϊ�������֣�һ��Ҫѧ���¾���\n"
        }));

        create_family("�䵱��", 2, "����");

        setup();
        set("inquiry", ([
           "ʯ��":     "��ʯ����ڿ��Դ����ջ�ġ�",
           "���":     "�����һ��Ҫע�����ܵġ�",
           "������":   "�Ҷ�ʦѧ�����ˣ����������ĵ�ѧ�ķ���"]) );
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
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

        if ((int)ob->query_skill("taiji-shengong", 1) < 30) {
                command("say ���䵱�����ڼ��书���������ڹ��ķ���");
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ����̫�����϶��µ㹦��");
                return;
        }
        if ((int)ob->query("shen") < 1000) {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
}
