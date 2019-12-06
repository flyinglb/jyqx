// baby.c

inherit NPC;

void try_move();

void create()
{
        set_name("����", ({"xiao baobao","baby"}) );
        set("gender", "Ů��");
        set("age", 1);
        set("attitude", "friendly");
        set("long","�Ա�����\n");
        set("combat_exp", 1);
        set("str",3);
        set("parents",({"dad","mom"}));
   
        set("chat_chance", 2);
        set("chat_msg", ({
           (: random_move :)
        }));

        set("is_baby",1);
        // to allow the identification of baby. by mon.

        setup();
}

void init()
{
       add_action("do_kill",({"kill","fight","hit","steal"}));
       add_action("do_get","get");
       add_action("do_drop","drop");
       /* follow is very costly to execute. 5/6/98 mon.
       if(member_array(this_player()->query("id"),
             this_object()->query("parents"))>-1)
       {
             this_object()->set_leader(this_player());
       }
   */
   
       remove_call_out("try_move");
       call_out("try_move",1);
}

void try_move()
{
      if(random(20)==0)
      {
             remove_call_out("random_move");
             call_out("random_move",5);
      }
}

int do_drop(string arg)
{
      object me=this_object(),who=this_player(),env;
      if(!arg) return 0;
      env = environment(who);
      if(present(arg,who)!=me) return 0;
      if(me->move(env))
      {
             message_vision("$N��$n�ӻ������������\n",who,me);
             return 1;
      }
      return 0;
}

int do_get(string arg)
{
      object me=this_object(),who=this_player(),env;

      if(!arg) return 0;
      env = environment(who);
      if(present(arg,env)!=me) return 0;
      if(member_array(who->query("id"),
             me->query("parents"))>-1)
      {
             if(me->move(who))
             {
                   message_vision("$N��������$n����������§�ڻ��\n",who,me);
             }
             else
             {
                   message_vision("$N������һ��ȴû��$n��������С�һ�ó��ģ�\n",who,me);
             }
      }
      else
      {
             message_vision("$N������$n�쿪˫�֣�$nȴһ���������ˣ�����\n",who,me);
      }
      return 1;
}

int do_kill(string arg)
{       
      object me,who;
//      string name,verb,what,obj;
      string verb,what,obj;
      if (!arg) return 0;
      verb=query_verb();
      me=this_player();
   
      if(verb=="steal")
      {
             if(sscanf(arg, "%s from %s", what, obj)!=2 ) 
             return 0;
      }
      else obj=arg;

      if(!objectp(who=present(obj,environment(me))) 
            || !living(who)) return 0;
//    if(who->query("is_baby")) {
      if(who==this_object())
      {
             switch(verb)
             {
                    case "kill":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"ƴ���ؿ����������������������"+
                             me->query("name")+"Ҫɱ�ң����������ѽ��\n");
                         break;
                    case "hit":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"������������������������"+
                             me->query("name")+"�۸��ң����������ѽ��\n");
                         break;
                    case "fight":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"�����������������������"+
                             me->query("name")+"Ҫ���ҵ��ǳԣ����������ѽ��\n");
                         break;
                    case "steal":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"�����������������������"+
                             me->query("name")+"Ҫ͵���ҵ��ǣ�\n");
                         break;
                    case "beg":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"С��һ������������������������"+
                             me->query("name")+"Ҫƭ�ҵ��ǳԣ�\n");
                         break;
             }
      }
      command(verb);
      return 0;
}

void relay_emote(object ob, string verb)
{
      if( !userp(ob) ) return;

      switch(verb)
      {
            case "kick":
                 command("say �������������"  + ob->query("name") + "����Ү��");
                 command("kick " + ob->query("id"));
                 break;
            case "slap":
                 command("say �������������"  + ob->query("name") +
                 "����Ү����ʹ����������");
                 command("slap " + ob->query("id"));
                 break;
            case "hit":
                 command("pain " + ob->query("id"));
                 break;
            case "bite":
                 command("face " + ob->query("id"));
                 break;  
            case "papaya":
                 command("angry");
                 break;  
      }
}

void relay_whisper(object me, string msg)
{
      if (member_array(me->query("id"),query("parents"))==-1)
      {
            message_vision((string)this_object()->query("name")
                        + "�ɻ�ؿ���$N��\n", me);
            return;
      }

      //note, do not allow the order contain "chat", "tell"...
      //may need disable more later...
      if( strsrch(msg, "chat") != -1 ||
          strsrch(msg, "tell") != -1 ||
          strsrch(msg, "follow") != -1 ||
          strsrch(msg, "apprentice") != -1 ||
          strsrch(msg, "recruit") != -1 )
            return;

      if (msg)
      {
            remove_call_out ("relaying");
            call_out ("relaying", 1+random(3), msg);
      }
}

void relaying (string msg)
{
//execute the order.
      command (msg);
}

