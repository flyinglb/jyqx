//playboy.c
inherit NPC;

void create()
{
	set_name("��������", ({ "playboy" }) );
	set("nickname", "�ɻ����");
	set("gender", "����" );
	set("age", 19);
	set("long", "���Ǹ����������Ļ������ӡ�\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 21);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	
	set("max_qi", 400);
	set("max_jing", 200);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 30000+random(10000));
	set("score", 10000);
	setup();
	add_money("silver", 10);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if(ob->query("gender")=="Ů��")
         {
          if(random(2)==1)
		say(" ��������ɫ����˵��"+RANK_D->query_respect(ob)+
		     "������ô�ż���·���������治����\n");
        else
		say(" �������ӳ�����·�ߵ�Ұ�����ɰײ���~~����λ"+RANK_D->query_respect(ob)+
		     "��˵����\n");
          }

}
