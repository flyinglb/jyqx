#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������", ({ "zhelemie" }) );
        set("title", BLU"�Ĺ�"NOR);
        set("gender", "����");
        set("age", 42);
        set("per", 14);
        set("long",
"���ǳɼ�˼���������������͵Ĵ󽫣��ųơ��Ĺ���֮һ��\n");
        set("combat_exp", 100000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 20);
}
