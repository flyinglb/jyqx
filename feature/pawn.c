// 相关文件：在/include/globals.h里增加了 #define PAWN "/feature/pawn"
// 为当铺提供pawn,redeem,redeemp,value,sell,list,buy指令

// 为了避免玩家作弊，必须在当铺设置no_fight为1，并且必须设置npc属性no_get为1
// 因为无no_fight,玩家就可以打晕npc然后steal，如果不设置no_get，玩家就可以利用一些特殊
// 的npc把当铺里的npc打晕，然后get起来，背到其他地方steal!

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
	add_action("do_redeemp", "redeemp");//赎人的命令
}

int do_pawn(string arg)
{
	object me,ob;
	string str,*nopawn;
	int i,value;
	
	nopawn = ({"coin", "silver","gold","cash",
			"thousand-cash","mailbox","box"});
	if (!arg||arg=="")
		return notify_fail("你要典当什么？\n");
	me=this_player();
	if(!objectp(ob=present(arg,me)))
		return notify_fail("你没有这样东西。\n");

	if (ob->query("item_origin"))
		return notify_fail("粗坯是不能当的。\n");
	if (ob->query("money_id"))
		return notify_fail("你想当「钱」？？\n");
	if (ob->query("food_supply"))
		return notify_fail("剩菜剩饭留给您自己用吧。\n");
	if(member_array(arg,nopawn)!=-1
		||ob->query("nopawn")==1)
		return notify_fail("这样东西不能典当！\n");
	if((ob->query("enpawn")==0)//如果这个属性不为0，说明它是可以当的！
		&&(
			ob->query("hunmi")!=0||living(ob)
			||ob->query_temp("block_msg/all")==1
		)
	)
		return notify_fail("这个东西是活的呀？！怎么当嘛，真够papaya的了！\n");
	value=ob->query("value");

	/*由于一些物品，没有设置value,所以无法典当，但是又很有用，所以暂时注释这几句
           如果允许这里，请注意enpawn属性也应该判断一下
	if(value<30)
		return notify_fail("这是什么垃圾？居然也拿来典当!\n");
	*/

	//典当值value的60%！
	MONEY_D->pay_player(me, value * 60 / 100);

	//str保存基本文件名
	str=base_name(ob);
	str=replace_string(str,"/","\\");		//注意："\\"即"\"!
	//避免出错！即在map里存map!


	//设置i为已典当了的数量,如是第一次是否为0呢？!!!!!!
	i=me->query("pawn/"+str);

	me->set("pawn/"+str,i+1);  //保存数量(+1)

	message_vision("$N拿出"+ob->query("name")+"典当了"+
		MONEY_D->price_str(value* 60/100)+"。\n",me);
	destruct(ob);
	return 1;
}

int do_redeemp(string target)
{
	object me,ob,dest;
	me=this_player();
	ob=this_object();
	if(!target||target=="")
		return notify_fail(ob->query("name")+"俯到你的耳边悄声问道：你要赎什么人？\n");
	if(!objectp(dest=find_player(target)))
		return notify_fail("玩家("+target+")目前不在线上！\n");
	if( !dest->query("jackyboy/selled"))
		return notify_fail(ob->query("name")+"急道：你可别诬陷好人，我怎么会非法扣押玩家呢！\n");
	switch (MONEY_D->player_pay(me, dest->query("per") * 700))
	{
	case 0:
		return notify_fail("穷光蛋，一边呆着去！\n");
	case 2:
		return notify_fail("您的零钱不够了，银票又没人找得开。\n");
	default:
		message_vision("$N从$n那里赎回了一" + dest->query("unit") + 
			dest->query("name") + "。\n", me, this_object());
		dest->move(environment(ob));
		dest->set("startroom",base_name(environment(ob)));
		dest->set("jackyboy/selled",0);
		message("vision",
			HIY "只听见嗖的一声，一个遍体鳞伤的家伙从天花板上掉了下来！\n" NOR,
			environment(dest), dest);
		tell_object(dest, "你被" + me->query("name") + "赎了出来。\n");
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
	//为了统一格式，可以把所有ansi颜色控制字符删除掉！这样来算长度！
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
		write("你没有当过任何物品。\n");
		return 1;
	}
	if (!target)
	{
		write("你目前当了的物品有：\n");
		terms = keys(env);
		for(i=0; i<sizeof(terms); i++)
		{
			sscanf(terms[i],"%s",str);
			str=replace_string(str,"\\","/");//文件名
			value=me->query("pawn/"+terms[i]);//数量
			term=getid(str);//查所有的ID
			printf("%d\t%s %s\n",
				i+1,
				getname(chinese_number(value),str),
				term);
		}
		return 1;
	}
	//num为要赎的物品个数，snum为同类id的物品的第几个。

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
					else//这里也要特殊处理
					{
						snum--;
						num=1;
						terms = keys(env);
						if(num<=0)
							num=1;
						i=sizeof(terms);
						if(snum>=sizeof(terms))
							return notify_fail("对不起，你没当过这件东西。\n");
						sscanf(terms[snum],"%s",str);
						value=me->query("pawn/"+terms[snum]);
						if(value<num)
							return notify_fail("你没有当过这么多，难道你想白赚？\n");
						str=replace_string(str,"\\","/");//文件名
						if(!objectp(ob=new(str)))
							return notify_fail("你所要赎的物品已经不再存在了。\n");
						switch(MONEY_D->player_pay(me,ob->query("value")*num*4/5))
						//赎回要花value的80%
						{
						case 0:
							return notify_fail("穷光蛋，一边呆着去！\n");
						case 2:
							return notify_fail("您的零钱不够了，银票又没人找得开。\n");
						default:
						}
						message_vision("$N从"+this_object()->query("name")+
							"那里花"+
						MONEY_D->price_str(ob->query("value")*num*4/5)+"赎了"+
							chinese_number(num)+
							ob->query("unit")+
							ob->query("name")+"。\n",me);
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
				snum=1;//利用下面的程序段
		//else// 全集：num id snum的处理
		{
			if(snum<=0)
				snum=1;
			terms = keys(env);
			for(i=0; i<sizeof(terms);i++)
			{
				sscanf(terms[i],"%s",str);
				str=replace_string(str,"\\","/");//文件名
				value=me->query("pawn/"+terms[i]);//数量
				if(member_array(id,(str)->parse_command_id_list())!=-1)
					snum--;
				if(snum==0)
					break;//中断循环
			}
			//如果此时snum=0,说明已经找到了，并且数目也足够！此时str里保存有该文件名
			if(snum==0)
			{
				if(value<num)
					return notify_fail("你没有那么多的"+(str)->query("name")+
						"典当在这里。\n");
				if(!objectp(ob=new(str)))
					return notify_fail("你所要赎的物品已经不再存在了。\n");
				switch(MONEY_D->player_pay(me,ob->query("value")*num*4/5))
				//赎回要花value的80%
				{
				case 0:
					return notify_fail("穷光蛋，一边呆着去！\n");
				case 2:
					return notify_fail("您的零钱不够了，银票又没人找得开。\n");
				default:
				}
				message_vision("$N从"+this_object()->query("name")+
					"那里花"+
					MONEY_D->price_str(ob->query("value")*num*4/5)+"赎了"+
					chinese_number(num)+
					ob->query("unit")+
					ob->query("name")+"。\n",me);
				if(value==num)
					me->delete("pawn/"+terms[i]);
				else
					me->set("pawn/"+terms[i],value-num);			
				for(i=0;i<num;i++)
					new(str)->move(me);
				return 1;
			}
			else //否则snum不为0说明没有这样东西
				return notify_fail("没有你要赎回的东西！请仔细看看你当了些什么！\n");
		}
	}
	else//这里要特殊处理
	{
		terms = keys(env);
		if(num<=0)
			num=1;
		snum--;
		if(snum>=sizeof(terms))
			return notify_fail("对不起，你没当过这件东西。\n");
		sscanf(terms[snum],"%s",str);
		value=me->query("pawn/"+terms[snum]);
		if(value<num)
			return notify_fail("你没有当过这么多，难道你想白赚？\n");
		str=replace_string(str,"\\","/");//文件名
		if(!objectp(ob=new(str)))
			return notify_fail("你所要赎的物品已经不再存在了。\n");
		switch(MONEY_D->player_pay(me,ob->query("value")*num*4/5))
		//赎回要花value的80%
		{
		case 0:
			return notify_fail("穷光蛋，一边呆着去！\n");
		case 2:
			return notify_fail("您的零钱不够了，银票又没人找得开。\n");
		default:
		}
		message_vision("$N从"+this_object()->query("name")+"那里花"+
		MONEY_D->price_str(ob->query("value")*num*4/5)+"赎了"+
			chinese_number(num)+
			ob->query("unit")+
			ob->query("name")+"。\n",me);
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
		return notify_fail("你要卖什么？\n");

	if (ob->query("money_id"))
		return notify_fail("你想卖「钱」？？\n");

	if (stringp(ob->query("no_drop")))
		return notify_fail("这样东西不能卖。\n");

	if (is_vendor_good(arg) != "") 
		return notify_fail("卖给你好不好？\n");

	if (ob->query("food_supply"))
		return notify_fail("剩菜剩饭留给您自己用吧。\n");
	
        if (ob->query("shaolin"))
                return notify_fail("小的只有一个脑袋，可不敢买少林庙产。\n");

	if (userp(ob))
	{
		ob->set("value", ob->query("per") * 500);
		CHANNEL_D->do_channel(ob, "rumor",
			sprintf("%s被某人拐卖给"+this_object()->query("name")+
				"了。", ob->name(1)));
	}

	value = ob->query("value");
	if (value < 30)
		write(ob->query("name") + "一文不值！\n");
	else {
		message_vision("$N卖掉了一" + ob->query("unit") + 
		ob->query("name") + "给$n。\n", this_player(), this_object());
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

