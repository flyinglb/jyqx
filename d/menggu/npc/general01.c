#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������", ({ "hesar" }) );
        set("gender", "����");
        set("age", 49);
        set("per", 18);
        set("long",
"���ǳɼ�˼���ĵܵܣ�һ�������ֳ�������ս��\n");
        set("combat_exp", 100000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 20);
}
