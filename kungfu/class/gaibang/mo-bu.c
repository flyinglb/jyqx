// mo-bu.c
// Modified By Venus. Nov.1997
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("Ī����", ({"mo bushou", "mo", "bushou"}));
        set("title", "ؤ����������");
        set("gender", "����");
        set("age", 17);
        set("long",
                "����λؤ���������ӣ������Ǹ��ܳԵÿ���һ��������\n");
        set("attitude", "peaceful");
        set("class", "beggar");
        set("str", 21);
        set("int", 20);
        set("con", 20);
        set("dex", 23);
        set("max_qi", 140);
        set("max_jing", 140);
        set("neili", 180);
        set("max_neili", 180);
        set("jiali", 15);
        set("combat_exp", 18000);
        set_skill("force", 40);
        set_skill("huntian-qigong", 40);
        set_skill("unarmed", 40);
        set_skill("xianglong-zhang", 40);
        set_skill("dodge", 40);
        set_skill("xiaoyaoyou", 40);
        set_skill("parry", 40);
        set_skill("begging", 40);
        set_skill("checking", 40);
        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");

        create_family("ؤ��", 20, "����");
        setup();
       carry_object(__DIR__"obj/beggar-cloth")->wear();
}
void attempt_apprentice(object ob)
{
        if( ob->query("gender") != "����") return;
        command("say �ðɣ�ϣ�����ܺú�ѧϰ�����书������Ϊؤ����һ��������");
        command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
