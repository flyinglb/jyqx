#include <ansi.h>

inherit NPC;

#define GOLD_CASH_OB "/clone/money/gold-cash"
#define SILVER_CASH_OB "/clone/money/thousand-cash"
#define MAX_PAWN 50
inherit F_VENDOR;
void destroy(object ob)
{
        if( !ob ) return;
        ob->move(VOID_OB);
        destruct(ob);
}

void create()
{
        set_name(HIG"林月如"NOR, ({ "ling yueru" ,"ling"}) );
        set("gender", "女性" );
        set("age", 29);
        set("title", HIR"魔剑士"NOR);
        set("long",
                "林月如是仙剑奇侠传的女主角之一，但是不知道
为什么却到了这个Mud里，并且在这里收集各种物品。\n");
        set("combat_exp", 99999999);
        set("attitude", "friendly");
        set("per",30);
        set("no_arrest",1);
        set("max_neili",9999);
        set("neili",9999);
        set("qi",5999);
        set("max_qi",5999);
        set("max_jing",9999);
        set("jing",9999);
        set_skill("unarmed",700);
        set_skill("dodge",700);
        set_skill("sword",700);
        set_skill("taiji-jian",500);
        set_skill("force",700);

        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        setup();

}
void init()
{
        add_action("do_value", "value");
        add_action("do_value", "gujia");
        add_action("do_pawn", "pawn");
        add_action("do_pawn", "dang");
        add_action("do_check", "check");
        add_action("do_redeem", "redeem");
        add_action("do_redeem", "shu");
}

string value_string(int value)
{
        if( value < 1 ) value = 1;
        else if( value < 100 )
                return chinese_number(value) + "文钱";
        else
                return chinese_number(value/100) + "两"
                        + (value%100? "又" + chinese_number(value%100) + "文钱": "");
}

void pay_player(object who, int amount)

{
        object ob;
        if( amount < 1 ) amount = 1;
        if( amount/10000 ) {
                ob = new(GOLD_OB);
                ob->set_amount(amount/10000);
                ob->move(who);
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
}

int do_value(string arg)
{
        object ob;
        int value;

        if( !arg || !(ob = present(arg, this_player())) )
                return notify_fail("你要拿什麽物品给本小姐估价？\n");

        if( ob->query("money_id") )
                return notify_fail("这是「钱」，你没见过吗？\n");

        value = ob->query("value");
        if( !value ) printf("%s一文不值。\n", ob->query("name"));
        else 
                printf("%s价值%s。\n如果你要典当(pawn)，可以拿到%s。\n如果卖断(sell)，可以拿到%s。\n",
                        ob->query("name"), value_string(value),
                        value_string(value * 50 / 100), value_string(value * 80 / 100));

        return 1;
}

int do_check(string arg)
{
        string *terms;
        mapping pawn;
        object me;
        int i;

        me = this_player();
        pawn = me->query("pawn");
        write("你目前典当的物品有：\n");
        if( !mapp(pawn) ||   !sizeof(pawn) )
                write("\t没有任何典当的物品。\n");
        else {
                        terms = keys(pawn);
                        for(i=0; i<sizeof(terms); i++)
                                printf("标号 "HIM"%-3s"NOR"：  %-15s  赎银：%s\n", terms[i], pawn[terms[i]],
                        value_string(((int)me->query("vpawn/"+terms[i]))* 3/4));
              }
        return 1;
}

int do_pawn(string arg)
{
        object ob;
        string term, *terms;
        string data;
        int value, pawn_count, i;
        mapping pawn;
        object me;

        me = this_player();
        pawn = me->query("pawn");
        if( !arg || !(ob = present(arg, this_player())) )
        {
        write("你要当什么？\n");
        return 1;
        }
        if( ob->query("money_id") )     return notify_fail("你要当「钱」？\n");
        if( ob->query("equipped") || ob->query("no_drop") || ob->query("no_sell") || ob->query("only"))
             return notify_fail("这样可当不了！\n");
        value = ob->query("value");
        if( !(value/4) ) return notify_fail("这样东西并不值很多钱。\n");
        if( mapp(pawn) && sizeof(pawn))
                {
                        terms = keys(pawn);
                        if(sizeof(terms) > MAX_PAWN)
                        return notify_fail("你已典当太多物品了。\n");
                        for(i=0; i<sizeof(terms); i++)  
                        {
                        pawn_count = i;
                        if(!((int) me->query("vpawn/" + sprintf("%d", i))))
                         break;
                        else pawn_count = i+1;
                        }
                }
        else pawn_count = 0;
        term = ob->query("name");
        data = base_name(ob)+ ".c";
        me->set("pawn/"+ sprintf("%d",pawn_count),  term);
        me->set("vpawn/"+sprintf("%d",pawn_count), ob->query("value"));
        me->set("fpawn/"+sprintf("%d",pawn_count), data);
        me->save();
        message_vision("$N把身上的" + ob->query("name") + "拿出来典当了"
                + value_string(value * 50 / 100) + "。\n", this_player());
        message_vision("谢谢惠顾！\n", this_player());
        pay_player(this_player(), value * 50 / 100 );
        destroy(ob);

        return 1;
}

int do_sell(string arg)
{
        object ob;
        int value;

        if( !arg || !(ob = present(arg, this_player())) )
                return notify_fail("你要卖断什麽物品？\n");

        if( ob->query("money_id") )     return notify_fail("你要卖「钱」？\n");
        value = ob->query("value");
        if( !value ) return notify_fail("这样东西不值钱。\n");


        message_vision("$N把身上的" + ob->query("name") + "卖掉。\n",
                this_player());

        pay_player(this_player(), value  * 80 / 100);
        destroy(ob);

        return 1;
}
void pay_him(object who, int amount)

{
        object ob;
        object cash, tencash, gold, silver, coin;
        tencash = present("gold-cash_money", who);
        cash = present("thousand-cash_money", who);
        gold = present("gold_money",who);
        silver = present("silver_money",who);
        coin = present("coin_money",who);
        if(tencash) destroy(tencash);
        if(cash) destroy(cash);
        if(gold) destroy(gold);
        if(silver) destroy(silver);
        if(coin) destroy(coin);


        if( amount < 1 ) amount = 1;
/*
        if( amount/1000000 ) {
                ob = new(GOLD_CASH_OB);
                ob->set_amount(amount/1000000);
                ob->move(who);
                amount %= 1000000;
        }
*/
        if( amount/100000 ) {
                ob = new(SILVER_CASH_OB);
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
        if( amount/10000 ) {
                ob = new(GOLD_OB);
                ob->set_amount(amount/10000);
                ob->move(who);
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
}

int affordable(object me, int amount)
{
        int total;
        object cash, tencash, gold, silver, coin;

        tencash = present("gold-cash_money", me);
        cash = present("thousand-cash_money", me);
        gold = present("gold_money",me);
        silver = present("silver_money",me);
        coin = present("coin_money",me);

        total = 0;
        if( tencash) total += tencash->value();
        if( cash) total += cash->value();
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value();

        if( total < amount ) return 0;

        return total;
}
int do_redeem(string arg)
{
        int num;
        int amount;
        string ob_file;
        object ob;
        object me;
        int afford;
        if( !arg || sscanf(arg, "%d", num)!=1 )
                return notify_fail("指令格式：redeem <物品标号>\n");
        me = this_player();
        amount = (int) me->query("vpawn/" + sprintf("%d", num));
        if( !amount )
                return notify_fail("有这个物品标号吗？\n");
        amount = amount * 3 /4;
        if( afford = affordable(me, amount) ) {
                ob_file = me->query("fpawn/"+sprintf("%d",num));
                ob = new(ob_file);
                if (ob->move(me)){
                 pay_him(me, afford-amount);
                        me->delete("pawn/"+sprintf("%d",num));
                        me->delete("vpawn/"+sprintf("%d",num)); 
                        me->delete("fpawn/"+sprintf("%d",num));
                        me->save();
                        message_vision("$N赎回了$n。\n", me, ob);
                        message_vision("谢谢惠顾！\n", me,ob);
                }
                return 1;
        } else
                return notify_fail("你的钱不够。\n");

}
