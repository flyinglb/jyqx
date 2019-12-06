// daoseng.c
inherit NPC;

void create()
{
        set_name("��ɮ", ({"daoseng","walker",}));
        set("title", "���ֵ�ɮ");
        set("long",
                "����һλ�����ķ������ߣ���˪���棬��ɫ�Ҵң��ƺ����ڰ�һ�����¡�\n"
        );

        set("gender", "����");
        set("attitude", "heroism");
        set("class", "bonze");

        set("age", 35);
        set("shen_type", 1);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);
        set("combat_exp", 200000);
        set("score", 100);
        set("apply/attack",  30);
        set("apply/defense", 30);

        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("blade", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("shaolin-shenfa", 100);
        set_skill("xiuluo-dao", 100);
        set_skill("hunyuan-yiqi", 100);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("blade", "xiuluo-dao");
        map_skill("parry", "xiuluo-dao");

        setup();
        carry_object("/d/city/obj/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}

void init()
{
        object me,ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();

        if (interactive(ob)
        && !environment(ob)->query("no_fight") && ob->query("gender")=="����"
        && ( (fam = ob->query("family")) && fam["family_name"] != "������" && ob->query("class") == "bonze") )
        {
                command("say ������޳�������ͽ���������ɣ�����\n");
                me->set_leader(ob);
                me->kill_ob(ob);
                ob->fight_ob(me);
        }
}
