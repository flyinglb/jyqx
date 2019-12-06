// /tengyilei.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��һ��", ({ "teng yilei", "teng" }));
        set("long",@LONG
���ǹ�����ħ�еĴ�ħ��һ�ס�����һֻ����ͭ�ˣ��������ǲ��ᡣ
LONG );
        set("nickname", HIY "�����ħ" NOR);
        set("gender", "����");
        set("age", 46);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 50);
        set("int", 20);
        set("con", 30);
        set("dex", 20);
        set("max_qi", 1500);
        set("max_jing", 500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 100);
        set("combat_exp", 180000);
        set("score", 20000);

        set_skill("force", 80);
        set_skill("xiaowuxiang", 50);
        set_skill("dodge", 50);
        set_skill("shenkong-xing", 60);
        set_skill("unarmed", 90);
        set_skill("yujiamu-quan", 40);
        set_skill("parry", 60);
        set_skill("hammer", 100);
        set_skill("riyue-lun", 100);

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "riyue-lun");
        map_skill("hammer", "riyue-lun");

        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object(__DIR__"obj/tongren")->wield();
        add_money("silver",50);
}

