// ����ļ�����/include/globals.h�������� #define PAWN "/feature/pawn"
// Ϊ�����ṩpawn,redeem,redeemp,value,sell,list,buyָ��

// Ϊ�˱���������ף������ڵ�������no_fightΪ1�����ұ�������npc����no_getΪ1
// ��Ϊ��no_fight,��ҾͿ��Դ���npcȻ��steal�����������no_get����ҾͿ�������һЩ����
// ��npc�ѵ������npc���Σ�Ȼ��get���������������ط�steal!

#include <ansi.h>

inherit F_DEALER;

int redeem(string arg);
string getid(string target);
string getname(string number,string target);
void setup()
{
	set("no_get",1);
	set("no_get_from",1);
//	::setup();
}
void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_pawn", "pawn");
	add_action("do_value", "value");
	add_action("do_redeem", "redeem");
	add_action("do_redeemp", "redeemp");//���˵�����
}

int do_pawn(string arg)
{
	object me,ob;
	string str,*nopawn;
	int i,value;
	
	nopawn = ({"coin", "silver","gold","cash",
			"thousand-cash","mailbox","box"});
	if (!arg||arg=="")
		return notify_fail("��Ҫ�䵱ʲô��\n");
	me=this_player();
	if(!objectp(ob=present(arg,me)))
		return notify_fail("��û������������\n");

	if (ob->query("item_origin"))
		return notify_fail("�����ǲ��ܵ��ġ�\n");
	if (ob->query("money_id"))
		return notify_fail("���뵱��Ǯ������\n");
	if (ob->query("food_supply"))
		return notify_fail("ʣ��ʣ���������Լ��ðɡ�\n");
	if(member_array(arg,nopawn)!=-1
		||ob->query("nopawn")==1)
		return notify_fail("�����������ܵ䵱��\n");
	if((ob->query("enpawn")==0)//���������Բ�Ϊ0��˵�����ǿ��Ե��ģ�
		&&(
			ob->query("hunmi")!=0||living(ob)
			||ob->query_temp("block_msg/all")==1
		)
	)
		return notify_fail("��������ǻ��ѽ������ô����湻papaya���ˣ�\n");
	value=ob->query("value");

	/*����һЩ��Ʒ��û������value,�����޷��䵱�������ֺ����ã�������ʱע���⼸��
           ������������ע��enpawn����ҲӦ���ж�һ��
	if(value<30)
		return notify_fail("����ʲô��������ȻҲ�����䵱!\n");
	*/

	//�䵱ֵvalue��60%��
	MONEY_D->pay_player(me, value * 60 / 100);

	//str��������ļ���
	str=base_name(ob);
	str=replace_string(str,"/","\\");		//ע�⣺"\\"��"\"!
	//�����������map���map!


	//����iΪ�ѵ䵱�˵�����,���ǵ�һ���Ƿ�Ϊ0�أ�!!!!!!
	i=me->query("pawn/"+str);

	me->set("pawn/"+str,i+1);  //��������(+1)

	message_vision("$N�ó�"+ob->query("name")+"�䵱��"+
		MONEY_D->price_str(value* 60/100)+"��\n",me);
	destruct(ob);
	return 1;
}

int do_redeemp(string target)
{
	object me,ob,dest;
	me=this_player();
	ob=this_object();
	if(!target||target=="")
		return notify_fail(ob->query("name")+"������Ķ��������ʵ�����Ҫ��ʲô�ˣ�\n");
	if(!objectp(dest=find_player(target)))
		return notify_fail("���("+target+")Ŀǰ�������ϣ�\n");
	if( !dest->query("jackyboy/selled"))
		return notify_fail(ob->query("name")+"��������ɱ����ݺ��ˣ�����ô��Ƿ���Ѻ����أ�\n");
	switch (MONEY_D->player_pay(me, dest->query("per") * 700))
	{
	case 0:
		return notify_fail("��⵰��һ�ߴ���ȥ��\n");
	case 2:
		return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
	default:
		message_vision("$N��$n���������һ" + dest->query("unit") + 
			dest->query("name") + "��\n", me, this_object());
		dest->move(environment(ob));
		dest->set("startroom",base_name(environment(ob)));
		dest->set("jackyboy/selled",0);
		message("vision",
			HIY "ֻ����ವ�һ����һ���������˵ļһ���컨���ϵ���������\n" NOR,
			environment(dest), dest);
		tell_object(dest, "�㱻" + me->query("name") + "���˳�����\n");
	}
	return 1;
}
string getid(string target)
{
	string temp;
	object ob=new(target);
	temp = implode(ob->parse_command_id_list(),",");
	destruct(ob);
	return temp;
}

string getname(string number,string target)
{
	string str1,str2;
	int i;
	//Ϊ��ͳһ��ʽ�����԰�����ansi��ɫ�����ַ�ɾ�������������㳤�ȣ�
	str2 = number+(target)->query("unit")+(target)->query("name");
	str1 = str2;
	str2 = replace_string(str2, BLK,"");
	str2 = replace_string(str2, RED,"");
	str2 = replace_string(str2, GRN,"");
	str2 = replace_string(str2, YEL,"");
	str2 = replace_string(str2, BLU,"");
	str2 = replace_string(str2, MAG,"");
	str2 = replace_string(str2, CYN,"");
	str2 = replace_string(str2, WHT,"");
	str2 = replace_string(str2, HIR,"");
	str2 = replace_string(str2, HIG,"");
	str2 = replace_string(str2, HIY,"");
	str2 = replace_string(str2, HIB,"");
	str2 = replace_string(str2, HIM,"");
	str2 = replace_string(str2, HIC,"");
	str2 = replace_string(str2, HIW,"");
	str2 = replace_string(str2, NOR,"");
	str2 = replace_string(str2, BLINK,"");
	if(strlen(str2)>=30)
		return str1;
	for(i=strlen(str2);i<30;i++)
		str1+=" ";
	return str1;
}

int do_redeem(string target)
{
	object *all,me,ob;
	int i, value,num,snum;
	string term, *terms,str,id;
	mapping env;

	all = users();
	me=this_player();
	env=me->query("pawn");
	if( !mapp(env) || !sizeof(env) )
	{
		write("��û�е����κ���Ʒ��\n");
		return 1;
	}
	if (!target)
	{
		write("��Ŀǰ���˵���Ʒ�У�\n");
		terms = keys(env);
		for(i=0; i<sizeof(terms); i++)
		{
			sscanf(terms[i],"%s",str);
			str=replace_string(str,"\\","/");//�ļ���
			value=me->query("pawn/"+terms[i]);//����
			term=getid(str);//�����е�ID
			printf("%d\t%s %s\n",
				i+1,
				getname(chinese_number(value),str),
				term);
		}
		return 1;
	}
	//numΪҪ�����Ʒ������snumΪͬ��id����Ʒ�ĵڼ�����

	if(sscanf(target,"%d %d",num,snum)!=2)
	{
		if(sscanf(target,"%d %s %d",num,id,snum)!=3)
			if(sscanf(target,"%d %s",num,id)!=2)
				if(sscanf(target,"%s %d",id,snum)!=2)
					if(sscanf(target,"%d",snum)!=1)
					{
						if(sscanf(target,"%s",id)!=1)
							return notify_fail("sorry!\n");
						else
						{
							snum=1;
							num=1;
						}
					}
					else//����ҲҪ���⴦��
					{
						snum--;
						num=1;
						terms = keys(env);
						if(num<=0)
							num=1;
						i=sizeof(terms);
						if(snum>=sizeof(terms))
							return notify_fail("�Բ�����û�������������\n");
						sscanf(terms[snum],"%s",str);
						value=me->query("pawn/"+terms[snum]);
						if(value<num)
							return notify_fail("��û�е�����ô�࣬�ѵ������׬��\n");
						str=replace_string(str,"\\","/");//�ļ���
						if(!objectp(ob=new(str)))
							return notify_fail("����Ҫ�����Ʒ�Ѿ����ٴ����ˡ�\n");
						switch(MONEY_D->player_pay(me,ob->query("value")*num*4/5))
						//���Ҫ��value��80%
						{
						case 0:
							return notify_fail("��⵰��һ�ߴ���ȥ��\n");
						case 2:
							return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
						default:
						}
						message_vision("$N��"+this_object()->query("name")+
							"���ﻨ"+
						MONEY_D->price_str(ob->query("value")*num*4/5)+"����"+
							chinese_number(num)+
							ob->query("unit")+
							ob->query("name")+"��\n",me);
						if(value==num)
							me->delete("pawn/"+terms[snum]);
						else
							me->set("pawn/"+terms[snum],value-num);
						for(i=0;i<num;i++)
							new(str)->move(me);
						return 1;
						
					}
				else
					num=1;
			else
				snum=1;//��������ĳ����
		//else// ȫ����num id snum�Ĵ���
		{
			if(snum<=0)
				snum=1;
			terms = keys(env);
			for(i=0; i<sizeof(terms);i++)
			{
				sscanf(terms[i],"%s",str);
				str=replace_string(str,"\\","/");//�ļ���
				value=me->query("pawn/"+terms[i]);//����
				if(member_array(id,(str)->parse_command_id_list())!=-1)
					snum--;
				if(snum==0)
					break;//�ж�ѭ��
			}
			//�����ʱsnum=0,˵���Ѿ��ҵ��ˣ�������ĿҲ�㹻����ʱstr�ﱣ���и��ļ���
			if(snum==0)
			{
				if(value<num)
					return notify_fail("��û����ô���"+(str)->query("name")+
						"�䵱�����\n");
				if(!objectp(ob=new(str)))
					return notify_fail("����Ҫ�����Ʒ�Ѿ����ٴ����ˡ�\n");
				switch(MONEY_D->player_pay(me,ob->query("value")*num*4/5))
				//���Ҫ��value��80%
				{
				case 0:
					return notify_fail("��⵰��һ�ߴ���ȥ��\n");
				case 2:
					return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
				default:
				}
				message_vision("$N��"+this_object()->query("name")+
					"���ﻨ"+
					MONEY_D->price_str(ob->query("value")*num*4/5)+"����"+
					chinese_number(num)+
					ob->query("unit")+
					ob->query("name")+"��\n",me);
				if(value==num)
					me->delete("pawn/"+terms[i]);
				else
					me->set("pawn/"+terms[i],value-num);			
				for(i=0;i<num;i++)
					new(str)->move(me);
				return 1;
			}
			else //����snum��Ϊ0˵��û����������
				return notify_fail("û����Ҫ��صĶ���������ϸ�����㵱��Щʲô��\n");
		}
	}
	else//����Ҫ���⴦��
	{
		terms = keys(env);
		if(num<=0)
			num=1;
		snum--;
		if(snum>=sizeof(terms))
			return notify_fail("�Բ�����û�������������\n");
		sscanf(terms[snum],"%s",str);
		value=me->query("pawn/"+terms[snum]);
		if(value<num)
			return notify_fail("��û�е�����ô�࣬�ѵ������׬��\n");
		str=replace_string(str,"\\","/");//�ļ���
		if(!objectp(ob=new(str)))
			return notify_fail("����Ҫ�����Ʒ�Ѿ����ٴ����ˡ�\n");
		switch(MONEY_D->player_pay(me,ob->query("value")*num*4/5))
		//���Ҫ��value��80%
		{
		case 0:
			return notify_fail("��⵰��һ�ߴ���ȥ��\n");
		case 2:
			return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
		default:
		}
		message_vision("$N��"+this_object()->query("name")+"���ﻨ"+
		MONEY_D->price_str(ob->query("value")*num*4/5)+"����"+
			chinese_number(num)+
			ob->query("unit")+
			ob->query("name")+"��\n",me);
		if(value==num)
			me->delete("pawn/"+terms[snum]);
		else
			me->set("pawn/"+terms[snum],value-num);
		for(i=0;i<num;i++)
			new(str)->move(me);
		return 1;
	}


	return 0;		
}
	
int do_sell(string arg)
{
	object ob;
	int value;
	
	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("��Ҫ��ʲô��\n");

	if (ob->query("money_id"))
		return notify_fail("��������Ǯ������\n");

	if (stringp(ob->query("no_drop")))
		return notify_fail("����������������\n");

	if (is_vendor_good(arg) != "") 
		return notify_fail("������ò��ã�\n");

	if (ob->query("food_supply"))
		return notify_fail("ʣ��ʣ���������Լ��ðɡ�\n");
	
        if (ob->query("shaolin"))
                return notify_fail("С��ֻ��һ���Դ����ɲ��������������\n");

	if (userp(ob))
	{
		ob->set("value", ob->query("per") * 500);
		CHANNEL_D->do_channel(ob, "rumor",
			sprintf("%s��ĳ�˹�����"+this_object()->query("name")+
				"�ˡ�", ob->name(1)));
	}

	value = ob->query("value");
	if (value < 30)
		write(ob->query("name") + "һ�Ĳ�ֵ��\n");
	else {
		message_vision("$N������һ" + ob->query("unit") + 
		ob->query("name") + "��$n��\n", this_player(), this_object());
		MONEY_D->pay_player(this_player(), value * 70 / 100);
		if ( userp(ob))
		{
			ob->move("/d/dali/storage");
			ob->set("startroom","/d/dali/storage");
			ob->set("jackyboy/selled",1);
		}
		else if (value < 50)
			destruct(ob);
		else
			ob->move(this_object());
	}
	return 1;
}

