#include <ansi.h>

inherit NPC;

void create()
{
        set_name("���̨", ({ "chahetai" }) );
        set("title", CYN"������"NOR);
        set("gender", "����");
        set("age", 27);
        set("per", 22);
        set("long",
"���ǳɼ�˼���Ĵ��ӣ��游�������֣��¹�������\n");
        set("combat_exp", 5000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10);
}
