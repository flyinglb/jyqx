// fengas.c
// edward.2000.3

inherit NPC;
//inherit F_MASTER;

#include <ansi.h>

string ask_me();

void create()
{
        set_name(HIC"冯阿三"NOR, ({ "feng asan", "feng" }));
        set("long", 
                "据说他就是鲁班的后人，当代的第一巧匠，设计机关的能手。\n");
        set("gender", "男性");
        set("age", 40);
        set("attitude", "friendly");
        set("class", "alchemist");
        set("shen_type", 1);
        set("str", 38);
        set("int", 28);
        set("con", 30);
        set("dex", 28);

        set("inquiry", ([
                "机关":(:ask_me:),
        ]) );

        set("max_qi", 600);
        set("max_jing", 600);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 30);
        set("combat_exp", 100000);
        set("score", 20000);

        set_skill("blade",50);
        set_skill("ruyi-dao",50);
        set_skill("force", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("lingboweibu", 50);
        set_skill("beiming-shengong",50);
        set_skill("liuyang-zhang", 50);

        map_skill("unarmed", "liuyang-zhang");
        map_skill("dodge", "lingboweibu");
        map_skill("force", "beiming-shengong");
        map_skill("blade", "ruyi-dao");

        create_family("逍遥派", 3, "弟子");
        set("title","逍遥派"MAG"“函谷八友”"NOR);
        set("nickname",HIY"巧匠"NOR);
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/blade")->wield();

}

string ask_me()
{

        if (random(100)<70)
                return "我在设计机关方面是有点特长，让大家见笑了。";   
        command("laugh");
        return "别吵着我，我在看书呢。哈哈，"HIY"芝麻开门"NOR"。。。。这书真好笑\n";
}
