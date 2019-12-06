// xian. ���ϰ�

inherit NPC;
inherit F_DEALER;

 int do_xiwan();
 int do_finish();
void create()
{
	set_name("���ϰ�", ({ "xian laoban", "xian" }));
	set("title", "����¥�ϰ�");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "����");
	set("age", 45);
	set("long", "ϴ�ϰ徭Ӫ�洫����������¥���ж��ꡣ\n");
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
                "ϴ��" : (: do_xiwan :),
                "����" : (: do_xiwan :),
                "job" : (: do_xiwan :),
                "���" : (: do_finish :),
                "��Ǯ" : (: do_finish :),
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
                tell_object(me,"���ϰ����´�������һ��˵����������ûʲô���������ɵġ���\n");
   return 1;
}
    if( me->query("combat_exp") > 10000 )
    {
                       message_vision(CYN"���ϰ��$N˵����Ӵ���ҿɲ���������ݡ�\n"NOR,me); 
        return 1;
}
    if( me->query_temp("xiwan") == 1 )
    {
                tell_object(me,"��������ȥϴ����\n");
                return 1;
    }  
    message_vision(CYN"���ϰ��$N˵������ȥ¥�µĳ���ϴ��ɡ�\n"NOR,me); 
        me->set_temp("xiwan", 1);
        return 1;   
}
 int do_finish()
{
         object me,obj;
       me = this_player(); 
        if (me->query_temp("xiwan") < 1)
{
                message_vision(CYN"���ϰ��$N˵��������ƭ��Ǯ��! \n"NOR,me);
                return 1;
}
         if (me->query_temp("xiwan") != 10)
{
                tell_object(me,"�㻹ûϴ���ء�����Ҫ��Ǯ��\n");
                return 1;
}
else
{
        message_vision(CYN"���ϰ��$N˵�������Ĳ������ǹ�Ǯ��\n"NOR,me);
        message_vision(CYN"���ϰ�ݸ�$NһЩ������\n"NOR,me);  
               me->delete_temp("xiwan");
        obj=new("/clone/money/silver");
       obj->set_amount(5+random(5));
        obj->move(me);
        return 1; 
}
}
