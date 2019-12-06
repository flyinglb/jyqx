//modify by robin
#include <ansi.h>;
#define YEAR "2001"
inherit NPC;
inherit F_DEALER;

string ask_me();
string ask_me2();
string ask_me3();
int do_pet(string arg);

void create()
{
	set_name(HIW "圣诞老人" NOR, ({"santa claus","santa","claus" }) );
	set("gender", "男性");
	set("age", 3005);
	set("long",
		"这是一位仙风道骨白发白须的红鼻子老人，每逢圣诞他会自动出现.\n他性好任侠，公正无私，平日里游山玩水, 云游四方。\n");
	set("combat_exp",6000000);
        set("shen_type", 1);
	set("attitude", "friendly");

	set("apply/attack", 500);
	set("apply/defense", 500);

	set("max_qi", 8000);
	set("eff_qi", 8000);
	set("qi", 8000);
	set("max_jing", 1000);
	set("max_neili", 8000);
	set_skill("force", 300);
	set_skill("unarmed", 300);
	set_skill("sword",300);
	set_skill("parry",300);
	set_skill("dodge", 300);
	set("inquiry", ([
		"圣诞礼物"   : (: ask_me :),
		"present"   : (: ask_me :),
		"gift"   : (: ask_me :),
		"礼物"   : (: ask_me :),
		"女朋友"   : (: ask_me2 :),
		"gf"   : (: ask_me2 :),
		"宠物"   : (: ask_me3 :),
		"pet"   : (: ask_me3 :),
	]));
        set("vendor_goods",({
		"/u/eatdami/cat-call", 
		"/u/eatdami/mac2",
		"/u/eatdami/mac3",
		"/d/city2/obj/magic",
                "/d/city2/obj/flower/flower",
		"/d/city2/obj/flower/guihua",
                "/d/city2/obj/flower/hua",
                "/d/city2/obj/flower/juhua",
                "/d/city2/obj/flower/seed",
        } ));
  
	setup();
        carry_object("/d/city2/obj/jinduan")->wear();
}

void init()
{
      object ob;
		::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
    add_action("do_pet","pet");
    add_action("do_list","list");
    add_action("do_buy","buy");
}

string ask_me()
{
object ob;
if (this_player()->query("asked/"+YEAR)) 
return ("对不起，今年的圣诞礼物你已经要过了。\n");
if (this_player()->query("age")<15 )
{
             ob=new("/d/city2/obj/flower/seed");
             ob->move(this_player());
 message_vision("$N念动咒语，右手一挥，"+this_player()->query("name")+"得到了一棵花种子作为小孩子的圣诞记念奖。\n", this_object(), this_player());
this_player()->set("asked/"+YEAR,1);
return ("祝圣诞快乐!\n");
}
if (random(10)>8) 
{
             ob=new("/clone/money/gold");
             ob->set_amount(1000);
             ob->move(this_player());
 message_vision("$N念动咒语，右手一挥，"+this_player()->query("name")+"得到了千两黄金作为圣诞礼物。\n", this_object(), this_player());
}
else if(random(10)>8) 
{
             ob=new("/u/eatdami/mac3");
             ob->move(this_player());
 message_vision("$N念动咒语，右手一挥，"+this_player()->query("name")+"得到了黄金点歌台作为圣诞礼物。\n", this_object(), this_player());
}
else if(random(10)>8) 
{
             ob=new("/clone/misc/mask");
             ob->move(this_player());
 message_vision("$N念动咒语，右手一挥，"+this_player()->query("name")+"得到了面具作为圣诞礼物。\n", this_object(), this_player());
}
else if (random(10)>8) 
{
             ob=new("/clone/money/thousand-cash");
             ob->set_amount(10);
             ob->move(this_player());
 message_vision("$N念动咒语，右手一挥，"+this_player()->query("name")+"得到了万两白银作为圣诞礼物。\n", this_object(), this_player());
}
if (random(10)>7) 
{
             ob=new("/d/city/obj/magic");
             ob->move(this_player());
 message_vision("$N念动咒语，右手一挥，"+this_player()->query("name")+"得到了魔法传送贴作为圣诞礼物。\n", this_object(), this_player());
}
else if(random(10)>7) 
{
             ob=new("/d/emei/obj/yitian-jian");
             ob->move(this_player());
 message_vision("$N念动咒语，右手一挥，"+this_player()->query("name")+"得到了倚天剑作为圣诞礼物。\n", this_object(), this_player());
}
else if(random(10)>8) 
{
             ob=new("/clone/money/thousand-cash");
             ob->set_amount(100);
             ob->move(this_player());
 message_vision("$N念动咒语，右手一挥，"+this_player()->query("name")+"得到了一百张千两银票作为圣诞礼物。\n", this_object(), this_player());
}
else if(random(10)>7) 
{
             ob=new("/d/shaolin/obj/fumo-dao");
             ob->move(this_player());
 message_vision("$N念动咒语，右手一挥，"+this_player()->query("name")+"得到了伏魔刀作为圣诞礼物。\n", this_object(), this_player());
}
else if(random(10)>7) 
{
             ob=new("/d/shaolin/obj/jingang-zhao");
             ob->move(this_player());
 message_vision("$N念动咒语，右手一挥，"+this_player()->query("name")+"得到了金刚罩作为圣诞礼物。\n", this_object(), this_player());
}
else if(random(10)>7) 
{
             ob=new("/d/city2/obj/shouzhuo");
             ob->move(this_player());
 message_vision("$N念动咒语，右手一挥，"+this_player()->query("name")+"得到了玉镯作为圣诞礼物。\n", this_object(), this_player());
}
else if(random(10)>8) 
{
             ob=new("/clone/money/tenthousand-cash");
             ob->move(this_player());
 message_vision("$N念动咒语，右手一挥，"+this_player()->query("name")+"得到了金票作为圣诞礼物。\n", this_object(), this_player());
}
else if(random(10)>7) 
{
             ob=new("/d/city2/obj/baojia");
             ob->move(this_player());
 message_vision("$N念动咒语，右手一挥，"+this_player()->query("name")+"得到了金丝宝甲作为圣诞礼物。\n", this_object(), this_player());
}
else if(random(10)>7) 
{
             ob=new("/d/city2/obj/bishou");
             ob->move(this_player());
 message_vision("$N念动咒语，右手一挥，"+this_player()->query("name")+"得到了匕首作为圣诞礼物。\n", this_object(), this_player());
}
else if(random(10)>7) 
{
             ob=new("/d/city2/obj/flower/flower");
             ob->move(this_player());
 message_vision("$N念动咒语，右手一挥，"+this_player()->query("name")+"得到了一朵花作为圣诞礼物。\n", this_object(), this_player());
}
else if(random(10)>6) 
{
             ob=new("/u/eatdami/mac2");
             ob->move(this_player());
 message_vision("$N念动咒语，右手一挥，"+this_player()->query("name")+"得到了天王麦克风作为圣诞礼物。\n", this_object(), this_player());
}
else
{
             ob=new("/d/city2/obj/flower/seed");
             ob->move(this_player());
 message_vision("$N念动咒语，右手一挥，"+this_player()->query("name")+"得到了一朵花种子作为圣诞记念奖。\n", this_object(), this_player());
}
this_player()->set("asked/"+YEAR,1);
return("祝圣诞快乐！\n");
}


string ask_me2()
{
object ob;
if (this_player()->query("asked/"+YEAR)) 
return ("对不起，今年的圣诞礼物你已经要过了。\n");

if (this_player()->query("gender")!="男性") 
return ("对不起，难道你要搞同性恋啊？\n");

message_vision("$N念动咒语，右手一挥，"+this_player()->query("name")+"得到了女朋友双儿作为圣诞礼物。\n", this_object(), this_player());
message_vision("$N对"+this_player()->query("name")+"说：try ask er about 你愿不愿意跟我走。\n", this_object(), this_player());
this_player()->set("weiwang",70);
this_player()->set("asked/"+YEAR,1);
ob=new("/d/city2/npc/shuanger");
ob->move(environment(this_player()));
return("祝圣诞快乐！\n");
}

string ask_me3()
{
//object ob;
if (this_player()->query("asked/"+YEAR)) 
return ("对不起，今年的圣诞礼物你已经要过了。\n");

if (this_player()->query("gender")!="女性") 
return ("对不起，男人家要宠物做甚？去找个女朋友做宠物吧。xixi\n");
   this_player()->set_temp("pet_ok");
say("圣诞老家伙看了你一眼说:「先要给猫眯取个好名子哦」\n"
"( pet 中文名 英文名 )\n"
"我等你的命令。\n");
return("祝圣诞快乐！\n");
}

int do_pet(string arg)
{

    string p_name,p_id;
    object pet;
    object me;
    me=this_player();
   if((me->query("pet/make"))) {
	say ("圣诞老家伙想了想说:「一人只能养一只猫眯」\n");
   return 1;
    }

  if(!arg)
       return notify_fail("想好再说.\n");
    sscanf(arg,"%s %s",p_name,p_id);
   if (!p_name||!p_id)
         return notify_fail("什么?(使用pet 中文名字 英文名字)\n");
  
   me->set("pet/make",1);
   me->set("pet/name",p_name);
   me->set("pet/value",0);

   me->set("pet/id",p_id);

   me->set("pet/lv",1);
   me->set("pet/host_name",me->query("name"));
 me->set("pet/host",me->query("id"));
  say ("圣诞老家伙笑了笑说:「可要好好待它哦」,说完打开一个小竹笼,一只小\n"
"猫从里边钻了出来\n");
 
   pet=new("/u/eatdami/cat", 1);
   pet->move(environment(me));
   message_vision("$N念动咒语，右手一挥，"+this_player()->query("name")+"得到了一只小猫咪作为圣诞礼物。\n", this_object(), this_player());
   this_player()->set("asked/"+YEAR,1); 
  return 1;
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
	say ("圣诞老人看见你进来,走到你身边说:「您想要什么礼物吗?」\n");
		break;
	case 1 :
	say("圣诞老人看见你进来,走到你身边说:「不想要个女朋友或宠物吗？」\n");
                break;
	}
}

