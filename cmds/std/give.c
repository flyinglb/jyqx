// give.c
#include <ansi.h>
inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("你要给谁什么东西？\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("你要给谁什么东西？\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("这里没有这个人。\n");

	if( who->query("env/no_accept") )
		return notify_fail("人家现在不想要什么东西。\n");

	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("你身上没有这样东西。\n");
		if( obj->query("no_drop") )
			return notify_fail("这样东西不能随便给人。\n");
                if(obj->query("no_npc"))
                        return notify_fail("这样东西不能随便给NPC。\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "不能被分开给人。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("你没有那么多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if( do_give(me, obj2, who) )
				return 1;
			else {
				obj->set_amount((int)obj->query_amount() + amount);
				return 0;
			}
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_give(me, inv[i], who);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");
	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
	object money;
        if( obj->query("dynamic_quest") )
        if( TASK_D->quest_reward(me,who,obj) )
        return 1;
//        if( obj->query("no_drop") && me->query("questname") != 0 )
        if( obj->query("no_drop") && me->query("questname") != obj->name() )
		return notify_fail("这样东西不能随便给人。\n");
		
        if(me->is_busy()|| me->is_busy())
                return notify_fail("你现在正忙着呢。\n");
//Add by Winzip
        if(obj->query("no_npc") && !userp(who))
                return notify_fail("这样东西不能随便给npc。\n");
// Add by Java 
	if( userp(obj) )
		return notify_fail("你只能卖玩家。\n");
// on June 3.1998
        if (who->name() == me->query("questname") && obj->name() == (HIW"书信"NOR) ){
	        int exp,pot,sc,shu,i;
	        i = me->query("questexp")/4;
	        exp = random(i) + i;
                pot = random(i/5) + 12;
	        sc = random(10) + 10;
	        me->add("combat_exp",exp);
	        me->add("potential",pot);
	        me->add("score",sc);
	        me->set("cangive",1);
	        me->delete("quest");
	        me->delete("questname");
	        shu = 10 + random(10);
	        money = new("/clone/money/silver.c");
	        money->set_amount(shu);
	        money ->move(me);
	        tell_object(me,HIW"你被奖励了：\n" +
       	                chinese_number(exp) + "点实战经验\n"+
       	                chinese_number(pot) + "点潜能\n" +
                        chinese_number(sc)+"点综合评价。\n你得到"+
                        chinese_number(shu)+"两白银\n"NOR);
                printf("你给%s一%s%s。\n", who->name(), obj->query("unit"),obj->name());
                message("vision", sprintf("%s给你一%s%s。\n", me->name(),
                        obj->query("unit"), obj->name()), who );
                message("vision", sprintf("%s给%s一%s%s。\n", me->name(), who->name(),
                        obj->query("unit"), obj->name()), environment(me), ({me, who}) );
                obj->move(VOID_OB);
                destruct(obj);
                return 1;
	    };

        if(who->query_encumbrance() + obj->weight() 
           > who->query_max_encumbrance() ) {
                return notify_fail("对方无法接受这东西\n");
        }

       if( !interactive(who) && !who->accept_object(me, obj) )
		return notify_fail("对方不接受这样东西。\n");

//        if( !obj ) return 1;//add Byp@MX 

        if( obj->move(who) ) {
		printf("你给%s一%s%s。\n", who->name(), obj->query("unit"),
			obj->name());
		message("vision", sprintf("%s给你一%s%s。\n", me->name(),
			obj->query("unit"), obj->name()), who );
		message("vision", sprintf("%s给%s一%s%s。\n", me->name(), who->name(),
			obj->query("unit"), obj->name()), environment(me), ({me, who}) );
		me->save();
		if (userp(who)) who->save();
		return 1;
	} else {
              tell_object(who,sprintf("%s想给你一%s%s。\n", me->name(),obj->query("unit"), obj->name()));
              return notify_fail("对方无法接受你的物品。\n");
        }
}
int help(object me)
{
write(@HELP
指令格式 : give <物品名称> to <某人>
      或 : give <某人> <物品名称>
 
这个指令可以让你将某样物品给别人，当然，首先你要拥有这样物品。
 
HELP
    );
    return 1;
}
