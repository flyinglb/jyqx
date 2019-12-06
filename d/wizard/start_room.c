// start_room.c

inherit ROOM;

mapping exits_site=([
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
"yz" : "/d/yanziwu/yimen",
"th" : "/d/taohua/mudi",
"gm" : "/d/gumu/mumen",
"quanz" : "/d/quanzhen/damen",
"cd" : "/d/city3/wuhouci",
"wjg" : "/d/wanjiegu/entrance",
"mj" : "/d/mingjiao/shanmen",
"wudu" : "/d/wudujiao/dating",
"dl" : "/d/dali/wangfugate",
"gw" : "/d/guanwai/huandi2",
]);

void create()
{
        set("short", "时空之门");
        set("long", @LONG
这是没有建造工作室的巫师的临时住处，这里的设备非常简单，
只有一些常用物品。
LONG );

        set("exits", exits_site);
        set("objects", ([
                 "/d/npc/zhaoda.c" : 1,
                 "/d/npc/spoiler.c" : 1,
        ]));
        setup();
}

void goto_realworld(object me)
{
    me->move("/d/city/guangchang");
}
void init()
{
        object me = this_player();
        if (me->query("id")== "zhao da") 
        {
            remove_call_out("goto_realworld");
            call_out("goto_realworld",1,me);
         return;
          }
        if(wizardp(me)||!userp(me)) return;
        me->move(VOID_OB);
        tell_object(me,"一阵时空扭曲将你送到另一个地方 ……\n");
}
