// xian. 冼老板

inherit NPC;
inherit F_DEALER;

 int do_xiwan();
 int do_finish();
void create()
{
	set_name("冼老板", ({ "xian laoban", "xian" }));
	set("title", "醉仙楼老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 45);
	set("long", "洗老板经营祖传下来的醉仙楼已有多年。\n");
	set("combat_exp", 50000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	set("vendor_goods", ({
		__DIR__"obj/hdjiudai",
		__DIR__"obj/kaoya",
	}));
        set("inquiry", ([
                "洗碗" : (: do_xiwan :),
                "工作" : (: do_xiwan :),
                "job" : (: do_xiwan :),
                "完成" : (: do_finish :),
                "工钱" : (: do_finish :),
                "finish" : (: do_finish :),
        ]) );
	setup();
        add_money("gold", 1);
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
//        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
 int do_xiwan()
{
          int pot;
          object me;
        me = this_player(); 
pot = (int) (me->query("potential")) - (int) (me->query("learned_points"));
 if(pot >= 1000 )
{
                tell_object(me,"冼老板上下打量了你一会说道：“现在没什么活可以让你干的。”\n");
   return 1;
}
    if( me->query("combat_exp") > 10000 )
    {
                       message_vision(CYN"冼老板对$N说道：哟！我可不敢劳您大驾。\n"NOR,me); 
        return 1;
}
    if( me->query_temp("xiwan") == 1 )
    {
                tell_object(me,"不是让你去洗碗吗？\n");
                return 1;
    }  
    message_vision(CYN"冼老板对$N说道：你去楼下的厨房洗碗吧。\n"NOR,me); 
        me->set_temp("xiwan", 1);
        return 1;   
}
 int do_finish()
{
         object me,obj;
       me = this_player(); 
        if (me->query_temp("xiwan") < 1)
{
                message_vision(CYN"冼老板对$N说道：你想骗工钱啊! \n"NOR,me);
                return 1;
}
         if (me->query_temp("xiwan") != 10)
{
                tell_object(me,"你还没洗完呢。就想要工钱？\n");
                return 1;
}
else
{
        message_vision(CYN"冼老板对$N说道：做的不错，这是工钱。\n"NOR,me);
        message_vision(CYN"冼老板递给$N一些碎银。\n"NOR,me);  
               me->delete_temp("xiwan");
        obj=new("/clone/money/silver");
       obj->set_amount(5+random(5));
        obj->move(me);
        return 1; 
}
}
