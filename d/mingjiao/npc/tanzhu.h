// tanzhu.h for join mingjiao 

int do_join(string arg)
{
	object me, ob, obj;
	mapping party;

	me = this_object () ;
	ob = this_player () ;

	if( !arg || arg!="mingjiao" )
		return notify_fail("��Ҫ����ʲô��֯��\n"); 
   	if( ob->query_temp("have_letter") || present("tuijian xin1", ob ))
   	{
                command("say �ð���");
                command("heihei "+ob->query("id") );
//                command("get xin1 from "+ob->query("id") );
		return 1;	
	}
//	if (ob->query("weiwang")>49)
//	{
//		message_vision("$Nҡҡͷ����$n˵�������Ѿ�������ػ��ˣ��������������̡�\n",me,ob);
//		return 1;
//	}
//	if(ob->query("shenlongjiao")) 
//	{
//		message_vision("$Nҡҡͷ����$n˵�������Ѿ������������ˣ��������������̡�\n",me,ob);
//		return 1;
//	}
   	if( !mapp(party = ob->query("party")) )
   	{
		message_vision("$N���ͷ����$n˵�����ã��㵽����ɽ�ܶ�ȥ�ҽ���ʹ�ߣ�����������̵ġ�\n",me,ob);
		message_vision("$N����$nһ���Ƽ��š�\n", me, ob);
		ob->set_temp("have_letter",1);
                obj=new("/d/mingjiao/obj/tuijianxin-1");
		obj->move(ob);
		return 1;	
	}
   	if( party["party_name"] != HIG "����" NOR )
	{
		message_vision("$Nҡҡͷ����$n˵�������Ѿ�������������ˣ��������������̡�\n",me,ob);
		return 1;
	}
	else
		message_vision("$Nҡҡͷ����$n˵�������Ѿ��������̵����ˡ�\n",me,ob);
	return 1;
}

#include "mingjiao.h"
