// hai.c ������
#include <ansi.h>
inherit NPC;
string ask_for_zigong();
string ask_for_jingong();
int do_pretend ( string arg );

void create()
{
	set_name("������", ({"hai gonggong", "hai", "gonggong"}));
	set("title", "����ǧ��");
	set("long",
		"���Ƕ�����̫�ຣ�󸻣���װ�İ������ģ������Ѱ�����֣����ü�����ͷ������̫̫��\n"
	);

	set("gender", "����");
	set("rank_info/respect", "����");

	set("attitude", "heroism");
	set("class", "eunach");

	set("inquiry",([
		"�Թ�"  : (: ask_for_zigong :),
		"����"  : (: ask_for_jingong :),
		"�ʹ�"  : (: ask_for_jingong :),
	]));

	set("age", 60);
	set("shen_type", -1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_qi", 500);
	set("max_jing", 100);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 75000);
	set("score", 5000);
	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("force", 50);
	set_skill("unarmed", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("pixie-jian", 50);

	map_skill("dodge", "pixie-jian");
	map_skill("sword", "pixie-jian");

	setup();
	set("chat_chance", 15);

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/d/city/obj/jiudai");
	carry_object("/d/city2/obj/yaofen");
	add_money("silver", 50);
}

void init()
{
	add_action("do_decide", "decide");
	add_action("do_pretend", "pretend");
}


string ask_for_zigong()
{
	object me;

	me = this_player();

	if( (string)me->query("gender")=="����" )
		return "����ͬ�����ˣ��αؿ�������ĵ���Ц��\n";

	if( (string)me->query("gender") == "Ů��" )
		return "�����ѷϣ���һ�����Ը������С���˴������֣�Ҫ��Ҫ���ԣ�\n";
	if ((int)me->query_str() > 28 )
		return "��λ�ú����ڴ�׳���Թ��а���հ�����ף����ס�\n";

	me->set_temp("pending/zigong", 1);
	return "�Թ�����λ������ò���ã��α�... ����ϣ����������Ǹ����Թ�֮�󣬲��ɺ�ڣ����������Ѷ�(decide)�������ҡ�\n";
}

string ask_for_jingong()
{
	object me;

	me = this_player();

	if( (string)me->query("gender")=="����" )
	return("������Ц������˵�����������ǹ����ˣ���Ȼ���Խ�����\n");          

	if( (string)me->query("gender") == "����" )
	{
	me->set_temp("pending/zigong", 1);
	return("������Ц������˵����������һ��Ҫ�Թ��ſ��Խ��ʹ��ģ�\n"+"���������������Ѷ�(decide)���Ҿͳ�ȫ���㡣\n");
	}

	if( (string)me->query("gender")=="Ů��" )
	return("������ҡͷ�������еģ��㳤��̫���ˡ�\n");                
}


int do_decide()
{
	if( !this_player()->query_temp("pending/zigong") )
		return 0;

	message_vision(
		"$Nһҧ�����������¡���Ů��ұ��ۣ���\n\n"
		"$n��������嵽$N����֮�䣬����һ�࣬����\n\n"
		"$N��ʱ�ҽ�һ�����˹�ȥ����\n\n",
		this_player(), this_object() );
	command("chat �ˡ���");
	command("hehe");
	this_player()->delete_temp("pending/zigong");
	this_player()->delete_temp("pending/jingong");
	this_player()->set("gender","����");
	this_player()->set("class", "eunach");
	this_player()->set("combat_exp",this_player()->query("combat_exp")+1000);
	this_player()->unconcious();
	
	return 1;
}

int accept_object(object me, object ob)
{
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("��û�����������");
	if ( (string)ob->query("name") == "ҩ��") 
	{
	 write(HIC "��������ҩ�������Сָ����ָ������һ���ĩ��\n"
	 +"���ž����ˣ����ǲ�ס���ԡ�\n" NOR);
	       if(objectp(present("xiao", environment(me))))
		{
		command("say ��֣�����ôҲ������ҩ��");   
		}
	       else
		{
		 command("smile "+ob->query("id"));
		 if(me->query_temp("haspretend"))
		 { 
		 command("say ��л����С���ӣ������ںö��� !");
		 me->delete_temp("haspretend");
		 me->set("huanggong\\canenter", 1);
		 }              
		 else command("say ��֣�����ôҲ������ҩ��");   
		}
	}
	else 
	{
		 command("shake ");
		 command("say ���ֶ������Ҫ ! ���������� !");
		 remove_call_out("kill_ob");
		 call_out("kill_ob", 1, this_player());
	}   
	     return 1;
}


int do_pretend ( string arg )
{
   object ob ;
   ob = this_player () ;
   if( !arg && arg!="guizi"&&arg!="xiao"&&arg!="xiao guizi")
     return notify_fail("\n��Ҫװ��˭��\n");
   
if(objectp(present("xiao", environment(ob))))
{
write(HIR "\n���������һ�������ð��С���ӣ����������㣡\n" NOR);
remove_call_out("kill_ob");
call_out("kill_ob", 1, this_player());
return 1;
}
if ( (string) ob -> query ("gender") == "����")
{
ob->set_temp("haspretend",1);
message_vision("\n$Nװ����С���ӣ�$nû������\n",this_player(),this_object());
message_vision("\n����������$Nһ�ۣ�˵�������ǲ����ָó�ҩ�ˣ���\n",this_player());
return 1;
}
}


void die()
{
	say("������������̾���������ϻ�ү���¶���û��ɰ���\n");                 
	message_vision("$N�Һ�һ�������ˣ�\n", this_object());
	::die();
}

