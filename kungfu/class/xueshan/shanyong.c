// /kungfu/class/xueshan/shanyong.c  ����
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����", ({ "shan yong", "shan", "yong" }));
        set("long",@LONG
һ�����ֵ�����ɮ�ˣ����Ц�ݣ�ȴ����Ц��ص����¡�
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
        set("max_qi", 800);
        set("max_jing", 400);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 50);
        set("combat_exp", 200000);
        set("score", 20000);

        set_skill("lamaism", 50);
        set_skill("literate", 60);
        set_skill("force", 60);
        set_skill("parry", 60);
        set_skill("blade", 60);
        set_skill("dodge", 60);
        set_skill("longxiang", 60);
        set_skill("shenkong-xing", 60);
        set_skill("hand", 60);
        set_skill("dashou-yin", 60);
        set_skill("xue-dao", 30);

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
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("gender") != "����")
        {
                command("say �Ҳ���Ůͽ�ܡ�\n");
                return;
        }
        command("haha");
        command("recruit " + ob->query("id"));

        ob->set("title", HIR "Ѫ���ŵ���������" NOR);
}
