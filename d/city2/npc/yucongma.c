// yucongma.c
inherit NPC;
inherit F_UNIQUE;
#include <ansi.h>
void create()
{
	set_name(HIC "������" NOR, ({ "yu cong ma","yu","ma"}));
	set("race", "Ұ��");
	set("gender", "����");
	set("age", 2+random(3));
	set("long", "����һƥ������������ǧ�ҹ�а˰١�\n"+
		"��ҿ���������ȥ�κεط�(ride/down)��\n");
	set("int", 30);
	set("qi", 300);
	set("max_qi", 300);
	set("jing", 100);
	set("max_jing", 100);
	set("shen_type", 0);
	set("combat_exp",50000);
	set("attitude", "peaceful");

	set("limbs", ({ "ͷ��", "����", "β��","����","ǰ��" }) );
	set("verbs", ({ "bite","hoof","knock" }) );
	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);

	setup();
}

void init()
{
        add_action("do_ride", "ride");
        add_action("do_go", "go");
        add_action("do_down", "down");
        remove_call_out("destme");
        call_out("destme", 90);
}
void destme()
{
	message_vision("$N��˻һ������ͷ�ر�����������ȥ�ˡ�\n",this_object());
        destruct(this_object());
}                    

int do_ride ( )
{
    object ob = this_player () ;
    if(ob->query("meili")<20)
    {
          message_vision("$NһԾ�������������ֻ�����������쳤Х��ͻȻ��Ȼһ��......\n"
                     HIR "��$N�ݺ�ˤ���˵��ϣ����$N���˵����ˡ�\n" NOR,ob);
          ob -> receive_damage ("qi",50) ;
          ob -> receive_wound  ("qi",50) ;
          remove_call_out("kill_ob");
          call_out("kill_ob", 1, ob);
          return 1;
    }
    if( objectp(query("rider"))) 
    {
          return notify_fail("���������Ѿ������ˣ�\n" ) ;
    }
    else
    {    
          ob->set_temp("onhorse",1);
          this_object()->set("rider",this_player());
          message_vision("$NһԾ�������������\n" , ob );
          this_object()->set_leader(this_player());
          command("follow "+ob->query("id"));
          write("������Ҫȥ�ĵ���, ʾ��(go baituo):\n"+
          "         beijing:  ������\n"+
          "         yangzhou: ���ݳ�\n"+
          "         shaolin:  ������\n"+
          "         taohua:   �һ���\n"+
          "         baituo:   ����ɽ\n"+
          "         xingxiu:  ���޺�\n"+
          "         xueshan:  ѩɽ��\n"+
          "         huashan:  ��  ɽ\n");
          return 1; 
    }
}

int do_down()
{
    object ob;
    ob = this_player () ;
    if(!objectp(query("rider"))) return notify_fail("����û�ˡ�\n");
    if(ob->query_temp("onhorse"))
    {
          message_vision("\n$N����һת��Ծ����������̬ʮ��������\n" , ob );
          delete("rider");
          command("follow none");
          ob->delete_temp("onhorse");
    }
    else 
    switch(random(3))
    {
          case 0: 
message_vision("\n$Nһ�Ѱ����ϵ��������������Լ�����ȥ��\n" , ob );
              command("follow none");
              query("rider")->delete_temp("onhorse");
              delete("rider");
              ob->set_temp("onhorse");
              break;
          case 1: 
          case 2:
   message_vision("\n$N������ϵ�����������,��û�гɹ���\n" , ob );
    }	  
    return 1;
 }

int do_go ( string arg )
{
    object ob ;
    ob = this_player () ;
    if( !arg || arg=="" )  return notify_fail("��Ҫȥ�Ķ���\n");
    if(!ob->query_temp("onhorse")) return notify_fail("�㻹û����\n");
    message_vision("\nֻ��$N������һ�У���������ǰ���۶�ȥ��\n" , ob );
    switch (arg)
    {
         case "baituo": 
               remove_call_out("baituo");
               call_out("baituo", 10, ob);
               return 1 ;
         case "xueshan": 
               remove_call_out("xueshan");
               call_out("xueshan", 10, ob);
               return 1 ;
         case "taohua": 
               remove_call_out("taohua");
               call_out("taohua", 10, ob);
               return 1 ;
         case "huashan": 
               remove_call_out("huashan");
               call_out("huashan", 10, ob);
               return 1 ;
         case "beijing": 
               remove_call_out("beijing");
               call_out("beijing", 10, ob);
               return 1 ;
         case "xingxiu": 
               remove_call_out("xingxiu");
               call_out("xingxiu", 10, ob);
               return 1 ;
         case "shaolin":
               remove_call_out("shaolin");
               call_out("shaolin", 10, ob);
               return 1 ;
        case "yangzhou": 
               remove_call_out("yangzhou");
               call_out("yangzhou", 10, ob);
               return 1 ;
    }
    return notify_fail("û������ط�\n");
}

void baituo(object ob)
{
    ob->move("/d/baituo/damen");
    this_object()->move("/d/baituo/damen");
    message_vision("\nֻ��$N������������������\n" , ob );
    message_vision("\n������ǰ��$N����һת��Ծ����������̬ʮ��������\n" , ob );
    delete("rider");
    ob->delete_temp("onhorse");
    command("follow none");
}
void xueshan(object ob)
{
    ob->move("/d/xueshan/shenghu") ;
    this_object()->move("/d/xueshan/shenghu");
    message_vision("\nֻ��$N������������������\n" , ob );
    message_vision("\n������ǰ��$N����һת��Ծ����������̬ʮ��������\n" , ob );
    delete("rider");
    ob->delete_temp("onhorse");
    command("follow none");
}
void taohua(object ob)
{
    ob->move("/d/taohua/dayuan") ;
    this_object()->move("/d/taohua/dayuan");
    message_vision("\nֻ��$N������������������\n" , ob );
    message_vision("\n������ǰ��$N����һת��Ծ����������̬ʮ��������\n" , ob );
    delete("rider");
    ob->delete_temp("onhorse");
    command("follow none");
}
void huashan(object ob)
{
    ob->move("/d/huashan/path1") ;
    this_object()->move("/d/huashan/path1") ;
    message_vision("\nֻ��$N������������������\n" , ob );
    message_vision("\n������ǰ��$N����һת��Ծ����������̬ʮ��������\n" , ob );
    delete("rider");
    ob->delete_temp("onhorse");
    command("follow none");
}
void beijing(object ob)
{
    ob->move("/d/city2/tian_anm") ;
    this_object()->move("/d/city2/tian_anm") ;
    message_vision("\nֻ��$N������������������\n" , ob );
    message_vision("\n������ǰ��$N����һת��Ծ����������̬ʮ��������\n" , ob );
    delete("rider");
    ob->delete_temp("onhorse");
    command("follow none");
}
void xingxiu(object ob)
{
    ob->move("/d/xingxiu/xxroad2") ;
    this_object()->move("/d/xingxiu/xxroad2") ;
    message_vision("\nֻ��$N������������������\n" , ob );
    message_vision("\n������ǰ��$N����һת��Ծ����������̬ʮ��������\n" , ob );
    delete("rider");
    ob->delete_temp("onhorse");
    command("follow none");
}
void shaolin(object ob)
{
    ob->move("/d/shaolin/shanmen") ;
    this_object()->move("/d/shaolin/shanmen") ;
    message_vision("\nֻ��$N������������������\n" , ob );
    message_vision("\n������ǰ��$N����һת��Ծ����������̬ʮ��������\n" , ob );
    delete("rider");
    ob->delete_temp("onhorse");
    command("follow none");
}
void yangzhou(object ob)
{
    ob->move("/d/city/guangchang") ;
    this_object()->move("/d/city/guangchang") ;
    message_vision("\nֻ��$N������������������\n" , ob );
    message_vision("\n������ǰ��$N����һת��Ծ����������̬ʮ��������\n" , ob );
    delete("rider");
    ob->delete_temp("onhorse");
    command("follow none");
}
