// /kungfu/class/xueshan/shengdi.c  ʤ��
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("ʤ��", ({ "sheng di", "sheng", "di" }));
        set("long",@LONG
����һ�����ο��������ɮ�ˣ���ɫ��Į���书��ͬ������ߵ�һ�ˡ�
LONG
        );
        set("title",HIR"Ѫ���ŵ��������"NOR);
        set("gender", "����");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);
        set("combat_exp", 500000);
        set("score", 50000);

        set_skill("lamaism", 50);
        set_skill("literate", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("blade", 100);
        set_skill("dodge", 100);
        set_skill("longxiang", 100);
        set_skill("shenkong-xing", 100);
        set_skill("hand", 100);
        set_skill("dashou-yin", 100);
        set_skill("xue-dao", 100);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");

        create_family("ѩɽ��", 5, "����");
        set("class", "bonze");

        setup();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/clone/weapon/gangdao")->wield();

        add_money("gold",1);
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("gender") != "����")
        {
                command("say �Ҳ���Ůͽ�ܡ�\n");
                return;
        }
        if (ob->query("shen") > -50000)
        {
                command("say �����һ�Ҫ�Ƚ�������ĺ�ɱ�ˡ�\n");
                return;
        }
        if ((int)ob->query_skill("longxiang", 1) < 45)
        {
                command("say ����Ѫ���ţ���ϰ���󹦷�����Ҫ�ġ�\n");
                return;
        }
        command("haha");
        command("recruit " + ob->query("id"));

        ob->set("title", HIR "Ѫ���ŵ���������" NOR);
}
