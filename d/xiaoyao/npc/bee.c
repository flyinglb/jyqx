// bee.c ¶¾·ä

inherit NPC;

void create()
{
        set_name("¶¾·ä", ({ "dufeng", "bee" }) );
        set("race", "Ò°ÊÞ");
        set("age", 10);
        set("long", "Ò»Ö»É«²Ê°ßìµ´ó¸öÒ°·ä£¬¿´ÆðÀ´²»ºÃÈÇ¡£\n");
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("limbs", ({ "·ä×ì","·äÑü","·ä³á","Î²´Ì" }) );
        set("verbs", ({ "bite", "sting" }) );

        set("combat_exp", 4000+random(1000));

        set_temp("apply/attack", 200);
        set_temp("apply/attack", 80);
        set_temp("apply/damage", 5);
        set_temp("apply/armor", 50);
        setup();
}
