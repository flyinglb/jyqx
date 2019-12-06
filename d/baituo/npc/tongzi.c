//tongzi.c
#include <ansi.h>
inherit NPC;
int do_bi(string arg);
void greeting(object);
void init();
void create()
{
	set_name("����ͯ��", ({ "tongzi"}) );
	set("gender", "����" );
	set("age", 16);
	set("long", "���Ǹ���������������ͯ�ӡ�\n");
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
	create_family("����ɽ��",10,"����");
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
	if (((string)ob->query("family/family_name") == "����ɽ��")
	    &&ob->query("combat_exp")<10000)
         message_vision(YEL"����ͯ�ӳ���$N"YEL"�е����������ұȻ����С�(bihua tongzi)\n"NOR,ob);
}

void attempt_apprentice(object ob)
{
     command("say �Ҳ�����ͽ���㻹�ǰ����ͷ�ɡ�\n");
     return;
}

int do_bi(string arg)
{
  object obj,me;
  obj = this_object();
  me = this_player();
  if(!arg||arg!="tongzi") return  notify_fail("��Ҫ��˭�Ȼ�?\n");
  if ((int)me->query("combat_exp")>10000)
   return notify_fail(YEL"����ͯ��ҡͷ����������书,�Ҳ�������������ˡ�\n"NOR);
  message_vision(YEL"����ͯ�Ӷ�$N���˵�ͷ˵�����ðɣ��Ҿ�����������\n"NOR,me);
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
    message_vision(YEL"����ͯ�Ӷ�$N"YEL"��е��������磡���ֱ�����!����\n"NOR,me);
  else
    message_vision(WHT"����ͯ�Ӷ�$N"WHT"ЦЦ����Ŭ���ɡ�\n"NOR,me);

  set("eff_qi",200);
  set("qi",200);
  set("combat_exp",10000);
  return;
}

int accept_fight(object ob)
{
      if ((string)ob->query("family/family_name") == "����ɽ��")
	 {
	  if((int)ob->query("combat_exp")<5000)
            return notify_fail(YEL"����ͯ��Ц������ľ���̫���ˣ������Ⱥ��ұȻ��ɣ�(bihua tongzi)\n"NOR);
	  }
    message_vision(YEL"����ͯ�Ӷ�$N"YEL"�е������ҾͲ������ˣ�\n"NOR,ob);
    return 1;
}

