// yelvqi.c Ү����

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("Ү����", ({ "Yelv qi", "yelv", "qi" }));
        set("title", "ȫ��̵ڶ������� ؤ��ڶ�ʮһ������");
        set("gender", "����");
        set("age", 25);
        set("per", 25);
        set("long",
        "�����ͻ��صĴ�Ů������ܽ���ɷ�\n",);

        set("combat_exp", 600000);
        set("shen_type", 1);

        set("max_neili", 2000);
        set("neili", 2000);
        set("jiali", 0);

        set_skill("force", 100);
        set_skill("sword", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("hubo" ,100);
        set_skill("haotian-zhang" ,100);
        set_skill("quanzhen-jian" ,100);
        set_skill("kongming-quan",200);
        map_skill("unarmed","kongming-quan");
        map_skill("strike","haotian-zhang");
        map_skill("sword","quanzhen-jian");
        map_skill("parry","quanzhen-jian");

        create_family("ȫ���", 2, "����");
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 50);

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
