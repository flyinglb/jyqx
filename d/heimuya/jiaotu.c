// jiaotu.c ������̽�ͽ
inherit NPC;
void create()
{
	int age;
	age = 20 + random(10);	
	set_name("������̽�ͽ", ({ "jiao tu", "tu" }));
	set("gender", "����");
	set("age", age);
	set_skill("unarmed", 20);
	set_skill("dodge", 20);	
        set("apply/attack", 20);
	set("apply/defense", 20);
	set("apply/damage", 5);
	set("combat_exp", 550+age*10);
	set("shen_type", 1);
	setup();
	add_money("silver", 10+age/10);
}	
void init()
{        object ob,me,what;
        ::init();
        ob = this_player();
        me = this_object();
        printf("%s aaa\n",what);
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