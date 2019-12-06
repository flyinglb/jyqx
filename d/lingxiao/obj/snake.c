//LUCAS 2000-6-18
//snake.c

inherit NPC; 
#include <ansi.h> 

string* sheobj = ({
     "/d/lingxiao/obj/blood"
     "/d/baituo/obj/shepi" 
     "/d/shenlong/obj/shedan"
});

void create()
{
        set_name(HIW"ѩɽ����"NOR, ({ "snake", "she" }) );
        set("race", "Ұ��");
        set("age", 20);
        set("long", "һֻѩɽ����,��ͨ��ѩ��,��������,����������������ĳ�Ѩ��\n");
        set("attitude", "aggressive");
        set("qi", 5000);
        set("max_qi", 5000);
        set("jing", 500);
        set("max_jing", 500);
        set("str", 100);
        set("cor", 90);
        set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 1500000); 

        
        set_temp("apply/attack", 85);
        set_temp("apply/damage", 80);
        set_temp("apply/armor", 88);
        set_temp("apply/defence",80); 

        carry_object("sheobj[random(sizeof(sheobj))]");

        setup();

} 

int hit_ob(object me, object ob, int damage)
{
        if( random(damage) > (int)ob->query_temp("apply/armor")
        &&      (int)ob->query_condition("snake_poison") < 10 ) {
                ob->apply_condition("snake_poison", 40);
        tell_object(ob, HIG "����ñ�ҧ�еĵط�һ����ľ,�����ж��ˣ�\n" NOR );
        }
}


