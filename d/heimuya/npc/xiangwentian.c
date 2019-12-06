// xiang wentian.c
#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);
string ask_me();

void greeting(object);
void init();
void create()
{
        set_name("向问天", ({"xiang wentian", "xiang" }) );
        set("nickname", HIB"天王老子"NOR );
        set("gender", "男性" );
        set("age", 55);
        set("long", "他面露豪气，全身肌肉虬筋突起，太阳穴高高隆起，一看既知是内外兼修的高手。\n");
        set("attitude", "friendly");
        set("shen_type", 1);

        set("str", 30);
        set("int", 25);
        set("con", 22);
        set("dex", 29);

        set("max_qi", 3000);
        set("max_jing", 1500);
        set("neili", 3000);
        set("max_neili", 3000);
        set("combat_exp", 500000);
        set("score", 30000);
        set("jiali", 50);
        set_skill("force", 140);
        set_skill("dodge", 120);
        set_skill("unarmed", 120);
        set_skill("parry", 120);
        set_skill("claw", 120);
        set_skill("blade",100);
        set_skill("xixing-dafa", 100);
        set_skill("sougu", 120);
        set_skill("tiyunzong", 120);
        set_skill("taiji-dao", 100);

        map_skill("force", "xixing-dafa");
        map_skill("dodge", "tiyunzong");

        map_skill("parry", "sougu");
        map_skill("blade", "taiji-dao");


        create_family(HIW"日月神教"NOR,2,"弟子"+HIB" 光明右使"NOR );

     set("inquiry", ([
                "日月神教" :  "\n只要是英雄好汉，都可以入我日月神教(join riyueshenjiao)。\n",
                "入教" :  "\n一般人是入不了我日月神教的(join riyueshenjiao).\n",         	]) );

        set("chat_chance", 2);
        set("chat_msg", ({
                "向问天突然豪气风发得说: 任教主这次重出江湖，定能夺回日月神教教主之位！\n"
          }) );
        setup();
         carry_object(__DIR__"obj/dadao")->wield();
         carry_object(__DIR__"obj/cloth")->wear();

}
void init()
{
	add_action("do_join","join");
}

#include "/d/heimuya/npc/riyueshenjiao.h"; 
