// by victori
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("��Ѫ֩��",({"zhi zhu"}));
	set("race", "Ұ��");
        set("long", "һֻȭͷ��С��ȫ����ë�Ķ�֩�롣\n");
	set("age", 1000);
	set("attitude", "peaceful");

	set("max_jing", 500);
	set("max_qi", 500);

	set("str", 30);
	set("con", 50);

	set("limbs", ({ "ͷ��", "����", "����" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
       set_skill("unarmed",80);
       set_skill("parry",80);
       set_skill("dodge",80);
       set_skill("force",80);
	set("combat_exp", 150000);
 
        set_weight(500000);
	setup();
}
void init()
{
//        object me, ob;
        object me;
        add_action("do_xun", "xun");
        if (interactive(me = this_player()))
        {
      	       remove_call_out("kill_ob");
              call_out("kill_ob", 1, me);
        }
        ::init();
}
int do_xun(string arg)
{
	object me,who;
	me =this_object();
	who=this_player();
	if (!arg || (arg != "zhi zhu"))
		return notify_fail("��Ҫѱ��ʲô��\n");
	if(me->is_fighting())
		return notify_fail("��ֻ֩������ս����\n");
	if((string)who->query("family/family_name")!="�嶾��")
		return notify_fail("ʲô��\n");
	
	message_vision("$N��$nһ���Х���󵨣�����ѱ��������ʱ��\n\n", who,me);
	message_vision("$N��Ȼ��ŭ��������˭ѱ˭����һ���ġ�\n
��������$nŤ��һ��\n",me,who);
	me->kill_ob(who);
	who->kill_ob(me);
        COMBAT_D->do_attack(me, who, query_temp("weapon"));
	me->set("owner",who->query("id"));
	return 1;
}

void die()
{
	string owner,name;
	object owner_ob;            
       object ob;
	owner = query("owner");
	if(owner) owner_ob= find_player(owner);
	if(owner_ob &&  (object)query_temp("last_damage_from") == owner_ob ) {
		message_vision("$Nſ�ڵ��ϣ�һ��Ҳ���Ҷ��ˡ�\n",this_object());
	ob=new(__DIR__"zhizhu2.c");
	ob->move(environment(owner_ob));
	ob->set_leader(owner_ob);
       ob->set("host_id",owner_ob->query("id"));
       name=this_object()->query("name");
       ob->set_name(name,({"zhi zhu"}));
	destruct(this_object());

	return;
	}
       else {
            message_vision("$N���ڵ��ϣ����ˣ�\n", this_object());
            ob=new(__DIR__"obj/zhizhudu.c");
	      ob->move(environment(this_object()));
	      destruct(this_object());
       }
//     return 1;
//	::die();
}

int hit_ob(object me, object ob, int damage)
{
       if ((string)ob->query("family/family_name") != "�嶾��") {
	     	ob->apply_condition("zhizhu_poison", 20
              +(int)ob->query_condition("zhizhu_poison") );
              tell_object(ob, HIG "����ñ�ҧ�еĵط�һ����ľ��\n" NOR );
	}
}

