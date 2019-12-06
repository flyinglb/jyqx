// tubi-weng.c
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("ͺ����", ({ "tubi weng", "weng" }));
        set("title", "÷ׯ��ׯ��");
        set("long",
                "������÷ׯ��λׯ�����е�����ͺ���̡�\n"
                "��һ���ɸɾ����İ�ɫ���ۡ�\n"
                "����������Ѯ����İ�С�����Ϲ��, һ����֪���Ǹ����׶�ŭ���ˡ�\n");
        set("gender", "����");
        set("age", 52);
        set("class", "scholar");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 2000);
        set("max_jing", 2000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 80);
        set("combat_exp", 1000000);
        set("shen", 15000);
        set("score", 60000);

        set_skill("force", 120);
        set_skill("wuzheng-xinfa", 120);
        set_skill("dodge", 100);
        set_skill("piaoyibu", 110);
        set_skill("parry", 120);
        set_skill("dagger", 200);
        set_skill("shigu-bifa", 140);
        set_skill("literate", 130);

        map_skill("force", "wuzheng-xinfa");
        map_skill("dodge", "piaoyibu");
        map_skill("parry", "shigu-bifa");
        map_skill("dagger", "shigu-bifa");

        create_family("÷ׯ", 1, "ׯ��");

        setup();
//        carry_object("/clone/weapon/panguan-bi")->wield();
        carry_object(__DIR__"obj/panguan-bi")->wield();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query_skill("wuzheng-xinfa") < 40) {
                command("say ���ǲ�������ͽ�ġ�");
                command("say ����÷ׯ���ڹ��ϣ�" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö��µ㹦��");
                return;
        }
        command("say �ðɣ����¾��������ˡ�");
        command("recruit " + ob->query("id"));
}

