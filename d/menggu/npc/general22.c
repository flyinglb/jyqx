#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�ٲ�̨", ({ "subutai" }) );
        set("title", BLU"�Ĺ�"NOR);
        set("gender", "����");
        set("age", 43);
        set("per", 16);
        set("long",
"���ǳɼ�˼���������������͵Ĵ󽫣��ųơ��Ĺ���֮һ��\n");
        set("combat_exp", 100000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 20);
}
