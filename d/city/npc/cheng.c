#include <ansi.h>
inherit NPC;


void create()
{
        set_name("��ҩ��", ({ "cheng yaofa", "cheng" }));
        set("title", "����֪��");
        set("gender", "����");
        set("age", 43);
        set("str", 20);
        set("dex", 20);
        set("long", "�����ǳ�ҩ������������֪����\n");
        set("combat_exp", 30000);
        set("shen_type", 0);
        set("attitude", "heroism");

        set_skill("unarmed", 50);
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/armor", 150);
        set_temp("apply/damage", 150);

        set("neili", 500); 
        set("max_neili", 500);
        set("jiali", 10);
	set("no_get", 1);

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
        ::init();
        add_action("do_chat", "chat");
        add_action("do_chat","chat*");
        add_action("do_jiehun","jiehun");
        add_action("do_jiehun","marry");
        add_action("do_lihun","lihun");
}

int do_chat()
{
   object ob;
   ob=this_player(1);
  
   say(HIW "֪����ɫһ�����ȵ���������֮�ϣ�������������\n" NOR);
   tell_object(ob, HIR "�������۳���ǰ�������ɷ�˵��һ��������"
                  +"Ƥ������,���˹�ȥ��\n" NOR);
   ob->unconcious();
   return 0;
}


int do_lihun(string arg)
{
object me;
object ob;

object *inv;
int i;

me=this_player(1);

if(!arg)   {
             tell_object(me,"��Ҫ��˭��鰡��\n");
             return 1;
            }

if( !objectp(ob = find_player(arg)))
         {
            tell_object(me,"������᲻�ڡ�\n");
            return 1;
         }


 say(me->query("name")+"��Ҫ��"+ob->query("name")+"���.\n");

      if( me->query("couple/couple_id") !=arg )
        {
          say("֪���ɻ�Ŀ��˿�"+me->query("name")+
                "˵������û�������\n");
          return 1;
        }

      if(!me->query("couple/have_couple"))
        {
         say("֪�����ȵ���"+me->query("name")+
             "����û�а��£�������?��\n");
         return 1;
        }

      if(!present(arg,environment()))
        {
         say("֪��ҡҡͷ˵:��"+ob->query("name")+"���ڲ��������\n");
         return 1;
        }
      if( ob->query("want_lihun")==me->query("id") )
        {
         say("֪��̾Ϣ�������������ñ���ʧ������\n");

         inv=all_inventory(me);
         for(i=0;i<sizeof(inv);i++)      
            {
             if(inv[i]->query("id")=="jiehunzheng") 
              {
                destruct(inv[i]);
              }
            }
         inv=all_inventory(ob);
         for(i=0;i<sizeof(inv);i++)
            {
             if(inv[i]->query("id")=="jiehunzheng")
              {
                destruct(inv[i]);

              }
            }

         me->delete("couple");
         me->delete("want_marry");
         me->delete("want_lihun");
         me->delete("marry_ok");
         me->delete("marry");
         ob->delete("couple");
         ob->delete("want_marry");
         ob->delete("want_lihun");
         ob->delete("marry");
         ob->delete("marry_ok");
         tell_object(me,"��Ļ�����ϵ�������\n");
         tell_object(ob,"��Ļ�����ϵ�������\n");
         message("shout", HIC "���ٸ�ͨ�桿��" + HIB + "�ֽ�" + me->query("name") + "��" 
         +ob->query("name") + "������ϵ�����\n" NOR,users());        
      }
      else
        {
         say("֪����:��"+me->query("name")+"����뷨��֪����"+
             ",������Ҫ����"+ob->query("name")+"����˼����\n");
         me->set("want_lihun",arg);
         return 1;
        }

return 1;
}



int do_jiehun(string arg)
{
object me;
object ob;
object card;

me=this_player(1);

if ( me->query("gender")=="����") 
           
           { tell_object(me,"�����޸�֮����ν�飿\n");
             return 1;}
if(!arg)   {
             tell_object(me,"���Լ����Լ���鰡��\n");
             return 1;
            }

if( (string)me->query("class")=="bonze" ) 
            {
             tell_object(me,"��������ô������Ҳ�뿪ɫ������?\n");
             return 1;
            }

if( !objectp(ob = find_player(arg)))
         {
            tell_object(me,"�������Ŀǰ����������ɣ�\n");
            return 1;
         }


      say(me->query("name")+"��Ҫ��"+ob->query("name")+"���.\n");
      
      if(me->query("age") <16)
        {
         say("֪��ҡҡͷ����Ȼ��û�ﵽ������䡣\n");
         return 1;
        }

      if(me->query("couple/couple_id")== arg )
        {
          say("֪���ɻ�Ŀ��˿�"+me->query("name")+
                "˵������������飿��\n");
          return 1;
        }
      if(me->query("id")== arg )
        {
          say("֪���ɻ�Ŀ��˿�"+me->query("name")+
                "˵:�����������񰡣���\n");
          return 1;
        }
      if(me->query("couple/have_couple")) 
        {
         say(HIW "֪����ŭ��һ�����Ӻȵ�����"+me->query("name")+
             "�����а��£������ػ飡��\n" NOR);
         say("�������۳���ǰ�������ɷ�˵��һ������"+
               me->query("name")+"Ƥ������,���˹�ȥ��\n");
         me->unconcious();
         return 1;
        }
      
      if(!present(arg,environment()))
        {
         say("֪��ҡҡͷ˵:��"+ob->query("name")+"���ڲ��������\n");
         return 1;
        }
      if( ob->query("want_marry")== me->query("id") )
        {
         say("֪��΢Ц������ף��������ͷг�ϣ����޶��ġ���\n");   
         
         ob->set("couple/have_couple",1);
         ob->set("couple/couple_id", me->query("id"));
         ob->set("couple/couple_name", me->query("name"));
         ob->set("marry/id",me->query("id")); 
         ob->set("marry/name",me->query("name"));                 
         if (me->query("gender")=="����")
          { ob->set("couple/couple_gender","�Ϲ�");}
         else
           { ob->set("couple/couple_gender","����");}
         
         me->set("couple/have_couple",1);
         me->set("couple/couple_id",ob->query("id"));
         me->set("marry/id",ob->query("id"));
         me->set("couple/couple_name",ob->query("name"));
         me->set("marry/name",ob->query("name"));
         if (ob->query("gender")=="����")
          { me->set("couple/couple_gender","�Ϲ�");}
         else
           {me->set("couple/couple_gender","����");}

         card= clone_object("/clone/misc/marry-token.c");
         card->move(me);
         card= clone_object("/clone/misc/marry-token.c");
         card->move(ob);
         me->delete("want_marry");
         ob->delete("want_marry");
         message("shout", HIC "���ٸ�ͨ�桿��" + HIR + "��ϲ" + me->query("name") + "��" 
         +ob->query("name") + "ϲ������\n"+"\n"+
         " 
         ��        �� 
    ����������������������
         ��        ��
     ��������������������
       ������    ������
       ��  ��    ��  ��
       ������    ������
        ����      ����
     ��������������������
       ������    ������
       ��  ��    ��  ��
       ������    ������\n"             
          NOR,users());
         return 1 ;
       } 
      else
        {
         if( me->query("gender") == ob->query("gender") )
          {
           say ("֪����"+me->query("name")+
                  "���ÿ��°�ĭ���˹�ȥ���ȵ�����Ī�����ж���֮񱣿��\n");
           return 1;
          }
         say("֪��΢Ц��:��"+me->query("name")+",���������֪����"+
             ",������Ҫ����"+ob->query("name")+"����˼����\n");
         me->set("want_marry",arg);
         return 1;
        }

return 1;
}

