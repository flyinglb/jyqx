// jiang-shangyou.c
// Modified by Venus Nov.1997
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������", ({"jiang shangyou", "jiang", "shangyou"}));
        set("title", "ؤ���������");
        set("gender", "����");
        set("age", 19);
        set("long",
                "����λؤ��������ӣ������Ǹ�Ӣ�����\n");
        set("attitude", "peaceful");
        set("class", "beggar");
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 27);
        set("max_qi", 220);
        set("max_jing", 200);
        set("neili",250);
        set("max_neili", 250);
        set("jiali",25);
        set("combat_exp", 50000);
        set_skill("force", 50);
        set_skill("huntian-qigong", 50);
        set_skill("unarmed", 50);
        set_skill("xianglong-zhang", 50);
        set_skill("dodge", 50);
        set_skill("xiaoyaoyou", 50);
        set_skill("parry", 50);
        set_skill("begging", 50);
        set_skill("checking", 50);
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
