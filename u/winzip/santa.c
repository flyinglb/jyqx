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
	set_name(HIW "ʥ������" NOR, ({"santa claus","santa","claus" }) );
	set("gender", "����");
	set("age", 3005);
	set("long",
		"����һλ�ɷ���ǰ׷�����ĺ�������ˣ�ÿ��ʥ�������Զ�����.\n���Ժ�������������˽��ƽ������ɽ��ˮ, �����ķ���\n");
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
		"ʥ������"   : (: ask_me :),
		"present"   : (: ask_me :),
		"gift"   : (: ask_me :),
		"����"   : (: ask_me :),
		"Ů����"   : (: ask_me2 :),
		"gf"   : (: ask_me2 :),
		"����"   : (: ask_me3 :),
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
return ("�Բ��𣬽����ʥ���������Ѿ�Ҫ���ˡ�\n");
if (this_player()->query("age")<15 )
{
             ob=new("/d/city2/obj/flower/seed");
             ob->move(this_player());
 message_vision("$N��������һ�ӣ�"+this_player()->query("name")+"�õ���һ�û�������ΪС���ӵ�ʥ�������\n", this_object(), this_player());
this_player()->set("asked/"+YEAR,1);
return ("ףʥ������!\n");
}
if (random(10)>8) 
{
             ob=new("/clone/money/gold");
             ob->set_amount(1000);
             ob->move(this_player());
 message_vision("$N��������һ�ӣ�"+this_player()->query("name")+"�õ���ǧ���ƽ���Ϊʥ�����\n", this_object(), this_player());
}
else if(random(10)>8) 
{
             ob=new("/u/eatdami/mac3");
             ob->move(this_player());
 message_vision("$N��������һ�ӣ�"+this_player()->query("name")+"�õ��˻ƽ���̨��Ϊʥ�����\n", this_object(), this_player());
}
else if(random(10)>8) 
{
             ob=new("/clone/misc/mask");
             ob->move(this_player());
 message_vision("$N��������һ�ӣ�"+this_player()->query("name")+"�õ��������Ϊʥ�����\n", this_object(), this_player());
}
else if (random(10)>8) 
{
             ob=new("/clone/money/thousand-cash");
             ob->set_amount(10);
             ob->move(this_player());
 message_vision("$N��������һ�ӣ�"+this_player()->query("name")+"�õ�������������Ϊʥ�����\n", this_object(), this_player());
}
if (random(10)>7) 
{
             ob=new("/d/city/obj/magic");
             ob->move(this_player());
 message_vision("$N��������һ�ӣ�"+this_player()->query("name")+"�õ���ħ����������Ϊʥ�����\n", this_object(), this_player());
}
else if(random(10)>7) 
{
             ob=new("/d/emei/obj/yitian-jian");
             ob->move(this_player());
 message_vision("$N��������һ�ӣ�"+this_player()->query("name")+"�õ������콣��Ϊʥ�����\n", this_object(), this_player());
}
else if(random(10)>8) 
{
             ob=new("/clone/money/thousand-cash");
             ob->set_amount(100);
             ob->move(this_player());
 message_vision("$N��������һ�ӣ�"+this_player()->query("name")+"�õ���һ����ǧ����Ʊ��Ϊʥ�����\n", this_object(), this_player());
}
else if(random(10)>7) 
{
             ob=new("/d/shaolin/obj/fumo-dao");
             ob->move(this_player());
 message_vision("$N��������һ�ӣ�"+this_player()->query("name")+"�õ��˷�ħ����Ϊʥ�����\n", this_object(), this_player());
}
else if(random(10)>7) 
{
             ob=new("/d/shaolin/obj/jingang-zhao");
             ob->move(this_player());
 message_vision("$N��������һ�ӣ�"+this_player()->query("name")+"�õ��˽������Ϊʥ�����\n", this_object(), this_player());
}
else if(random(10)>7) 
{
             ob=new("/d/city2/obj/shouzhuo");
             ob->move(this_player());
 message_vision("$N��������һ�ӣ�"+this_player()->query("name")+"�õ���������Ϊʥ�����\n", this_object(), this_player());
}
else if(random(10)>8) 
{
             ob=new("/clone/money/tenthousand-cash");
             ob->move(this_player());
 message_vision("$N��������һ�ӣ�"+this_player()->query("name")+"�õ��˽�Ʊ��Ϊʥ�����\n", this_object(), this_player());
}
else if(random(10)>7) 
{
             ob=new("/d/city2/obj/baojia");
             ob->move(this_player());
 message_vision("$N��������һ�ӣ�"+this_player()->query("name")+"�õ��˽�˿������Ϊʥ�����\n", this_object(), this_player());
}
else if(random(10)>7) 
{
             ob=new("/d/city2/obj/bishou");
             ob->move(this_player());
 message_vision("$N��������һ�ӣ�"+this_player()->query("name")+"�õ���ذ����Ϊʥ�����\n", this_object(), this_player());
}
else if(random(10)>7) 
{
             ob=new("/d/city2/obj/flower/flower");
             ob->move(this_player());
 message_vision("$N��������һ�ӣ�"+this_player()->query("name")+"�õ���һ�仨��Ϊʥ�����\n", this_object(), this_player());
}
else if(random(10)>6) 
{
             ob=new("/u/eatdami/mac2");
             ob->move(this_player());
 message_vision("$N��������һ�ӣ�"+this_player()->query("name")+"�õ���������˷���Ϊʥ�����\n", this_object(), this_player());
}
else
{
             ob=new("/d/city2/obj/flower/seed");
             ob->move(this_player());
 message_vision("$N��������һ�ӣ�"+this_player()->query("name")+"�õ���һ�仨������Ϊʥ�������\n", this_object(), this_player());
}
this_player()->set("asked/"+YEAR,1);
return("ףʥ�����֣�\n");
}


string ask_me2()
{
object ob;
if (this_player()->query("asked/"+YEAR)) 
return ("�Բ��𣬽����ʥ���������Ѿ�Ҫ���ˡ�\n");

if (this_player()->query("gender")!="����") 
return ("�Բ����ѵ���Ҫ��ͬ��������\n");

message_vision("$N��������һ�ӣ�"+this_player()->query("name")+"�õ���Ů����˫����Ϊʥ�����\n", this_object(), this_player());
message_vision("$N��"+this_player()->query("name")+"˵��try ask er about ��Ը��Ը������ߡ�\n", this_object(), this_player());
this_player()->set("weiwang",70);
this_player()->set("asked/"+YEAR,1);
ob=new("/d/city2/npc/shuanger");
ob->move(environment(this_player()));
return("ףʥ�����֣�\n");
}

string ask_me3()
{
//object ob;
if (this_player()->query("asked/"+YEAR)) 
return ("�Բ��𣬽����ʥ���������Ѿ�Ҫ���ˡ�\n");

if (this_player()->query("gender")!="Ů��") 
return ("�Բ������˼�Ҫ����������ȥ�Ҹ�Ů����������ɡ�xixi\n");
   this_player()->set_temp("pet_ok");
say("ʥ���ϼһ￴����һ��˵:����Ҫ��è��ȡ��������Ŷ��\n"
"( pet ������ Ӣ���� )\n"
"�ҵ�������\n");
return("ףʥ�����֣�\n");
}

int do_pet(string arg)
{

    string p_name,p_id;
    object pet;
    object me;
    me=this_player();
   if((me->query("pet/make"))) {
	say ("ʥ���ϼһ�������˵:��һ��ֻ����һֻè�С�\n");
   return 1;
    }

  if(!arg)
       return notify_fail("�����˵.\n");
    sscanf(arg,"%s %s",p_name,p_id);
   if (!p_name||!p_id)
         return notify_fail("ʲô?(ʹ��pet �������� Ӣ������)\n");
  
   me->set("pet/make",1);
   me->set("pet/name",p_name);
   me->set("pet/value",0);

   me->set("pet/id",p_id);

   me->set("pet/lv",1);
   me->set("pet/host_name",me->query("name"));
 me->set("pet/host",me->query("id"));
  say ("ʥ���ϼһ�Ц��Ц˵:����Ҫ�úô���Ŷ��,˵���һ��С����,һֻС\n"
"è��������˳���\n");
 
   pet=new("/u/eatdami/cat", 1);
   pet->move(environment(me));
   message_vision("$N��������һ�ӣ�"+this_player()->query("name")+"�õ���һֻСè����Ϊʥ�����\n", this_object(), this_player());
   this_player()->set("asked/"+YEAR,1); 
  return 1;
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
	say ("ʥ�����˿��������,�ߵ������˵:������Ҫʲô������?��\n");
		break;
	case 1 :
	say("ʥ�����˿��������,�ߵ������˵:������Ҫ��Ů���ѻ�����𣿡�\n");
                break;
	}
}

