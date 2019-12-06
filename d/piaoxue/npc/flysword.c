#include <ansi.h>
inherit NPC;
int  piaoxue();

void create()
{
        set_name("天仙飞剑", ({ "fly sword","sword" }));
	set("title", HIM"〖飘"HIW"雪"HIM"山庄〗"BLINK+HIR"★接引天使★"NOR );
        set("gender", "男性");
        set("age", 20);
        set("long","他是飘雪山庄的接引使者，负责接引各路英豪取道飘雪山庄\n",);
        set("no_get",1);

        set("combat_exp", 1000000);
        set("shen_type", 1);

	set("eff_qi",2000);
	set("qi",2000);
        set("max_neili", 1000);
        set("neili", 1000);
        set("jiali", 100);

        set_skill("force", 200);
        set_skill("unarmed", 400);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set("inquiry", ([
                
                "飘雪山庄" :   (: piaoxue :)

        ]) );

        setup();
	carry_object("/clone/misc/cloth")->wear();
 }

int piaoxue()
{
        object where;
	object me;
	object room;
	me = this_player();
	where = environment(me);
	if ((string)where->query("short")=="渔港")
	        {
        	message_vision("$N满面笑容对$n说：你想去飘雪山庄？好，没问题。\n",this_object(),me);
	        room = load_object("/d/piaoxue/dating");
        	message_vision("只见天仙飞剑凌空一指，一团迷雾包围了$N，不一会儿整个人不见了！\n",me);
        	me->move(room);
                }
        else    {
                message_vision("$N发愁地对对$n说：我只有到海边才能送你去飘雪山庄。\n",this_object(),me);
                return 1;
                }
        
}
