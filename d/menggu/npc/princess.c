#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����", ({ "huazheng" }) );
        set("title", MAG"����"NOR);
        set("gender", "Ů��");
        set("age", 18);
        set("per", 27);
        set("long",
"���ǳɼ�˼����Ů�������������÷����֮�ꡣ\n");
        set("combat_exp", 3000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10);
}
