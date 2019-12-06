// /kungfu/class/xueshan/daerba.c  �����
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�����", ({ "daerba huofo", "huofo" }));
        set("long",@LONG
���ǽ��ַ������µĴ���ӡ���÷������洫��
��һ����ɫ���ģ�ͷ��ɮñ��
LONG
        );
        set("title", HIY "���" NOR);
        set("gender", "����");
        set("age", 45);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 2500);
        set("max_jing", 1200);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 50);
        set("combat_exp", 300000);
        set("score", 150000);

        set_skill("lamaism", 80);
        set_skill("literate", 80);
        set_skill("force", 120);
        set_skill("xiaowuxiang", 120);
        set_skill("dodge", 100);
        set_skill("shenkong-xing", 100);
        set_skill("unarmed", 100);
        set_skill("yujiamu-quan", 80);
        set_skill("parry", 100);
        set_skill("sword", 70);
        set_skill("mingwang-jian", 60);

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "mingwang-jian");
        map_skill("sword", "mingwang-jian");

        create_family("ѩɽ��", 3, "���");
        set("class", "bonze");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();

        add_money("gold",1);
}

void attempt_apprentice(object ob)
{

        if ((string)ob->query("gender") != "����") {
                command("say ��ϰ�����ڹ���Ҫ����֮�塣");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
        }

         if ((string)ob->query("class") != "bonze") {
                command("say �ҷ��ŵ����������ࡣ");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
        }

        if ((string)ob->query("family/family_name") != "ѩɽ��")        {
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�ȷǱ��µ��ӣ�������ذɣ�");
                return;
        }

        if ((int)ob->query_skill("lamaism", 1) < 60) {
                command("say ����ѩɽ�£���ϰ�����ķ�����Ҫ�ġ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö�����б��ŵ��ķ���");
                return;
        }

        command("say ������ҵĵ����ˣ�");
        command("recruit " + ob->query("id"));

        ob->set("title", HIY "������" NOR);
}
