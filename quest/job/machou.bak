// 根据XKX100的抢镖改编
// by sdlkx 2001-9-23 1:56

#include <ansi.h>

#define D_time 360

inherit NPC;

string ask_job();
int do_move();

int no_move;

mapping *move = ({
/*        ([
                "address_name":         "这里",
                "address":              "/u/sdlkx/workroom",       ]),
*/

        ([
                "address_name":         "泸溪",
                "address":              "/d/tiezhang/lx",       ]),
        ([
                "address_name":         "黄土路",
                "address":              "/d/tiezhang/road-2",   ]),
        ([
                "address_name":         "土路",
                "address":              "/d/tiezhang/hunanroad2",       ]),
        ([
                "address_name":         "客店",
                "address":              "/d/tiezhang/kedian",   ]),
        ([
                "address_name":         "黄土路",
                "address":              "/d/tiezhang/road-1",   ]),
        ([
                "address_name":         "山脚下",
                "address":              "/d/tiezhang/shanjiao", ]),

        });

mapping *quest = ({
/*        ([      "name":                "test",
                "start" :              "/u/sdlkx/workroom",
                "place" :              "这里",        ]),    
*/

        ([      "name":                "hgg",
                "start" :              "/d/city4/hanguguan",
                "place" :              "函古关",        ]),    
        ([      "name":                "zn",
                "start" :              "/d/city4/zhongnan",
                "place" :              "终南山口",      ]), 
        ([      "name":                "mj",
                "start" :              "/d/fuzhou/fzroad8",
                "place" :              "闽江",          ]),
        ([      "name":                "hsn",
                "start" :              "/d/shaolin/hanshui1",
                "place" :              "汉水南岸",      ]),
        ([      "name":                "zts",
                "start" :              "/d/huashan/jzroad5",
                "place" :              "中条山密林",    ]),
        ([      "name":                "shanjiao",
                "start" :              "/d/xingxiu/shanjiao",
                "place" :              "天山脚下",      ]),
        ([      "name":                "hs",
                "start" :              "/d/huashan/path1",
                "place" :              "华山脚下",      ]), 
        ([      "name":                "pdz",
                "start" :              "/d/heimuya/pingdingzhou",
                "place" :              "平定州",        ]), 
        ([      "name":                "lsp",
                "start" :              "/d/heimuya/road1",
                "place" :              "乱石坡",        ]), 
        ([      "name":                "xiaoqiao",
                "start" :              "/d/qingcheng/xiaoqiao",
                "place" :              "青城小桥",      ]), 
        ([      "name":                "sbg",
                "start" :              "/d/wudang/sanbuguan",
                "place" :              "三不管",        ]), 
        ([      "name":                "bxs",
                "start" :              "/d/kunlun/baixiang",
                "place" :              "白象山",        ]), 
        ([      "name":                "dsl",
                "start" :              "/d/wanjiegu/entrance",
                "place" :              "大森林",        ]), 
        ([      "name":                "sxz",
                "start" :              "/d/huanghe/shixiazi",
                "place" :              "石峡子",        ]), 
        ([      "name":                "xxl",
                "start" :              "/d/fuzhou/fzroad1",
                "place" :              "仙霞岭",        ]), 

});
    
void create()
{
        set_name("马仇", ({ "ma chou", "ma"}) );
        set("gender", "男性" );
        set("nickname", "土匪");
        set("age", 31);
        set("long", "住在山西一带的土匪头，略有名气，常常以打劫镖车为生。\n");
        set("str", 29);
        set("dex", 26);
        set("con", 24);
        set("int", 22);
        set("per", 18);
        set("shen", -7500);
        set("max_qi", 2000);
        set("max_jing", 2000);
        set("neili",2000);
        set("max_neili",2000);
        set("eff_jingli", 1800);
        set_skill("dodge",100);
        set_skill("force",200);
        set_skill("blade",100);
        set_skill("zixia-shengong",200);
        set_skill("hujia-dao",100);

        map_skill("force","zixia-shengong");
        map_skill("blade","hujia-dao");
         
        set("combat_exp", 750000);

        set("time",time() - D_time);
        set("inquiry", ([
                "劫镖"  :       (: ask_job :),
                "抢劫"  :       (: ask_job :),
                "rob"   :       (: ask_job :),
        ]));
        
        setup();
        carry_object(__DIR__"obj/blade")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("silver", 10);
        call_out("do_move",120);
}

int accept_object(object me, object obj)
{
        object ob=this_object();

        if(!me || environment(me) != environment())
                return 0;

        if(!objectp(obj))
                return 0;

        if(!present(obj, me))
                return notify_fail("你没有这件东西。");
                
        if(userp(obj)){
                command("consider "+(string)me->query("id"));
                command("say 你拿个快死的人来骗我？");
                return 0;
        }

        if(obj->query("money_id"))
        {
                command("pat " + me->query("id"));
                command("say 钱我有的是，你以后还是留给自己吧。");
                return 0;
        }
        
        if (base_name(obj)!=__DIR__"red")
        {
//              command("say " + base_name(obj) );
                return 0;
        }

        if(obj->query("id") == "prize" && obj->query("time") + 180 > time())
        {
                command("heng");
                command("say 你还回来做什么？都这么长时间，是不是想私吞啊？");
                me->destruct(obj);
                return 0;
        }
        
        if(obj->query("id") == "prize" && obj->query("owner") == me->query("id")){
                ob -> set("no_move", 1);
                command("nod "+(string)me->query("id"));
                command("say 好样的！干得好！\n");
                message_vision(HIY"$N将$n"HIY"拆开，拿出了一大堆金银财宝。\n"NOR,ob, obj);
                remove_call_out("destroying");
                call_out("destroying", 5, obj, ob, me);                       
                return 1;
        }

        if(obj->query("owner") != me->query("id")){
                command("hehe "+(string)me->query("id"));
                command("say 不错啊，但这活可不是你干的。");
                me->destruct(obj);
                return 1;
        }
        
        else return 0;       
}

void destroying(object obj, object ob, object me)
{   
        object n_money;
        int pot;
   
        if(obj)
                destruct(obj);

        if(!ob)
                return;

        if(!me || environment(me) != environment()){
                command("say 咦，人呢？");
                ob ->set("no_move", 0);
                return;
        }

        command("pat "+me->query("id"));
        message_vision(HIY"$N对$n说道：你这次做得极为出色，这是你该得的部分，拿去吧！\n"NOR,ob, me);
        n_money = new("/clone/money/gold");
        n_money->move(me); 
        n_money->add_amount(1);
        pot = random(200)+1200;
        if ( ((me->query("potential")) - (me->query("learned_points"))) < 5000 )
                me->add("potential", pot);

        me->set_temp("robjob_pot", 1000+(me->query_temp("biaoshi")*(random(50)+20)));
        tell_object(me,"你被奖励了\n" + chinese_number(pot) + "点潜能值。\n");
                destruct(obj);
//      me->add("potential", me->query_temp("biaoshi")*20);
        tell_room(environment(me), me->name()+"数着钱袋里的金子，脸上的肌肉不住地颤动，眼睛散发着一种奇怪的光芒。\n" NOR, ({ me }));     
//      tell_object(me, "你被奖励了"+chinese_number(me->query_temp("robjob_exp"))+"点经验值！\n");
        ob ->set("no_move", 0);
        me->delete_temp("robjob_exp");
        me->delete_temp("biaoshi");
        return;      
}

string ask_job()
{
        object me, ob;
        mapping aquest;
        int exp, j;     
        me = this_player();
        ob = this_object();
        aquest = quest[random(sizeof(quest))];
        exp = me->query("combat_exp"); 
 

        if(exp < 3000000)
                return "你还是再回去练练吧。这可不是好玩的!";

        if(me->query("shen") > -10000)
                return "抢劫？！这可不是闹着玩的，我什么也不知道。";

        if(me->query_condition("job_busy"))
                return "你现在还有任务在身，等会儿再来吧。";

        if(ob->query_temp("job_asked") == me->query("id")) 
                return "不是叫你先去那里等我吗？怎么还赖在这里？";

        if(ob->query_temp("job_asked")) 
                return "嘿嘿，你来晚了，等下一次吧。";

        if(ob->query("time") + D_time > time())
                return "现在还没有任何消息，你再回去等一阵吧。";

        if(exp>=12000000) j=6;
                else if(exp>=10000000) j=5;
                        else if(exp>=8000000) j=5;
                                else if(exp>=5000000) j=4;   
                                        else j=3;   
  
        me->set_temp("rob_job", 1);
        me->delete_temp("biaoshi");
        me->set_temp("j",j);
        message_vision(CYN"\n$N阴阴一笑，说道：这两天福威镖局会有一趟镖经过，你够胆就和我一起去看看吧。\n"NOR, ob, me);
        ob->set_temp("job_asked", me->query("id"));
        ob->set_temp("dest", aquest["name"]);
        ob->set_temp("start_place", aquest["start"]);
        ob->set_temp("place", aquest["place"]);
        me->set_temp("j", j);    
        me->set("no_move",1);
//      me->apply_condition("rob_task", 60+(j*20));
        me->start_busy(1);
        remove_call_out("going");
        call_out("going", 120, ob); 
        ob->set("time",time());

        return "我还有些事要办，你先去"+ob->query_temp("place")+"等我。\n";    
}


void going(object me)
{
        message_vision("$N急急忙忙地走了出去。\n", me);       
        me->move(me->query_temp("start_place"));
                message_vision("$N急急忙忙地走了过来。\n", me);
        command("sys 我现在在" + environment(me) -> query("short") + "。" );

        remove_call_out("do_move");
        remove_call_out("do_back");
        call_out("do_back", 240, me);
}


void init()
{
        object ob, where, me;
        ::init();
        ob=this_object();
        where = environment(ob);
        if(ob->query_temp("dest")){
                if(interactive(me = this_player()) && me->query_temp("rob_job")
                        && ob->query_temp("job_asked") == me->query("id")
                        && file_name(where) == ob->query_temp("start_place"))
                {
//                              call_out("do_back",240,ob);
                                remove_call_out("waiting");
                                call_out("waiting", 1, ob, me);
                }
        }

}

void waiting(object ob, object me)
{
        if(!ob || !living(me)) return;
        command("nod "+me->query("id"));
        command("say 好，我们就在这里等着他们来吧。");
        ob->set_temp("wait_target", 1);
        me->set_temp("wait_target", 1);
        remove_call_out("wait_target");
        call_out("wait_target", 30, ob, me);

        ob->set("no_move", 1);

        return; 
}

void do_back(object me)
{
        object ob;
        
        ob = this_object();
        
        ob -> set("no_move", 0);
        
        call_out("do_move",0);

        me->delete_temp("wait_target");
        me->delete_temp("start_place");
        me->delete_temp("place");
        me->delete_temp("dest");
        me->delete_temp("job_asked");
        me->delete("rob_id");
        message_vision("$N转过山丘，几个起落就不见了。\n", me);
                me->move("/d/tiezhang/lx");  
        message_vision("$N急急忙忙地走了过来。\n", me);
        command("sys 我现在在" + environment(ob) -> query("short") + "。" );
        
}

int wait_target(object ob, object me)
{
        object obj;
        
        if(!objectp(present(me, environment(ob))))
        {
                message_vision("$N说道：耶？那家伙怎么不见了？\n", ob);
                me->delete_temp("job_asked");
                remove_call_out("do_back");
                do_back(ob);
                return 1;
        }
        
        if(!objectp(ob = present("ma chou", environment(me))))
        {
                tell_object(me,"你发现马仇不见了，只好转身离开。\n");
                tell_room(environment(me), me->name()+"突然一脸茫然的表情，看来是想要离开了。\n", ({ me }));
                me->delete_temp("rob_job");
                me->clear_condition("rob_task");
                me->delete_temp("wait_target");
                me->delete_temp("job_asked");
                return 1;
        }

        obj = new(__DIR__"biaodui");
        obj->move(environment(me)); 
        obj->set("arg", ob->query_temp("dest"));
        obj->set_temp("j", me->query_temp("j"));
        obj->set("rob_id",me->query("id"));
        message_vision(HIY"\n只听一阵车轮声传来，一只福威镖局的镖队出现在眼前！\n\n"NOR, ob);
        tell_object(me,"猎物终于出现了！\n"); 
        message_vision(HIY"$N对着$n大声命令道：你快抢(qiang)镖队，我来对付其他人！\n"NOR, ob, me); 
        message_vision("说完$N就冲上前去，和几个护镖镖师打斗追逐开了。\n", ob);   
        remove_call_out("do_back");
        do_back(ob);
        me->delete_temp("wait_target");
        me->set_temp("rob_start", 1);
}

int do_move()
{
        mapping go;
        string goal;
        object ob = this_object();
        
        if(ob->query("no_move"))
                return 0;
        
        if(ob->query("hunmi"))
                return 0;
                
        go = move[random(sizeof(move))];
        goal = go["address"];

        message_vision("$N急急忙忙走开了。\n", ob);   
                move(goal);
        message_vision("$N急急忙忙走了过来。\n", ob);   
        command("sys 我现在在" + environment(ob) -> query("short") + "。" );
        
        remove_call_out("do_move");
        call_out("do_move",120);
}


