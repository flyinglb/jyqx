// liu.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
        set_name("������", ({ "liu zhengfeng", "liu" }) );
        set("gender", "����");
        set("class", "swordsman");
        set("long", "һ�������ߡ��������񣬱���һ������������ЩСС��
����֮��������Щ����������ʱͻȻ�Գ�����Ӣ������ʧ
���ַ緶��\n");
        set("age", 45);
        set("attitude", "peaceful");
        set("per", 19);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 30);
        set("max_qi",2000);
        set("max_jing",1200);
        set("combat_exp", 1000000);
        set("shen_type", 1);

        set_skill("unarmed", 120);
        set_skill("sword", 120);
        set_skill("force", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("hengshan-sword", 120);
        set_skill("lingxu-bu", 120);

        map_skill("sword", "hengshan-sword");
        map_skill("parry", "hengshan-sword");
        map_skill("dodge", "lingxu-bu");

        create_family("��ɽ��", 13, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/luo_cloth")->wear();
}

