// jiaotu.c ������̽�ͽ
inherit NPC;
void create()
{
	int age;
	age = 20 + random(10);	
	set_name("�ɵµ���µ���", ({ "dizi" }));
	set("gender", "����");
	set("age", age);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);	
        set("apply/attack", 40);
	set("apply/defense", 40);
	set("apply/damage", 35);
	set("combat_exp", 5000+age*40);
	set("shen_type", -1);
	setup();
	add_money("silver", 10+age/10);
}	
void init()
{
//        object ob,me,what;
        object ob,me;
        ::init();
        ob = this_player();
        me = this_object();
        if( interactive(ob) && !is_fighting() ) 
        {
                remove_call_out("greeting");
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( "������̣��ճ�������Ψ�Ҳ��ܡ�\n");
                        break;
                
        }
}
