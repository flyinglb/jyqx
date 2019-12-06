// obtree.c
// by atu@sjfy
#include <ansi.h>
inherit F_CLEAN_UP;
void drawtree(object,int);

int main(object me, string arg)
{
	object ob;
	if(!arg)
		return notify_fail("你要看什么东东的继承树呀？\n");
	if (!objectp(ob = find_object(arg))){
		arg=(string)me->query("cwd")+arg+".c";
		ob=find_object(arg);
		if(!objectp(ob))
			return notify_fail("找不到这个OBJECT。\n");
	}
	write(HIR"☆"WHT+(stringp(ob->name(1))?ob->name(1):ob->query("short"))+"的继承结构树"HIR"☆\n"NOR);
	drawtree(ob, 0);
	write(NOR "\n");
	return 1;
}
void drawtree(object ob, int level)
{
	string * pig;
	int i = level;
	if (!ob)
		return;
	write(RED);
	while ( --i > 0 )
		write("   ｜");
	if (level)
		write("   ├—");
	write(YEL);
	write(base_name(ob) + NOR "\n");
	pig = inherit_list(ob);
	if (!sizeof( pig))
		return;
	foreach( string str in pig)
	{
		object obj;
		obj = find_object(str);
		if (!obj)
			catch( obj = new (str) );
		if (!obj)
			return;
		drawtree( obj , level +1);
	}
	return;
}
int help()
{
	write(@TEXT
指令格式：obtree <文件名>

这个指令可以画出指定物件的继承树。
TEXT);
	return 1;
}


