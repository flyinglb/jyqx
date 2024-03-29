//inventory.c
//modified by wind
#include <ansi.h>
inherit F_CLEAN_UP;
object find_player(string target)
{
	int i;
	object *str;
	str=users();
	for (i=0;i<sizeof(str);i++)
		if (str[i]->query("id")==target)
			return str[i];
	return 0;
}
int main(object me, string arg)
{
	int i,amount;
	object *inv, ob,obj;
	mapping my;
	string *str;
	if( wizardp(me) && arg ) {
		ob = find_player(arg);
		if( !ob ) ob = find_living(arg);
		if( !ob ) ob = present(arg, environment(me));
	}
	if( !ob ) ob = me;
	inv = all_inventory(ob);
	if( !sizeof(inv) ) {
		write((ob==me)? "目前你身上没有任何东西。\n"
			: ob->name() + "身上没有携带任何东西。\n");
		return 1;
	}
	obj=first_inventory(ob);
	arg="";
        while(obj){
		reset_eval_cost();
		if (obj->query("equipped")  || obj->query("money_id")){
			arg+=sprintf("%s%s \n",obj->query("equipped")? HIC "□" NOR:"  ",obj->short());
			obj = next_inventory(obj);
			continue;
		}
		if (!mapp(my))
		   	my=([obj->query("unit")+obj->short():1]);
		else{
			amount=my[obj->query("unit")+obj->short()];
		   	my[obj->query("unit")+obj->short()]=amount+1;
		}
		obj = next_inventory(obj);
	}
	if (mapp(my)){
		str=keys(my);
		for (i=0;i<sizeof(my);i++)
                arg+=sprintf("  %s%s\n",
my[str[i]]==1?"":CHINESE_D->chinese_number(my[str[i]]),
my[str[i]]==1?str[i][2..]:str[i]);
	}
	printf("%s身上带著下列这些东西(负重 %d%%)：\n%s\n",
		(ob==me)? "你": ob->name(),
		(int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance(),
		arg);
	return 1;
}
int help (object me)
{
        write(@HELP
指令格式: inventory
 
可列出你目前身上所携带的所有物品。
 
注 : 此指令可以 " i " 代替。
 
HELP
);
        return 1;
}
