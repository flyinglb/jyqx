// modify by wind
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
object ob;
int number=1;

void create ()
{
  seteuid(getuid());
	set_name(HIY"�ƽ���̨"NOR, ({"mac3"}));
  set("long",
HIY"�ã���  �գӣ�  �ȣţ̣�  �ͣ���\n"+
HIY"	��  ����  �������  �����д�Ǯ �� �����\n"NOR);
        if( clonep() )
                set_default_object(__FILE__);
        else {

  set_weight(50000);
  set("unit","֧");
  set("value",100000);
  set("material","gold");
set("wield_msg", HIW"$N��ţ���Ĵ�����γ�һֻ"+this_object()->query("name")+"\n
"NOR);
set("unwield_msg", HIY"$N����ĸ���Ҿ���һ�������������е�\n"NOR+
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

	notify_fail("��Ҫ˵Щʲô��\n");

   flag=0;

   return 0;

  }

for(i=0;i<number;i++)

  {


    if(ob!=this_player())

    {

	message("channel:music", HIY"�������ݳ��᡿"+this_player()->query("name")+"������"+str+"\n"NOR,users());
 flag++;

    }

  }

  if(flag!=0)

  {

	write("�����ţͣ��������˵��"+str+"\n");

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
        return notify_fail("��Ҫ��ʲ��?\n");
	if (this_object()->query_temp("sing")==1) 
           return notify_fail("�����������ڳ����أ����Ե�һ����ɡ�\n"); 
	if (this_player()->query_temp("sing")==1) 
           return notify_fail("�����������ڳ����أ����Ե�һ����ɡ�\n"); 
	this_player()->set("money", 10000);
	if(this_player()->query("balance")<this_player()->query("money"))
	return notify_fail(""+this_player()->name()+"you no balance\n");
else
	if(this_player()->query("balance")>=this_player()->query("money"))
{
	this_player()->set("balance",this_player()->query("balance") -
	this_player()->query("money"));
	message_vision(HIB"�ͣ���  ���������  ����  �������\n"NOR,
	this_player());
	this_player()->set("money", 0);
}
	this_object()->set_temp("sing",1);
	this_player()->set_temp("sing",1);

        if(str=="cd-3")
        {
        message_vision("$N������һ��������ġ���̫��!\n",this_player());
	ob=new("/u/eatdami/cds/cd03");
        }
        if(str=="cd-2")
        {
	message_vision("$N����һ�š�ͬ�����㡷�ڣףϣңˣͣ�����\n",me);
	ob=new("/u/eatdami/cds/cd02");
       }
        if(str=="cd-1")
        {
	message_vision("$N����һ�š�����ң���ڣףϣңˣͣ�����\n",me);
	ob=new("/u/eatdami/cds/cd01");
        }
        if(str=="cd-4")
        {
	message_vision("$N����һ�š���С�����ģã��ڣףϣңˣͣ�����\n",me);
	ob=new("/u/eatdami/cds/cd04");
        }
        if(str=="cd-5")
        {
	message_vision("$N����һ�š������糾���ģã��ڣףϣңˣͣ�����\n",me);
	ob=new("/u/eatdami/cds/cd05");
        }
        if(str=="cd-6")
        {
	message_vision("$N����һ�š���ͷƤЬ���ģã��ڣףϣңˣͣ�����\n",me);
	ob=new("/u/eatdami/cds/cd06");
       }
         if(str=="cd-7")
        {
	message_vision("$N����һ�š����꡷�ģã��ڣףϣңˣͣ�����\n",me);
	ob=new("/u/eatdami/cds/cd07");
        }
         if(str=="cd-8")
        {
	message_vision("$N����һ�š������ᡷ�ģã��ڣףϣңˣͣ�����\n");
	ob=new("/u/eatdami/cds/cd08");
        }
         if(str=="cd-9")
        {
        message_vision("$N ������һ��ɺ�ġ�����ˮ�硷!\n",this_player());
        ob=new("/u/eatdami/cds/cd09");
        }
         if(str=="cd-10")
        {
        message_vision("$N ������һ��Ӣ�ĸ���!\n",this_player());
        ob=new("/u/eatdami/cds/cd10");
        }
         if(str=="cd-11")
        {
        message_vision("$N ������һ��Ӣ�ĸ���!\n",this_player());
        ob=new("/u/eatdami/cds/cd11");
        }
         if(str=="cd-12")
        {
        message_vision("$N ������һ��Ӣ�ĸ���\n",this_player());
        ob=new("/u/eatdami/cds/cd12");
        }
         if(str=="cd-13")
        {
        message_vision("$N ������һ��Ӣ�ĸ���\n",this_player());
        ob=new("/u/eatdami/cds/cd13");
        }
         if(str=="cd-14")
        {
        message_vision("$N ������һ��Ӣ�ĸ���\n",this_player());
        ob=new("/u/eatdami/cds/cd14");
        }
         if(str=="cd-15")
        {
        message_vision("$N ������һ��Ӣ�ĸ���\n",this_player());
        ob=new("/u/eatdami/cds/cd15");
        }
         if(str=="cd-16")
        {
        message_vision("$N ������һ��ưټҵġ����롷\n",this_player());
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
���  �����  ������  �����  ���������  �����  ��play��
such as play cd-1  (cd-1��cd-8   ���ĸ�)
or      play cd-10 (cd-10��cd-15 english song)
or	play cd-16 (cd-16  MUD����һ)

ע: ����ˮ��MAC, �ŵ��ǵ���CD, �������ܻ���Щ����. 
    ���ѡcdѡ����, MAC���ܻῨ��, �Ͳ����ٳ���, �����¹���.
    ��������MAC��CD��,����robin��ϵ.
Help

);

  return 1;
}
