#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

void create()
{
	set_name(MAG "������" NOR, ({ "ziliuma"}));
	set("race", "Ұ��");
	set("gender", "����");
	set("age", 2+random(3));
	set("long", "����һƥ����������ǧ�ҹ�а˰١�\n"+
		"��ҿ���������ȥָ���ĵط�(ride)��\n");
	set("ridable", 1);
	set("int", 30);
	set("qi", 300);
	set("max_qi", 300);
	set("jing", 100);
	set("max_jing", 100);
	set("shen_type", 0);
	set("combat_exp",50000);
	set("attitude", "peaceful");

	set("limbs", ({ "ͷ��", "����", "β��","����","ǰ��" }) );
	set("verbs", ({ "bite","hoof" }) );
	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);

	set("chat_chance", 5);
        set("chat_msg", ({
		MAG"������"NOR"�������꡹һ��˻������ͣ�����Ž��ơ�\n",
                MAG"������"NOR"�ĳ�β�ͺܲ���ʵ�ز�ͣ��˦��˦ȥ��\n",
        }) );

	setup();
}
