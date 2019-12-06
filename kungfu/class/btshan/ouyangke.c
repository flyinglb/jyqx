//NPC /d/baituo/npc/ouyangke.c
#include <ansi.h>
inherit F_MASTER;
inherit F_UNIQUE;
inherit NPC;
void greeting(object ob);
int accept_object(object who, object ob);
void create()
{
	seteuid(getuid());
	set_name("ŷ����", ({ "ouyang ke", "ouyang", "ke" }));
	set("long", "��һ��Ʈ�ݵİ�ɫ��������ҡ���ȣ��������š�\n");
	set("title", "����ɽ��ׯ��");
	set("nickname", HIM "��������" NOR);
	set("gender", "����");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 10);

	set("combat_exp", 200000);
	set("score", 40000);

	set_skill("unarmed", 100);
	set_skill("hand", 80);
	set_skill("dodge", 120);
	set_skill("parry", 90);
	set_skill("force", 90);
	set_skill("staff", 80);
	set_skill("training", 50);
	set_skill("hamagong",90);
	set_skill("chanchu-bufa", 100);
	set_skill("shexing-diaoshou", 100);
	set_skill("lingshe-zhangfa", 100);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");

	set("startroom","/d/city/beidajie1");

        create_family("����ɽ��",2,"����");

	set("chat_chance", 10);
	set("chat_msg", ({
		"ŷ���˳���: Ư���������������������Ҷ࿴��һ�ۣ���\n",
		"ŷ����ɫ���Եؿ��Žֱߵ�С���\n",
		"ŷ���˰�ֽ��һչ��ת����ȥ�����������������֪�����ѵã�\n",
		(: random_move :)
	}) );

	setup();
	carry_object("/d/baituo/obj/baipao")->wear();
	add_money("silver",10);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) 
       {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("gender")=="Ů��")
	{
	   switch(random(3))
	   {
		case 0:command("rose "+(string)ob->query("id"));break;
	  	case 1:command("kiss "+(string)ob->query("id"));break;
	   	case 2:command("love "+(string)ob->query("id"));break;
	   }
     
	}
	else
           say("ŷ����̾��һ����˵����λ"+RANK_D->query_respect(ob)+
               ",��Ҫ���ܸ���Ūһ��Ů�����ͺ��ˡ�\n");
	return;
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") == "����ɽ��")
	{
	     if((int)ob->query("combat_exp")<10000)
	       command("say ��ľ���̫�ͣ��һ��������㡣����Ŭ���ɡ�\n");
	     else
               {command("say �������Ҫ�ú�ѧ��\n");               
	        command("recruit "+ob->query("id"));
                 }
	      return;
	}
	if ((string)ob->query("gender") == "Ů��")
		message_vision("ŷ���˶����˵������λ" + RANK_D->query_respect(ob) +
		"�����ҵĺ���֪����\n�����ڻ��������㣬ֻ�������ϰ���ɽ��\n",ob);
	else
		message_vision("ŷ����ЦЦ˵����λ"+RANK_D->query_respect(ob)+
		"�������ڻ��������㣬ֻ�������ϰ���ɽ��\n",ob);
     write(HIY "ֻ��ŷ���˰�ֽ��������ǰһ�Σ�\n
     �������ǰһ����������ƮƮ�ط��˳�ȥ����\n" NOR);
     ob->move("/d/baituo/liangong");

}

int accept_fight(object ob)
{
	if ((string)ob->query("gender") == "Ů��")
	{
		message_vision("ŷ���˰ڰ���˵������λ"+RANK_D->query_respect(ob)+
		"���������۸�Ů�����أ�\n", ob);
		return 0;
        }
          if ((string)ob->query("family/family_name") == "����ɽ��")
	 {
	  if((int)ob->query("combat_exp")<100000)
	    return notify_fail("ŷ����Ц������ľ���̫����,��������ɡ���\n");
	  }
	message_vision("ŷ����һ����˵������λ"+RANK_D->query_respect(ob)+
	"����������ˡ�\n", ob);

	return 1;
}
 
int accept_object(object who, object ob)
{
	object obn;
          if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	
	if ( !present(ob, who) ) {say("��û�����������\n"); return 0;}

	if (  (string)ob->query("gender") != "Ů��")
	{	say("ŷ���˲���Ҫ���������\n"); return 0;}
	if( environment(this_object())->query("short") == "����Ժ" )
	{	say("ŷ�����Ѿ���Ů���ˡ�\n"); return 0;}
	if ( (int)ob->query("age") <18 )
	{	say("ŷ���˴�ʧɫ����δ������Ů������Ҫ��\n"); return 0;}
        if ( (int)ob->query("age") >40 )
	{	 say("ŷ���������һЦ���������ϹŶ������������Լ��ɣ�\n"); return 0;}

			  
	obn=new("/clone/money/silver");
        obn->set_amount(30);
        obn->move(who);
        message_vision("ŷ����һ�Ѱ�"+ob->query("name")+"���ڻ����$N˵����������������ѣ�
              �ۻ�ͷ����\n˵�꣬��Я��"+ob->query("name")+"������Ժ��ȥ...\n",who);
        move("/d/city/lichunyuan");
        return 1;
}
