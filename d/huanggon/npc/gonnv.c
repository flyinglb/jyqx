// gonnv.c
inherit NPC;

void create()
{
        set_name("��Ů", ({ "gong nv", "nv"}) );
        set("gender", "Ů��" );
        set("age", 14+random(10));
        set("long", "����һ����Ů,��ò������,����ͦ�ܸ�.\n");
        set("shen_type", 1);
        set("combat_exp", 3000);
        set("str", 18);
        set("dex", 18);
        set("con", 18);
        set("int", 19);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
