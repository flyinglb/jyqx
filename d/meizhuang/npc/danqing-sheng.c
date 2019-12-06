// danqing-sheng.c 
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("������", ({ "danqing sheng", "sheng" }));
        set("title", "÷ׯ��ׯ��");
        set("long",
                "������÷ׯ��λׯ�����е��ĵĵ�������\n"
                "��һ���ɸɾ�������ɫ���ۡ�\n"
                "����������Ѯ������ݳ���������⡣�񵭳�ͣ���Ĭ���ԡ�\n");
        set("gender", "����");
        set("age", 40);
        set("class", "scholar");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 300000);
        set("shen", 15000);
        set("score", 60000);

        set_skill("force", 100);
        set_skill("wuzheng-xinfa", 120);
        set_skill("dodge", 100);
        set_skill("piaoyibu", 110);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("wuyun-jianfa", 100);
        set_skill("literate", 130);

        map_skill("force", "wuzheng-xinfa");
        map_skill("dodge", "piaoyibu");
        map_skill("parry", "wuyun-jianfa");
        map_skill("sword", "wuyun-jianfa");

        create_family("÷ׯ", 1, "ׯ��");

        set("inquiry", ([
                "����" : (: ask_me :),
        ]));

        set("item_count", 1);

        setup();
        carry_object("/clone/weapon/changjian")->wield();

}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") < 0) {
                command("say ��÷ׯ��Ȼ����ʲô��������, ����ͽҲ��Ϊ�ϸ�");
                command("say ��Ʒ�з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
        if ((int)ob->query_skill("wuzheng-xinfa") < 30) {
                command("say ���ǲ�������ͽ�ġ�");
                command("say ����÷ׯ���ڹ��ϣ�" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö��µ㹦��");
                return;
        }
        command("say �ðɣ����¾��������ˡ�");
        command("recruit " + ob->query("id"));
}

string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "÷ׯ")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("item_count") < 1)
                return "�������ˣ�÷�����Ʋ��ڴ˴���";
        add("item_count", -1);
        ob = new(__DIR__"obj/lingpai");
        ob->move(this_player());
        return "�ðɣ����÷�����ƾͽ����㱣���ˡ�";
}

