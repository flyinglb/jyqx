//NPC /npc/shizhe.c

inherit NPC;
#include <ansi.h>

void greeting(object);
void init();

void create()
{
        set_name("����ʹ��", ( { "shi zhe", "zhe" }) );
        set("gender", "����" );
        set("age", 30);
        set("long",
              "���Ǹ����Ż��µ���ʮ���꺺�ӣ��ֳ�ľ�������ޱ��顣\n"
             );
        set("attitude", "friendly");
        set("shen_type", 1);

        set("str", 30);
        set("int", 39);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 330);
        set("max_jing", 320);
        set("neili", 300);
        set("max_neili", 300);

        set("combat_exp", 16000);
        set("score", 10000);

        set_skill("force", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 50);
        set_temp("apply/armor", 50);

        set_temp("ling",0);
        set_temp("times",5);
        create_family("���͵�", 2, "����");

        set("inquiry", ([
            "���͵�" : "С���������һ���ӣ�����û��˵����\n",
            "����"   : "�ϱ߻��м��Ҵ������Լ�����ȥ�ɣ�\n",
        ]));
        setup();
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
}

void greeting(object ob)
{

        if( !ob || environment(ob) != environment() ) return;
        say("����ʹ��˵������λ" + RANK_D->query_respect(ob)
                + "����ҽй�������ʲô����\n");
             return;
}

int accept_object(object who, object ob)
{
    object ling1;
    object ling2;
    object room, myenv;
 
    if( !who || environment(who) != environment() ) return 0;
    if ( !objectp(ob) ) return 0;
    if ( !present(ob, who) ) return notify_fail("��û�����������\n");

    if ( (string)ob->query("id") != "shan pai"
         && (string)ob->query("id") !="e pai" )
    {
          return notify_fail("�Ҳ���Ҫ���������\n");
    }
    if ( query_temp("times")==0 )
    {
          return notify_fail("��̫���ˣ����������\n");
    }
    if ( (string)ob->query("id") == "shan pai" )
    {
          if ( (string)ob->query_temp("own") != (string)who->query("id") )
          {
message_vision("�ⲻ��������ӡ���������ƭ�ң������뺦�Ҽ���������\n",who);
                return 0;
          }
          if (query_temp("ling")==2)
          {
message_vision("ʹ��һ��������ͭ�ƣ�����Ǹ��ض�$N˵���ϵ���ͭ�ƹ����飬�㻹ȱһ�鷣��ͭ�ơ�\n",who);
              return 0;
          }
          add_temp("ling",2);
          if(!( room = find_object("/d/xiakedao/duchuan")) )
              room = load_object("/d/xiakedao/duchuan");

          room = find_object("/d/xiakedao/duchuan");
          room->add_temp("pai",2);

          if( query_temp("ling")==2 )
          { message_vision("ʹ��һ��������ͭ�ƣ�������ϲ�ض�$N˵���㻹��һ�鷣��ͭ����\n",who);
              return 1;
          }
     }

     if ( (string)ob->query("id") == "e pai" )
     {
          if ( (string)ob->query_temp("own") != (string)who->query("id") )
          {
message_vision("�ⲻ��������ӡ���������ƭ�ң������뺦�Ҽ���������\n",who);
              return 0;
          }
          if(query_temp("ling")==1)
          {
message_vision("ʹ��һ���Ƿ���ͭ�ƣ������ź��ض�$N˵������ͭ��һ�����飬�㻹ȱ����ͭ�ơ�\n",who);
              return 0;
          }
          add_temp("ling",1);
          if(!( room = find_object("/d/xiakedao/duchuan")) )
              room = load_object("/d/xiakedao/duchuan");
          room = find_object("/d/xiakedao/duchuan");
          room->add_temp("pai",1);
          //command("say " +(string)room->query_temp("pai") +"haha");
          if( query_temp("ling")==1 )
          {
message_vision("ʹ��һ���Ƿ���ͭ�ƣ�������ϲ�ض�$N˵���㻹������ͭ����\n",who);
              return 1;
          }
     }

     command("smile "+(string)who->query("id"));
     message_vision("ԭ�������͵��Ĺ������������ϵ�ȥ�ɡ�\n",who);
     ling1 = new("/d/xiakedao/obj/tongpai1");
     ling1->set_temp("own",who->query("id"));
     ling1->move(who);
     ling2 = new("/d/xiakedao/obj/tongpai2");
     ling2->set_temp("own",who->query("id"));
     ling2->move(who);
     set_temp("ling",0);
     add_temp("times",-1);
     myenv = environment (who) ;
     who->move("/d/xiakedao/duchuan");
     tell_room(myenv,
     "����ʹ���������֣�һֻС�ۿ�����"+who->query("name")+"�粽�ϴ���\n");
     tell_object(who, BLU "���ں��Ϻ�����������ҹ.......\n"NOR);
     call_out("goto_xiake",10,who) ;
     return 1;
}

void goto_xiake(object ob)
{
     tell_object(ob , "������ͣ����һ��С���ߡ������´�����\n" ) ;
     ob->move ("/d/xiakedao/haitan") ;
}
