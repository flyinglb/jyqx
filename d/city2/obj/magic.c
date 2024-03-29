// transite.c   
// modified by wind

inherit ITEM;

mapping where_map=([
"gc":"/d/city/guangchang",
"sl":"/d/shaolin/guangchang1",
"bt":"/d/baituo/dating",
"tam":"/d/city2/tian_anm",
"hmy":"/d/heimuya/up1",
"hs":"/d/huashan/zhenyue",
"wd":"/d/wudang/jiejianyan",
"ts":"/d/taishan/nantian",
"xy":"/d/xiaoyao/qingcaop",
"xx":"/d/xingxiu/xxh1",
"xk":"/d/xiakedao/dating",
"xs":"/d/xueshan/dadian",
"sld":"/d/shenlong/dating",
"qz":"/d/quanzhou/zhongxin",
"lj":"/d/lingjiu/dating",
"tl": "/d/tianlongsi/damen", 
"td":"/d/city2/dating",
"em" : "/d/emei/hcazhengdian",
"mr" : "/d/murong/matou",
"th" : "/d/taohua/mudi",
"gm" : "/d/gumu/mumen",
"quanz" : "/d/quanzhen/damen",
"cd" : "/d/city3/wuhouci",
"wjg" : "/d/wanjiegu/entrance",
"mj" : "/d/mingjiao/shanmen",
"wudu" : "/d/wudujiao/dating",
"dl" : "/d/dali/wangfugate",
"gw" : "/d/guanwai/huandi2",
"fs" : "/d/foshan/street3",
"ny" : "/d/henshan/hengyang",
"lz" : "/d/lingzhou/center",
"by" : "/d/hengshan/square",
"tz" : "/d/tiezhang/guangchang",
]);

void init(){
       if( this_player()==environment() )
                add_action("do_trans","trans");
/*
        if( !userp(environment()) )
                destruct(this_object());
*/
}

void create()
{
set_name("魔法传送帖",({"trans site","site"}));
set("no_get",1);
set("no_steal",1);
set_weight(100); 
set_max_encumbrance(8000);
set("value", 10000);
set("used_count", 0);
set("can_use_count",5+random(10));
set("no_put", "这东西不能随便给人！\n");
set("no_drop", "这样东西不能离开你。\n");

if( clonep() )   set_default_object(__FILE__);
else {     set("long", "一张魔法传送帖，以它的魔力现在所能到达(trans)的地方如下。\n
\t中央广场(gc)    少林寺(sl)    白驼山(bt)    天安门(tam) \n
\t黑木崖(hmy)     华山(hs)      武当山(wd)    泰山(ts)    \n
\t逍遥派(xy)      星宿海(xx)    雪山寺(xs)    神龙岛(sld) \n
\t泉州(qz)        灵鹫宫(lj)    天龙寺(tl)    天地会(td)  \n
\t侠客岛(xk)      峨嵋派(em)    慕容山庄(mr)  桃花岛(th)  \n
 \t古墓派(gm)      全真教(quanz) 成都(cd)      万劫谷(wjg) \n
\t明教(mj)        五毒教(wudu)  大理(dl)      关外(gw)    \n
\t佛山(fs)        衡山(by)      恒山(ny)      灵州(lz)   \n
\t铁掌帮(tz)\n");
set("unit","张");
}
}

int do_trans(string arg)
{
        object me;
	string msg,str;

	str=where_map[arg];
        if( !arg||!stringp(str)) return notify_fail("你要去哪里？\n");
        me=this_player();
        if (! environment(me)->query("outdoors"))
         return notify_fail("在这房间里无法使用魔法传送。\n");
        if (me->is_fighting())
        return notify_fail("战斗中无法使用魔法传送！");
        if (me->is_busy())
                return notify_fail("你正忙着呢！\n");
        if( me->query("sleeped"))
                return notify_fail("你在睡梦中飞啊飞！\n");

/*          if (this_object()->query("used_count")>this_object()->query("can_use_count"))
        {
        this_object()->set("value", 20000);
        this_object()->delete("no_put");
        this_object()->delete("no_drop");
        this_object()->set_name("报废的魔法传送帖",({"trans site","site"}));
        return notify_fail("这张魔法传送贴用得太久，已经报废了！\n");
      } */

        if(this_player()->query_temp("in_guard")
        && base_name(environment(this_player())) == "/d/wudang/xuanyuegate") 
        return notify_fail("你任务还没有完成，不能离开。\n");
        str+=".c";
        if(file_size(str)<0) 
        return notify_fail("没有这个地方。\n");
        if( stringp(msg = me->query("env/msg_mout")) )      
        {if (msg!="") message_vision(msg+"\n", me);} 
         else message_vision("只见一阵烟雾过後，$N的身影已经不见了。\n", me);
        me->move(str);
        if( stringp(msg = me->query("env/msg_min")) )
               {if (msg!="") message_vision(msg+"\n", me);}
        else  message_vision("$N的身影突然出现在一阵烟雾之中。\n", me);        
        this_object()->add("used_count",1);
        return 1;
}

void owner_is_killed()
{
        move(VOID_OB);
        destruct(this_object());
} 


