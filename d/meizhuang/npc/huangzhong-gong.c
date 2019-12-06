// huangzhong-gong.c
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("���ӹ�", ({ "huangzhong gong", "gong" }));
        set("title", "÷ׯ��ׯ��");
        set("long",
                "������÷ׯ��λׯ�����е�һ�Ļ��ӹ���\n"
                "��һ���ɸɾ����Ļ�ɫ���ۡ�\n"
                "����������Ѯ������еȣ����ݺͰ����ס�\n");
        set("gender", "����");
        set("age", 62);
        set("class", "scholar");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 100);
        set("combat_exp", 500000);
        set("shen", 15000);
        set("score", 60000);

        set_skill("force", 150);
        set_skill("wuzheng-xinfa", 150);
        set_skill("dodge", 150);
        set_skill("piaoyibu", 150);
        set_skill("parry", 150);
        set_skill("sword", 150);
        set_skill("wuyun-jianfa", 150);
        set_skill("literate", 100);

        map_skill("force", "wuzheng-xinfa");
        map_skill("dodge", "piaoyibu");
        map_skill("parry", "wuyun-jianfa");
        map_skill("sword", "wuyun-jianfa");
        create_family("÷ׯ", 1, "ׯ��");
        setup();
        carry_object("clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query_skill("wuzheng-xinfa") < 50) {
                command("say ���ǲ�������ͽ�ġ�");
                command("say ����÷ׯ���ڹ��ϣ�" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö��µ㹦��");
                return;
        }
        command("say �ðɣ����¾��������ˡ�");
        command("recruit " + ob->query("id"));
}

