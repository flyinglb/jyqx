// huanying.c 幻影
#include <ansi.h>
inherit NPC;
void create()
{        set_name("幻影",({"huanying"}));
       set("gender","男性");
       set("age",20);
       set("str",30);
       set("per",20);
       set("combat_exp",1000);
   set("attitude", "friendly");
       set_skill("dodge",10);
        setup();
        carry_object("/d/city/obj/cloth")->wear();
}
void copy_status(object me,object ob)
{
        object *inv;
        mapping skill_status,map_status;
        string *sname,*mname;
       int i;
        me->set("name",ob->query("name"));
        me->set("title",ob->query("title"));
        me->set("nickname",ob->query("nickname"));
        skill_status=me->query_skills();
        sname=keys(skill_status);
        for(i=0;i<sizeof(skill_status);i++) {
                me->delete_skill(sname[i]);
}
        skill_status=ob->query_skills();
        sname=keys(skill_status);
        for(i=0;i<sizeof(skill_status);i++) {
                me->set_skill(sname[i],skill_status[sname[i]]);        }
        if ( mapp(map_status = me->query_skill_map()) ) {
               mname  = keys(map_status);
                for(i=0; i<sizeof(map_status); i++) {
                        me->map_skill(mname[i]);
                }
       }
        map_status = ob->query_skill_map();
        mname  = keys(map_status);
        for(i=0; i<sizeof(map_status); i++) {
                me->map_skill(mname[i], map_status[mname[i]]);
        }
       inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]->query("weapon_prop") && 
inv[i]->query("equipped") ) {
                        inv[i]->unequip();
                        me->set("weapon", 0);
                }
               if( inv[i]->query("armor_prop") && 
inv[i]->query("equipped") ) {
                        inv[i]->unequip();
                        me->set("armor", 0);
                }
        }
        inv = all_inventory(ob);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]->query("weapon_prop") 
                &&  inv[i]->query("equipped") ) {
                       carry_object(base_name(inv[i]))->wield();
                      me->set("weapon", base_name(inv[i]));
                }
                else if( inv[i]->query("armor_prop")                 &&  inv[i]->query("equipped") ) {
                        carry_object(base_name(inv[i]))->wear();
                        me->set("armor", base_name(inv[i]));
                }
        }
   me->set("age",ob->query("age"));
       me->set("str",ob->query("str"));
        me->set("int",ob->query("int"));
       me->set("con",ob->query("con"));
        me->set("per",ob->query("per"));
        me->set("dex",ob->query("dex"));
        me->set("kar",ob->query("kar"));
        me->set("max_qi",ob->query("max_qi"));
        me->set("eff_qi",ob->query("eff_qi"));
        me->set("qi",ob->query("qi"));
        me->set("max_jing",ob->query("max_jing"));
        me->set("eff_jing",ob->query("eff_jing"));
       me->set("jing",ob->query("jing"));
        me->set("max_neili",ob->query("max_neili"));
        me->set("neili",ob->query("neili"));
        me->set("jiali",ob->query("jiali"));
        me->set("max_jingli",ob->query("max_jingli"));
        me->set("jingli",ob->query("jingli"));
      me->set("combat_exp",ob->query("combat_exp")/1);
}
void die()
{
        object env = environment();

        if ( env )
                message("vision",
                HIB + name() + "的影子不见了。\n" NOR,env,
               this_object() );
        destruct(this_object());
}
int heal_up()
{
        object me=this_object();
        object who;

	if( me->query("leader") && environment(me) )
		who = present(me->query("leader"),environment(me) );
        if( environment() && (!is_fighting() || !objectp(who) || 
		!who->is_fighting() )  ) {
		call_out("die", 1);
		return 1;
        }
        if( (int)me->query("time") > 10 ) {
                call_out("die",1);
               return 1;
        }
       add("time", 1);
        return ::heal_up() + 1;
}
void invocation(object who)
{
        int i;
       object me,*enemy;
       me=this_object();
       message("vision",
                HIB "只见"+who->query("name")+"的身体越打越快,就在恍惚之间多了一个"+who->query("name")+"的幻影！\n" NOR,
                environment(),this_object());
        copy_status(me,who);
        enemy=who->query_enemy();
       i=sizeof(enemy);
               if( enemy[i] && living(enemy[i]) ) {                        fight_ob(enemy[i]);
                        if( userp(enemy[i]) ) 
enemy[i]->fight_ob(this_object());
                        else enemy[i]->fight_ob(this_object());
               }
   }
/*       set("leader", (string)who->query("id"));
       set_leader(who);
} */
