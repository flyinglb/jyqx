// cat.c
#include <ansi.h>
#include <dbase.h>

inherit NPC;
object me=this_player();
string p_host=me->query("pet/host");
void create()
{
	object me=this_player();

  string p_name,p_id,p_host,host_name;
    int p_lv;
    p_name=me->query("pet/name");
    p_id=me->query("pet/id");
    p_lv=me->query("pet/lv");
    p_host=me->query("pet/host");
    host_name=me->query("pet/host_name");
    set("p_host",p_host);
	set_name(host_name+"的猫咪"+p_name,({p_id}));
	set("combat_exp", (p_lv*p_lv)*20);
   set("max_neili",50+20*p_lv);
   set("neili",50+20*p_lv);
   set("max_qi",50+20*p_lv);
   set("max_jing",50+10*p_lv);
   set("jiali",10);
    
	set("race", "野兽");
	set("age", 1);
     set("value",1);
 	set("long", "它长的虎头虎脑的十分可爱。\n");
	
	set("str", 32);
	set("dex", 36);

	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
        set_skill("unarmed",p_lv*20);
        set_skill("force",p_lv*20);

	set("chat_chance", 6);
	set("chat_msg", ({
  
	"猫咪打了个哈气,『喵』的一声,睡着了。\n",
	"猫咪跑过来,闻了闻你的脚『喵』的叫了一声,样子好可爱。\n",
	"猫咪眼睛一眨一眨的看着你,好象饿了。\n",
    }) );
		
	set_temp("apply/attack", p_lv*50);
	set_temp("apply/armor", p_lv*40);
    set_leader(me);

	setup();
}

/*void die()

{  object host,pet;
  pet=this_object();
  host=find_player(pet->query(p_host));
  tell_object(host,"你的猫咪被人杀死了,你心里好难受。\n");
  host->set("eff_neili",1);
  host->set("eff_jing",1);
  host->set("eff_qi",1);
 }
*/
int init()
{
 add_action("do_attack","attack");
 add_action("do_gokill","gokill");
 add_action("do_stop","stop");
 add_action("do_xunlian","xunlian");
}
int accept_object(object who, object ob)
{
	if (ob ->id ("cat food")){
	message("vision", name() + "小猫喵喵的叫了起来\n",environment());
		return 1;
	}
}
int do_attack(string arg)
{
  object ob;
  object me=this_player();
  
  if(me->query("id")!=p_host)
   return notify_fail("它理都不理你.\n");
     if(!arg||!objectp(ob=present(arg,environment(me))))
  return notify_fail("要它做正常点的事吧!\n");
if(!living(ob))
   return notify_fail("你连它也杀");
  message_vision("你的小猫奋不顾身的向$N扑了过去\n",ob);
  if(!environment(ob)->query("no_fight"))
  fight_ob(ob);
  return 1;
}

 int do_stop(string arg)
{
 object ob;
 object me=this_player();
 if(me->query("id")!=p_host)
  return notify_fail("它理都不理你.\n");

  if(!is_fighting())
   return notify_fail("它现在没和人打斗.\n");
  command("halt");
  return 1;
}

 int do_gokill(string arg)
{
 int i;
 object me,ob;
 object* obj;
 me=this_player();
 if(me->query("id")!=p_host)  
 return notify_fail("它理都不理你.\n");
 if(!arg||!objectp(ob=present(arg,environment(me))))
 return notify_fail("你要它杀谁?\n");
  if(!environment(ob)->query("no_fight"))
  {
	message_vision("小猫咪『喵』的一声,露出一排小白牙,向$N猛扑过去\n",ob);
     remove_call_out("kill_ob");
     call_out("kill_ob",1,ob);
  }
return 1;
}

int do_xunlian(object pet)
{
  object me;
  int p_zhi,p_lv;
  me=this_player();
  if(!pet)
    return notify_fail("你要驯练什么?\n");
  if((int)me->query("neili")<30)
    return notify_fail("你的内力不足,无法驯练它.\n");
  if((int)me->query("qi")<100)
   return notify_fail("你的气不足,无法驯练它.\n");
  if((int)me->query("eff_jing")<25)
   return notify_fail("你的精不足,无法驯练它.\n");
	if((int)me->query("potential")<1)
  return notify_fail("你的潜能不够,无法练猫眯了\n");
	write("你和小猫玩了一会,小猫『喵』的叫了一声。\n");
    
   me->add("neili",-30);
   me->add("qi",-100);
  me->add("eff_jing",-10);
   
   me->add("learned_points",2);
   p_zhi=(int)me->query("pet/value");
   p_zhi++;
   me->set("pet/value",p_zhi);
   p_lv=(int)me->query("pet/lv");
   if(p_zhi>=(p_lv+1)*(p_lv+1))
  {
    p_lv++;
    me->set("pet/lv",p_lv);
write("经过你的驯练小猫的战斗力提高了!\n");
   pet=this_object();
   reload_object(pet);
   me->set("pet/value",0);  
   return 1;
 }
write("小猫变的更灵活了!\n");
   return 1;
}



