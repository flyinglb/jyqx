// yetu.c Ұ��

inherit NPC;

void create()
{
        set_name("Ұ��", ({ "ye tu", "hare" ,"tu"}) );
	set("race", "Ұ��");
	set("age", 5);
        set("long", "һֻ�ÿɰ���СҰ�ã����ƺ�����������������⡣\n");
	set("attitude", "peaceful");
	
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 500);

	set_temp("apply/attack", 2);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 2);
	set_temp("apply/armor", 1);

	setup();
}

void die()
{
	object ob;
	message_vision("$N��ҵĺ��˼��������ˡ�\n", this_object());
        if( random(3) >1 )      {
        	ob = new(__DIR__"turou");
                ob->move(environment(this_object()));
        }
        else    
                message_vision("�����ͻȻ����һֻͺ�գ���$N�����ˡ�\n", this_object());
	destruct(this_object());
}
