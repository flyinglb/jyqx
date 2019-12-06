// kuai-huosan.c
// Modified by Venus Nov.1997
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("�����", ({"kuai huosan", "kuai", "huosan"}));
        set("title", "ؤ���Ĵ�����");
        set("gender", "����");
        set("age", 18);
        set("long",
                "����λؤ���Ĵ����ӣ������Ǹ����е�������ˡ�\n");
        set("attitude", "peaceful");
        set("class", "beggar");
        set("str", 22);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 180);
        set("max_jing", 190);
        set("neili",200);
        set("max_neili", 200);
        set("jiali", 20);
        set("combat_exp", 32000);
        set_skill("force", 45);
        set_skill("huntian-qigong", 45);
        set_skill("unarmed", 45);
        set_skill("xianglong-zhang", 45);
        set_skill("dodge", 45);
        set_skill("xiaoyaoyou", 45);
        set_skill("parry", 45);
        set_skill("begging", 45);
        set_skill("checking", 45);
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
