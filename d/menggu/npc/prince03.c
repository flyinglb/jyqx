#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����̨", ({ "wokuotai" }) );
        set("title", CYN"������"NOR);
        set("gender", "����");
        set("age", 24);
        set("per", 26);
        set("long",
"���ǳɼ�˼�������ӣ��غ���ˣ������̳����ɹ���λ��\n");
        set("combat_exp", 5000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10);
}
