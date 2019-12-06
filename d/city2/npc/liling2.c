inherit NPC;
#include <ansi.h>

int waiting(object me);
int checking(object me);
int do_chase(object me);
int do_kill(object me, object dest);
string ask_bf();
string reclaim();
varargs void drool(string msg, string who);
string *rnd_say = ({
	"�Һ�Ȼ����ȥ����.",
	"������û����bbs���к�����Ӵ!",
	"Ϊʲô��Ҷ�������?��",
	"�ɲ����Ը�����������ɱ�ˣ�",
	"���������鲻���, ��ҿ�ҪС����.",
	"��������������?",
	"��������������?",
	"˭�뽲�����£�",
	"���ڼ����ˣ�",
	"Ϊʲô��˵����?",
	"Ϊʲô����ȥ˯����?",
	"˭��ȥ����Ӱ?",
	"�ҿ��Գ�ȥɱ����?",
        "���ֱ����һ����å! ",
	"�Ҷ�MUD����ûʲô�ø�.",
	"�Ҷ��������ûʲô��Ȥ.",
	"�Һ���ܱ�Ү.",
	"�������������?",
	"˭Ҫ������ᰡ��",
	});

void create()
{
	set_name("����", ({"liling"}));
	set("nickname", HIM "����֮��" NOR);
	set("long", HIC "\n�����ü�������������˫�۾����ĵ�ֱ���Թ��˻��ǡ�\n"+
	"����ɫ��Ө����ӳ���ں�����֮�£��������ɷ��\n"+
	"������ȻһЦ�����������·����۲���ת֮�䣬\n"+
	"���һ����������飬�������м����ľ��硣\n" NOR);
	set("title", HIC "����֮��" NOR);
	set("gender", "Ů��");
	set("age", 21);
	set("rank_info/respect", "С����");
	set("max_qi", 10000);
	set("max_jing", 10000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("inmortal",1);
	set("age", 20);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	set("no_get_from", 1);
	set("killed", "����");
	set("killer", "����");

	set_skill("force", 200);
	set_skill("dodge", 500);
	set_skill("unarmed", 500);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("whip", 200);
	set_skill("blade", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);
	set_skill("literate", 200);

	set_skill("yunlong-jian", 150);
	set_skill("yunlong-xinfa", 100);
	set_skill("yunlong-shengong", 200);
	set_skill("yunlong-shenfa", 200);
	set_skill("shenxing-baibian", 200);
	set_skill("yunlong-bian", 150);
	set_skill("yunlong-shou", 200);
	set_skill("yunlong-zhua", 200);

	map_skill("dodge", "shenxing-baibian");
	map_skill("force", "yunlong-shengong");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");
	
	prepare_skill("hand", "yunlong-shou");
	prepare_skill("claw", "yunlong-zhua");

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 100);
	set("env/wimpy", 90);
	set("inquiry", ([
		"̸ҫ"   : (: ask_bf :),
		"����"   : (: ask_bf :),  
		"��"     : (: ask_bf :),
		"rec"     : (: reclaim :),
	]) );
	set("chat_chance", 10);
	set("chat_msg", ({
		"�����Ȼ���˸�������Ц��: �������ȥ������\n",
		(: reclaim :),
		(: reclaim :),
		(: reclaim :),
		(: reclaim :),
		(: reclaim :),
		(: reclaim :),
		(: reclaim :),
		(: reclaim :),
		(: reclaim :),
		(: reclaim :),
		(: reclaim :),
		(: reclaim :),
		(: command("kuang") :),
		(: command("kan") :),
		(: command("sing2") :),
		(: command("angry") :),
		(: command("slogan2") :),
		(: command("yawn") :),
		(: command("lazy") :),
		(: command("laughproud") :),
		"�����Ȼ����˵���򵹳���̶���򵹷磡\n",
		"�������ĵ������־̾��: ����һ���ˣ���û��˼��\n",
		"�������������һ���С�֣������°�˵: ˭�����˵˵��?\n",
		"����ն��������˵: �ţ�˭Ҫ���۸��ң��Ҿ���������\n",
		"�����Ȼݸ��һЦ��: ����������Ҫ��ɱ˭�أ�\n",
		"������˸���Ƿ������������סӣ��С�ڣ��������������ˡ�\n",
		(: drool :),
		(: drool :),
		(: drool :),
		(: drool :),
		(: drool :),
		(: drool :),
	}) );
	set("combat_exp", 3000000);
	set("shen_type", 1);
	set("score", 5000000);
	set("chat_chance_combat", 20);  
	set("chat_msg_combat", ({
		"��������̾���������������Ǻο���?\n",
		(: command("!!!") :),
		(: command("smile") :),
		(: command("poem") :),
		(: command("yawn") :),
		(: command("lazy") :),
		(: command("giggle") :),
		(: command("waggle") :),
		(: command("laughproud") :),
		(: command("nomatch") :),
		(: command("xixi") :),
		(: command("chat ���кλ����������? ����ͳ�ȫ����ɡ�\n") :),
		(: command("chat ����" + RANK_D->query_rude(this_player())+"�������ִ�Բ���?\n") :),
		(: command("unwield bishou") :),
		(: command("unwield bishou") :),
		(: command("unwield bishou") :),
		(: command("unwield bishou") :),
		(: command("wield bishou") :),
		(: command("wield bishou") :),
		(: command("wield bishou") :),
		(: command("wield bishou") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
	}) );
	setup();
	carry_object("/d/city2/obj/ring")->wear();
	carry_object("/d/city2/obj/crystal")->wear();
	carry_object("/d/city2/obj/shouzhuo")->wear();
	carry_object("/d/city2/obj/majia")->wear();
	carry_object("/d/city2/obj/baojia")->wear();
	carry_object("/d/city2/obj/bishou")->wield();
	carry_object("/d/city2/obj/yupei")->wear();
	carry_object("/d/city2/obj/hlbian")->wield();
	if( clonep() ) CHANNEL_D->register_relay_channel("chat");
	if( clonep() ) CHANNEL_D->register_relay_channel("rumor");
}

string make_reply()
{
}

int add_phrase(string who, string msg)
{
	msg = replace_string(msg, "?", "");
	msg = replace_string(msg, "��", "");
	msg = replace_string(msg, "��", "");
	msg = replace_string(msg, "!", "");
	msg = replace_string(msg, "��", "");
	msg = replace_string(msg, "��", "");
	msg = replace_string(msg, "��", "");
	msg = replace_string(msg, "Ү", "");
	msg = replace_string(msg, "��", "");
	msg = replace_string(msg, "Ŷ", "");
	msg = replace_string(msg, "��", "");

	if( msg!="" ) {
		add("memory/" + who, ({ msg }));
		return 1;
	} else return 0;
}


void relay_channel(object ob, string channel, string msg)
{
	string who;

	if( !userp(ob) || (channel != "chat") ) return;
	who = ob->query("name");

	if( ob==this_object() ) return;

	if( add_phrase(who, msg) &&	random(10) > 3 )
		drool(msg, ob->query("name"));
}

void relay_say(object ob, string msg)
{
	string who;

	if( !userp(ob) ) return;
	who = ob->query("name");

	if( ob==this_object() ) return;

	if( add_phrase(who, msg) &&	random(10) > 3 )
		drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
       if( !userp(ob) ) return;
	switch(verb) {

        case "shutup":	
        command ("chat "+ ob->query("name") + ",�����" + RANK_D->query_rude(ob)+"���Һ���������\n");
	message_vision("\n$N����һ������˵���������Ϊ�ұ���ġ�\n", this_object());
	message_vision("$N˵�꣬����һ������ȥ��\n", this_object());
	destruct(this_object());
        break;
   
    
	case "fang":
	case "hug":
	case "kiss":
	case "mo":
	case "18mo":
	case "nocloth":

	if ( (string) ob -> query ("gender") == "����"||(string) ob -> query ("gender") == "����" )
	{
	command ("chat �����������"+ ob->query("name") + "��Ҫ�����ң�\n") ;
	command("chat ��Ӵ��˭��õ���" + RANK_D->query_rude(ob)+"����Ҳ��һ����ɫ֮ͽ ��");
	}
	else
	{
	message_vision("\n�����$NЦ����������ͬΪŮ��������ôϲ��Ҳ��Ҫ����������\n", ob);
	command("giggle");
	command("chat �벻��"+ ob->query("name") +"��" + RANK_D->query_rude(ob)+"����Ȼ��һ����̬��");
	}
	message_vision("$Nҡ��ҡͷ����$n����̾���������������Ǻο���?\n",this_object(),this_player());
	if(wizardp(ob))
	{
	ob->set("env/immortal",0);
	command("aim "+ob->query("id"));
	command("shoot");
	}
	this_object()->kill_ob(ob);
	break;
       default:
       if( random(10)<2 )
       {
	command(verb + " " + ob->query("id"));
	return;
       }
       else
	{
	switch(verb)
	{
	case  "zhuyi":
	case  "jia":
	case  "cuo":
	case  "rou":
	case  "cu":
	case  "kan":
	case  "bi":
	case  "die":
	case  "kick":
	case  "taste":
	case  "hate":
	case  "brag":
	case  "showscar":
	case  "callname":
	case  "slap":
	case  "rascal":
	case  "slapsb":
	case  "bite":
	case  "knife":
	case  "drug":
	case  "cook":
	case  "stuff":
	case  "shit":
	case  "shutup":
	case  "stare":
	case  "praisemapi":
	case  "anniversary":
	case  "heng":
   switch(random(50))
   {
    case 0:
    command ("kick "+ ob->query("id"));
    command ("xixi");
    break;
    case 1:
    command ("slap "+ ob->query("id"));
    command ("xixi");
    break;
    case 2:
    command ("drug "+ ob->query("id"));
    break;
    case 3:
    command ("smell");
    command ("cook "+ ob->query("id"));
    break;
    case 4:
    command ("trip "+ ob->query("id"));
    break;
    case 5:
    command ("knife "+ ob->query("id"));
    command ("doubt "+ ob->query("id"));
    break;
    case 6:
    command("cry");
    command("chat ����"+ob->query("name")+"��"+RANK_D->query_rude(ob)+"���滵��\n");
    break;
    case 7:
    command ("shutup ");
    command ("shutup "+ ob->query("id"));
    break;
    case 8:
    command("cry");
   command ("chat �����������"+ ob->query("name") + "��Ҫ�����ң�\n") ;
   command ("die "+ ob->query("id"));
    break;
    case 9:
    command ("callname "+ ob->query("id"));
    break;
    case 10: 
    command ("shit "+ ob->query("id"));
    break;
    case 11: 
    command ("hero");
    command ("shout "+ ob->query("id"));
    break;
    case 12: 
    command ("shake");
    command ("nomatch "+ ob->query("id"));
    break;
    case 13: 
    command ("stare "+ob->query("id"));
    command ("hit "+ ob->query("id"));
    break;
    case 14: 
    command ("sneer");
    break;
    case 15: 
    command("chat ��Ӵ��"+ob->query("name")+"���" + RANK_D->query_rude(ob)+"�治Ҫ����\n");
    command ("faint");
    break;
    case 16: 
    command ("shrug");
    break;
    case 17: 
    command ("poke "+ob->query("id"));
    command ("hehe");
    break;
    case 18: 
    command ("blush");
    break;
    case 19: 
    command ("nono");
    write(HIM "����һ�����ߺ��������������㣬�㡣����\n" NOR);
    break;
    case 20: 
    command("cry");
    command("chat ��Ӵ��˭��õ���" + RANK_D->query_rude(ob)+"����Ҳ��һ����̬��\n");
    break;
    case 21: 
    command ("blush");
    command ("chat �����������"+ ob->query("name") + "��Ҫ�����ң�\n") ;
    break;
    case 22: 
    command ("nono");
    command ("cry");
    break;
    case 23:
    command ("hate");
    command ("die "+ob->query("id"));
    break;
    case 24: 
    command ("careful");
    break;
    case 25: 
    command ("rascal "+ob->query("id"));
    break;
    case 26:
    command ("nono");
    command ("faint");
    break;
    case 27: 
    command ("grpfight "+ob->query("id"));
    break;
    case 28: 
    command ("rascal "+ob->query("id"));
    command("chat ��Ӵ��˭��õ���" + RANK_D->query_rude(ob)+"����Ȼ��һ������å��\n");
    break;
    case 29: 
    command ("rascal "+ob->query("id"));
    command ("die "+ob->query("id"));
    break;
    case 30:
    command("waggle "+ob->query("id"));
    break;
    case 31:
    command("waggle");
    command ("callname "+ ob->query("id"));
    break;
    case 32: 
    command ("chat �����˰������Ҵ�"+ ob->query("name") + "�����ɫħ��\n") ;
    break;
    case 33: 
    command("chat ��Ӵ����Ӵ��"+ ob->query("name")+"��" + RANK_D->query_rude(ob)+"����ʵ��\n");
    command ("shit "+ ob->query("id"));
    break;
    case 34:
    command ("chat �����������"+ ob->query("name") + "��Ҫ�����ң�\n") ;
    command("chat ��Ӵ��˭��õ���" + RANK_D->query_rude(ob)+"����Ҳ��һ����̬��\n");
    command("faint "+ob->query("id"));
    break;
    case 35: 
    command ("kick "+ ob->query("id"));
    command ("grin");
    break;
    case 36:
    command ("slap "+ ob->query("id"));
    command ("hehe");
    break;
    case 37: 
    command("faint");
    break;
    case 38: 
    command("chat ��Ӵ��˭��õ���" + RANK_D->query_rude(ob)+"����Ҳ��һ����̬��\n");
    command ("callname "+ ob->query("id"));
    break;
    case 39: 
    command("!!!");
    break;
    default:
       if( random(10)<3 )
       {
	command(verb + " " + ob->query("id"));
	return;
       }
	else	
	{ 
	command ("chat �����������"+ ob->query("name") + "��Ҫ�����ң�\n") ;
	  command("chat ��Ӵ��˭��õ���" + RANK_D->query_rude(ob)+"����Ҳ��һ����̬��\n");
	  write(HIC "�����Ȼ����˵���򵹳���̶���򵹷磡\n" NOR);
	  command("cry");
	  command("faint "+ob->query("id"));
	}
       break;
   return;
   }
   break;
	case "wanfu":
	case "sister":
	case "jump":
	case "love":
	case "lovelook":
	case "praise":
	case "visite":
	case "drinkcup":
	case "goodkid":
	case "pat":
	case "addoil":
	case "laughproud":
	case "smile":
	case "xixi":
	case "hehe":
	case "giggle":
	case "thumb":
	case "admire":
	case "applaud":
	case "hi":
	case "qmarry":
	case "lov":
	case "ai":
	case "yi":
   switch(random(35))
   {
    case 0: 
    command ("pat "+ ob->query("id"));
    break;
    case 1: 
    command ("humble");
    break;
    case 2: 
    command ("praise "+ ob->query("id"));
    break;
    case 3: 
    command ("xixi");
    break;
    case 4: 
    command("chat "+ob->query("name")+"�����µ�һ����ˣ�\n");
    command ("giggle "+ ob->query("id"));
    break;
    case 5: 
    command ("goodkid "+ ob->query("id"));
    break;
    case 6:
    command ("pat "+ ob->query("id"));
    break;
    case 7: 
    command("chat "+ob->query("name")+"���������õ����ˣ�\n");
    command ("giggle");
    break;
    case 8:
    command ("praisemapi "+ ob->query("id"));
    break;
    case 9:
    command ("laughproud "+ ob->query("id"));
    break;
    case 10:
    command("chat �ţ�"+ob->query("name")+"����Ŭ������\n");
    command ("thank");
    break;
    case 11: 
    command ("nod");
    command ("xixi");
    break;
    case 12:
    command ("shake");
    break;
    case 13:
    command("chat �ţ�"+ob->query("name")+"����Ŭ������\n");
    command ("courage "+ob->query("id"));
    break;
    case 14: 
    command ("xixi");
    break;
    case 15:
    command ("lovelook "+ob->query("id"));
    break;
    case 16:
    command ("smile "+ob->query("id"));
    break;
    case 17:
    command("chat �ţ��Һ�ϲ��"+ob->query("name")+"Ү��\n");
    command ("kiss "+ob->query("id"));
    break;
    case 18:
    command ("addoil "+ob->query("id"));
    break;
    case 19:
    command ("xixi");
    break;
    case 20:
    command ("shakehand "+ob->query("id"));
    break;
    case 21:
    command ("courage "+ob->query("id"));
    break;
    case 22:
    command ("touch "+ob->query("id"));
    break;
    case 23:
    command ("humble");
    break;
    case 24:
    command ("protect "+ob->query("id"));
    break;
    case 25:
    command ("thumb "+ob->query("id"));
    break;
    case 26:
    command ("applaud ");
    command ("giggle ");
    break;
    case 27:
    command ("hi");
    break;
    case 28:
    command ("hi "+ob->query("id"));
    break;
    case 29:
    command("chat ����ô������\n");
    command("angry");
    break;
    default:
    command(verb + " " + ob->query("id"));
    command("smile");
    break;
   return;
   }
  return;
  }
}
}
return;
}

varargs void drool(string msg, string who)
{
	mapping mem;
	string *ob;

	mem = query("memory");
	if( !mapp(mem) )
	{
		if (random(10)<7)
			command("chat ��ô��Ҷ���˵���ˣ����ǻ�������\n");
                else if (random(10)<8)
                        command("chat " +  rnd_say[random(sizeof(rnd_say))]);
                return;
	}

	if( !msg || !who) {
		ob = keys(mem);
		who = ob[random(sizeof(ob))];
		msg = mem[who][random(sizeof(mem[who]))];
	}

//��ҥ˭����....

	if(random(5)<2)
    {
	if(this_object()->query("killed")!=who)
	this_object()->set("killed",who);
	}
	while (this_object()->query("killed")==this_object()->query("killer"))
    {
	if(random(10)<6)
    {
		if(this_object()->query("killer")!=this_object()->query("killed"))
		this_object()->set("killer",who);
	}
	else switch(random(15))
    {
        case 1:	this_object()->set("killer","����");break;
	case 2:	this_object()->set("killer","����ɮ��");break;
	case 3:	this_object()->set("killer","����");break;
	case 4:	this_object()->set("killer","������");break;
	case 5:	this_object()->set("killer","����");break;
	case 6:	this_object()->set("killer","����");break;
	case 7:	this_object()->set("killer","����");break;
	case 8:	this_object()->set("killer","������");break;
	case 9:	this_object()->set("killer","����");break;
	case 10:this_object()->set("killer","������");break;
	case 11:this_object()->set("killer","������");break;
	}
    }
	if( (strsrch(msg, "help liling") >= 0)&&(query("shutup") >= -5)) 
        { 
        command ("chat "+ who + "�������лл�㰡��\n");
        command("chat* ������Ц�˼���.\n"); 
        this_object()->add("shutup",-1);
        return;
        }
	if( (strsrch(msg, "shutup liling") >= 0)||(strsrch(msg, "�������") >= 0)||(strsrch(msg, "��������") >= 0))
	{	
        if(this_object()->query("shutup")>=5)
           {
           command ("chat "+ who + ",�����" + "����å���Һ���������\n");
	   message_vision("\n$N����һ������˵���������Ϊ�ұ���ġ�\n", this_object());
	   message_vision("$N˵�꣬����һ������ȥ��\n", this_object());
	   destruct(this_object());
           }
        else
        {       
        this_object()->add("shutup",1);
        command("chat* �����������.\n"); 
	command("chat �ߣ�Ϊʲô���ð�˵������\n"); 
	}
	return;
	}
	
if( (strsrch(msg, "liling") >= 0)||(strsrch(msg, "����") >= 0))
	{	
	if((strsrch(msg, "���") >= 0)||(strsrch(msg, "bye") >= 0)|| (strsrch(msg, "ɢ") >= 0)|| (strsrch(msg, "��") >= 0))
	{	
		if( sscanf(msg, "%*sbye%s", msg) == 2 ) msg = "bye" + msg;
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		if( sscanf(msg, "%*sɢ%s", msg) == 2 ) msg = "ɢ" + msg;
		if( sscanf(msg, "%*s���%s", msg) == 2 ) msg = "���" + msg;
		switch(random(13)) {
		case 0:	command("chat "+who+",�����Ҫ����\n"); break;
		case 1:	command("chat �㲻�ǿ���Ц��?\n");	break;
		case 2:	command("chat �Ǹ�����,MUD�����û�ô�.\n"); break;
		case 3:	command("chat* ���˵�ͷ.\n");	break;
		case 4:command("chat* �����������.\n"); break;
		case 5:command("chat* ������޺���۾�����ŵ��� "+who+",����Ҫ���˾ͱ��ٻ�����\n"); break;
		case 6:	command("chat* �����̾��һ���� ��\n");	break;
		case 7:	command("chat "+who+",����һ����ò���?\n");	break;
		case 8:	command("chat "+msg);	break;
		case 9:command("chat �ޣ�"+who+"���������õ�����!\n"); break;
		}
		return;
	}
	if( (strsrch(msg, "kiss") >= 0)|| (strsrch(msg, "love") >= 0)|| (strsrch(msg, "��") >= 0)
		|| (strsrch(msg, "mo") >= 0)|| (strsrch(msg, "��") >= 0)|| (strsrch(msg, "hug") >= 0))
		{
		if( sscanf(msg, "%*skiss%s", msg) == 2 ) msg = "kiss" + msg;
		if( sscanf(msg, "%*smo%s", msg) == 2 ) msg = "mo" + msg;
		if( sscanf(msg, "%*shug%s", msg) == 2 ) msg = "hug" + msg;
		if( sscanf(msg, "%*slove%s", msg) == 2 ) msg = "love" + msg;
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		if( sscanf(msg, "%*s��", msg) == 2 ) msg = "��"+ msg;
		switch(random(20)) {
		case 0:	command("chat "+who+",�㡣����\n"); break;
		case 1:	command("chat �㲻�ǿ���Ц��?\n");	break;
		case 2:	command("chat �Ҳ�ͬ�⣡\n");break;
		case 3:command("chat* ��"+who+"�������˹�ȥ��\n"); break;
		case 4:command("chat* �����������.\n"); break;
		case 5:command("chat ��Ҫ�������\n"); break;
		case 6:command("chat ���񰡷���"+who+"��С��å��������\n"); break;
		case 7:command ("chat �����������"+ who + "��Ҫ�����ң�\n") ;
		case 8:	command("chat* ������Ц�˼���.\n"); break;
		case 9:	command("chat* �������ؾ��˾��졣\n");	break;
		case 10:command("chat* ���ε������ʼ�.\n");	break;
		case 11:command("chat ���Ů��������������\n"); break;
		case 12:command("chat �������ô������\n"); break;
		case 13:command("chat* ��ȻһЦ��˵�����˹���!\n"); break;
		case 14:command("chat* �����͵�ͨ�죬�������㡣���� ��\n");	break;
		case 15:command("chat �ţ�"+who+"���������õ����ˣ�\n"); break;
	                case 16:command ("chat �����������"+ who + "�۸��ң�\n") ; break;
		}
		return;
	}
	if( (strsrch(msg, "��") >= 0)||(strsrch(msg, "shit") >= 0)||(strsrch(msg, "pig") >= 0))
	{	
		if( sscanf(msg, "%*spig%s", msg) == 2 ) msg = "pig" + msg;
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		if( sscanf(msg, "%*sshit%s", msg) == 2 ) msg = "shit" + msg;
		switch(random(15)) {
		case 0:	command("chat ����˵" + msg + "��\n"); break;
		case 1:	command("chat �ѵ���˵����....��\n");	break;
		case 2:	command("chat ���㡰" + msg + "������������ô���أ�\n"); break;
		case 3:	command("chat* �������ؾ��˾��졣\n");	break;
		case 4:	command("chat �������Ϊ��" + msg + "����\n"); break;
		case 5:	command("chat �Ҿ������е�����Ӳ��塣\n"); break;
		case 6:	command("chat ����˵�ɱ���Ҳ�������\n"); break;
		case 7:	command("chat �йء�" + msg + "���Ļ���, �͵���Ϊֹ��.\n"); break;
		case 8:	command("chat "+ who+",�������������е�����ͷ��������\n"); break;
		case 9:	command("chat* ���ĵؿ���"+who+",�޲���"+who+"ȥ����\n"); break;
		case 10:command("chat* ��"+who+"�������˹�ȥ��\n"); break;
		case 11:command("chat* ��Ȼ����˵���򵹳���̶���򵹷磡\n"); break;
		case 12:command("chat* ������޺���۾�����ŵ��� "+who+",�Һ������ˣ�\n"); break;
		case 13:command ("chat �����������"+ who + "����Ҫ�����ң�\n") ; break;
		}
        return;
	}
	if(  (strsrch(msg, "fool") >= 0)||(strsrch(msg, "��") >= 0)|| (strsrch(msg, "fuck") >= 0))
	{	
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		if( sscanf(msg, "%*sfool%s", msg) == 2 ) msg = "fool" + msg;
		if( sscanf(msg, "%*sfuck%s", msg) == 2 ) msg = "fuck" + msg;
		switch(random(15)) {
		case 0:	command("chat �������ô������\n"); break;
		case 1:	command("chat �ҿ����������ܻ���\n");	break;
		case 2:	command("chat "+ who +",���������å��\n"); break;
		case 3:	command("chat* ������ס���ӣ�˵��"+who+"˵���ó�!\n");	break;
		case 4:	command("chat �������Ϊ��" + msg + "����\n"); break;
		case 5:	command("chat �Ҿ������е�����Ӳ��塣\n"); break;
		case 6: command("chat ��!\n"); break;
		case 7:	command("chat* ŭ��:����ô֪����" + msg + "����\n"); break;
		case 8:	command("chat "+ who+"������!��Ҫ����������е�����ͷ��������\n"); break;
		case 9:	command("chat* ���ĵؿ���"+who+",�޲���"+who+"ȥ����\n"); break;
		case 10:command("chat* �����������.\n"); break;
		case 11:command("chat* ������޺���۾�����ŵ��� "+who+"���˵����ҹ���ȥ��\n"); break;
		case 12:command("chat ���񰡷���"+who+"�Ǹ����˵���\n"); break;
		}
		return;
	}
	if(  (strsrch(msg, "cool") >= 0)||(strsrch(msg, "thumb") >= 0)||(strsrch(msg, "praise") >= 0)|| (strsrch(msg, "admire") >= 0))
	{	
		if(random(5)<3)
        {
		switch(random(15)) {
		case 0:	command("chat �������ô������\n"); break;
		case 1:	command("chat ������˵����\n"); break;
		case 2:	command("chat "+who+",û�뵽��Ҳ��ô������\n"); break;
		case 3:	command("chat* ��ȻһЦ��˵������!\n"); break;
		case 4:	command("chat �������Ϊ��" + msg + "����\n"); break;
		case 5: command("chat* ��Ȼݸ��һЦ��: �����ǲ����е����������\n");break;
		case 6:    command("chat* ��ͷ����"+who+"һ�ۣ�û������\n");break;
		case 7: command("chat ��,"+who+"��һ���ú���.\n"); break;
		case 8:command("chat "+who+",�㲻�������ֺ��Ұ�?\n"); break;
		case 9:command("chat* ���˹��ֵ������������� !\n");break;
		case 10:command("chat* ָ��"+who+"��̾������"+who+"�����ֵ�һ���֣���\n");break;
		case 11:command("chat* һ����Ʒ�������������.\n");break;
		}
		return;
        }
	}
	switch(random(80)) {
		case 0:	command("chat �������˵" + msg + "��\n"); break;
		case 1:	command("chat ��Ϊʲô������ô����Ȥ��\n");	break;
		case 2:	command("chat ���㡰" + msg + "������������ô���أ�\n"); break;
		case 3:	command("chat ��,��" + msg + "������Ҳû��ϵ.\n"); break;
		case 4:	command("chat "+who+",���������å��\n"); break;
		case 5:	command("chat ����˵���ǣ�"+"��ʵ"+who+"���Ǹ��ö�����\n"); break;
		case 6:	command("chat ������˵�ġ�" + msg + "��������ʱ�����̬��\n"); break;
		case 7:	command("chat ����Ϊ���̬�Ȳ����Ү.\n"); break;
		case 8:	command("chat ��ע�⣬��ֻ�ǻ�����Ү!\n"); break;
		case 9:	command("chat ���Ů��������������\n"); break;
		case 10:	command("chat ��Ҫ�������Һò��ã�\n");	break;
		case 11:	command("chat �����ҿ������������顣\n");	break;
		case 12:	command("chat* �����̾��һ���� ��\n");	break;
		case 13:	command("chat* ��"+who+"�������˹�ȥ ��\n");	break;
		case 14:	command("chat* �����͵�ͨ�죬�������㡣���� ��\n");	break;
		case 15:    command("chat* ҧ��ҧ����ŭ��: �ţ�˭Ҫ�ٸ��۸��ң��Ҿ���������\n");break;
		case 16:    command("chat* ��Ȼݸ��һЦ��: �������Ǻο��أ�\n");break;
		case 17:    command("chat* ���˸���Ƿ������������סӣ��С�ڣ��������������ˡ�\n"); break;
		case 18:    command("chat* ��ͷ����"+who+"һ�ۣ�û������\n");break;
		case 19:    command("chat* һ˦ͷ��˵���ߣ��Ҷ��������㡣\n");break;
		case 20:	command("chat �йء�" + msg + "���Ļ���, �͵���Ϊֹ��.\n"); break;
		case 21:	command("chat �Ҿ���"+who+"���˼�ֱ����������\n"); break;
		case 22:	command("chat ������˵����\n"); break;
		case 23:	command("chat "+who+",û�뵽��Ҳ������\n"); break;
		case 24:	command("chat* ��ȻһЦ��˵������!\n"); break;
		case 25:	command("chat ��Ȼ������������!\n");
		 	command("chat* �����������.\n"); break;
        case 26:	command ("chat �����������"+ who + "���������ң�\n") ; break;
      	case 27:	command ("chat �Ҽ�ֱ�ܲ�����!\n") ; break;
        case 28:	command ("chat �Һ޲���"+who+"ȥ��!\n") ; break;
        case 29:	command ("chat �����Ϻ��ҹ���ȥ!\n") ; break;
        case 30:	command ("chat �벻Ҫ�����Һò���?\n") ; break;
   		case 31:	command ("chat* �����̲�ס����������\n") ; break;
		case 32:	command("chat* ���ĵؿ���"+who+",�޲���"+who+"ȥ����\n"); break;
		case 33:    command("chat* ҧ��ҧ����ŭ��: �ţ�˭Ҫ���۸��ң��Ҿ���������\n");break;
		case 34:    command("chat* ��Ȼݸ��һЦ��: �����ǲ����е����������\n");break;
		case 35:    command("chat* ���˸���Ƿ������������סӣ��С�ڣ������������е�����ˡ�\n"); break;
		case 36:    command("chat* ��ͷ����"+who+"һ�ۣ�û������\n");break;
		case 37:    command("chat* һ˦ͷ��˵���ߣ��Ҷ��������㡣\n");break;
		case 38:    command("chat ��" + msg + "��,�������\n"); break;
		case 39:    command("chat �Ҿ���"+who+"�����ֻ�����.\n"); break;
		case 40:    command("chat ����ȥ��������.\n"); break;
		case 41:    command("chat �Ҿ�����ѱ��齱Ӧ������"+who+".\n"); break;
		case 42: command("chat* Ц�����Ŀ���"+who+"\n"); break;
		case 43: command("chat �����ģ�������!\n"); break;
		case 44: command("chat �ߣ�\n"); break;
		case 45: command("chat* ����"+who+"һ������.\n"); break;
		case 46: command("chat �ߣ�˭���㰡!\n");break;
		case 47: command("chat ��,"+who+"��һ���ú���.\n"); break;
		case 48:command("chat* ¶���Ի�ı���.\n"); break;
		case 49:command("chat ����?\n"); break;
		case 50:command("chat "+who+",���ǲ������ֺ��Ұ�?\n"); break;
		case 51:command("chat ��,˭��˵�һ���?!\n");break;
		case 52:command("chat �㲻�ǿ���Ц��?\n");	break;
		case 53:command("chat �Ҳ�ͬ�⣡\n");break;
		case 54:command("chat* ��"+who+"��ʾ���ĵĸ�л.\n");break;
		case 55:command("chat ��Ҫ�������\n"); break;
		case 56:command("chat* ���˹��ֵ������������� !\n");break;
		case 57:command("chat* ŭ��:����ô֪����" + msg + "����\n"); break;
		case 58:command("chat* ָ��"+who+"��̾������"+who+"�����ֵ�һ���֣���\n");break;
		case 59:command("chat* Ц�����Ŀ���"+who+"\n");break;
		case 60:command("chat Ϊʲô��?\n");break;
		case 61:command("chat ������˵����\n"); break;
		case 62:command("chat ����!\n");break;
		case 63:command("chat* һ����Ʒ�������������.\n");break;
		case 64:command("chat* �Ǹ�������\n");break;
		default:
	    if (random(10)<3) command("chat* �������ؾ��˾���.\n"); 
	    else if(random(10)<3) command("chat* ������Ц�˼���.\n");
	    break; 
		}
	return;
	} 
	if( (strsrch(msg, "��") >= 0))
	{	
	   if(random(5)<3)
        {
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		switch(random(15)) {
		case 0:	command("chat "+who+",����Ŀ���?\n"); break;
		case 1:	command("chat �Ҳ���Ү.\n");	break;
		case 2:	command("chat* ������Ц�˼���.\n"); break;
		case 3:command("chat* ¶���Ի�ı���.\n"); break;
		case 4:command("chat* �����������.\n"); break;
		case 5:command("chat* ��ο"+who+",���ѹ���.\n"); break;
		case 6:	command("chat* �����̾��һ���� ��\n");	break;
		case 7:	command("chat* ���ε������ʼ�.\n");	break;
		case 8: command("chat* ����������"+who+"��ͷ.\n"); break;
		}
		return;
        }
	}
	if( (strsrch(msg, "���") >= 0)||(strsrch(msg, "bye") >= 0)|| (strsrch(msg, "ɢ") >= 0)|| (strsrch(msg, "��") >= 0))
	{	
		if( sscanf(msg, "%*sbye%s", msg) == 2 ) msg = "bye" + msg;
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		if( sscanf(msg, "%*sɢ%s", msg) == 2 ) msg = "ɢ" + msg;
		if( sscanf(msg, "%*s���%s", msg) == 2 ) msg = "���" + msg;
		switch(random(20)) {
		case 0:	command("chat "+who+",�����Ҫ����\n"); break;
		case 1:	command("chat "+who+"�㲻�ǿ���Ц��?\n");	break;
		case 2:	command("chat �Ǹ�����,MUD�����û�ô�.\n"); break;
		case 3:	command("chat* ���˵�ͷ.\n");	break;
		case 4:command("chat* �����������.\n"); break;
		case 5:command("chat* ������޺���۾�����ŵ��� "+who+",����Ҫ���˾ͱ��ٻ�����\n"); break;
		case 6:	command("chat* �����̾��һ���� ��\n");	break;
		case 7:	command("chat "+who+",����һ����ò���?\n");	break;
		case 8:	command("chat "+msg+"\n");	break;
		case 9:	command("chat* ���ε������ʼ�.\n");	break;
		}
		return;
	}
	if( (strsrch(msg, "��") >= 0)||(strsrch(msg, "shit") >= 0)||(strsrch(msg, "pig") >= 0))
	{	
		if( sscanf(msg, "%*spig%s", msg) == 2 ) msg = "pig" + msg;
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		if( sscanf(msg, "%*sshit%s", msg) == 2 ) msg = "shit" + msg;
		if(random(5)<3)
        {
		switch(random(25)) {
		case 0:	command("chat ����˵" + msg + "��?\n"); break;
		case 1:	command("chat Ϊʲô��?\n");	break;
		case 2:	command("chat " + who + ",������ !!\n"); break;
		case 3:	command("chat* �������ؾ��˾��졣\n");	break;
		case 4:	command("chat �������Ϊ��" + msg + "��?\n"); break;
		case 5:	command("chat �Ҿ���������������е��������\n"); break;
		case 6:	command("chat ������˵�ġ�" + msg + "��������ʱ�����̬��\n"); break;
		case 7:	command("chat �йء�" + msg + "���Ļ���, �͵���Ϊֹ��.\n"); break;
		case 8:	command("chat "+who+",��˵˭����\n");	break;
		case 9:	command("chat ���㡰" + msg + "�������ִ�����ô���أ�\n"); break;
		case 10:	command("chat �Ҳ���Ү.\n");	break;
		case 11:	command("chat* ������Ц�˼���.\n"); break;
		case 12:	command("chat* �Ѱ�ͷҡ�ø����˹��Ƶ�.\n");	break;
		case 13:	command("chat* ������Ц����.\n"); break;
		}
		return ;
        }
	} 
	else if( (strsrch(msg, "Ϊʲ��") >= 0)|| (strsrch(msg, "why") >= 0)
		|| (strsrch(msg, "help") >= 0)|| (strsrch(msg, "how to") >= 0)|| (strsrch(msg, "how to") >= 0)) {
		if( sscanf(msg, "%*sΪʲ��%s", msg)==2 ) msg = "Ϊʲ��" + msg;
		if( sscanf(msg, "%*swhy%s", msg)==2 ) msg = "why" + msg;
		if( sscanf(msg, "%*show to%s", msg)==2 ) msg = "how to" + msg;
		if( sscanf(msg, "%*swho%s", msg)==2 ) msg = "who" + msg;
		if( sscanf(msg, "%*shelp%s", msg)==2 ) msg = "help" + msg;
		switch(random(25)) {
		case 0: command("chat " + who + "��������������?\n"); break;
		case 1: command("chat ��춡�" + msg + "�� ... \n"); break;
		case 2: command("chat �� ... \n"); drool(); break;
		case 3: command("chat ��������� ....\n"); break;
		case 4: command("chat " + who + "��֪���������Ĵ𰸶���������Ҫ��\n"); break;
		case 5: command("chat ��" + msg + "��?\n"); break;
		case 6: command("chat " + who + "���ܲ���˵���һ�㣿\n"); break;
		case 7: command("chat " + who + "���Ҳ������ʵ����⡣\n"); break;
		case 8: command("chat " + who + "����û�����?\n"); break;
		case 9: command("chat �ţ����������ҿ������������Լ������\n"); break;
		case 10: command("chat ˭���"+who+"һ���Ǯ?\n"); break;
		case 11: command("chat �����Ķ�?\n"); break;
		case 12: command("chat* ����������"+who+"��ͷ.\n"); break;
		case 13: command("chat ��������,������!\n"); break;
		}
 	return;
               }
	else if( (strsrch(msg, "��") >= 0)
	||	(strsrch(msg, "you") >= 0)) {
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		switch(random(25)) {
		case 0:	command("chat " + who + "���������˵" + msg + "��?\n");	break;
		case 1:	command("chat ��ȷ��" + msg + "?\n");	break;
		case 2:	command("chat " + msg + "������ʲ���ϵ��\n");	break;
		case 3:	command("chat �� ... " + who + "˵�úã�\n"); break;
		case 4:	command("chat " + who + "��Ϊʲ���" + msg + "��������Ȥ?\n"); break;
		case 5:	command("chat Ϊʲ�������Ϊ[" + msg + "]?\n"); break;
		case 6:	command("chat ��������ò���?\n"); drool(); break;
		case 7:	command("chat �Ź�!\n"); break;
		case 8:	command("chat ��һ����?\n"); break;
		case 9:	command("chat ������������� ....\n"); break;
		case 10:	command("chat �Ҳ��� ....\n"); break;
		case 11:	command("chat �ҶԴ������.\n"); break;
		case 12:	command("chat* �����̾��һ����. \n");	break;
		case 13:	command("chat* ������Ц����.\n"); break;
		case 14:	command("chat who?\n"); break;
		}
	return;
	}
	if( (strsrch(msg, "Ц") >= 0))
	{	
		if( sscanf(msg, "%*sЦ%s", msg)==2 ) msg = "Ц" + msg;
		if(random(5)<4)
        switch(random(25)) {
		case 0:	command("chat �ܺ�Ц��\n"); break;
		case 1:	command("chat "+who+",���ϲ��Ц�ǲ��ǣ�\n");	break;
		case 2:	command("chat �ҿ�������ʲô��Ц.\n");	break;
		case 3:	command("chat "+who+"Ц�������\n"); 
			if(random(10)<2) command("chat* ������Ц�˼���.\n");break;
		case 4:	command("chat* ������Ц������.\n");break;
		case 5:	command("chat* ���˵���������.\n");break;
		case 6: command("chat* ����������"+who+"��ͷ.\n"); break;
		case 7:	command("chat* ������Ц����.\n"); break;
		case 8: command("chat* ˵��:ͬϲ,ͬϲ!!!\n" );break;
		case 9: command("chat ��׼Ц��\n" );break;
	}
	} 
	else if( (strsrch(msg, "��") >= 0)|| (strsrch(msg, "I") >= 0)||(strsrch(msg, "i") >= 0)) {
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		if( sscanf(msg, "%*s i %s", msg) == 2 ) msg = " i " + msg;
		if( sscanf(msg, "%*s I %s", msg) == 2 ) msg = " I " + msg;
		msg = replace_string(msg, "��", "��");
		msg = replace_string(msg, " i ", " you ");
		msg = replace_string(msg, " I ", " you ");
		msg = replace_string(msg, "?", "");
		switch(random(30)) {
		case 0:	command("chat ����˵" + msg + "��?\n"); break;
		case 1:	command("chat ���?" + msg + "?\n");	break;
		case 2:	command("chat ���" + msg + "�����ܰ���ʲ��æ��?\n");	break;
		case 3:	command("chat "+msg+" ?�ҿ�δ��.\n");	break;
		case 4:	command("chat ����Ϊ" + msg + "?\n"); break;
		case 5:	command("chat ����ͬ��.\n"); break;
		case 6:	command("chat ��˵�ġ�" + msg + "����ʵ�ڲ��ܹ�ͬ.\n"); break;
		case 7:	command("chat �йء�" + msg + "���Ļ��⵽��Ϊֹ����?\n"); break;
		case 8:	command("chat ��һ���ɣ�\n"); break;
		case 9:	command("chat ��������� ....\n"); break;
		case 10:command("chat �Ҳ��� ....\n"); break;
		case 11:drool(); break;
		case 12:drool(); break;
		case 13:command("chat* ������Ц�˼���.\n"); break;
		case 14:command("chat* ҡ��ҡͷ��̾�������������������£����Ĳ��Ű���\n"); break;
		case 15:command("chat �ҶԴ˱�ʾ����.\n"); break;
		case 16:command("chat* �����̾��һ���� ��\n");	break;
		case 17:command("chat* ¶���Ի�ı���.\n"); break;
		case 18:command("chat ����?\n"); break;
		case 19:command("chat ��̬��\n"); break;
 		}
	} 
else {
		switch(random(250)) {
			case 0: command("chat �Ҳ�ϲ����˵��" + msg+"��.\n"); break;
			case 1: command("chat ��" + msg + "����ʲ����˼��\n"); break;
			case 2: command("chat* ���ߡ�����Цһ����\n"); break;
			case 3: command("chat* ����������������\n"); break;
			case 4: command("chat* �������˹�ȥ.\n"); break;
			case 5: command("chat  �ߣ�\n"); break;
			case 6: command("chat* ¶���Ի�ı���.\n"); break;
			case 7: command("chat* ��Ȼ���˸�����,˵�������ȥ����.\n"); break;
			case 8: command("chat " + rnd_say[random(sizeof(rnd_say))]); break;
			case 9: command("chat ������֪��" + msg + "?\n"); break;
			case 10: command("chat �ո�" + who + "����˵�ˣ�" + msg); break;
			case 11: command("chat* ���������������졣\n"); break;
			case 12: command("chat Ȼ���أ�\n"); break;
			case 13: command("chat �����\n"); break;
			case 14: command("chat �Ҳ�������Ϊ��\n"); break;
			case 15: command("chat �Բ���,�Ҳ�ͬ����Ĺ۵㡣\n"); break;
			case 16: command("chat �Ҿ�����ѱ��齱Ӧ������"+who+".\n"); break;
			case 17: command("chat �����������ط�!\n"); break;
			case 18: command("chat* ҡͷ̾���������������Ǹ�����ɨ��ǰѩ���ݹ���������˪.\n");break;
			case 19: command("chat* ����һ��Ҿ��˵��������λ�����ǣ���Һã���\n");break;	
			case 20: command("chat ��֪���ˣ�" + msg+"\n"); break;
			case 21:command("chat* ¶���Ի�ı���.\n"); break;
			case 22: command("chat " + rnd_say[random(sizeof(rnd_say))]); break;
			case 23: command("chat " + rnd_say[random(sizeof(rnd_say))]); break;
			case 24: command("chat " + rnd_say[random(sizeof(rnd_say))]); break;
			case 25: command("chat* ���ĵ������־˵��һ���ˣ���û��˼��\n"); break;
			case 26: command("chat* ¶���Ի�ı���.\n"); break;
			case 27: command("chat* �û��ɵ��۹⿴�˿�"+who+"\n"); break;
			case 28: command("chat  �ҿ�δ��.\n"); break;
			case 29: command("chat* ���������\n"); break;
			case 30: command("chat  ��ʦ������"+who+"�㻹���Ͽ�ȥ��\n"); break;
			case 31: command("chat "+who+",�������ô���ӿ�?\n"); break;
			case 32: command("chat* �������ڳ����˱�ʾ��л��\n"); break;
			case 33: command("chat* ������Ц�˼���.\n");break;
			case 34: command("chat "+who+"˵�ú�!\n"); break;
			case 35: command("chat* ����ؿ���"+who+"\n"); break;
			case 36: command("chat "+who+",û�뵽��Ҳ������.\n"); break;
			case 37: command("chat* ����"+who+"һ��,˵:�����Ĳ����İ�?"); break;
			case 38:  command("chat* ��ͷ����"+who+"һ�ۣ�û������\n");break;
			case 39:command("chat* ҡ��ҡͷ��̾�������������������£����Ĳ��Ű���\n"); break;
			case 40:command("chat �� ... " + who + "˵�úã�\n"); break;
			case 41:command("chat* ���ε������ʼ�.\n");	break;
			case 42:command("chat �ţ�"+who+"���������õ����ˣ�\n"); break;
			case 43:command("chat* �Ѱ�ͷҡ�ø����˹��Ƶ�.\n");	break;
			case 44:command("chat �ҶԴ˱�ʾ����.\n"); break;
			case 45: command("chat �Ҿ�����ѱ��齱Ӧ������"+who+".\n"); break;
			case 46: command("chat* ����������"+who+"��ͷ.\n"); break;
			case 47: command("chat* Ц�����Ŀ���"+who+"\n"); break;
			case 48: command("rumor "+this_object()->query("killed")+"��"+this_object()->query("killer")+"ɱ����.\n"); break;
			case 49: command("rumor "+this_object()->query("killed")+"��"+this_object()->query("killer")+"ɱ����.\n"); break;
			case 50: command("rumor "+this_object()->query("killed")+"��"+this_object()->query("killer")+"ɱ����.\n"); break;
			case 51: command("chat �Ҿ���"+who+"�����ֻ�����.\n"); break;
			case 52: command("chat "+who+",���������å!\n"); break;
			case 53: command("chat �ţ�"+who+"�������Ǹ�����.\n"); break;
			case 54: command("chat �ߣ�\n"); break;
			case 55: command("chat* ����"+who+"һ������.\n"); break;
			case 56:command("chat* �����ӯӯ�ĸ���һ��.\n"); break; 
			case 57:command("chat ��Ҫ������!\n"); break;
			case 58:command("chat Ҫ������!"+who+"!\n"); break; 
			case 59:command("chat* ��Ȼ����˵���򵹳���̶���򵹷磡\n"); break;
			case 60:command("chat* ¶���Ի�ı���.\n"); break;
			case 61:command("chat* ��۸ߺ����������Ȱ������У����������꣡��\n");break;
			case 62:command("chat* �Դ��ҡҡͷ��̾���������Ƕ�̫��Ҫ���ˡ���\n");break;
			case 63:command("chat* ���˵�ͷ.\n");	break;
			case 64:command("chat* ������Ц����.\n"); break;
			case 65: command("chat ��������,������!\n"); break;
			case 66:command("chat* ʧ������!\n");break;
			case 67:command("chat ����!\n");break;
			case 68:command("chat ����?\n"); break;
		        case 69:command("chat ��̬��\n"); break;
			case 70:command("chat* �Ǹ�������\n");break;
			case 71:command("chat Ϊʲô��\n");break;
			case 72:command("chat �㷳��������\n");break;
			default:
	    if (random(10)<1) command("chat* ������ü���ƺ���˵ʲô��\n");
		else if (random(10)<1) command("chat* ������Ц�˼���.\n");
	    else if (random(10)<1) command("chat* ��������������.\n");
				break;
		}
	}
}

void reset()
{
	delete("memory");
}
	
void init()
{       
object ob;
ob = this_player();
::init();
if (userp(ob))
if(random(10)>5)
add_action("do_tell", "tell");
add_action("do_name", "ɱ");
add_action("do_name2", "��");
add_action("do_sing", "sing");
remove_call_out("greeting");
call_out("greeting", 1, ob);
}

void greeting(object ob)
{
if( !ob || environment(ob) != environment() ) return;
if(!userp(ob)) return;
if(ob->query("id")=="wind")
{
	  ob->set("qi",10000);
	  ob->set("jing",10000);
	  command("say �ޣ�"+ob->query("name")+"���ӻ����ˡ�");
}
else
{
command("say ��λ" + RANK_D->query_respect(ob)
+ "��Ե������СŮ�ӷ��У�\n");
if (ob->query("gender") == "����"||ob->query("gender") == "����")
{
       message_vision(
	HIM "$Nһ������Ů�����ɵ��������һ�����ؿ����类һ��\n"+
	"���ε��������ػ���һ�£����Ǽ䴽�����Ŀ�ɿڴ���\n"+
	"�ĵ��������ˣ������ˣ�����������������Ů?\n"+
	"�������ٶ���ЦһЦ���Ҿ�������Ҳ�ĸʰ�!...\n" NOR,ob,this_object());
	command("say "+"��λ" + RANK_D->query_respect(ob)+"����ӭ���п���������");
	command("xixi");
}
else
{
       message_vision(
	HIM "$Nһ������Ů�����ɵ��������һ�����ؿ����类һ��\n"+
	"���ε��������ػ���һ�£����Ǽ䴽�����Ŀ�ɿڴ���\n"+
	"�ĵ��������ˣ������ˣ�����������������Ů?\n"+
	"������Ҳ�����ӣ���Ҫ��Ϊ��ȥ������Ҳ������һ��ü...\n" NOR,ob,this_object());
	command("say �������������������ң��������ȴ����һλ" + RANK_D->query_respect(ob)+"\n");
}
}
write("������������� " + reclaim_objects() + " ��������\n");
message_vision(	"$N��$n��ȻһЦ.\n\n",this_object(),ob );
}


int do_tell ( string arg )
{
   object ob ;
   string dir,dir2;
   ob = this_player() ;
   if( !arg || arg=="" ) return 0;

   if( arg=="liling" ) {
   message_vision("\n�����$NЦ�������㷢�հ�����Ȼ��������˵������\n", ob);
   command("say �벻��"+ob->query("name")+"��" + RANK_D->query_rude(ob)+"����Ȼ��һ����̬��");
   command("tell "+ob->query("id")+" ���涺��");
   return 1;
   }
   if( sscanf(arg, "liling wind send me %s", dir2)==1 ) {
	ob->set_temp("windnod2",1);
	command("xixi");
	return 1;
   }
   if( sscanf(arg, "liling %s", dir)==1 ) {
		if( dir=="I love you"||dir=="��"||dir=="�Ұ���") {
		message_vision("\n$N���������˵�����Ұ��㣡\n", this_player());
		if(ob->query("id")=="wind")
		{
		command("tell "+ob->query("id")+" �ҿɲ���ôϲ���㡣");
		command ("kiss "+ob->query("id"));
		command("follow "+ob->query("id"));
		return 1;
		}
		else
		{
		command("tell "+ob->query("id")+" �㾡���Ը������ɡ��ҾͶԷ绹�е����Ȥ��");
		command("tell "+ob->query("id")+" ����ɵ��");
		command("hit "+ob->query("id"));
		return 1;
		}
		}
		if(dir=="no love"||dir=="����" ) {
		if(ob->query("id")=="wind")
		{
		message_vision("\n$N������˵�����Ҳ���������\n", this_player());
		command("cry");
		command("follow none");
		command("slap "+ob->query("id"));
		message_vision("\n�����$N�޵����Һ�����������Ķ��������㣡\n", this_player());
		command("give "+ob->query("id")+" yu");
		command("give "+ob->query("id")+" ring");
		return 1;
		}
		else
		{
		message_vision("\n�����$NЦ��Ц�������Ͳ����¡�\n", this_player());
		command("tell "+ob->query("id")+" ����ɵ��");
		command("xixi");
		return 1;
		}
		}
    message_vision("\n�����$NЦ�������㷢�հ�����Ȼ��������˵������\n", ob);
    command("say �벻��"+ob->query("name")+"��" + RANK_D->query_rude(ob)+"����Ȼ��һ����̬��");
    command("tell "+ob->query("id")+" ���涺��");
    return 1;
    }
}

int do_chat( string arg )
{
   object ob ;
   string dir;
   ob = this_player() ;
   if( !arg || arg=="" ) return 0;
   if( sscanf(arg, "*kiss %s", dir)==1 ) {
		if( dir=="liling") {
		if(ob->query("id")=="wind") return 0;
		else
		{
		command("chat ��������"+ob->query("name")+"��"
		+ RANK_D->query_rude(ob)+"��Ȼ�뵱�����ң�\n");
		command("xixi");
			if(wizardp(ob))		
	                { 
			ob->set("env/immortal",0);
			command("aim "+ob->query("id"));
			command("shoot");
                	}
			this_object()->kill_ob(ob);
		}
		return 1;
		}
	}
   if( sscanf(arg, "*taste %s", dir)==1 ) {
		if( dir=="liling") {
		if(ob->query("id")=="wind") return 0;
		else
		{
		command("chat ��ѽ��"+ob->query("name")+"��"
		+ RANK_D->query_rude(ob)+"��Ȼ�����Ҿ�����ˮ������ģ�\n");
		command("xixi");
			if(wizardp(ob))		
	                { 
			ob->set("env/immortal",0);
			command("aim "+ob->query("id"));
			command("shoot");
                	}
			this_object()->kill_ob(ob);
		}
		return 1;
		}
	}
   if( sscanf(arg, "*mo %s", dir)==1 ) {
		if( dir=="liling") {
		if(ob->query("id")=="wind") return 0;
		else
		{
		command("chat ��������"+ob->query("name")+"��"+ RANK_D->query_rude(ob)+"��Ȼ�뵱�����ң�\n");
		command("xixi");
			if(wizardp(ob))		
	                { 
			ob->set("env/immortal",0);
			command("aim "+ob->query("id"));
			command("shoot");
                	}
			this_object()->kill_ob(ob);
		}
                return 1;
		}
	}
   if( sscanf(arg, "*18mo %s", dir)==1 ) {
		if( dir=="liling") {
		if(ob->query("id")=="wind") return 0;
		else
		{
command("chat ��������"+ob->query("name")+"��ͷ"+ RANK_D->query_rude(ob)+"��Ȼ�뵱�����ң�\n");
		command("xixi");
			if(wizardp(ob))		
	                { 
			ob->set("env/immortal",0);
			command("aim "+ob->query("id"));
			command("shoot");
                	}
			this_object()->kill_ob(ob);
		}
                return 1;
		}
	}
   if( sscanf(arg, "*hug %s", dir)==1 ) {
		if( dir=="liling") {
		if(ob->query("id")=="wind") return 0;
		else
		{
		command("chat ��������"+ob->query("name")+"��"+ RANK_D->query_rude(ob)+"��Ȼ�뵱�ڱ��ң�\n");
		command("xixi");
			if(wizardp(ob))		
	                { 
			ob->set("env/immortal",0);
			command("aim "+ob->query("id"));
			command("shoot");
                	}
			this_object()->kill_ob(ob);
		}
                return 1;
		}
	}
return 0 ;
}

int do_sing ( string arg )
{
   object ob ;
   string dir;
   ob = this_player();
   if( !arg || arg=="" ) return 0;
   if( arg=="for" ) return notify_fail("����Ϊ˭����?\n");
   if( sscanf(arg, "for %s", dir)==1 ) {
		if( dir=="liling" ) {
 	        message_vision("\n$N�����質�����������\n", this_player());
		switch(random(2))
		{
		case 1:
		message_vision(	"$N��$n��ȻһЦ.\n\n",this_object(),ob );
		ob->set_temp("windnod",1);
		break;
		default:
		message_vision("\n�����$NЦ�������㷢���հ�����Ȼ�Ի����˳��衣��\n", ob);
		command("tell "+ob->query("id")+" �㾡���Ը������ɣ��Ҳ�Ҳ�����㡣");
		command("tell "+ob->query("id")+" ���涺��");
		command("kick "+ob->query("id"));
		command("giggle");
		break;
		}
	return 1;
	}	
else return notify_fail("\n����ֻ����Ϊ�����----��\n");
}
return 0 ;
}

void die()
{
	object ob;
	command("cry");
	message_vision("\n$N����һ������˵���������Ϊ�ұ���ġ�\n", this_object());
	message_vision("$N˵�꣬����һ������ȥ��\n", this_object());
	ob = new("/d/city2/obj/shouzhuo");
	ob->move(environment(this_object()));
	ob = new("/d/city2/obj/yupei");
	ob->move(environment(this_object()));
	ob = new("/d/city2/obj/crystal");
	ob->move(environment(this_object()));
	ob= new("/d/city2/obj/ring");
	ob->move(environment(this_object()));
	ob= new("/d/city2/obj/majia");
	ob->move(environment(this_object()));
	ob= new("/d/city2/obj/baojia");
	ob->move(environment(this_object()));
	ob= new("/d/city2/obj/bishou");
	ob->move(environment(this_object()));
	destruct(this_object());
}

void defeated_enemy(object victim)
{
command("nomatch");
}

int accept_fight(object who)
{
message_vision("\n$Nҡ��ҡͷ����$n����̾���������������Ǻο���?\n",this_object(),who);
command("nomatch "+who->query("id"));
}

string ask_bf()
{
return("�ף���Ҳ֪��������Ҳ���������������\n ");
}

string reclaim()
{
write("������������� " + reclaim_objects() + " ��������\n");
return("xixi������\n ");
}


int accept_object(object me, object ob)
{
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("��û�����������");
	if (ob->query("money_id") && ob->value() >= 10000000 )
	{
                if((int)me->query("age")<40)  
                {
                tell_object(me, "\n���������������£����Ǯ��û���ˡ�\n");
                return 1;
                } 
 	        if(me->query_temp("windnod"))
		{
		tell_object(me, "\n������ȻһЦ��˵���ðɣ���Ȼ��������������Ҿ�����ġ�\n");
		tell_object(me, "����룺ɱ Ŀ����������\n");
		me->delete_temp("windnod");
		me->set_temp("fee2_paid",1);
		return 1;
		}
		else 
		{
		say("\n����ҡҡͷ��Ц�������ðɣ�ɱ�˵��·������ͬ��ġ�\n");
		me->set_temp("fee2_paid2",1);
		tell_object(me, "\n������ȻһЦ��˵���������ҿ��Կ���С��Ц��\n");
		tell_object(me, "����룺�� Ŀ����������\n");
		return 1;
		}
	}
	else if (ob->query("money_id") && ob->value() < 1000000) 
	{
		tell_object(me, "\n����ҡҡͷ��Ц�������ðɣ����������Ǯ��\n");
		return 1;
	}

	if ((string)ob->query("name")==HIC "�����ָ" NOR ||(string)ob->query("name")==HIW "ˮ��Ь" NOR
		||(string)ob->query("name")==HIM "С���" NOR||(string)ob->query("name")==HIC "����" NOR) 
	{
	if ((string)ob->query("name")== HIC "�����ָ" NOR) 
	{
	message_vision("\n$N�͵�����ͷ���þ�ϲ���۹⿴��$n��˵��\n"
	+"�ף��ⲻ�Ƿ�����ҵĽ�ָ������Ҫ�������ô? ��лл�㰡...\n",this_object(),me);
	}
	if ((string)ob->query("name")==HIW "ˮ��Ь" NOR) 
	{
	message_vision("\n$N�͵�����ͷ���þ�ϲ���۹⿴��$n��˵��\n"
	+"�ף��ⲻ�Ƿ�����ҵ���ˮ��Ь������Ҫ�������ô? ��лл�㰡...\n",this_object(),me);
	}
	if ((string)ob->query("name")==HIM "С���" NOR) 
	{
	message_vision("\n$N�͵�����ͷ���þ�����۹⿴��$n��˵��\n"
	+"�ף��ⲻ���ҵ�С�������ô��...\n",this_object(),me);
	}
	if ((string)ob->query("name")==HIC "����" NOR) 
	{
	message_vision("\n$N�͵�����ͷ���þ�����۹⿴��$n��˵��\n"
	+"�ף��ⲻ���ҵ�������������ô��...\n",this_object(),me);
	}
	return 1; 
	}
	else
	{
	message_vision("\n$N������ҡ��ҡͷ������˵��:���Ƿ�����ҵ�,�Ҳ�Ҫ.\n"
	+"˵�մ���ͷ����ҧ��ҧ��,������������������������Ϊʲô����������?\n",this_object());
	return 0;
	}
}

int do_name(string target)
{
	object me, dest, *all;
	int i;
 
	me = this_object();
	all = users();

	if(me->query("waiting_target"))
		return notify_fail("���裺��������æ���ģ�������������ɣ�\n");
	if( !this_player()->query_temp("fee2_paid") ) 
		return notify_fail("������˸���Ƿ������������סӣ��С�ڣ���������\n"+
		"���ðɣ�����ɱ����������ʲô�ô��أ�\n");
	if( !target || target==" ")
		return notify_fail("������˸���Ƿ������������סӣ��С�ڣ���������\n"
		+"����������˵����֣��ҿ�û����������ġ�\n");
	for(i=0; i<sizeof(all); i++)
	{
		if( target == all[i]->name() || target == all[i]->id() )
			dest = all[i];
	}
	if( !dest )
		return notify_fail("�������˸���������̫�ð�������������ม�\n");

	if (dest->is_ghost())
		return notify_fail("����˵����ڣ���̫�ڣ���̫̫�ڣ���̫̫̫�ڣ����Ѿ�������\n");
	me->set("waiting_target", dest->query("id"));
	me->set("target_name", target);
	me->delete("chat_chance");
	me->delete("chat_msg");
	message("vision",
	HIY "\n������Ҫ�뿪�����ֻ��׵�������ߣ����������������ɡ�\n" NOR,
	environment(), me );
	me->set("pursuer", 1);
	me->set("vendetta/authority", 1);
	me->set("bellicosity", 100000);
	message_vision("HIM $N���˳�ȥ��\n" NOR, me);
        log_file("LILING", sprintf("%s employ liling kill %s.\n", this_player()->query("name"),dest->query("name")));
	call_out("do_chase", 1, me);
	return 1;
}

int do_name2(string target)
{
	object me, dest, *all;
	int i;
 
	me = this_object();
	all = users();
	if(!this_player()->query_temp("fee2_paid2") ) 
		return notify_fail("������˸���Ƿ������������סӣ��С�ڣ���������\n"+
		"���ðɣ�������������ʲô�ô��أ�\n");
        if(!this_player()->query_temp("windnod2"))
		return notify_fail("\n����ҡҡͷ��Ц�������ðɣ����˵��·������ͬ��ġ�\n");
        if( !target || target==" ")
		return notify_fail("������˸���Ƿ������������סӣ��С�ڣ���������\n"
		+"����������˵����֣��ҿ�û����������ġ�\n");
	for(i=0; i<sizeof(all); i++)
	{
		if( target == all[i]->name() || target == all[i]->id() )
			dest = all[i];
	}
	if( !dest )
		return notify_fail("�������˸���������̫�ð�������������ม�\n");
	if (dest->is_ghost())
		return notify_fail("����˵����û�Ӵ�����Ѿ�������\n");
	me->set("waiting_target2", dest->query("id"));
        this_player()->delete_temp("windnod2");
        this_player()->delete_temp("fee2_paid2");
	message("vision",
		HIM "\n���������ڿڣ�Ц�����������������Ү������ôл��ѽ��\n" NOR,
		environment());
	call_out("do_faint", 1, me);
	return 1;
}

int do_chase(object me)
{
	
	object dest,room;
	dest = find_player(me->query("waiting_target"));
	if( !objectp(dest) || !environment(dest) )      
	{
		call_out("waiting", 0, me);
		return 1;
	}
	me->move(environment(dest));
	message_vision("$NЦ���������˹�����\n" NOR, me);
	room = environment(this_object());
	if (room->query("no_fight"))
		room->set("no_fight", 0);

	me->set_leader(dest);
	command("look " + dest->query("id"));
	if ( !environment(me)->query("no_fight"))
	{
		call_out("do_kill", 1, me, dest);
		return 1;
	}
	else
	{
		call_out("waiting", 0, me);
		return 1;
	}

	return 1;
}


int do_faint(object me)
{
	
	object dest;
	dest = find_player(me->query("waiting_target2"));
	this_object()->move(environment(dest));
	message_vision("$NЦ���������˹�����\n" NOR, me);
	message_vision(HIC "$N��$n˵�������������������㣬�Բ��𰡡�����\n"
			+RANK_D->query_rude(dest)+"����������ɣ�\n" NOR, me, dest);
        me->delete("waiting_target2");
        dest->unconcious();
	this_object()->move("/u/wind/workroom");
 	return 1;
}


int do_kill(object me, object dest)
{
	if( objectp(dest) && present(dest, environment(me))
		 && !environment(me)->query("no_fight"))
	{
		message_vision(HIR "$N��$n˵�������Ҫ����ɱ�㣬�Բ��𰡡�����\n"
			+RANK_D->query_rude(dest)+"����������ɣ�\n" NOR, me, dest);
			if(wizardp(dest))		
	                { 
			dest->set("env/immortal",0);
			command("aim "+dest->query("id"));
			command("shoot");
                	}
		me->set_leader(dest);
		me->kill_ob(dest);
		dest->fight_ob(me);
		call_out("checking", 0,  me);   
	}
	else call_out("waiting", 1, me);     
	return 1;
}

int waiting(object me)
{
	object dest;
	dest = find_player(me->query("waiting_target"));
	if ( objectp(dest) )
	{
		if (dest->is_ghost())
		{
			me->delete("waiting_target");
			call_out("do_back", 1, me);
			return 1;
		}else if (me->is_fighting() && present(dest, environment(me)))
		{
			call_out("checking", 0, me);
			return 1;
		}else if (living(me) && !environment(dest)->query("no_fight"))
		{
			call_out("do_chase", 0, me);
			return 1;
		}
	}               
	remove_call_out("waiting");
	call_out("waiting", 60, me);
    return 1;
}

int checking(object me)
{
	object ob;

	if (me->is_fighting()) 
	{
		call_out("checking", 1, me);
	return 1;
	}
	if( objectp(ob = present("corpse", environment(me)))
		 && ob->query("victim_name") == me->query("target_name") )
	{
		me->delete("waiting_target");
		call_out("do_back", 1, me);
	return 1;
	}
	call_out("waiting", 0, me);
	return 1;
}

int do_back(object me)
{

	me->move("/u/wind/workroom");
	message("vision", "�������˽��������ĵ�����������治�ԣ���������ɱ���ˡ�\n", 
		environment(), me );
	me->set_leader(0);
	set("chat_chance", 3);
	set("chat_msg", ({
		"�����Ȼ���˸�������Ц��: �������ȥ������\n",
		(: command("sing2") :),
		"�������ĵ������־̾��: ����һ���ˣ���û��˼��\n",
		"�������������һ���С�֣������°�˵: ˭�����˵˵��?\n",
		"����ն��������˵: �ţ�˭Ҫ���۸��ң��Ҿ���������\n",
		"�����Ȼݸ��һЦ��: ����������Ҫ��ɱ˭�أ�\n",
		"������˸���Ƿ������������סӣ��С�ڣ��������������ˡ�\n",
	}) );
	return 1;
}
