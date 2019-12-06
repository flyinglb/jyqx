//NPC /npc/xiaoqing.c
#include <ansi.h>
inherit NPC;

void greeting(object);
void init();
string inquiry_gao();

void create()
{
	set_name("С��", ( { "qing", "xiao qing" }) );
	set("title", "ҩ��ʦ");
	set("gender", "Ů��" );
	set("age", 16);
	set("long",
	      "���Ǹ��������ɵ�С������ĺ����أ�һϮ���£�ȴҲ�Ե��������¡�\n"
          "С����˷ǳ����顣��Ҫ�Ǹ�����������ͻ������һ�㣡\n"
	     );
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 20);
	set("int", 29);
	set("con", 23);
	set("dex", 22);

	set("max_qi", 130);
	set("max_jing", 120);
	set("neili", 120);
	set("max_neili", 120);

	set("combat_exp", 60000);
	set("score", 1000);

	set_skill("force", 26);
	set_skill("dodge", 23);
	set_skill("unarmed", 24);
	set_skill("parry", 22);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 17);
	set_temp("apply/armor", 10);

	set_temp("dan",0);
	set_temp("times",5);
	create_family("����ɽ��", 5, "����");

       set("inquiry", ([
	    "���ڴ���" : "�⡺���ڴ��롻������õ�����ͷСԺ��ȥ����ˮ�ȡ�\n",
	    "ҩ��" : "ҩ�����Ƕ������Լ����ɣ�\n",
	    "�ߵ���" : (: inquiry_gao :),
	]));

	setup();
	carry_object("/d/baituo/obj/qingpao")->wear();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{

	if( !ob || environment(ob) != environment() ) return;
	if(random(2)==1)
	    {say("С��Ц������˵������λ" + RANK_D->query_respect(ob)
		+ "���������������ˡ�\n");
	     return;
	    }
	  else
	  {say("С��Ц��Ц˵������λ" + RANK_D->query_respect(ob)
		+ "������ɡ� \n");
	     return;
	    }
}

string inquiry_gao()
{
  object ob=this_player();
  if(query_temp("dan")==3) return "��û�����Ѿ��������\n";
  if(query_temp("times")==0) return "ʦ�������Ѿ������������ߵ��ࡻ�ˣ�\n";
  say("��λ" + RANK_D->query_respect(ob)+
    "������˵��ʦ�����������ߵ��ࡻ��\n����",ob);
  switch (query_temp("dan"))
  {
   case 0: write(HIY "��һֻ���ߵ���һֻ���ߵ���\n" NOR);
	   break;
   case 1: write(HIY "����һֻ���ߵ���\n" NOR);
	   break;
   case 2: write(HIY "����һֻ���ߵ���\n" NOR);
	   break;
  }
  return "��֪��λ�������ܰ�����أ�\n";
}

int accept_object(object who, object ob)
{
	object obn;

	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("��û�����������\n");

	if (  (string)ob->query("id") != "qing dan"
		&& (string)ob->query("id") != "jin dan"  )
		    return notify_fail("С�಻��Ҫ���������\n");
	if ( query_temp("times")==0 )
		    return notify_fail("С�������Ѿ��������ߵ��ࡻ�ˡ�\n");
	if ( (string)ob->query("id") == "jin dan" )
		{
			if (query_temp("dan")==2)
			  {message_vision("С��һ���ǽ��ߵ��������ź�
�ض�$N˵���һ������ߵ�����ȱ���ߵ���\n",who);
			   return 0;
			  }
			add_temp("dan",2);
			if (query_temp("dan")==2)
			  { message_vision("С�࿴�����ߵ������˵�����������\n
§��$N�Ĳ���˵���������ߵ��ʹ󹦸���ˣ�\n",who);
			    return 1;
			  }
		}
     if ( (string)ob->query("id") == "qing dan" )
		{
			if (query_temp("dan")==1)
			  {message_vision("С��һ���ǣ������ź�
�ض�$N˵���һ�����ߵ�����ȱ���ߵ���\n",who);
			   return 0;
			  }
			add_temp("dan",1);
			if (query_temp("dan")==1)
			  { message_vision("С�࿴�����ߵ������˵�����������\n
§��$N�Ĳ���˵������ͽ��ߵ��󹦸���ˣ�\n",who);
			    return 1;
			  }
		}
   command("kiss "+(string)who->query("id"));
   write( HIY "ֻ��С���ֽ������ذ���ֻ�ߵ�Ͷ��ҩ���У��ּ���һЩ\n
	  ��֪��ʲô��ҩ�ۣ�Ȼ���ϡ�ﻩ��һҡ���٣����ߵ��ࡻ��\n
	  ���ˡ�\n" NOR );
   message_vision("С������صشս�$N����˵��Щʲô��\n", who);
   tell_object(who,"��͵͵����һ�㡺�ߵ��ࡻ�͸��㣬ʦ�����ᷢ�ֵġ�\n");
   message_vision("С�����������$Nһ�ۣ������ˡ�\n",who);
   obn = new("/d/baituo/obj/shedangao");
   obn->move(who);
   set_temp("dan",0);
   add_temp("times",-1);
   return 1;
}

