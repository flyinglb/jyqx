#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�ܱ�", ({ "zhebie" }) );
        set("title", BLU"�Ĺ�"NOR);
        set("gender", "����");
        set("age", 39);
        set("per", 26);
        set("long",
"���ǳɼ�˼����������������֣��ųơ��Ĺ���֮һ��\n");
        set("combat_exp", 100000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 20);
}
