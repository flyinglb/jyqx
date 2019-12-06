//tongzi.c
#include <ansi.h>
inherit NPC;
int do_bi(string arg);
void greeting(object);
void init();
void create()
{
	set_name("陪练童子", ({ "tongzi"}) );
	set("gender", "男性" );
	set("age", 16);
	set("long", "这是个陪人练功的陪练童子。\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 21);
	set("int", 21);
	set("con", 21);
	set("dex", 20);

	set("max_qi", 200);
	set("combat_exp", 10000);
	set("score", 500);
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry",20);
	create_family("白驼山派",10,"弟子");
	setup();
}

void init()
{
	object ob;
        add_action("do_bi","bihua");


	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if (((string)ob->query("family/family_name") == "白驼山派")
	    &&ob->query("combat_exp")<10000)
         message_vision(YEL"陪练童子冲着$N"YEL"叫道：快来跟我比划几招。(bihua tongzi)\n"NOR,ob);
}

void attempt_apprentice(object ob)
{
     command("say 我不能收徒。你还是拜李教头吧。\n");
     return;
}

int do_bi(string arg)
{
  object obj,me;
  obj = this_object();
  me = this_player();
  if(!arg||arg!="tongzi") return  notify_fail("你要和谁比划?\n");
  if ((int)me->query("combat_exp")>10000)
   return notify_fail(YEL"陪练童子摇头道：以你的武功,我不能做你的陪练了。\n"NOR);
  message_vision(YEL"陪练童子对$N点了点头说：“好吧！我就陪你练练。\n"NOR,me);
  set("combat_exp",me->query("combat_exp"));
  obj->fight_ob(me);
  me->fight_ob(obj);
  remove_call_out("checking");
  call_out("checking",1,me,obj);
  return 1;
}

void checking(object me,object obj)
{
  if ( me->is_fighting() )
  {
  call_out("checking",1,me,obj);
    return;
  }
  if ( !present(obj, environment()) ) return ;
  if(query("qi")<100)
    message_vision(YEL"陪练童子对$N"YEL"大叫道：「哇噻！你简直酷毙了!」。\n"NOR,me);
  else
    message_vision(WHT"陪练童子对$N"WHT"笑笑道：努力吧。\n"NOR,me);

  set("eff_qi",200);
  set("qi",200);
  set("combat_exp",10000);
  return;
}

int accept_fight(object ob)
{
      if ((string)ob->query("family/family_name") == "白驼山派")
	 {
	  if((int)ob->query("combat_exp")<5000)
            return notify_fail(YEL"陪练童子笑道：你的经验太低了，还是先和我比划吧！(bihua tongzi)\n"NOR);
	  }
    message_vision(YEL"陪练童子对$N"YEL"叫道：那我就不让你了！\n"NOR,ob);
    return 1;
}

