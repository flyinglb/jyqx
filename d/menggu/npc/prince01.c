#include <ansi.h>

inherit NPC;

void create()
{
        set_name("׾��", ({ "zhuochi" }) );
        set("title", CYN"������"NOR);
        set("gender", "����");
        set("age", 32);
        set("per", 24);
        set("long",
"���ǳɼ�˼���ĳ��ӣ��������˻��ɲ��ǳɼ�˼����������\n");
        set("combat_exp", 5000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10);
}
