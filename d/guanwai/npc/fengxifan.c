// fengxifan.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("������", ({ "feng xifan", "feng" }) );
        set("nickname", HIR"һ����Ѫ"NOR);
        set("gender", "����");
        set("class", "swordsman");
        set("age", 45);
        set("long",
                "����������ƽ�������ӳ��������ɵ�һ���֣�һ�Ű�տտ����Ƥ��\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 2400);
        set("max_neili", 2400);
        set("jiali", 30);
        set("max_qi",2000);
        set("max_jing",1200);

        set("combat_exp", 1000000);
        set("shen", -200000);
        set("apprentice_available", 3);

        set_skill("unarmed", 180);
        set_skill("sword", 160);
        set_skill("force", 160);
        set_skill("parry", 160);
        set_skill("dodge", 160);
        set_skill("literate", 100);
        set_skill("huashan-sword", 180);
        set_skill("kuangfeng-jian", 180);
        set_skill("huashan-neigong", 160);
        set_skill("huashan-ken", 170);
        set_skill("huashan-zhangfa", 170);
        set_skill("huashan-shenfa", 170);

        map_skill("sword", "kuangfeng-jian");
        map_skill("parry", "kuangfeng-jian");
        map_skill("force", "huashan-neigong");
        map_skill("unarmed", "huashan-zhangfa");
        map_skill("dodge", "huashan-shenfa");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
