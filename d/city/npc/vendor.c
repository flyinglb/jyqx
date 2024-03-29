// vendor.c

#include <dbase.h>

int buy_object(object me, string what)
{
        string ob;

        if( stringp(ob = query("vendor_goods/" + what)) )
                return ob->query("value");
        else
                return 0;
}

void compelete_trade(object me, string what)
{
        string ob_file;
        object ob;

        if( stringp(ob_file = query("vendor_goods/" + what)) ) {
                ob = new(ob_file);
                ob->move(me);
                message_vision("$N向$n买下一" + ob->query("unit") + ob->query("name") + "。\n",
                        me, this_object() );
        }
}

string price_string(int v)
{
        if( v%10000 == 0 )
                return chinese_number(v/10000) + "两黄金";
        if( v%100 == 0 )
                return chinese_number(v/100) + "两白银";
        return chinese_number(v) + "文铜板";
}

int do_vendor_list(string arg)
{
        mapping goods;
        string list, *name;
        int i;

        if( !mapp(goods = query("vendor_goods")) ) return 0;
        if( arg && !this_object()->id(arg) ) return 0;
        name = keys(goods);
        list = "你可以购买下列这些东西：\n";
        for(i=0; i<sizeof(name); i++)
                list += sprintf("%-30s：%s\n",
                        goods[name[i]]->query("name") + "(" +
                        goods[name[i]]->query("id") + ")",
                        price_string(goods[name[i]]->query("value")) );
        write(list);
        return 1;       
}


// by buick
int do_value(string arg)
{
    object ob;
    int value;
    int amount;
    if( !arg || !(ob = present(arg, this_player())) )
        return notify_fail("你要拿什麽物品给当铺估价？\n");
    if( ob->query("money_id") )
        return notify_fail("这是「钱」，你没见过吗？\n");
    if (ob->query("shaolin") || ob->query("no_sell")||ob->query("no_drop")) return notify_fail("这东西是无价之宝！\n");
    value = ob->query("value");
    if( !value )    {
        printf("%s一文不值。\n", ob->query("name"));
        return 1;
    }else 
        if (!amount=ob->query_amount()) amount=1;
        value*=amount;
        if (value<100)
        printf("\n %s%s%s价值%s。\n如果你要典当(pawn)，可以拿到%s。\n如果卖断(sell)，可以拿到%s。\n",
            chinese_number(amount),(ob->query("base_unit")?ob->query("base_unit"):ob->query("unit")),ob->query("name"), price_string(value),
            price_string(value *60/ 100), price_string(value *80/100));
        else
        printf("\n %s%s%s价值%s。\n如果你要典当(pawn)，可以拿到%s。\n如果卖断(sell)，可以拿到%s。\n",
            chinese_number(amount),(ob->query("base_unit")?ob->query("base_unit"):ob->query("unit")),ob->query("name"), price_string(value),
            price_string(value / 100 * 60), price_string(value / 100*80));
    return 1;
}

int pay_player(object who, int amount)
{
    object ob;
    int total;
    if( amount < 1 ) amount = 1;
        if( amount/10000 ) {
        if (!ob=present("gold_money", who)){
                    ob = new(GOLD_OB);
            if (!ob->move(who)) ob->move(environment(who));
        }else total=ob->query_amount();
                ob->set_amount(amount/10000+total);
                amount %= 10000;
    }
    if( amount/100 ) {
        if (!ob=present("silver_money", who)){
                    ob = new(SILVER_OB);
            if (!ob->move(who)) ob->move(environment(who));
        }else total=ob->query_amount();
                ob->set_amount(amount/100+total);
        amount %= 100;
    }
    if( amount ) {
        if (!ob=present("coin_money", who)){
            ob = new(COIN_OB);
            if (!ob->move(who)) ob->move(environment(who));
        }else total=ob->query_amount();
                ob->set_amount(amount+total);
    }
    return 1;
}


int do_pawn(string arg)
{
    object ob; string *pawns; mapping fam;
      int value, amount;

	if ( (fam=this_player()->query("family")) && fam["family_name"] == "丐帮" ) 
        return notify_fail("你是个穷叫化，当什麽东西！\n");
    if( !arg || !(ob = present(arg, this_player())) )
        return notify_fail("你要典当什麽物品？\n");
    if (ob->query("shaolin"))   return notify_fail(this_object()->name()+"惊呼：小的就一个脑袋，可不敢动少林的亩产！\n");
    if( ob->query("money_id") ) return notify_fail("你要当「钱」？你脑瓜有毛病？\n");
    value = ob->query("value");
    if( !value)
        return notify_fail("这样东西不值钱。\n");
    if( value<100) return notify_fail("你当我这是垃圾店，什么乱七八糟的东西都往这塞？\n");
    if (ob->query("no_drop") || ob->query("no_sell"))  return notify_fail("这么重要的东西你也敢拿来典当？\n");
    pawns=this_player()->query("pawns");
    if (sizeof(pawns)>100)
        return notify_fail(this_object()->query("name")+"说道：客官在本店典当的物品太多了，小店怕日后担当不起。\n");
    if (!amount=ob->query_amount()) amount=1;
    value*=amount;
    if (value<100)
        value=value*60/100;
    else
        value=value/100*60;
    pay_player(this_player(), value);
    message_vision("$N把身上的" + ob->query("name") + "拿出来典当了"
        + price_string(value) + "。\n", this_player());
    if (!pawns)
        this_player()->set("pawns",({ base_name(ob) }) );
    else {
        pawns+=({ base_name(ob) });
        this_player()->set("pawns",pawns );
    }
    destruct(ob);
    return 1;
}

int do_sell(string arg)
{
    object ob,obj,*inv; string str;
      int value,amount,i,j=0;

    if( !arg )
        return notify_fail("你要卖断什麽物品？\n");
    if(sscanf(arg, "%d %s", j,str)==2 ) arg=str;
    if( !(obj = present(arg, this_player())) )
        return notify_fail("你要卖断什麽物品？\n");
    if (j<1) return notify_fail("什么？几个？你当我是三岁小孩呀？\n");
    if (obj->query("money_id") )    return notify_fail("你要卖「钱」？\n");
    if (obj->query("shaolin"))  return notify_fail(this_object()->name()+"惊呼：小的就一个脑袋，可不敢动少林的亩产！\n");
    if (obj->query("no_sell") || obj->query("no_drop")) return notify_fail("这东西是无价之宝，不能卖断！\n");
    value = obj->query("value");
    if( !value)
        if (!value=obj->query("base_value")) return notify_fail("这样东西不值钱。\n");
    if (!amount=obj->query_amount())    amount=1;
    value*=amount;
    if (value<10000)
        value=value*80/100;
    else
        value=value/100*80;
    for (i=0;i<j;i++){
        if( !(ob = present(arg, this_player())) )
            break;
        else{
            ob->move(this_object());
                inv = all_inventory(this_object());
                if (sizeof(inv)>610)
                destruct(inv[sizeof(inv)-2]);
        }
    }
    pay_player(this_player(), value*i);
    message_vision("$N把身上的" + CHINESE_D->chinese_number(i)+obj->query("unit")+obj->query("name") + "卖掉"+ price_string(value*i)+"。\n",
        this_player());
    if (!obj->query("value")) destruct(obj);
    return 1;
}

object find_player(string target)
{
    int i; object *str;

    str=users();
    for (i=0;i<sizeof(str);i++)
        if (str[i]->query("id")==target)
            return str[i];
    return 0;
}

int do_check(string arg)
{
    string str,*ob; object me,obj;
    int i;

    me=this_player();
    if (arg){
        if( wizardp(me)) {
            obj = find_player(arg);
            if( !obj ) obj = find_living(arg);
            if( !obj ) obj = present(arg, environment(me));
        }else   return 0;
    }
    if (!objectp(obj))  obj=me;
    if (!(ob = obj->query("pawns")))
        return notify_fail(this_object()->query("name")+sprintf("说道：%s并未在本店典当过任何物品。\n",obj==me?"你":obj->short(1)));
    str="\n"+((obj==me)?"你":obj->query("name"))+"在本店典当的物品如下:\n\n";
    for(i=0;i<sizeof(ob);i++){
        str+=sprintf("%-40s :%s \n",
        ob[i]->short(),
        price_string(ob[i]->query("value")));
    }
    write(str);
    return 1;
}

int do_redeem(string arg)
{
    string *pawns,*new_pawns,ob;
    object obj;
    mapping all_id;
    int i,j;

    if (!(pawns = this_player()->query("pawns")))
        return notify_fail(this_object()->query("name")+"说道：客官并未在本店典当过任何物品。\n");
    for(i=0;i<sizeof(pawns);i++){
        ob=pawns[i];
        all_id=ob->parse_command_id_list();
        for (j=0;j<sizeof(all_id);j++){
            if (all_id[j]==arg)
                break;
        }
		if (j!=sizeof(all_id))
            break;
    }
    if (j==sizeof(all_id))
        return notify_fail(this_object()->query("name")+"急了：你...你何时在小店典当过这东西？\n");
    if( this_player()->can_afford(ob->query("value"),1))
        this_player()->pay_money(ob->query("value"),0);
    else
        return notify_fail("你的钱不够。\n");
    new_pawns=({});
    j=1;
    for(i=0;i<sizeof(pawns);i++){
        if (j==1 && ob==pawns[i]) {
            j--;
            continue;
        }else new_pawns+=({pawns[i]});
    }
    if (sizeof(new_pawns))
        this_player()->set("pawns",new_pawns );
    else
        this_player()->delete("pawns");
    message_vision("$N从当铺里赎回一" + ob->query("unit")
         + ob->query("name") + "。\n",
            this_player() );
    obj=new(ob);
    if (!obj->move(this_player()))  obj->move(environment(this_player()));
    return 1;
}


string is_vendor_good(string arg,int once)
{
        string *goods,*all_id;
        int i,j;
        if (goods = query("vendor_goods")) 
        for (i = 0; i < sizeof(goods); i++){
            if (!all_id=goods[i]->parse_command_id_list())
                return "";
            if (goods[i]->query("name")==arg)
                return goods[i];
            for (j=0;j<sizeof(all_id);j++)
                if (all_id[j]==arg)
                    if (goods[i]->id(arg) && once==1)
                        return goods[i];
                    else once--;
        }
        return "";
}

string inventory_desc(object ob)
{
    if (ob->query("equipped")) return "";
    else return sprintf("  (一%s)%-25s:  %s",
        ob->query("unit"),      ob->short(),
        price_string(ob->query("value")));
}

int do_list()
{
    string *goods; mapping my;
    object ob,*inv;
     int i,amount;

    inv=all_inventory(this_object());
    if (!sizeof(inv) && !arrayp(goods = query("vendor_goods")))
            return notify_fail("目前没有可以卖的东西。\n");
    if (arrayp(goods = query("vendor_goods"))){
        printf("你可以向%s购买下列物品：\n", query("name"));
            for (i = 0; i < sizeof(goods); i++)
                        printf("%40-s：%20-s\n", goods[i]->short(),
            price_string(goods[i]->query("value")));
            return 1;
    }
    delete("my");
    ob=first_inventory(this_object());
        while(ob){
                if (ob->query("equipped") || ob->query("money_id")){
            ob = next_inventory(ob);
            continue;
        }
        if (!mapp(my=query("my")))
            set("my",([base_name(ob):1]));
        else{
            amount=my[base_name(ob)];
            my[base_name(ob)]=amount+1;
        }
        ob = next_inventory(ob);
    }
    if (!mapp(my=query("my")))
    return notify_fail("目前没有可以卖的东西。\n");
        printf("你可以向%s购买下列物品：\n", query("name"));
        inv=keys(my);
        for (i=0;i<sizeof(my);i++)
                printf("%30-s：%-20s(共有：%s%s)\n", inv[i]->short(),
            price_string(inv[i]->query("value")),
            CHINESE_D->chinese_number(my[inv[i]]),
            inv[i]->query("unit")
            );
    return 1;
}       


int do_buy(string arg)
{
    string items,targ;
    object dest,ob, owner,obj;
    mapping fam;
    int price, i,amount=1;
    int once=1;
    
	dest=this_player();
    reset_eval_cost();
    if ( (fam=dest->query("family")) && fam["family_name"] == "丐帮" ) 
        return notify_fail("你是个穷叫化，买什麽东西！\n");
    targ="";
    if ( !arg )
        return notify_fail("你要买什么东西？\n");
        if(sscanf(arg, "%d %s %d from %s",amount,items,once, targ)!=4 )
            if(sscanf(arg, "%d %s from %s",amount,items, targ)!=3 )
            if(sscanf(arg, "%s %d from %s", items,once,targ)!=3 )
        if( sscanf(arg, "%d %s %d",amount,items,once)!=3 )
                if(sscanf(arg, "%s from %s", items, targ)!=2 )
            if( sscanf(arg, "%d %s",amount,items)!=2 )
            if( sscanf(arg, "%s %d",items,once)!=2 )
                items=arg;
    if(targ=="")
        owner=this_object();
    else    if (!objectp(owner = present(targ, environment(dest))) )
        return notify_fail("你要跟谁买东西？\n");
    arg=items;
    items = is_vendor_good(arg,once);
    if (items == ""){
            if (!objectp(obj=present(arg, owner)))
                return notify_fail("你想买什么？ \n");
    }
    if(amount<1) return notify_fail("至少得买一个吧？\n");
    if(amount>100) return notify_fail("你一次不能买这么多。\n");
    if (items == ""){
        if (obj->query("equipped")||obj->query("money_id"))
            return notify_fail(owner->query("name")+"气冲冲地说：身上的东西，不卖！\n");
        price=obj->query("value");
    }else{
        price=items->query("value");
    }
    if( dest->can_afford(price*amount) ) {
        reset_eval_cost();
        for (i=0;i<amount;i++){
            if (items == ""){
                if (ob = present(arg, owner)){
                    if (!ob->move(dest)) ob->move(environment(dest));
                }else break;
            } else{
                ob=new(items);
                if (!ob->move(dest)) ob->move(environment(dest));
            }
        }
        amount=i;
        dest->pay_money(price*amount);
        if (items == "")
            message_vision("$N向$n买下" +CHINESE_D->chinese_number(amount)+obj->query("unit") + obj->query("name") + "。\n",dest, owner );
        else{
            if (amount>9 && items->query("name")=="牛皮酒袋")
                message_vision("$N一边转身去装酒，嘴里一边嘀咕：买这么多酒，用来洗澡呀？\n",owner );
            message_vision("$N向$n买下" +CHINESE_D->chinese_number(amount)+items->query("unit") + items->query("name") + "。\n",dest, owner );
        }
        return 1;
    } else
        return notify_fail("你的钱不够。\n");
}
