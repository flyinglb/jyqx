// by victori
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("ç�����",({"chan chu"}));
	set("race", "Ұ��");
        set("long", "һֻȭͷ��С�����������Ķ���󡡣\n");
	set("age", 1000);
	set("attitude", "peaceful");

	set("max_jing", 500);
	set("max_qi", 500);

	set("str", 30);
	set("con", 50);

	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 70);
       set_skill("unarmed",80);
       set_skill("parry",80);
       set_skill("dodge",80);
       set_skill("force",80);

	set("combat_exp", 150000);
 
        set_weight(5000);
	setup();
}
void init()
{
        object me,who;
        ::init();
        who = this_object();
        if (interactive(me = this_player()))
        {
	if (me->query("id")==who->query_temp("kill_name"))          
              {
	       remove_call_out("kill_ob");
               call_out("kill_ob", 1, me);
		}
        }
       add_action("do_attack","attack");
       add_action("do_stop","stop");
       add_action("do_send","sendto");
       add_action("do_sha","sha");
       add_action("do_guard","guard");
	add_action("do_hit","hit");
	add_action("do_hit","kill");
	add_action("do_hit","touxi");
//	remove_call_out("do_baohu");
//	call_out("do_baohu",5);

}



int do_attack(string arg)
{
  object ob; 
  object me=this_player();
  object who=this_object();
 //  if(query("id")=="shuang er")
 //  {say("����Ȩʹ�ô����\n");
 //  return 0;}
 // sscanf(query("id"),"dushe",host_id);
  if(me->query("id")!=(who->query("host_id")))
  return notify_fail(who->query("name")+"���������㣡\n");
  if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail(who->query("name")+"ɵɵ�������㣬�����������˼��\n");
  if(ob->query("id")==me->query("id"))
	return notify_fail(who->query("name")+"��æ��ͷһ�ͣ��ƺ���Ը��ȥ�ɡ�\n");
  if(!living(ob)) 
	 return notify_fail(who->query("name")+"˵:"
              +ob->query("name")+"�Ѿ��������㻹Ҫ...??!!\n");
  message_vision(who->query("name")+"֨֨�ֽ�һ�����˳�ȥ.\n",me);
  fight_ob(ob);
  return 1;
}

int do_stop()
{
 object who=this_object();
  object me=this_player();
  if(me->query("id")!=(who->query("host_id")))
  return notify_fail(who->query("name")+"���������㣡\n");
 who->set_leader(me);
message_vision("$N��"+who->query("name")+"�ȵ�������ˣ���������\n",me);
// if(!is_fighting())
//	 return notify_fail(who->query("name")+"����û���˴�.\n");
 command("halt");
 who->delete_temp("kill_name");
 message_vision(who->query("name")+"�ԹԵĻص�$N��ߡ�\n",me);
 return 1;
}

int do_sha(string arg)
{
  object who=this_object();
	object me,ob;
	me = this_player();
  if(me->query("id")!=(who->query("host_id")))
  return notify_fail(who->query("name")+"���������㣡\n");
	if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("��Ҫ"+who->query("name")+"ɱ˭��\n");
  if(ob->query("id")==me->query("id"))
	return notify_fail(who->query("name")+"��æ��ͷһ�ͣ��ƺ���Ը��ȥ�ɡ�\n");
	if(!environment(ob)->query("no_fight"))
	{
        message_vision(who->query("name")+"֨֨�ֽ�һ�����˳�ȥ.\n",me);
	command("say �ٺ�,�������ɣ�����Ҫ��ɱ����!");
	who->set_leader(ob);
       who->set_temp("kill_name",ob->query("id"));
	remove_call_out("kill_ob");
  	call_out("kill_ob", 0, ob); 
	}
	return 1;
}       
int hit_ob(object me, object ob, int damage)
{
       if ((string)ob->query("family/family_name") != "�嶾��") {
	     	ob->apply_condition("chanchu_poison", 20
              +(int)ob->query_condition("chanchu_poison") );
              tell_object(ob, HIG "����ñ�ҧ�еĵط�һ����ľ��\n" NOR );
	}
}
void die()
{
       object ob;
       message_vision("$N���ڵ��ϣ����ˣ�\n", this_object());
       ob=new(__DIR__"obj/chanchudu.c");
	ob->move(environment(this_object()));
	destruct(this_object());
      
//       return 1;
//	::die();
}
int do_guard(string arg)            //160
{
  object who=this_object();
       int i ;
	object me,ob;
	object* enemy;
	me = this_player();
       if(me->query("id")!=(who->query("host_id")))
            return notify_fail(who->query("name")+"���������㣡\n");
	if(!arg)
	ob = this_player();
	if(arg){
              if(!userp(present(arg,environment(me))))
	           return notify_fail("��Ҫ"+who->query("name")+"����˭��\n");
              }
	if(arg)
            ob = present(arg,environment(me));
       who->set_temp("guard_ob",ob->query("id"));
 	message("vision",
		 name() + "������΢��֨��������ʼ����"+ob->name()+"�Ĵ����ߣ�\n" NOR,environment(), this_object() );
	enemy = ob->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
       ob->remove_all_killer();
	who->set_leader(ob);
	return 1;
}       
int do_hit(string arg)
{
	object ob = this_object();
	object me = this_player();
	
	if (!arg )  return 0;
       if (arg != ob->query_temp("guard_ob")) return 0;
	message_vision("$Nһ���ֽк�Ȼ������"+me->name()+"����ǰ��\n", this_object());
	remove_call_out("kill_ob");
  	call_out("kill_ob", 0, me); 
	return 1;
}

