#include <ansi.h>
inherit ITEM; 

void setup() 
{}
void init() 
{
	add_action("do_eat", "eat"); 
}
void create() 
{
	set_name(HIR "还魂丹" NOR, ({ "huanhun dan" , "dan" })); 
	if (clonep()) 
		set_default_object(__FILE__); 
	else {
		set("unit", "颗"); 
		set("long", "这是一颗还魂丹,是恢复功夫的灵药。\n"); 
		set("no_get", "这样东西不能离开那儿。\n"); 
}
	setup(); 
} 

int do_eat(string arg) 
{ 
	object me = this_player(); 
	mapping hp_status, skill_status; 
	string *sname; 
	int i; 

	if (!id(arg)) 
		return notify_fail("你要吃什么？\n"); 

	skill_status = me->query_skills(); 
	if (!skill_status) 
		return notify_fail("你用不着吃还魂丹。\n"); 
	sname  = keys(skill_status);
	for(i=0; i<sizeof(skill_status); i++) {
		me->set_skill(sname[i], skill_status[sname[i]]+1);
        }

	hp_status = me->query_entire_dbase(); 
	{
	if ((int)me->query("combat_exp",1) < 980000 )
		{
		me->set("combat_exp",hp_status["combat_exp"]*50/49); 
		}
	else
		{
		me->add("combat_exp", 20000);
		}
	}
	me->set("shen",hp_status["shen"]*10/9); 

	me->save(); 
	write(HIR "你吃下一颗还魂丹,感觉一阵肚痛,功力顿时全部恢复了。\n" NOR, me); 
        move(VOID_OB); 
	destruct(this_object()); 
	return 1; 
} 

