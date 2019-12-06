// judge.c
// modified by wind
#include <ansi.h>

inherit NPC;
void create()
{
        set_name("����", ({ "judge" }) );
        set("gender", "����" );
        set("age", 22);
        set("long", "�����ϵı���·��ǿ�������ڴ����Ǯһ�㡣\n");
        set("per", 25);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 70);
        set("inquiry", ([
                "��" : "���ĳ����Ŷġ���С�����ӣ���Ҫ������Ȥ���������ѣ�(ya big|small <����> <��������>)",
        ]) );
        setup();
        add_money("silver", 1);
        set("accept",1);
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/dagger")->wield();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
           remove_call_out("greeting");
           call_out("greeting", 1, ob);
        }
        add_action("do_ya", "ya");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) )
        {
          case 0:
                 say( "�����ģ�����������\n");
                 break;
          case 1:
                 say( "Ӯ�˿�������������\n");
                 break;
        }
}

int do_ya(string arg)
{
    int ran,cnt;
    string type0, type1,status;
    object money_ob,me;

    int min, max;
    min = 100;
    max = 1000000;

    me = this_player();

    if (!arg || sscanf(arg, "%s %d %s", type0, cnt,type1) !=3)
      return notify_fail("ya big|small <����> <��������>\n���磺ya big 3 silver\n");
    money_ob = present(type1,me);
    if( !money_ob)
      return notify_fail(HIY"������û�����ֻ��ҡ�\n");
    if( cnt<1 )
      return notify_fail("��Ҫѹ���ٰ�?\n");
    if( (int)money_ob->query_amount() < cnt)
      return notify_fail("������û����ô��" + money_ob->query("name") + "��\n");
    if( cnt*money_ob->query("base_value") < min || cnt*money_ob->query("base_value") >(max+1)) 
      return notify_fail("��Ķ�ע�����޶�֮��!\n������޶���һ��������һ�����ƽ�\n");
    if ( (type0 != "big") && (type0 != "small") ) 
      return notify_fail("��ҪѺ����ѽС?\n");

    ran=random(10);
    
    if (ran>=5) 
         message_vision(HIY"����������"HIM"��"NOR"\n", me);
    else
         message_vision(HIY"����������"HIC"С��"NOR"\n", me);
       

    if ((ran>=5 && type0=="small") || (ran<5 && type0=="big")) status="lose";
    else status="win";

    if ( status == "lose") 
     {
       message_vision(me->query("name") + "����" + chinese_number(cnt) +money_ob->query("base_unit") + money_ob->query("name") + "��\n", me);
       money_ob->set_amount((int)money_ob->query_amount() - cnt);
       money_ob->move(me);
      }
    else
     {
       message_vision(me->query("name") + "Ӯ��" + chinese_number(cnt) +money_ob->query("base_unit") + money_ob->query("name") + "��\n", me);
       money_ob->set_amount((int)money_ob->query_amount() + cnt);
       money_ob->move(me);
      }
    return 1;
}
