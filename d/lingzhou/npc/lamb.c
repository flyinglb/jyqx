// lamb.c Ұ����

#include <command.h>
#include <dbase.h>
#include <origin.h>
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIY"Ұ����"NOR, ({ "lamb" }));
        set("long","һֻҰ��������ͷ����س��Ųݡ�\n");
        set("race", "Ұ��");
        set("age", 5);
        set("int", 30);
        set("ridable", "1");
        set("qi", 300);
        set("max_qi", 300);
        set("jing", 100);
        set("max_jing", 100);
        set("shen_type", 0);
        set("combat_exp",500);
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����", "β��","����","ǰ��" }) );
        set("verbs", ({ "bite","hoof" }) );
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 5);
        set_temp("apply/damage", 15);

        setup();
}

