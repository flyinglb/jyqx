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
	set_name(host_name+"��è��"+p_name,({p_id}));
	set("combat_exp", (p_lv*p_lv)*20);
   set("max_neili",50+20*p_lv);
   set("neili",50+20*p_lv);
   set("max_qi",50+20*p_lv);
   set("max_jing",50+10*p_lv);
   set("jiali",10);
    
	set("race", "Ұ��");
	set("age", 1);
     set("value",1);
 	set("long", "�����Ļ�ͷ���Ե�ʮ�ֿɰ���\n");
	
	set("str", 32);
	set("dex", 36);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );
        set_skill("unarmed",p_lv*20);
        set_skill("force",p_lv*20);

	set("chat_chance", 6);
	set("chat_msg", ({
  
	"è����˸�����,��������һ��,˯���ˡ�\n",
	"è���ܹ���,��������Ľš������Ľ���һ��,���Ӻÿɰ���\n",
	"è���۾�һգһգ�Ŀ�����,������ˡ�\n",
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
  tell_object(host,"���è�䱻��ɱ����,����������ܡ�\n");
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
	message("vision", name() + "Сè�����Ľ�������\n",environment());
		return 1;
	}
}
int do_attack(string arg)
{
  object ob;
  object me=this_player();
  
  if(me->query("id")!=p_host)
   return notify_fail("����������.\n");
     if(!arg||!objectp(ob=present(arg,environment(me))))
  return notify_fail("Ҫ������������°�!\n");
if(!living(ob))
   return notify_fail("������Ҳɱ");
  message_vision("���Сè�ܲ��������$N���˹�ȥ\n",ob);
  if(!environment(ob)->query("no_fight"))
  fight_ob(ob);
  return 1;
}

 int do_stop(string arg)
{
 object ob;
 object me=this_player();
 if(me->query("id")!=p_host)
  return notify_fail("����������.\n");

  if(!is_fighting())
   return notify_fail("������û���˴�.\n");
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
 return notify_fail("����������.\n");
 if(!arg||!objectp(ob=present(arg,environment(me))))
 return notify_fail("��Ҫ��ɱ˭?\n");
  if(!environment(ob)->query("no_fight"))
  {
	message_vision("Сè�䡺������һ��,¶��һ��С����,��$N���˹�ȥ\n",ob);
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
    return notify_fail("��Ҫѱ��ʲô?\n");
  if((int)me->query("neili")<30)
    return notify_fail("�����������,�޷�ѱ����.\n");
  if((int)me->query("qi")<100)
   return notify_fail("���������,�޷�ѱ����.\n");
  if((int)me->query("eff_jing")<25)
   return notify_fail("��ľ�����,�޷�ѱ����.\n");
	if((int)me->query("potential")<1)
  return notify_fail("���Ǳ�ܲ���,�޷���è����\n");
	write("���Сè����һ��,Сè�������Ľ���һ����\n");
    
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
write("�������ѱ��Сè��ս���������!\n");
   pet=this_object();
   reload_object(pet);
   me->set("pet/value",0);  
   return 1;
 }
write("Сè��ĸ������!\n");
   return 1;
}



