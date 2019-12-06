// dealer.c ����
// This is a inheritable object.
// Each dealer should support buy, sell, list, value 4 commands
// should add support pawn command


#include <dbase.h>
#include <ansi.h>

string is_vendor_good(string arg)
{
        string *goods;
        int i;

        if (arrayp(goods = query("vendor_goods"))) 
                for (i = 0; i < sizeof(goods); i++) 
                        if (goods[i]->id(arg))
                                return goods[i];
        return "";
}

int do_value(string arg)
{
        object ob;
        int value;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("��Ҫ��ʲô�ļۣ�\n");
        
        if (ob->query("money_id"))
                return notify_fail("��û�ù�Ǯ����\n");

        if (userp(ob))
                ob->set("value", ob->query("per") * 500);

        value = ob->query("value");
        if (value < 1)
                write(ob->query("name") + "һ�Ĳ�ֵ��\n");
        else 
                write(ob->query("name") + "ֵ" + 
                MONEY_D->price_str(value * 70 / 100) + "��\n");
        return 1;
}

int do_sell(string arg)
{
        object ob;
        object *inv;
        string sell_ob;
        string ob_file;
        int i, sell_number, amount, value;

        
        if (!arg) 
                return notify_fail("��Ҫ��ʲô��\n");
        
        if ((sscanf(arg, "%d %s", sell_number, sell_ob)==2)) {
                
                if (!(ob = present(sell_ob, this_player())))
                        if ((ob_file = is_vendor_good(sell_ob)) == "")
                                return notify_fail("������ʲô�� \n");

                if (sell_number<1) 
                        return notify_fail("�������������ٱ�����һ�� \n");
                
                inv = all_inventory(this_player());
                
                for(i=0; i<sizeof(inv); i++) {
                        if(inv[i]->short()!= ob->short() ) continue;
                        amount += 1;
                }

                if (amount < sell_number) 
                        return notify_fail("��û����ô���" + ob->query("name") + "��������\n"); 
                
        } else {
                if (sscanf(arg, "%s", sell_ob)==1) {
                        
                        if (!ob = present(sell_ob, this_player())) 
                                return notify_fail("��Ҫ��ʲô��\n");
                        
                        sell_number=1;
                        
                } else
                        return notify_fail("������ʲô�� 3 if\n");
        }
        
        if (ob->query("money_id"))
                return notify_fail("��������Ǯ������\n");

        if (ob->query("no_sell"))
                return notify_fail("����������������\n");

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
                        sprintf("%s��ĳ�˹�����%s�ˡ�", ob->name(1), this_object()->query("name")));
        }

        value = ob->query("value");
        if (value < 30)
                return notify_fail(ob->query("name") + "һ�Ĳ�ֵ��\n");
        else {
                message_vision("$N������" + chinese_number(sell_number) + ob->query("unit") + 
                ob->query("name") + "��$n��\n", this_player(), this_object());
                
                MONEY_D->pay_player(this_player(), value * sell_number * 70 / 100);
                
                if ( userp(ob))
                {
                        ob->move("/d/city/cangku");
                        ob->set("startroom","/d/city/cangku");
                        ob->set_temp("selled");
                        ob->save();
                }
                else if (value < 50)
                        destruct(ob);
                else
                {
                        for(i=0; i<sell_number; i++) 
                        {
                                ob->move(this_object());
                                ob = present(sell_ob, this_player());
                        }
                }
        }
        inv = all_inventory(this_object());
        if(sizeof(inv) > 99) {
                for(i=0; i<sizeof(inv); i++) {
                        //if(ob->query("value") > 500) continue;
                        ob = inv[i];
                        destruct(ob);
                }
        }
        return 1;
}

int do_list()
{
        string *goods;
        object *inv;
        object *inv1;
        int *count;
        int i;
        int j;

        inv = all_inventory(this_object());

        if (!sizeof(inv) && !arrayp(goods = query("vendor_goods")))
                return notify_fail("Ŀǰû�п������Ķ�����\n");
        for (i = 0; i < sizeof(inv); i++) 
        {
                if (!inv[i]->query("equipped") && !inv[i]->query("money_id"))
                {
                        if (!arrayp(inv1))
                        {
                                inv1=({inv[i]});
                                count=({1});
                        }
                        else
                        {
                                for (j = 0; j < sizeof(inv1); j++)
                                        if (inv[i]->short()==inv1[j]->short())
                                                break;
                                if (j == sizeof(inv1))
                                {
                                        inv1+=({inv[i]});
                                        count+=({1});
                                }
                                else
                                        count[j]+=1;
                        }
                }
        }
        
        printf("�������%s����������Ʒ��\n", query("name"));

        for (i = 0; i < sizeof(inv1); i++) 
                printf("%30-s��������%3-i %s\n", inv1[i]->short(),
                count[i],
                MONEY_D->price_str(inv1[i]->query("value") * 6 / 5));
        if (arrayp(goods = query("vendor_goods")))
                for (i = 0; i < sizeof(goods); i++)
                        printf("%30-s��%s\n", goods[i]->short(),
                        MONEY_D->price_str(goods[i]->query("value")));
        return 1;
}       

int do_buy(string arg)
{
        int val_factor, buy_number, i, amount;
        string buy_ob;
        string ob_file;
        string *goods;
        object ob;
        object *inv;

//      mapping fam;

//      if ( (fam = this_player()->query("family")) && fam["family_name"] == "ؤ��" ) 
//              return notify_fail("���Ǹ���л�����ʲ�ᶫ����\n");

        if (!arg) 
                return notify_fail("������ʲô�� \n");
        
        if ((sscanf(arg, "%d %s", buy_number, buy_ob)==2)) {
                
                if (!(ob = present(buy_ob, this_object())))
                        if ((ob_file = is_vendor_good(buy_ob)) == "")
                                return notify_fail("������ʲô�� \n");

                if (buy_number<1) 
                        return notify_fail("�㹺���������ٱ�����һ�� \n");
                
                if (buy_number>10) 
                        return notify_fail("������ѽ��Ҫ�����������г�ȥ�� \n");
                        
                if (!arrayp(goods = query("vendor_goods"))) {
                        
                        inv = all_inventory(this_object());
                
                        for(i=0; i<sizeof(inv); i++) {
                                if(inv[i]->short()!= ob->short() ) continue;
                                amount += 1;
                        }

                        if (amount < buy_number) 
                                return notify_fail(this_object()->query("name") + "û����ô���" + ob->query("name") + "��������\n"); 
                }
                

        } else {
                if (sscanf(arg, "%s", buy_ob)==1)
                        buy_number=1;
                else
                        return notify_fail("������ʲô�� \n");
        }
        
        if (!(ob = present(buy_ob, this_object())))
                if ((buy_ob = is_vendor_good(buy_ob)) == "")
                        return notify_fail("������ʲô�� \n");

/*
        if (buy_ob->query("money_id"))
                return notify_fail("������Ǯ������\n");
*/

        if (!ob) {
                ob = new(buy_ob);
                val_factor = 10;
        } else {
                if (ob->query("equipped"))
                        return notify_fail("������ʲô�� \n");
                val_factor = 12;
        }

        if (ob->query("money_id"))
                return notify_fail("��������Ǯ������\n");

        if (query_temp("busy"))
                return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");
        
        switch (MONEY_D->player_pay(this_player(), ob->query("value") * buy_number * val_factor / 10)) {
        
        case 0:
                return notify_fail("��⵰��һ�ߴ���ȥ��\n");
        case 2:
                return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");

        default:
        
                message_vision("$N��$n����������" + chinese_number(buy_number) + ob->query("unit") + 
                ob->query("name") + "��\n", this_player(), this_object() );

                if (!arrayp(goods = query("vendor_goods"))) {
                        for(i=0; i<buy_number; i++) {
                                ob->move(this_player());
                                ob = present(buy_ob, this_object());
                        }
                } else {
                        for(i=0; i<buy_number; i++) {
                                ob->move(this_player());
                                ob = new(buy_ob);
                        }
                }

          set_temp("busy",1);
        }
        
        remove_call_out("enough_rest");
        call_out("enough_rest", 1);

        return 1;
}

int do_pawn(string arg)
{
        object ob;
        int amount, value;
        string *pawns;

        
        if (!arg) 
                return notify_fail("��Ҫ��ʲô��\n");
                
/*        
        if ((sscanf(arg, "%d %s", pawn_number, pawn_ob)==2)) {
                
                if (!(ob = present(pawn_ob, this_player())))
                        if ((ob_file = is_vendor_good(pawn_ob)) == "")
                                return notify_fail("���뵱ʲô�� \n");

                if (pawn_number<1) 
                        return notify_fail("�㵱���������ٱ�����һ�� \n");
                
                inv = all_inventory(this_player());
                
                for(i=0; i<sizeof(inv); i++) {
                        if(inv[i]->short()!= ob->short() ) continue;
                        amount += 1;
                }

                if (amount < pawn_number) 
                        return notify_fail("��û����ô���" + ob->query("name") + "���Ե���\n"); 
                
        } else {
                if (sscanf(arg, "%s", sell_ob)==1) {
                        
                        if (!ob = present(pawn_ob, this_player())) 
                                return notify_fail("��Ҫ��ʲô��\n");
                        
                        pawm_number=1;
                        
                } else
                        return notify_fail("������ʲô�� 3 if\n");
        }
*/        

	if (!ob = present(arg, this_player())) 
                return notify_fail("��Ҫ��ʲô��\n");
                
        if (ob->query("money_id"))
                return notify_fail("��Ҫ����Ǯ�������Թ���ë����\n");

        if (stringp(ob->query("no_drop")) || ob->query("no_drop")
        || stringp(ob->query("no_sell")) || ob->query("no_sell")
        || stringp(ob->query("only")) || ob->query("only") )
                return notify_fail("�����������ܵ���\n");

        if (is_vendor_good(arg) != "") 
                return notify_fail("��Ҫ��ʲô��\n");

        if (ob->query("food_supply"))
                return notify_fail("ʣ��ʣ���������Լ��ðɡ�\n");
        
        if (ob->query("shaolin"))
                return notify_fail(this_object()->name()+"������С�ľ�һ���Դ����ɲ��Ҷ����ֵ�Ķ����\n");
        
        pawns=this_player()->query("pawns");
    
    	if (sizeof(pawns)>100)
        	return notify_fail(this_object()->query("name")+"˵�����͹��ڱ���䵱����Ʒ̫���ˣ�С�����պ󵣵�����\n");
        

        value = ob->query("value");
        
        if( value<100) 
         	return notify_fail("�㵱�����������꣬ʲô���߰���Ķ�������������\n");
/*
                message_vision("$N������" + chinese_number(pawn_number) + ob->query("unit") + 
                ob->query("name") + "��$n��\n", this_player(), this_object());
                
                MONEY_D->pay_player(this_player(), value * pawn_number * 70 / 100);
*/

	if (!amount=ob->query_amount()) 
		amount=1;
    
    	value*=amount;
    
    	if (value<100)
        	value=value*60/100;
    	else
        	value=value/100*60;
        	
        MONEY_D->pay_player(this_player(), value);
    
    	message_vision("$N�����ϵ�" + ob->query("name") + "�ó����䵱��"
        + MONEY_D->price_str(value) + "��\n", this_player());

        if (!pawns)
        	this_player()->set("pawns",({ base_name(ob) }) );
    	else {
        	pawns+=({ base_name(ob) });
        	this_player()->set("pawns",pawns );
        }
        
        ob->move(this_object());
        destruct(ob);
        return 1;
}
int do_shu(string arg)
{
    	string *pawns,*new_pawns,ob;
    	object obj;
    	mapping all_id;
    	int i,j;

    	if (!(pawns = this_player()->query("pawns")))
        	return notify_fail(this_object()->query("name") +
        	"˵�����͹ٲ�δ�ڱ���䵱���κ���Ʒ��\n");
        	
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
        	return notify_fail(this_object()->query("name") + 
        	"���ˣ���...���ʱ��С��䵱���ⶫ����\n");
        	
    	if( this_player()->can_afford(ob->query("value"),1))
        	this_player()->pay_money(ob->query("value"),0);
    	else
	        return notify_fail("���Ǯ������\n");
    	
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
    	
    	message_vision("$N�ӵ��������һ" + ob->query("unit")
         + ob->query("name") + "��\n", this_player() );
         
    	obj=new(ob);
    	
    	if (!obj->move(this_player()))
    		obj->move(environment(this_player()));
    		
    	return 1;
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
        	return notify_fail(this_object()->query("name") + 
        	sprintf("˵����%s��δ�ڱ���䵱���κ���Ʒ��\n",obj==me?"��":obj->short(1)));
        	
    	str="\n"+((obj==me)?"��":obj->query("name"))+"�ڱ���䵱����Ʒ����:\n\n";
    	
    	for(i=0;i<sizeof(ob);i++){
        	str+=sprintf("%-40s :%s \n",
        	ob[i]->short(),
        	MONEY_D->price_str(ob[i]->query("value")));
    	}
    
    	write(str);
        return 1;
}
void enough_rest()
{
        delete_temp("busy");
}
