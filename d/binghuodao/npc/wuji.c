//wuji.c
inherit NPC;
string ask_huijia()
{
object me=this_player();
set_leader(me);
return "谢谢你愿意送我回家.\n";
}

string ask_daojia()
{
 object ob,me;
 ob = this_object();
 me = this_player();
//  int a;
//     a=me->query_temp("marks/bing");
 if((string)file_name(environment(me))=="/d/binghuodao/home")
         {

          set_leader(0);
          me->add_temp("marks/bing",1);
          write("终于到家了，太谢谢你了.\n");
          ob->move("/d/binghuodao/midong");
//          destruct(ob);
           return "无忌刚到家又出去玩了.....\n";  
//          return;
      }
        else {
                return "还没到.\n";
        }
}
void greeting(object ob)
{
        tell_object(ob,"无忌说:洞外面有狼,我不敢出去!\n");
}
void create()
{
        set_name("张无忌",({ "zhang wuji" }) );
        set("gender", "男性" );
        set("age", 6);
        set("long", "这是谢逊义子,张翠山与殷素素的儿子\n");
        set("combat_exp", 500);
        set("shen_type", 200);
        set("str", 10);
        set("dex", 10);
        set("con", 10);
        set("int", 10);
        set("attitude", "friendly");
        set("chat_chance", 6);
        set("inquiry", ([
        "回家" : (:ask_huijia:) ,
        "到家" : (:ask_daojia:) ,
         ]) );

        set("neili",200);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("force",20);        
        set_skill("parry", 40);
        set_skill("qishang-quan", 20);
        set_skill("literate", 10);
map_skill("unarmed", "qishang-quan");
         setup();
        carry_object("/d/binghuodao/npc/obj/skin")->wear();
}

void init()
{
        greeting( this_player());
}


