// yamen_police.c
#include <ansi.h>
#define THIEF 3
#define ROBBER 5
#define GO 0
#define BACK 1

inherit NPC;

void patrol();
void catchyou(object);
int mygo(string);
//int do_go(string arg);
//int do_quit(string arg);
int accept_bribery(string);

int direction=GO;

mapping BigWay=([
                "/d/city/yamen":({"south",0}),
                "/d/city/xidajie1":({"east","north"}),
                "/d/city/xidajie2":({"east","west"}),
                "/d/city/dongdajie1":({"east","west"}),
                "/d/city/dongdajie2":({"north","west"}),
                "/d/city/guangchang":({"north","south"}),
                "/d/city/nandajie1":({"north","south"}),
                "/d/city/nandajie2":({"north","south"}),
                "/d/city/beidajie1":({"north","south"}),
                "/d/city/beidajie2":({"east","south"}),
                "/d/city/zuixianlou": ({0,"west"}),
                "/d/city/nanmen": ({0,"north"}),
                "/d/city/yaopu": ({0,"south"}),
                ]);

void create()
{
     string *surname=({"Ľ��","����","����","�Ϲ�","�Ϲ�","ŷ��","˾ͽ",});
     set_name(surname[random(sizeof(surname))]+"Ѳ��", ({ "xun bu","police"}) );
     set("gender", "����" );
     set("age", 25);
     set("str", 45);
     set("cor", 50);
     set("cps", 35);
     set("int", 20);
     set("per", 20);
     set("kar", 15);
     set("long",@LONG
Ѳ���������ֽý���ǿ����ɽ���޲��ŷ�ɥ����
LONG
);
     set("status","patrol");
     set("CatchWho",0);
     set("combat_exp", 500000);
     set("attitude", "heroism");
     set("chat_chance_combat", 40);
     set("chat_msg_combat", ({
                            "Ѳ��˵���������ʲô? ��������ȥ��������!?\n",
                            "Ѳ��˵������! ��Ȼ�ҵ��־ܲ�! ���췴��\n",
                            "Ѳ�����еĵ�Խ��Խ�죬����Ӧ�Ӳ�Ͼ��\n",
                            "Ѳ��˵����������ˣ����ǹԹԵĸ����߰ɡ�\n"
                            }) );
     set ("inquiry",([
                "bribery":
"˵���ﻰ������̫ү��ƶ���������������µ�������û����������\n"+
"�������Ǯ�ɣ�\n",
                "salary":
"������үٺ��΢�������ǵ�������Ȼ������......\n",
                "money":
"˵ʵ�ڵģ���Ҳ��ҪǮ����Ҫ������ү֪���������ܻ�¸(bribery)��\n����Ҳ�ðǲ�Ƥ\n
",
                        ]));
     set ("chat_chance",99);
     set ("chat_msg", ({
                      (:call_out,"patrol",0:),
                      }) );
     set("pursuer",1);
     set_skill("blade", 100);
     set_skill("parry", 90);
     set_skill("dodge", 70);
     setup();
     direction=GO;
     carry_object("/clone/weapon/gangdao")->wield();
     carry_object("/clone/misc/cloth")->wear();
     add_money("silver",30);
}

void init()
{
object catchwho,you,*npc;
object oldman,start_room;
int i;
catchwho=query("CatchWho");
you=this_player();
if (query("status")=="patrol")
   {
   if (!is_fighting()&&interactive(you)&&living(you))
      {
        npc=all_inventory(environment());
        i=sizeof(npc);
        while (i--) {
                if (npc[i]->query("id")=="gangster"&&!userp(npc[i]))
                        {
                        say(HIW "�����ʲô���ӣ�\n"+"��Ȼ"+
                                npc[i]->query("name")+
                               "Ҳ���ڴ�������գ�" NOR);
                        npc[i]->remove_all_enemy();
                        say("ȥ���ɣ���\n");
                        EMOTE_D->do_emote( npc[i],"fear");
                        kill_ob(npc[i]);
                        npc[i]->kill_ob(this_object());
                        }
                else if (npc[i]->query("title")=="Ұ��ɽկ��կ��"&&!userp(npc[i]))
                        {
                        say(HIR "�ߣ����°ܽ�������һ������Ҫ��ƽҰ��ɽկ��\n" NOR);
                        npc[i]->remove_all_enemy();
                        EMOTE_D->do_emote( npc[i],"fear");
                        kill_ob(npc[i]);
                        }
                }
        if (you->query("thief")&&random(10)<7)
           {
           say (HIR "���˰���ԭ��"+you->query("name")+
                        "�Ǹ�����! ����һ�˰�!\n" NOR);
           you->add("crime_lv",THIEF);
           you->add("thief",-1);
           if (!you->query("thief")) you->delete("thief");
           catchyou(you);
                return;
           }
        else
            if (you->query("marks/ǿ��")&&random(10)<9)
               {
               message_vision("$N����$n�ȵ������컯��֮�£����ȻҲ������ɱ�ˣ�
�������һ�ȥ�԰��ӣ�\n"
                +"˵�գ�$N������������$n�Ĳ����ϡ�\n",this_object(),you);
                        you->add("crime_lv",ROBBER);
                        you->add("marks/ǿ��",-1);
                        if (!you->query("marks/ǿ��")) you->delete("marks/ǿ��");
                catchyou(you);
                }
        }
   }
else if (query("status")=="catching")
   {
   catchyou(catchwho);
   message_vision(HIR "ֻ��$NͻȻ���������һ����������$n�Ĳ����ϡ�\n"NOR,
                this_object(),catchwho);
   }
else {
      if (objectp(catchwho=this_object()->query("CatchWho")))
        {
            if (BigWay[file_name(environment())][direction]==0)
                        {
        say("try to patrol\n");
                        start_room=find_object("/d/choyin/yamen.c");
                        oldman=find_object("/d/choyin/npc/judgeman.c");
                        oldman=present(oldman->query("id"),start_room);
                        write(oldman->query("id"));
                        catchwho->move(start_room);
                        move(start_room);
                        say("��ү���˷��Ѵ�����С��Ѳ��ȥ�ˡ�\n");
                        set("CatchWho",0);
                        direction=GO;
                        set("status","patrol");
                        move(find_object(query("startroom")+".c"));
                        patrol();
                        call_other(oldman,(:call_out,"settle_lawsuit",catchwho,2:));
                        return;
                        }
                }
        }
//add_action("do_go","go");
//add_action("do_quit","quit");
add_action("accept_bribery","bribe");
}

void patrol()
{
int i,on_way;
 object *content,catchwho,start_room,crime;
string *bigwayname,where,dir;
bigwayname=keys(BigWay);
where=file_name(environment());
write("in patrol\n");
for (i=0;i<sizeof(bigwayname);i++)
    {
    if (where==bigwayname[i])
       {
       on_way=1;
       break;
       }
    else on_way=0;
    }
if (on_way)
   {
   if (this_object()->query("status")=="patrol")
      {
      if (!BigWay[where][direction]) direction=1-direction;
      }
   else if (this_object()->query("status")=="catching")
      {
      catchyou(catchwho);
      message_vision(HIR "ֻ��$NͻȻ���������һ����������$n�Ĳ�����"NOR,
                        this_object(),catchwho);
      }
   else
      {
        write("here???\n");
         }
  }
else
   {
   content=all_inventory(this_object());
   for (i=0;i<sizeof(content);i++)
       {
       if (content[i]->query("id")=="amulet")
                {
                if (!stringp(dir=content[i]->query("map")[where]))
                        {
                        move(start_room=find_object(query("startroom")+".c"));
                        if (objectp(crime=query("CatchWho")))
                                {
                                if (where==file_name(environment(crime)))
                                        crime->move(start_room);
                                }
                        }
                else mygo(dir);
          break;
          }
  }
return;
}
mygo(BigWay[where][direction]);
}

void catchyou(object crime)
{
object ob;
ob=this_object();
while (environment(ob)!=environment(crime))
                   move(environment(crime));
crime->set_leader(ob);
set("CatchWho",crime);
set("status","caught");
crime->set("being_caught",1);
direction=BACK;
return;
}

int mygo(string dir)
{
//GO_CMD->main(this_object(),dir);
command("go "+dir);
return 1;
}

int do_go(string arg)
{
object me;
me=this_player();
if (!me->query("being_caught")) return 0;
tell_object(me, "�ٺ�, ����������?!\n");
return 1;
}

int do_quit(string arg)
{
object me;
me=this_player();
if (!me->query("being_caught")) return 0;
if (is_fighting()&&random(20)<16)
        {
        me->delete("being_caught");
        set("status","patrol");
        return 0;
        }
message_vision(HIR "$N��������$n������, $n�޷��˳�!\n" NOR, this_object(),me);
return 1;
}

void die()
{
object killer,room;
if (objectp(killer=query_temp("last_damage_from")))
        {
        room=find_object(query("startroom"));
        killer->delete("being_caught");
        killer->add("crime_lv",5);
/*      for (i=0;i<2;i++)
                {
                seteuid(getuid());
                ob=new("/d/choyin/npc/yamen_po.c");
                ob->set("call_out",1);
                ob->set("CatchWho",killer);
                ob->set("persuer",1);
                ob->set("startroom",query("startroom"));
                ob->move(environment());
                message_vision(HIR "�󵨿�ͽ��$N...��Ȼ��ɱ¾����$n�����ߣ������
�\n" NOR,killer,this_object());
                ob->kill_ob(killer);
                if (stringp(file=find_command("kill")))
                        {
                        message_vision(file+"$N$n",killer,ob);
                        call_other(file,"main",killer,ob->query("id"));
                        }
                }
*/
        }
::die();
}

int accept_bribery(string arg)
{
object money_ob,me,ob;
string toid,money;
int amount,bv1;
me=this_player();
if(!(me->query("being_caught"))) return 0;
if (!arg||sscanf(arg,"%s with %d %s",toid,amount,money)!=3) return 0;
if (!objectp(present(toid,environment())))
        return notify_fail("��Ҫ��¸˭��\n");
money_ob=present(money+"_money",this_player());
if (!money_ob) return notify_fail("������û�����ֻ��ҡ�\n");
if( amount < 1 ) return notify_fail("����ʹ������Ҫһ��/ÿ�Ρ�\n");
if( (int)money_ob->query_amount() < amount )
                return notify_fail("������û���Ƕ�" + money_ob->query("name") +"��\n");
bv1 = money_ob->query("base_value");
if( !bv1 ) return notify_fail("���ֶ�����ֵǮ��\n");
if (bv1*amount>=100000)
        {
        write("����ô��?......Ҫ������ү֪����......\n");
        write("ʢ����ȴ....�Ҿ�������..\n");
        EMOTE_D->do_emote(this_object(),"grin",me->query("id"));
        ob=new(base_name(money_ob));
        ob->move(this_object());
        ob->set_amount(amount);
        money_ob->add_amount(-amount);
        me->delete("being_caught");
        if (me->query("crime_lv")>3)
                        me->add("crime_lv",-3);
        else me->delete("crime_lv");
        me->set_leader(0);
        set("status","patrol");
        set("CatchWho",0);
        direction=GO;
        return_home(find_object(query("startroom")));
        }
else
        {
        write("������ʲô��˼?......˭ϡ�����Ǯ?!\n");
        me->add("crime_lv",1);
        }
return 1;
}

