// caoyao.c 草药

inherit ITEM;

void create()
{
        set_name("草药", ({ "cao yao",  }));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "一棵不知名的药草。\n");
        set("value", 0);
	}
}

void init()
{
        object who = this_player();
        if(environment() == who) {
        if(who->query_temp("job_xiaoyao") 
        && who->query("family/family_name") == "逍遥派")
        set("long","这是一棵不甚起眼的草药，看来这东西可以拿回去交差。\n");
        set("job", 1);//保留标记
        }
}
