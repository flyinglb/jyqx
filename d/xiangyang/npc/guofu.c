// guofu.c
inherit NPC;
inherit F_MASTER;

void create()
{
    set_name("��ܽ", ({"guo fu", "guo", "fu"}));
    set("gender", "Ů��");
    set("age", 19);
    set("long", "���ǹ������صĴ�Ů������а��ҩʦ�Ĵ�����Ů�������绨����\n");

    set("attitude", "peaceful");
       
    set("per", 30);
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);

    set("qi", 1000);
    set("max_qi", 1000);
    set("jing", 500);
    set("max_jing", 500);
    set("neili", 500);
    set("max_neili", 500);
    set("jiali", 0);
       
    set("combat_exp", 50000);
    set("score", 0);
       
    set_skill("force", 60);
    set_skill("bibo-shengong", 60);
    set_skill("unarmed", 60);
    set_skill("luoying-zhang", 60);
    set_skill("dodge", 80);
    set_skill("anying-fuxiang", 60);
    set_skill("parry", 60);
    set_skill("sword", 60);
    set_skill("luoying-shenjian", 60);
    set_skill("qimen-wuxing", 60);
       
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
       
    setup();
    carry_object("/kungfu/class/taohua/obj/ruanwei")->wear();
    carry_object("/kungfu/class/taohua/obj/shudai")->wear();

}

