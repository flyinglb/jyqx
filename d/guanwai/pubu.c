// /guanwai/pubu.c

inherit ROOM;

  int do_longdao();

void create()
{
	set("short", "长白瀑布");
	set("long", @LONG
天池水从两百余尺高飞流跌落，轰鸣之声远传数里，水花直落大嶂谷，
与天然屏障玉壁、金壁相映，恰似白练当空，水柱扑向深深的谷底，溅起几
丈高的飞浪，犹如仙女散花，阳光照射下，虹飞氤跃，璀灿壮观之极。古人
诗云：“白河两岸景清幽，碧水悬崖万古留；疑似龙池喷瑞雪，如同天际挂
飞流。不须鞭石渡沧海，直可乘槎问斗牛？欲识林泉真乐趣，明朝结伴再来
游。”
LONG );
	set("exits", ([
		"southeast"  : __DIR__"damen",
		"westdown"   : __DIR__"xiaotianchi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
}
void init()
{
        add_action("do_longdao", "longdao");
}
int do_longdao()
{
object ob;
   int c_exp,c_skill;
   ob = this_player();

   c_skill=(int)ob->query_skill("blade", 1);
   if (c_skill <20)
   {
     message_vision("$N的基本刀法显然太低，无法练习。\n",ob);
return 1; 
}
c_exp=ob->query("combat_exp");
   if ((c_skill*c_skill*c_skill/10)> c_exp)
{
message_vision("$N的实战经验不足，无法领悟。\n",ob);
      return 1; 
}
if (ob->query("jing")<20)
{
message_vision("$N太累了，现在无法领悟。\n",ob);
      return 1; 
}
   if (c_skill>100)
{
message_vision("$N觉得自己的基本刀法还可以不想练了。\n",ob);
      return 1; 
}

   message_vision("$N把手中小刀把玩良久，对基本刀法似有所悟。\n",ob);
   ob->improve_skill("blade", random(ob->query("int")) );
   ob->add("jing",-5);
      return 1; 
}
