// XieXun.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;
// inherit F_MASTER;
inherit F_UNIQUE;

string ask_huijia()
{
 object me,ob,ob1,ob3;
int a,b;
// object *ob_list;
// int i;

me=this_player();
a=me->query_temp("marks/bing");
b=me->query("mufa");
//if(a=0)
if(!me->query_temp("marks/bing"))
{
return "�޼��ҵ�����?\n";}
//else if(!me->query_temp("marks/bing"))
else if(!me->query("mufa"))
{return "ľ���������.\n";}
else
{ob=new("/d/binghuodao/npc/zhangcui");
ob->move("/d/binghuodao/road11");
ob1=new("/d/binghuodao/npc/susu");
ob3=new("/d/binghuodao/npc/wuji");
ob1->move("/d/binghuodao/road11");
ob3->move("/d/binghuodao/road11");
write("�����߰�.\n");
destruct(present("mufa",me));
ob->move("/d/binghuodao/mufa");
ob1->move("/d/binghuodao/mufa");
ob3->move("/d/binghuodao/mufa");
me->move("/d/binghuodao/mufa");
me->delete_temp("marks/bing");
me->delete("mufa");
tell_object(me, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
call_out("goto_taohua",20,me);
}
return "�߰�.\n";
}
void goto_taohua (object ob)
{
object ob1,ob2,ob3;   
tell_object(ob , "������ͣ����һ����ۡ������´�����\n" ) ;
   ob->move ("/d/city2/haigang") ;
ob2=new("/d/binghuodao/npc/zhangcui");
ob2->move("/d/city2/haigang");
ob1=new("/d/binghuodao/npc/susu");
ob1->move("/d/city2/haigang");
ob3=new("/d/binghuodao/npc/wuji");
ob3->move("/d/city2/haigang");
destruct(ob1);
destruct(ob2);
destruct(ob3);
tell_object(ob,"лл������ǻص�����.����Щ��������.���Ǿʹ˸��.\n");
//tell_object(ob,"���Ǿʹ˸��.\n");
if(!ob->query("send_zhang"))
{ob->set("send_zhang",1);
ob->add("combat_exp",500);}
else {ob->add("combat_exp",1);}
ob->delete("mufa");
ob->delete_temp("marks/bing");
}

string ask_zhaochuan()
{
object me;
me = this_player () ;

if (!present("mu chai", me) && !present("chang teng",me))
write("������û�в��ϣ�\n");
if (present("mu chai", me) && present("chang teng",me))
{
write("һ��ľ������֪ͨ��.\n");
destruct(present("mu chai",me));
destruct(present("chang teng",me));
call_out("make_chuan",20,me);
}
}

void create()
{
        set_name("лѷ", ({"xie xun", "xie", "xun", }));
        set("long",
        "����һλ��Ŀ�ΰ�쳣�ĵ����ߣ���һ���ײ����ۡ�\n"
        "����ͷ�Ʒ����������ݣ���������һ�㣬ֻ����ֻ�۾�����������\n"
        );

        set("title",HIG "����" HIY "��ëʨ��" NOR);
        set("level",9);
        set("gender", "����");
        set("attitude", "peaceful");

        set("age", 63);
        set("shen_type", 1);
        set("per", 25);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 5500);
        set("max_jing", 5500);
        set("neili", 5000);
        set("max_neili", 15000);
        set("jiali", 250);

        set("combat_exp", 8000000);
        set("score", 800000);

        set_skill("force", 260);
        set_skill("dodge", 240);
        set_skill("sword", 240);
        set_skill("blade", 240);
        set_skill("parry", 240);
        set_skill("cuff", 200);
        set_skill("blade", 250);
        set_skill("jinwu-daofa", 250);
        set_skill("jiuyang-shengong", 250);
        set_skill("lingxu-bu", 250);
        set_skill("damo-jian", 250);
        set_skill("qishang-quan", 250);
        set_skill("hunyuan-zhang", 250);
        set_skill("literate", 100);

        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "lingxu-bu");
        map_skill("cuff", "qishang-quan");
        map_skill("parry", "hunyuan-zhang");
        map_skill("sword", "damo-jian");
        map_skill("blade", "jinwu-daofa");

        set_temp("apply/attack", 700);
        set_temp("apply/defense", 500);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        prepare_skill("cuff","qishang-quan");

        set("chat_chance_combat", 200);
        set("chat_msg_combat", ({
                (: command("perform hunpofeiyang") :),
        }) );
        create_family("����",35, "����");
set("inquiry", ([
        "������" : (:ask_huijia:) ,
        "�촬" : (:ask_zhaochuan:) ,
         ]) );
set("chat_chance",8);
        set("chat_msg",({
           "лѷ������˼��:��������������,�㵽����ʲô������?\n",
           "лѷ�޺޵�˵��:��������,�㺦�Ҽ�������,�Ҳ�����ɱ����,�����Ŀ.\n"
        }) );
        setup();
         carry_object(__DIR__"obj/killdragon")->wield();
        carry_object("/d/mingjiao/obj/baipao")->wear();
}
/*
void init()
{
        object me,ob;
        me = this_object () ;
        ob = this_player () ;

        ::init();

        if (interactive(this_player()) && this_player()->query_temp("fighting"))
        {
                COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
                this_player()->add_temp("beat_count", 1);
        }       
        if( interactive(ob) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me, ob);
        }
}
*/
void make_chuan(object who,object me)
{
object ob;
me = this_player () ;
tell_object(who,"������.\n");
ob=new("/d/binghuodao/npc/obj/chuan");
ob->move(me);
//ob->move("/d/binghuodao/road11");
me->delete_temp("teng");
me->delete_temp("mutou");
me->set("mufa",1);
}

int accept_object(object who,object ob,object me)
{
        me = this_player () ;
//if(query_temp("marks/bing"))
//{
if(ob->query("id")=="teng") me->set_temp("teng",1);
if(ob->query("id")=="mu chai") me->set_temp("mutou",1);

if(me->query_temp("mutou"))
{
if(me->query_temp("teng")) 
{
write("һ��ľ������֪ͨ��.\n");
call_out("make_chuan",20,who);
//return "�����һ��!.\n";  
}
}
return 1;
}

void die()
{
        object ob;
        
        ob = this_object();
        write("лѷ���һ����������ɽȥ����������Ӱ��\n");
        destruct(ob);
        return;
}

