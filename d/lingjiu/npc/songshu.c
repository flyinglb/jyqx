//songshu.c
inherit NPC;

void create()
{
        set_name("����", ({ "song shu", "shu" }) );
        set("race", "Ұ��");
        set("age", 2);
        set("long", "һֻ�ɰ�������\n");
        set("attitude", "peaceful");
 
        set("str", 15);
        set("cor", 16);

        set("limbs", ({ "ͷ��", "����", "צ��", "β��" }) );
        set("verbs", ({ "bite" }) );
 
        set("combat_exp", 300);

        set_temp("apply/attack", 5);
        set_temp("apply/damage", 3);
	set_temp("apply/defence",5);
	set_temp("apply/armor",3);

	setup();
}
