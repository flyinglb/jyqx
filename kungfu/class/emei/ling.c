// ling.c ������

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������", ({ "zhao lingzhu","zhao","lingzhu"}));
        set("long",
                "���Ƕ����ɵĵ��Ĵ��׼ҵ��ӡ�\n");
        set("gender", "Ů��");
        set("age", 22);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("shen", 10000);
        set("class", "fighter");

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);

        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jingli", 1500);
        set("max_jingli", 1500);

        set("combat_exp", 150000);
        set("score", 1000);
        set_skill("throwing", 30);
        set_skill("persuading", 50);
        set_skill("force", 70);
        set_skill("dodge", 80);
        set_skill("finger", 60);
        set_skill("parry", 80);
        set_skill("strike", 60);
        set_skill("blade", 90);
        set_skill("jinding-zhang", 60);
        set_skill("tiangang-zhi", 60);
        set_skill("yanxing-dao", 90);
        set_skill("zhutian-bu", 80);
        set_skill("linji-zhuang", 70);

        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("blade","yanxing-dao");
        map_skill("parry","yanxing-dao");
        create_family("������", 4, "����");

        setup();
        carry_object("/d/city/obj/gangdao")->wield();
        carry_object("/d/city/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("combat_exp") > 10000) {
                command("say �Ҷ���ע�����ޣ��Ե���Ҫ�������ܼ�į��");
                command("say �ڽ����������棬" + RANK_D->query_respect(ob) +
                        "�����ḻ���Ƿ����ڶ����޵���");
                return;
        }
        if ((int)ob->query("shen") < 0) {
                command("say �Ҷ������������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
}
