// liujing.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
        set_name("��ݼ", ({ "liu jing", "jing" }) );
        set("gender", "Ů��");
        set("class", "swordsman");
        set("long", "�����������Ů����\n");
        set("age", 17);
        set("attitude", "peaceful");
        set("per", 29);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 10);
        set("max_qi",700);
        set("max_jing",200);
        set("combat_exp", 100000);
        set("shen_type", 1);

        set_skill("unarmed", 40);
        set_skill("sword", 40);
        set_skill("force", 40);
        set_skill("parry", 40);
        set_skill("dodge", 40);
        set_skill("hengshan-sword", 40);
        set_skill("lingxu-bu", 40);

        map_skill("sword", "hengshan-sword");
        map_skill("parry", "hengshan-sword");
        map_skill("dodge", "lingxu-bu");

        create_family("��ɽ��", 14, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/female1-cloth")->wear();
}

