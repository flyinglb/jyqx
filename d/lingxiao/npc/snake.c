//LUCAS 2000-6-18
//snake.c

inherit NPC; 
#include <ansi.h>

void create()
{
        set_name("ѩɽ����", ({ "snake", "she" }) );
        set("race", "Ұ��");
        set("age", 20);
        set("long", HIW"һֻѩɽ����,��ͨ��ѩ��,����"HIR"����"HIW",����������������ĳ�Ѩ��\n"NOR);
        set("attitude", "aggressive");
        set("qi", 8000);
        set("max_qi", 8000);
        set("jing", 5000);
        set("max_jing", 5000);
        set("str",50);
        set("con",50);
        set("dex",50);
        set("int",5);
        set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 3000000);

        
        set_temp("apply/attack", 85);
        set_temp("apply/damage", 80);
        set_temp("apply/armor", 88);
        set_temp("apply/defence",80);

        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("force",100);
        setup();

} 

int hit_ob(object me, object ob, int damage)
{
        if( random(damage) > (int)ob->query_temp("apply/armor")
        &&      (int)ob->query_condition("snake_poison") < 10 ) {
                ob->apply_condition("snake_poison", 40);
        tell_object(ob, HIG"����ñ�ҧ�еĵط�һ����ľ,�����ж��ˣ�\n" NOR );
        }
}

void die()
{
        object ob, corpse;
        message_vision(RED"$N˶��һ����ͷ�߸�̧��,Ȼ������ί�����������ˣ�\n"NOR, this_object());
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        ob = new("/d/lingxiao/obj/blood");
        ob->move(corpse);
        corpse->move(environment(this_object()));
        destruct(this_object());
}

