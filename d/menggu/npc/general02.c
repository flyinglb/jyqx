#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��ľ��", ({ "tiemuge" }) );
        set("gender", "����");
        set("age", 45);
        set("per", 14);
        set("long",
"���ǳɼ�˼���ĵܵܣ�һ�������ֳ�������ս��\n");
        set("combat_exp", 100000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 20);
}
