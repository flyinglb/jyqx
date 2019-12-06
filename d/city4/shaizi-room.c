/*  <SecCrypt CPL V3R05>  */
 
//standroom.c  used  by  weiqi...others  may  hate  this  format:D
//shaizi-room.c...weiqi,  98/01/17
//allow  ��ׯ����ע�ȡ�

inherit  ROOM;

int  round  =  0;  //this  indicates  how  many  games  processed.
int  ask_for_zhuang  =  0;

int  game_status  =  0;
//=0,  no  game  yet.
//=1,  zhuang-jia  determined.
//=2,  zhuang-jia  typed  "start",  begin  bet  process.
//=3,  bet  finished...zhuang-jia  used  "bet  ***"  to  put  on  money,  now  game  processing.
//return  to  0,  game  finished.
//if  zhuang-jia  retire,  return  to  0.

string  zhuang_id  =  "no  zhuang";  //zhuang-jia's  id.

int  total_bet  =  0;//total  money  on  table,  in  unit  of  silver.

int  max_bet  ;  //max  bet  each  round,  determined  by  zhuang-jia.  

void  pay_player(object  me,  int  total);
int  pay_out(object  me,  int  total);
int  check_silver(object  me);
void  game_process();
void  show_shaizi(object  me);
void  game_result();
void  check_finish(int  previous_round);
void  check_start(int  previous_round);

void  create  ()
{
	set  ("short",  "���ӷ�");
	set  ("long",  @LONG
���м����һ�ſ������൱��ʵ�Ĵ�����(table)������Χ��
ʮ���ѿ���ľ�Ρ�����ǽ����һ������(paizi)��
LONG);

	set("item_desc",  (["paizi"  :  "

�����ӹ���
ÿһ���и�ׯ�ң���Ӯֻ��ׯ�ұȡ��������ӣ��ɶ�Ϊ��ʮ����С��
����˳��
һ��ȷ��ׯ��(��zz��zuozhuang��ׯ��retire��rz,  rangzhuang��ׯ)��
����ׯ����������(start  <��ע����>)��
���������ע(bet��xz,  xiazhu)��
�ģ�ׯ����ע(bet��xz,  xiazhu)������ҪѺ�����ҵ��ܺ͡�
�壬ׯ����ע�Ϳ����ˡ�

ע�����
һ�����в�Ҫ�뿪�ĳ�������һ����ʧ�Ų�����
������ׯʱҪ���ó��������ӵı�֤����ׯʱ�˻�����������ׯ(��
������;�뿪��)��֤���Զ�ʧȥ��
����ÿһ�ִ�ׯ������������ʮ����֮�ڱ�����ɣ�����ȡ��������
������ׯ������֮ע�ɱ��˻أ���ׯ������ܻ�����ʧ��
�ģ����ׯ�ҳٳٲ��������̣���ҿ�����ׯ(zz)ָ��Ҫ��ׯ��
����Ҫ��ׯ����������ׯ�ұ����������̣�����ׯ��
�壬����ע�����п���ȡ��(cancel)ָ�ׯ���ô�ָ���������˾���Ч��
������ҽ���עȡ�أ�ׯ�ҷ�������ׯ����ׯ���ô�ָ�����ʾ�˳���
�����֣���ע��ȡ�ء�
		\n"  ]));
	//for  look  something.

	set("exits",  
	([  //sizeof()  ==  4
		//"south"  :  __DIR__"xiaomuwu",
		//"north"  :  __DIR__"chufang",
		//"west"  :  __DIR__"duchang2",
		"east"  :  __DIR__"clubpoem",
		//"up"  :  __DIR__"***",
		//"down"  :  __DIR__"***",
	]));
	
	set("objects",  
	([  //sizeof()  ==  1
		__DIR__"npc/gongsun"  :  1,
	]));


	//set("outdoors",  "city");
	set("no_fight",  1);
	set("no_magic",  1);
	
	set("no_clean_up",  1);

	set("no_caishen",  1);

	setup();
}

void  init()
{
	object  me;

	add_action("do_bet",  "bet");
	add_action("do_bet",  "xiazhu");
	add_action("do_bet",  "xz");

	add_action("do_zuozhuang",  "zuozhuang");
	add_action("do_zuozhuang",  "zz");

	add_action("do_retire",  "retire");
	add_action("do_retire",  "rangzhuang");
	add_action("do_retire",  "rz");

	add_action("do_start",  "start");
	add_action("do_start",  "kaipan");
	add_action("do_start",  "kp");
	
	add_action("do_cancel",  "cancel");

	add_action("do_look",  "look");

	//all  ppls  enter  this  room,  "shaizi/***"  got  deleted.
	me=this_player();
	if(  me->query_temp("shaizi")  )
	{
		me->delete_temp("shaizi");
	}
}

int  do_bet(string  arg)
{
	object  me;
	int  amount;
	string  money;
	object  ob;
	int  this_bet;  //in  unit  of  silver.

	me=this_player();

	if(!arg || sscanf(arg,"%d %s",  amount,  money)  !=  2)
		return  notify_fail("��ʹ�ã�bet(��xiazhu, xz) <��Ŀ> <����>\n");

	//check  valid  money  first.
	ob  =  present  (money+"_money",  me);
	if(!  ob)  return  notify_fail("������û������Ǯ��\n");
	if(amount  <  1)  return  notify_fail("����ƭ��\n");
	if(amount  >  ob->query_amount())  return  notify_fail("��û��ô��Ǯ��\n");
	if(money=="coin")  return  notify_fail("ͭ�壿���ǵ������ȥ�İɡ�\n");

	if(zhuang_id  !=  me->query("id"))
	{//I  am  not  zhuang-jia.
		if(game_status  !=  2)
			return  notify_fail("��û����ע��ʱ����ׯ�ҷԸ���\n");

		//now  let's  bet.
		this_bet  =  amount*ob->query("base_value")/100;
		if(  (this_bet  +  (int)me->query_temp("shaizi/bet_amount"))  >  max_bet  )
			return  notify_fail("ׯ��̫���ˣ��Ĳ��𡣻�ׯ�Ұɡ�\n");

		total_bet  +=  this_bet;
	
		me->set_temp("shaizi/bet_amount",  this_bet  +  (int)me->query_temp("shaizi/bet_amount"));
		message_vision  (sprintf("$N�ó�%s%s%s��Ѻ�������ϡ�\n",
			chinese_number(amount),
			ob->query("base_unit"),
			ob->query("name")),
			me);

		if  (amount  ==  ob->query_amount())  destruct  (ob);
		else  ob->add_amount(-amount);
	}
	else
	{//I  am  zhuang-jia.
		if(game_status  !=  2)
			return  notify_fail("������ͷ�Բ����ѣ����Ǳ���ׯ�ˡ�\n");
		if(total_bet  ==  0)
			return  notify_fail("��û����ע�ء��ȴ�Ҷ������������°ɡ�\n");

		//now  let's  bet.
		this_bet  =  amount*ob->query("base_value")/100;
		if(this_bet  <  total_bet)
			return  notify_fail("��һ�ֹ���ע"+total_bet+"�����ӣ�ׯ����Ѻ�������������Ŀ��\n");		

		total_bet  +=  this_bet;	
		me->set_temp("shaizi/bet_amount",  this_bet  +  (int)me->query_temp("shaizi/bet_amount"));
		message_vision  (sprintf("$N�ó�%s%s%s��Ѻ�������ϡ�\n",
			chinese_number(amount),
			ob->query("base_unit"),
			ob->query("name")),
			me);

		if  (amount  ==  ob->query_amount())  destruct  (ob);
		else  ob->add_amount(-amount);

		message_vision("$N��һѹ���ã����ڿ��������һ��һ������\n",  me);
		game_status  =  3;
				
		call_out("game_process",  1);	
	}	
	return  1;
}

int  do_cancel()
{
	//this  can  only  happen  in  bet  process.
	//for  zhuang-jia,  he  does  not  want  continue  and  lost  his  zhuang_deposit  and  
	//others  get  money  back.  
	//for  non_zhuang  players,  he  simply  gets  his  money  back.
	object  me;
	int  i;
	object  *inv  =  all_inventory(this_object());
	me  =  this_player();

	if(game_status  !=  2)  return  notify_fail("����û��ʲô��Ҫȡ���ġ�\n");  

	if(  me->query_temp("shaizi_cancel_count")  >  5  )
		return  notify_fail("��������ڵĴ���̫���ˣ������Ѿ�̫�\n");  

	if(  me->query("id")  ==  zhuang_id  )
	{//I  am  zhuang-jia.
		message_vision("$N����˵������һ���ҶĲ���ȥ�ˣ����ǰ�Ǯ�û�ȥ��������ׯ�ɣ�\n",  me);		
		zhuang_id  =  "no  zhuang";
		me->delete_temp("shaizi");

		me->set_temp("shaizi_cancel_count",  1+me->query_temp("shaizi_cancel_count"));

		//give  ppls  money  back.
		for(i=0;  i<sizeof(inv);  i++)
		{
			if(  inv[i]->query_temp("shaizi/bet_amount")  >  0  &&  inv[i]->query("id")  !=  zhuang_id  )
			{
				total_bet  -=    inv[i]->query_temp("shaizi/bet_amount");
				if(total_bet  >=  0)
				{
					pay_player(inv[i],  inv[i]->query_temp("shaizi/bet_amount"));
					message_vision("$N����ѷ��������ϵĶ�ע���˻�����\n",  inv[i]);
				}
				else
				{
					message_vision("��⣡����������͵Ǯ��$N��Ǯû�ˡ�\n",  inv[i]);
				}
			}
			if(  inv[i]->query_temp("shaizi")  )  inv[i]->delete_temp("shaizi");
		}
		zhuang_id  =  "no  zhuang";
		game_status  =  0;
		total_bet  =  0;
		remove_call_out("check_finish");
	}
	else
	{//if  I  am  not  zhuang-jia.
		if(  me->query_temp("shaizi/bet_amount")  <=  0  )  
			return  notify_fail("����û��ע����������ʲô�壿\n");  
			
		total_bet  -=    me->query_temp("shaizi/bet_amount");
		if(  total_bet  >=0  )
		{		
			message_vision("$N����ѷ��������ϵĶ�ע���˻�����\n",  me);
			pay_player(me,  me->query_temp("shaizi/bet_amount"));
			me->delete_temp("shaizi");
			me->set_temp("shaizi_cancel_count",  1+me->query_temp("shaizi_cancel_count"));
		}
		else
		{
			message_vision("��⣡����������͵Ǯ��$N��Ǯû�ˡ�\n",  me);
		}
	}
	return  1;
}

int  do_zuozhuang()
{
	object  me,  zhuang;

	int  zhuang_deposit  =  500;  //5  gold.

	me=this_player();

	if  (zhuang_id  ==  me->query("id"))
	{
		return  notify_fail("���Ѿ���ׯ���ˡ�\n");
	}
	
	if(game_status  ==  1  ||  game_status  ==  0  )
	{//only  in  this  two  case  can  ��ׯ
		if(objectp(zhuang=present(zhuang_id,  this_object()))  )
		{//if  the  previous  zhuang-jia  is  here.
			//if  the  zhuang-jia  does  not  "start"...cancel  his  zhuang.
			if(ask_for_zhuang  ==  0)
			{
				ask_for_zhuang  =  1;
				call_out("check_start",  120,  round);
				tell_room(this_object(),  me->query("name")+"Ҳ����ׯ�����ׯ���������ڲ��ܿ���(start)���͵���ׯ�ˡ�\n");
			}  
			return  notify_fail("�Ѿ���ׯ���ˣ���"+zhuang->query("name")+"("+zhuang->query("id")+")��ׯ�ɡ�\n");	
		}
		else
		{
			if(  !pay_out(me,  zhuang_deposit)  )
				return  notify_fail("��û���㹻��Ǯ����ׯ��֤��\n");

			me->set_temp("shaizi_zhuang_deposit",  500);
			//note  this  parameter  is  not  in  "shaizi"  array.
		
			message_vision("$N�ó�һ������������һ�ģ���ׯ�ҵ�λ��������������\n",  me);
			zhuang_id  =  (string)me->query("id");
			game_status  =  1;  //zhuang-jia  changed.
			return  1;
		}
	}
	else
		return  notify_fail("���ڻ����ܻ�ׯ��\n");
}

int  do_retire()
{
	object  me;

	me=this_player();

	if(zhuang_id  !=  me->query("id"))
		return  notify_fail("���ֲ���ׯ�ң���ʲô�ã�\n");

	if(game_status  ==  1  ||  game_status  ==  0  )
	{
		message_vision("$Nվ�����µ������ùׯ�ҿɲ����ˣ�˵��˳�ֽ����ϵı�֤���ڻ��\n",  me);
		zhuang_id  =  "no  zhuang";
		game_status  =  0;
		pay_player(me,  me->query_temp("shaizi_zhuang_deposit"));
		me->delete_temp("shaizi_zhuang_deposit");
		return  1;
	}
	else
	{//not  the  time  to  ��ׯ.
		return  notify_fail("���ӣ��ô��ö�����һ�ѡ�\n");
	}
}

int  do_start(string  arg)
{
	int  max_limit  =  1000;  //1000  gold.
	int  min_limit  =  10;  //10  gold.
	int  current_limit;

	object  me;

	me=this_player();

	if(zhuang_id  !=  me->query("id"))
		return  notify_fail("ֻ��ׯ�Ҳ��ܿ��̡�\n");

	if(game_status  ==  1  ||  game_status  ==  0  )
	{
		if(!  arg  ||  sscanf  (arg,"%d",  current_limit)  !=  1)
			return  notify_fail("��ʹ�ã�start  <��ע���ޣ���λ���ƽ�>\n");

		if(current_limit  <  min_limit)
			return  notify_fail("��Ҳ̫���˰ɣ����Ǳ���ׯ�ˡ���ע���ޱ�����"+chinese_number(min_limit)+"���ƽ�\n");
		if(current_limit  >  max_limit)
			return  notify_fail("��Ҳ̫���˰ɣ��𳬹�"+chinese_number(max_limit)+"���ƽ�\n");

		max_bet  =  100*current_limit;  //max_bet  in  silver.
		message_vision("$N��һ�Ӵ����е������̣����ڿ�ʼ��ע��\n",  me);
		message_vision("$N����һ�£���ע�𳬹�"+chinese_number(current_limit)+"���ƽ�\n",  me);

		total_bet  =  0;
		game_status  =  2;  //enter  the  bet  process.
		round++;  //we  increase  this  number  to  indicate  a  new  round  of  game.
		remove_call_out("check_finish");
		call_out("check_finish",  600,  round);  
		//a  game  must  be  finished  within  10  minutes.  
		return  1;
	}
	else
	{//not  the  time  to  ����.
		return  notify_fail("���ڻ����ܿ��̡�\n");
	}
}

void  check_start(int  previous_round)
{
	ask_for_zhuang  =  0;//so  after  this,  can  ask  again...

	if(previous_round  !=  round)  return;  //it  means  already  started.	

	//now  if  still  in  this  round.
	if(  game_status  ==  3)  return;  //game  in  processing,  can  do  nothing  here.

	tell_room(this_object(),  "ׯ�ҳٳٲ����̣�ֻ�û�ׯ�ˡ�\n");
	zhuang_id  =  "no  zhuang";
	game_status  =  0;
	total_bet  =  0;
}

void  check_finish(int  previous_round)
{
	int  i;
	object  *inv  =  all_inventory(this_object());

	if(previous_round  !=  round)  return;  //it  means  already  finished.
	
	//now  if  still  in  this  round.
	if(  game_status  ==  3)  return;  //game  in  processing,  can  do  nothing  here.

	//here  we  need  cancel  the  game.
	//give  money  back  to  all  players  except  zhuang-jia,  cuz  this  is  his/her  fault.
	tell_room(this_object(),  "��һ�ֳٳ�δ����ɣ�ֻ��ȡ�������ˡ�\n");
	for(i=0;  i<sizeof(inv);  i++)
	{
		if(  inv[i]->query_temp("shaizi/bet_amount")  >  0  &&  inv[i]->query("id")  !=  zhuang_id  )
		{
			total_bet  -=    inv[i]->query_temp("shaizi/bet_amount");
			if(total_bet  >=  0)
			{
				pay_player(inv[i],  inv[i]->query_temp("shaizi/bet_amount"));
				message_vision("$N����ѷ��������ϵĶ�ע���˻�����\n",  inv[i]);
			}
			else
			{
				message_vision("��⣡����������͵Ǯ��$N��Ǯû�ˡ�\n",  inv[i]);
			}
		}
		if(  inv[i]->query_temp("shaizi")  )  inv[i]->delete_temp("shaizi");
	}

	zhuang_id  =  "no  zhuang";
	game_status  =  0;
	total_bet  =  0;
}

void  game_process()
{
	int  i,  j;
	object  *inv  =  all_inventory(this_object());
	
	j=0;
	for(i=0;  i<sizeof(inv);  i++)
	{
		if(  (int)inv[i]->query_temp("shaizi/bet_amount")  >  0  )
		{
			j++;
			call_out("show_shaizi",  j*4,  inv[i]);
		}
	}

	call_out("game_result",  (j+2)*4);	
}

void  show_shaizi(object  me)
{
	string  point_msg;
	string  *sha_msg  =  ({
		"����һ�Ժ��ۣ����һ����ɱ�����е�����������������һˤ��\n",
		"�����ϴ��˿�����������������һ�ף�����\n",
		"΢΢һЦ������������������һ��������\n",
		"�������˸�Ҿ���������ӣ���������սս���������һͶ������\n",
		"�����������ӣ����㾫��Ȣ�����������ڴ�һ�٣�\n",
		"����һ�������е������ҵģ�\n",
		"ҧ���гݣ����������������Ϻݺݵ�һ�ң�����\n",
		"��ͷ�󺹣���������������ԣ����ԣ������Ҽ��˰ɣ�����\n",
		"���������˸��ķ�Ҿ����Ѹ���Ӯ�������ˣ�����\n",
		});

	string  *shaizi_msg  =  ({
"����������\n"+
"����������\n"+
"����������\n"+
"����������\n"+
"����������\n",  
"����������\n"+
"����������\n"+
"�����񡡩�\n"+
"����������\n"+
"����������\n",  
"����������\n"+
"����������\n"+
"���񡡡�\n"+
"����������\n"+
"����������\n",  
"����������\n"+
"���񡡡���\n"+
"�����񡡩�\n"+
"��������\n"+
"����������\n",  
"����������\n"+
"���񡡡�\n"+
"����������\n"+
"���񡡡�\n"+
"����������\n",  
"����������\n"+
"���񡡡�\n"+
"�����񡡩�\n"+
"���񡡡�\n"+
"����������\n",  
"����������\n"+
"���񡡡�\n"+
"���񡡡�\n"+
"���񡡡�\n"+
"����������\n",
		});

	if(environment(me)  ==  this_object()  ||  me->query_temp("shaizi/bet_amount")  >  0)
	{
		me->set_temp("shaizi/point1",  1+random(6));//first  shaizi.
		me->set_temp("shaizi/point2",  1+random(6));//second  shaizi.
		if(  me->query_temp("shaizi/point1")  ==  me->query_temp("shaizi/point2")  &&  me->query_temp("shaizi/point2")  !=  0  )
		{
			me->set_temp("shaizi/point",    100+me->query_temp("shaizi/point2"));
			point_msg  =  chinese_number(me->query_temp("shaizi/point2"))+"��";
		}
		else
		{
			me->set_temp("shaizi/point",    (me->query_temp("shaizi/point1")  +me->query_temp("shaizi/point2")  )%10);
			point_msg  =  chinese_number(me->query_temp("shaizi/point"))+"��";
			if(me->query_temp("shaizi/point")  ==  0)
				point_msg  =  "��ʮ";
		}		

		tell_room  (this_object(),  me->query("name")+sha_msg[random(sizeof(sha_msg))]);
		tell_room  (this_object(),  shaizi_msg[(int)me->query_temp("shaizi/point1")]);
		tell_room  (this_object(),  shaizi_msg[(int)me->query_temp("shaizi/point2")]);
		tell_room  (this_object(),  "���������е���"+point_msg+"��\n");
	}
	
}

void  game_result()
{
	object  zhuang;
	int  i,  zhuang_point;
	object  *inv  =  all_inventory(this_object());

	if(objectp(zhuang=present(zhuang_id,  this_object()))  &&  living(zhuang)  )
	{//if  the  zhuang-jia  is  here.
		tell_room(this_object(),  zhuang->query("name")+"�������������ʣ�\n");	
		zhuang_point  =  zhuang->query_temp("shaizi/point");
	}
	else  
	{
		tell_room(this_object(),  "ׯ�Ҳ�֪���ܵ�����ȥ�ˡ���Ҷ�Ӯ�ˣ�\n");	
		zhuang_point  =  -1;
		zhuang_id  =  "no  zhuang";
	}	
	
	for(i=0;  i<sizeof(inv);  i++)
	{
		if(  (int)inv[i]->query_temp("shaizi/bet_amount")  >  0  &&    inv[i]->query("id")  !=  zhuang_id)
		{
			if(  (int)inv[i]->query_temp("shaizi/point")  >  zhuang_point  )
			{//this  player  won.
				tell_room(this_object(),  inv[i]->query("name")+"Ӯ��"+chinese_number(inv[i]->query_temp("shaizi/bet_amount"))+"�����ӡ�\n");
				total_bet  -=  2*inv[i]->query_temp("shaizi/bet_amount");
				if(total_bet  >=  0)
				{  
					pay_player(inv[i],  2*inv[i]->query_temp("shaizi/bet_amount"));
				}
				else
				{
					tell_room(this_object(),  "��⣡����������͵Ǯ��"+inv[i]->query("name")+"Ӯ��Ǯ�ò����ˡ�\n");
				}
			}
			else
			{//this  player  lost.
				tell_room(this_object(),  inv[i]->query("name")+"����"+chinese_number(inv[i]->query_temp("shaizi/bet_amount"))+"�����ӡ�\n");
			}
		}
	}

	//now  consider  the  zhuang-jia.
	if(zhuang  &&  total_bet  >  0)
	{
		tell_room(this_object(),  "ʣ�µ�"+chinese_number(total_bet)+"�����Ӷ���ׯ��"+zhuang->query("name")+"���ˡ�\n");
		pay_player(zhuang,  total_bet);
		total_bet  =  0;
	}

	//finally,  clear  everything  for  players.
	for(i=0;  i<sizeof(inv);  i++)
	{
		if(  inv[i]->query_temp("shaizi")  )  inv[i]->delete_temp("shaizi");
	}
	game_status  =  0;
	total_bet  =  0;
	remove_call_out("check_finish");
}

void  pay_player(object  me,  int  total)
{
	object  pay_cash,  pay_gold,  pay_silver;

	if(total/1000  >  0)
	{
		pay_cash  =  new("/clone/money/1000-cash");
		pay_cash->set_amount  (total/1000);
		total  -=  1000*pay_cash->query_amount();

		pay_cash->move(me);
	}

	if(total/100  >  0)
	{
		pay_gold  =  new("/clone/money/gold");
		pay_gold->set_amount(total/100);
		total  -=  100*pay_gold->query_amount();

		pay_gold->move(me);
	}

	pay_silver  =  new("/clone/money/silver");
	pay_silver->set_amount(total);
	if(total  >  0)
	{
		pay_silver  =  new("/clone/money/silver");
		pay_silver->set_amount(total);
		total  -=  pay_silver->query_amount();

		pay_silver->move(me);
	}
}

int  pay_out(object  me,  int  total)
{//player  pay  money  out,  in  unit  of  silver.
  //if  sucessful  return  1,  else  return  0.
  //what  I  did  here  is  check  all  the  money  in  silver  the  player  has,
  //then  destroy  all  his  cash,  gold,  silver...then  pay  him  back  the  difference.
	
	int  diff;
	object  cash,  gold,  silver;

	diff  =  check_silver(me)  -  total;	
	if(  diff  <  0  )  return  0;  
	//the  player  does  not  have  enough  money.

	//now  destroy  this  players  cash,  gold  and  silver.
	cash  =  present("1000-cash_money",  me);
	gold  =  present("gold_money",  me);
	silver  =  present("silver_money",  me);
	if(  cash  )  destruct(cash);
	if(  gold  )  destruct(gold);
	if(silver)  destruct(silver);

	//now  pay  his  back  the  difference.	
	if(  diff  >  0  )  pay_player(me,  diff);

	return  1;		
}

int  check_silver(object  me)
{//this  function  check  the  money  in  silver  a  player  has,
	object  cash,  gold,  silver;
	int  total_silver;
	
	cash  =  present("1000-cash_money",  me);
	gold  =  present("gold_money",  me);
	silver  =  present("silver_money",  me);
	total_silver  =  0;
	if(  cash  )  total_silver  +=  1000*(cash->query_amount());
	if(  gold  )  total_silver  +=  100*(gold->query_amount());
	if(silver)  total_silver  +=  (silver->query_amount());	

	return  total_silver;
}


int  do_look(string  arg)
{
	object  zhuang;
	object  *inv  =  all_inventory(this_object());
	int  i;
//        object  me  =  this_player();

	if(arg  ==  "table")
	{
		if(total_bet  >  0)
		{
			write("���ڵĶ�ע�ܹ���"+total_bet+"�����ӡ�\n");
			for(i=0;  i<sizeof(inv);  i++)
			{
				if(  inv[i]->query_temp("shaizi/bet_amount")  >  0  )
					write(inv[i]->query("name")+"��"+inv[i]->query_temp("shaizi/bet_amount")+"����\n");
			}

		}
		else  write("���ڻ�û������ע��\n");

		if(zhuang_id  ==  "no  zhuang")
			write("Ŀǰ��û��ׯ�ҡ�\n");
		else
		{
			if(objectp(zhuang=present(zhuang_id,  this_object()))  &&  living(zhuang)  )
			{//if  the  zhuang-jia  is  here.
				write("Ŀǰ��ׯ����"+zhuang->query("name")+"("+zhuang->query("id")+")��\n");	
			}
			else  
			{
				write("ׯ�Ҳ�֪���ܵ�����ȥ�ˡ�\n");
				zhuang_id  =  "no  zhuang";
			}		
		}
		return  1;
	}
	return  0;	
}





