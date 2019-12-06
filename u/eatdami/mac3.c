// modify by wind
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
object ob;
int number=1;

void create ()
{
  seteuid(getuid());
	set_name(HIY"黄金点歌台"NOR, ({"mac3"}));
  set("long",
HIY"ＣＡＮ  ＵＳＥ  ＨＥＬＰ  ＭＡＣ\n"+
HIY"	点  ｏｎｅ  ｍｕｓｉｃ  费银行存钱 １ ｇｏｌｄ\n"NOR);
        if( clonep() )
                set_default_object(__FILE__);
        else {

  set_weight(50000);
  set("unit","支");
  set("value",100000);
  set("material","gold");
set("wield_msg", HIW"$N很牛ｘ的从腰间拔出一只"+this_object()->query("name")+"\n
"NOR);
set("unwield_msg", HIY"$N深情的给大家鞠了一恭，收起了手中的\n"NOR+
HIB"	"+this_object()->query("name")+"\n"NOR);
}
	init_sword(100);
  setup();
}
 
void init()

{
add_action("help","help");
add_action("mac","mac");
add_action("play", "play");

}
 

int mac(string str)

{

int i,flag=0;

 

if(!str)

  {

	notify_fail("你要说些什么？\n");

   flag=0;

   return 0;

  }

for(i=0;i<number;i++)

  {


    if(ob!=this_player())

    {

	message("channel:music", HIY"【天王演唱会】"+this_player()->query("name")+"唱道："+str+"\n"NOR,users());
 flag++;

    }

  }

  if(flag!=0)

  {

	write("你拿着ＭＡＣ深情的说："+str+"\n");

  }

  else

  {

	return 0;

  }

  flag=0;

  return 1;

}

int play(string str)
{
	object ob,me;
	me=this_player();
        if(!str)
        return notify_fail("你要放什麽?\n");
	if (this_object()->query_temp("sing")==1) 
           return notify_fail("现在有人正在唱歌呢，你稍等一会儿吧。\n"); 
	if (this_player()->query_temp("sing")==1) 
           return notify_fail("现在有人正在唱歌呢，你稍等一会儿吧。\n"); 
	this_player()->set("money", 10000);
	if(this_player()->query("balance")<this_player()->query("money"))
	return notify_fail(""+this_player()->name()+"you no balance\n");
else
	if(this_player()->query("balance")>=this_player()->query("money"))
{
	this_player()->set("balance",this_player()->query("balance") -
	this_player()->query("money"));
	message_vision(HIB"Ｍｕｄ  ｗｏｒｋｍａｎ  ｃａｎ  ｐｌａｙ！\n"NOR,
	this_player());
	this_player()->set("money", 0);
}
	this_object()->set_temp("sing",1);
	this_player()->set_temp("sing",1);

        if(str=="cd-3")
        {
        message_vision("$N放入了一卷任贤齐的《心太软》!\n",this_player());
	ob=new("/u/eatdami/cds/cd03");
        }
        if(str=="cd-2")
        {
	message_vision("$N放了一张《同桌的你》在ＷＯＲＫＭＡＮ中\n",me);
	ob=new("/u/eatdami/cds/cd02");
       }
        if(str=="cd-1")
        {
	message_vision("$N放了一张《任逍遥》在ＷＯＲＫＭＡＮ中\n",me);
	ob=new("/u/eatdami/cds/cd01");
        }
        if(str=="cd-4")
        {
	message_vision("$N放了一张《笨小孩》的ＣＤ在ＷＯＲＫＭＡＮ中\n",me);
	ob=new("/u/eatdami/cds/cd04");
        }
        if(str=="cd-5")
        {
	message_vision("$N放了一张《恋恋风尘》的ＣＤ在ＷＯＲＫＭＡＮ中\n",me);
	ob=new("/u/eatdami/cds/cd05");
        }
        if(str=="cd-6")
        {
	message_vision("$N放了一张《大头皮鞋》的ＣＤ在ＷＯＲＫＭＡＮ中\n",me);
	ob=new("/u/eatdami/cds/cd06");
       }
         if(str=="cd-7")
        {
	message_vision("$N放了一张《冰雨》的ＣＤ在ＷＯＲＫＭＡＮ中\n",me);
	ob=new("/u/eatdami/cds/cd07");
        }
         if(str=="cd-8")
        {
	message_vision("$N放了一张《孤星泪》的ＣＤ在ＷＯＲＫＭＡＮ中\n");
	ob=new("/u/eatdami/cds/cd08");
        }
         if(str=="cd-9")
        {
        message_vision("$N 放入了一卷江珊的《梦里水乡》!\n",this_player());
        ob=new("/u/eatdami/cds/cd09");
        }
         if(str=="cd-10")
        {
        message_vision("$N 放入了一卷英文歌盘!\n",this_player());
        ob=new("/u/eatdami/cds/cd10");
        }
         if(str=="cd-11")
        {
        message_vision("$N 放入了一卷英文歌盘!\n",this_player());
        ob=new("/u/eatdami/cds/cd11");
        }
         if(str=="cd-12")
        {
        message_vision("$N 放入了一卷英文歌盘\n",this_player());
        ob=new("/u/eatdami/cds/cd12");
        }
         if(str=="cd-13")
        {
        message_vision("$N 放入了一卷英文歌盘\n",this_player());
        ob=new("/u/eatdami/cds/cd13");
        }
         if(str=="cd-14")
        {
        message_vision("$N 放入了一卷英文歌盘\n",this_player());
        ob=new("/u/eatdami/cds/cd14");
        }
         if(str=="cd-15")
        {
        message_vision("$N 放入了一卷英文歌盘\n",this_player());
        ob=new("/u/eatdami/cds/cd15");
        }
         if(str=="cd-16")
        {
        message_vision("$N 放入了一卷黄百家的《梦想》\n",this_player());
        ob=new("/u/eatdami/cds/cd16");
        }
	
return 1;
}
int query_autoload()
{
    return 1;
}
int help(string str)
{

  if (str!="mac") return 0;

write(@Help
ｉｆ  ｙｏｕ  ｗａｎｔ  ｐｌａｙ  ｗｏｒｋｍａｎ  ｕｓｅ  （play）
such as play cd-1  (cd-1至cd-8   中文歌)
or      play cd-10 (cd-10至cd-15 english song)
or	play cd-16 (cd-16  MUD歌曲一)

注: 这是水货MAC, 放的是盗版CD, 歌名可能会有些混乱. 
    如果选cd选错了, MAC可能会卡壳, 就不能再唱了, 请重新购买.
    欲买正版MAC及CD者,请与robin联系.
Help

);

  return 1;
}
