#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�����", ({ "kubilai" }) );
        set("title", BLU"�Ĺ�"NOR);
        set("gender", "����");
        set("age", 40);
        set("per", 12);
        set("long",
"���ǳɼ�˼���������������͵Ĵ󽫣��ųơ��Ĺ���֮һ��\n");
        set("combat_exp", 100000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 20);
}
