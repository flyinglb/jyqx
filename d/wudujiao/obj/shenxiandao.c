// shenxiandao.c

// inherit F_CLEAN_UP;
inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{

	set_name("���ɵ�", ({ "shenxiandao","yao"}) );
	if( clonep() )                       
		set_default_object(__FILE__);
	else {
		set("long",
			"����һ���嶾�̵�ʥҩ�������������޽���ҲҪ���¡�\n
�������(pour)�������ԡ�\n" );
		set("unit", "Щ");
		set("base_value", 200);
		set("base_unit", "��");
		set("base_weight", 30);
		set("value", 800);
	}
	set_amount(1);                     // 21
}

void init()
{
	add_action("do_pour", "pour");
}

int do_pour(string arg)
{
	string  what;
	object ob,me,who,victim;
//     object *inv;
	function f;
       me = this_player();
	if( !arg
	||	sscanf(arg, "%s in %s", who, what)!=2
       ||victim == me)
		return notify_fail("�����ʽ: pour <����> in <��Ʒ>��\n");
	victim = present(who, environment(me));
	if( !victim || victim==me) return notify_fail("û�������¶�����Ŷ��\n");
       if ((string)me->query("family/family_name") != "�嶾��")    
              return notify_fail("�¶���������ô�ܸ���ô���ɵ���Ŷ��\n");
       if ((int)me->query_skill("duji",1) < 50)    
              return notify_fail("����ô�㱾�¾��뺦�ˣ����������嶾�̵���������\n");
	ob = present(what, victim);
	if( !ob )                               // 41
		return notify_fail("�Է�����û��" + what + "����������\n");
//	if( me->query_temp("being_toudu") )
//		return notify_fail("���Ѿ����һ��������ˣ�\n");
	if( ob->query("max_liquid"))
       {
           int myskill = (me->query_skill("duji",1))*10+me->query("neili");
           int skill = victim->query("neili");
           if((int)ob->query("liquid/remaining")<1)
       	    return notify_fail("�Ǹ������ǿյģ����������ܽⶾ�ۣ�\n");
           if (random(myskill)<random(skill))
           {
		tell_object(me, HIR "��⣡��ʧ���ˣ�\n\n" NOR);
		message_vision("$Nһ��ͷ�����÷���$n������$P���ϵ�" + ob->name() + "�¶���\n\n"
			+ "$N�ȵ�������ʲô����\n\n", victim, me);
		if( userp(victim) )
		{
			victim->fight_ob(me);
			me->fight_ob(victim);
		}
		else
		{
			victim->kill_ob(me);
			me->kill_ob(victim);
		}
              me->start_busy(3);
              return 1;
           }
           f = (: call_other, __FILE__, "drink_drug" :);
	    ob->set("liquid/drink_func", bind(f, ob));
	    ob->add("liquid/slumber_effect", 1000);
	    message("vision","����" + victim->name() + "���������͵͵����" + name() + "����������" + ob->name()+ "���档\n", this_player());
	    add_amount(-1);
           me->start_busy(2);
		if( random(myskill) < skill/2 )
			message("vision", "�㿴��" + me->name() + "����������"
				+ victim->name() + "���ϵ�һ" + ob->query("unit")
				+ ob->name() + "��������һЩ"+name()
                           +"��\n", environment(me), ({ me, victim }) );
	     return 1;
       }
       else return notify_fail("��ֻ��������ˮ���棡\n");
       return 1;
  

}

int drink_drug(object ob)
{
	this_player()->apply_condition("slumber_drug",
		(int)this_player()->query_condition("slumber_drug") 
		+ (int)ob->query("liquid/slumber_effect") );
	return 0;
}
