//������100�����II
 // xiaoer.c ƽ���ǵ�С�� 
//����lywin 2000/6/1 ��ͯ��  
#include <ansi.h>
#include <command.h>
 inherit NPC;
  void consider();
 int do_gongzuo();
 int ask_done();
 void create() 
{ 
        set_name("��С��", ({"xiao er", "xiao"}));
         set("gender", "����");
         set("age", 25); 
        set("long",                  "����ƽ����ջ�ĵ�С����\n");
         set("qi", 100); 
        set("max_qi", 100);
         set("jing", 100);
         set("max_jing", 100);
         set("per", 25); 
                 set("combat_exp", 1500);
         set("score", 200);
                  set("inquiry", ([  
               "����" : (: do_gongzuo :), 
                "job"  : (: do_gongzuo :),  
               "work" : (: do_gongzuo :),
         ]) ); 
         setup();
         carry_object("clone/cloth/cloth")->wear();
 }
 int do_gongzuo()
 {               object me;
         me = this_player(); 
              if (me->query("combat_exp")>=10000)
     {                 tell_object(me,"���С����ô�������Ĵ�ݡ�\n");
                 return 1;
     }  
     if( me->query_temp("gongzuo/xipanzi")>0)
     {                 tell_object(me,"��ȥϴ���Ӱɡ�\n");
                 return 1;
     } 
      message_vision(CYN"С����$N˵�����⼸����˶࣡����ϴ����������ȥ�����ҹ���Ҫ��������ϴ�ɡ�\n"NOR,me);
          me->set_temp("gongzuo/xipanzi", 1); 
        return 1;
    }
 int accept_object(object me, object ob)
 {         object ob1; 
        if (me->query_temp("gongzuo/xipanzi")<1)         
{ 
         command("say ��û������Ҫ�������ɡ�\n");
         }         else if ( ob->query("name") != "����" ) 
//        else if (strsrch(ob->query("name"), "����") < 0) 
         {             command("say ����ϴ�õ����ӣ��㲻�ǿ���Ц�ɣ�\n"); 
        }         else         
{     message_vision(CYN"С����$N˵���������ˣ�������Ĺ�Ǯ��\n"NOR,me); 
    message_vision(CYN"С���ݸ�$NһЩ���ӡ�\n"NOR,me); 
                  me->delete_temp("gongzuo/xipanzi");
                 me->delete_temp("gongzuo/gepanzi"); 
                if (me->query("combat_exp")>=5000)
                 {                   me->add("combat_exp",2); 
                  me->add("potential",1);   
                ob1=new("/clone/money/silver");  
                 ob1->move(me); 
                   call_out("destroying", 1, this_object(), ob); 
                } 
                else if (me->query("combat_exp")< 5000)
                 {  
               me->add("combat_exp",30+random(10)); 
                me->add("potential",10+random(10));
                 ob1=new("/clone/money/silver");
                 ob1->move(me); 
                 call_out("destroying", 1, this_object(), ob); 
                } 
            return 1; 
        }     
return 0;
 } 
 void destroying(object me, object obj) { 
//        destruct(obj); 
        return;
 } 
