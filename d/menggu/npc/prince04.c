#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����", ({ "tuolei" }) );
        set("title", CYN"������"NOR);
        set("gender", "����");
        set("age", 21);
        set("per", 27);
        set("long",
"���ǳɼ�˼�������ӣ������ҵĸ��ף����⽻�ֶ�������\n");
        set("combat_exp", 5000);
        set("attitude", "piece");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10);
}
