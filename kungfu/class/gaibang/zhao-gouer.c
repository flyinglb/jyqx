// zhao-gouer.c
// Modified by Venus Nov.1997
inherit NPC;
inherit F_MASTER;
void create()                                                                   
{
        set_name("�Թ���", ({"zhao gouer", "zhao", "gouer"}));
        set("title", "ؤ��һ������");
        set("gender", "����");
        set("age", 15);
        set("long",
                "����λ��Ʀ�Ƶ�ؤ��һ�����ӣ������Ǹ�С��Ʀ��\n");
        set("attitude", "peaceful");
        set("class", "beggar");
        set("str", 18);
        set("int", 20);
        set("con", 20);
        set("dex", 23);
        set("max_qi", 120);
        set("max_jing", 120);
        set("neili", 150);
        set("max_neili", 150);
        set("jiali", 5);
        set("combat_exp", 2500);
        set_skill("force", 10);
        set_skill("huntian-qigong", 10);
        set_skill("unarmed", 10);
        set_skill("xianglong-zhang", 10);
        set_skill("dodge", 10);
        set_skill("xiaoyaoyou", 10);
        set_skill("parry", 10);
        set_skill("begging", 10);
        set_skill("checking", 10);
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
