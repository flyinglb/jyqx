// kurong.c
// modified by wind

inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
int ask_me();
string ask_six();
string ask_join();
int accept_fight(object ob);
int checking(object me, object ob);
string* names = ({
	"ben yin",
	"ben can",
	"ben chen",
	"ben guan",
	"ben xiang",
	"ku rong",
});
void create()
{
        set_name("���ٴ�ʦ", ({ "ku rong","kurong", "ku", "rong"}) );
	set("gender", "����" );
	set("title", "�����µ�ʮ����ɮ��");
	set("class", "bonze");
	set("long", 
"������������֮������ߵ�һ����ɫ����Ƥ���⻬������Ӥ����
�ұߵ�һ��ȴ��ݹǣ�����һ�Ž��Ƶ���Ƥ֮��ȫ�޼��⣬��ͷͻ
�˳�������Ȼ���ǰ�����ù�ͷ����������ϰ�����������¡�\n");
	set("age", 100);
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 50);
	set("combat_exp", 1000000);
	set("score", 1000000);
	set("book_count", 1);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("finger", 200);
	set_skill("sword", 200);
	set_skill("tiannan-step", 200);
	set_skill("kurong-changong", 200);
	set_skill("duanjia-sword", 200);
	set_skill("six-finger", 200);
	set_skill("buddhism", 200);
	set_skill("literate", 120);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "six-finger");
	map_skill("finger", "six-finger");
	map_skill("sword", "duanjia-sword");
	prepare_skill("finger","six-finger");

	set("inquiry" ,([
	"���"	: (: ask_join :),
	"����"	: (: ask_join :),
	"��������" : (: ask_six :),
	"��������" : (: ask_six :),
	"������" : (: ask_me :),
	"��������" : (: ask_me :),
	"�����񽣽���" : (: ask_me :),
	]));
	create_family("����μ�",16,"��ɮ");

	setup();
	carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}

void init()
{
	add_action("do_kneel", "kneel");
}

int ask_me()
{
        if ((int)this_player()->query_temp("marks/find_temp")&&this_player()->query_temp("marks/ask_temp3")) 
		{
        	say(
"���ٿ���" + this_player()->name() + "һ�ۣ�˵����\n"
"��λʩ����Ȼ������ʩ������ʤ�����ľͿɵõ��������ס�\n");
       		return 1;
        }
}

int accept_fight(object ob)
{
        object me;

        me = this_object();
      
        if( ob->query_temp("marks/find_temp")&&ob->query_temp("marks/ask_temp3") ) {
           say(ob->name() + "�Կ���˵���ðɣ���" 
             "�Ҿ�ͬ���д꼸�аɣ��㵽Ϊֹ��\n");
	  remove_call_out("checking");
          call_out("checking", 1, me, ob);
          return 1;
        }
        else
    	  return 0;
}

int checking(object me, object ob)
{

        object obj;
        int my_max_qi, his_max_qi;
        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");

        if (me->is_fighting()) 
        {
                call_out("checking",2, me, ob);
                return 1;
        }

        if ( !present(ob, environment()) ) return 1; 

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
        {
                if( ((time()-(int)ob->query_temp("sun_book_last_get_time")) < 6*3600)
                && ((int)ob->query_temp("sun_book_last_get_time") != 0 )){

                        say("����˵��ʩ�����ֹ�Ȼ���������������\n");
                        return 1;
                } else {
                        say("����˵��ʩ�����ֹ�Ȼ���������������\n"
                        "����������û�е��ˣ��Ȿһ��ָ��������ȥ�ɡ�\n");
                        obj= new("/clone/book/sun_book"); 
                        obj->move(ob);
                        message("channel:rumor", 
                        HIM"��"+HIR+"ҥ��"+HIM+"��"+HIR+"ĳ�ˣ�"
                        +this_player()->query("name")+"�����һ��ָ������\n"NOR, users());
                        message_vision("$N����$nһ���顣\n", me, ob);
                        ob->set_temp("sun_book_last_get_time",time());
                        ob->delete_temp("marks/find_temp");
                        ob->delete_temp("marks/ask_temp3");
                        return 1;
                }
        }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
        {
                say(
                   "����˫�ֺ�ʮ������Եһ��������ʩ����ذɡ�\n"
                );
                message_vision("$N�Կ��ٴ�ʦ���������ؿ���һ��ͷ���뿪Ĳ���á�\n", ob);
                ob->move("/d/tianlongsi/banruotai");
                return 1;
        }
        return 1;
}

string ask_six()
{
	mapping skl; 
        object fighter, me, room, monk;
	string *sname;
	int i,j;

	fighter = this_player();
	me = this_object();

	skl = fighter->query_skills();
	if (sizeof(skl) <= 1)
		return RANK_D->query_respect(fighter) + 
		"���������������ʸ���������";
	sname  = keys(skl);
	for(i=0; i<sizeof(skl); i++) {
		if ((skl[sname[i]] < 80) || (sizeof(skl) == 0))
		return RANK_D->query_respect(fighter) + 
		"������㱾��Ҳ�봳��������";
	}

	if ( me->query("assigned_fighter") )
		return RANK_D->query_respect(fighter) + 
		"��������������ս�����������һ��ʱ�������ɡ�";

	say("\n���ٴ�ʦ�����ðɣ���һ��������̨���Ұɡ�\n");

	me->set("assigned_fighter", fighter->query("id")); 		
	
	message_vision("\n���ٴ�ʦ�����뿪��\n\n", fighter);

	if(!( room = find_object("/d/tianlongsi/baodian")) )
		room = load_object("/d/tianlongsi/baodian");
	me->move(room);

	if( !objectp(monk = present("ben yin", room) ))
	{
		move("/d/tianlongsi/munitang");
		message_vision("\n���ٴ�ʦ���˹�����\n\n", fighter);
			return "���ǶԲ��𣬱����ɲ��ڣ��޷�������������\n";	
	}

	message("vision", "\n���ٴ�ʦ���˹�������" + monk->query("name") + "��������˵�˼��䡣\n", room, monk);
	message("vision", monk->query("name") + "���˵�ͷ���첽���˳�ȥ��\n", room, monk);
	monk->move("/d/tianlongsi/munitang");
	me->move("/d/tianlongsi/munitang");
	message("vision", monk->query("name") + "�첽���˹�����\n", room, monk);

	for(j=2; j<6; j++) 
	{
		if(!( room = find_object("/d/tianlongsi/munitang")) )
                room = load_object("/d/tianlongsi/munitang");
  		me->move(room);

		if( !objectp(monk = present(names[j-1], room) ))
		{
	        	me->move("/d/tianlongsi/munitang");
        	        message_vision("\n���ٴ�ʦ���˹�����\n\n", fighter);
			return "���ǶԲ���"+monk->query("name")+"���ڣ��޷�������������\n";	
		}
	}

	me->move("/d/tianlongsi/banruotai");
        call_out("waiting", 1, me);
	return "�ã���Ҷ������ˡ�\n";
}

int waiting(object me)
{
	object fighter;
	int wait_time;

	if( wait_time == 300 )
	{
		say( "���ٴ�ʦ˵�����������������ˣ����ǻ�ȥ�գ�\n\n");
		call_out("do_back", 0, me);		
	}

	if( !objectp( fighter = present( me->query("assigned_fighter"), environment(me) ) ) )
	{
		wait_time++;
		call_out("waiting", 1, me);
	}
	call_out("preparing", 1, me, fighter);

	return 1;
}

int preparing(object me, object fighter)
{
//        object monk, room, ob;
        object room;

	if(!( room = find_object("/d/tianlongsi/banruotai")) )
	room = load_object("/d/tianlongsi/banruotai");

	message("vision", HIY "\n���ٴ�ʦ�������������������Χ��\n" NOR, room);
	message("vision", "\nֻ������������ţ������¸�ɮ�Ǹ���������ɱ��\n"
		"�����ش�Ħ��������Ჽ����Χס��ͨ·��\n\n", room);
	room->delete("exits");

	say( "�����ֵ���׼�����������󼴿̷�����\n\n");

	fighter->delete_temp("beat_count");
	fighter->set_temp("fighting", 1);

	call_out("fighting",  10, me, fighter, 0);

	return 1;
}

int fighting(object me, object fighter, int count)
{
	object monk1, monk2, room1, room2;

	if(!( room1 = find_object("/d/tianlongsi/munitang")) )
	room1 = load_object("/d/tianlongsi/munitang");

	if(!( room2 = find_object("/d/tianlongsi/banruotai")) )
	room2 = load_object("/d/tianlongsi/banruotai");

	if( count <= 4 ) {
		message("vision", "\n�����������ݺᣬ����б�ɣ�\n" NOR, room2);

		monk1 = present(names[count], room1);
		monk1->move(room2);
	}
		
	if( count >= 1 && count <= 5 ) {
		monk2 = present(names[count-1], room2);
		monk2->move(room1);
	}

	if( !find_player(me->query("assigned_fighter")) ||
	!living(fighter) || fighter->query("qi") <= 1 )
	{
		if( objectp(present(me->query("assigned_fighter"), environment(me)) )) {
			fighter->delete_temp("fighting");
			fighter->delete_temp("beat_count");
		}
		monk1->move(room1);

		say( "���ٴ�ʦҡ��ҡͷ��˵������򻹲� ... ����\n\n");
		fighter->delete_temp("fighting");
		command("sigh");
		call_out("do_back", 5, me );
	}
	else if( count >= 5 )
	{
		if( (int)fighter->query_temp("beat_count") >= 5 )	
			call_out("do_recruit", 5, me, fighter);
		else
			call_out("do_back", 5, me );
	}
	else
	{
		count++;
		call_out("fighting", 2, me, fighter, count);
	}
 
	return 1;
}

int do_recruit(object me, object fighter)
{
        object book;
//        mapping ft_fam, my_fam;

	fighter->delete_temp("beat_count");
	fighter->delete_temp("fighting");
	command("say �ٽ���һ�У� \n");
	COMBAT_D->do_attack(this_object(), fighter, query_temp("weapon") );
	if( !living(fighter) || fighter->query("qi") <= 1 )
		say("\n���ٴ�ʦ˵�������ǲ��У� \n");
	else
	{
		say("\n���ٴ�ʦ˵������ϲ�㴳������������ \n");
		if (query("book_count") > 0)
			add("book_count", -1);
		book = new("/clone/book/six_book");
		book->move(this_player());
		book = new("/clone/book/liumai_sword");
		book->move(this_player());
		command("rumor "+this_player()->query("name")+"�õ�������������\n");
		command("�ðɣ����������������ס������ȥ�ɡ�˵�Ų�ȻһЦ��\n");
	}
	call_out("do_back", 5, me );
		
	return 1;
}

int do_back(object me)
{
        object monk, room1, room2;
//        int i;

	message("vision", "\n���ٴ�ʦ���˻��֣�������Ħ���á�\n", environment(me) );

	if(!( room1 = find_object("/d/tianlongsi/banruotai")) )
	room1 = load_object("/d/tianlongsi/banruotai");
	room1->set("exits/north", "/d/tianlongsi/doushuai" );
	room1->set("exits/south", "/d/tianlongsi/munitang");

	if(!( room1 = find_object("/d/tianlongsi/baodian")) )
	room1 = load_object("/d/tianlongsi/baodian");

	if(!( room2 = find_object("/d/tianlongsi/munitang")) )
		room2 = load_object("/d/tianlongsi/munitang");

	if( objectp( monk = present("ben yin", room2) ));
		monk->move(room1);

	me->delete("assigned_fighter");
	this_object()->move("/d/tianlongsi/munitang");
	return 1;
}

string ask_join()
{
	object me;

	me = this_player();

	if( (string)me->query("class")=="bonze" )
		return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ�ƶɮ�������Ц��\n";

	if( (string)me->query("gender") != "����" )
		return "�����ӷ����գ����գ�Ůʩ������������ҷ𣬿�ȥ��ɽ�����ܽ䡣\n";

	me->set_temp("pending/join_bonze", 1);
	return "�����ӷ����գ����գ�ʩ������������ҷ������(kneel)�ܽ䡣\n";
}

int do_kneel()
{
	object me = this_player();

	string name, new_name;

	if( !me->query_temp("pending/join_bonze") )
		return 0;

	message_vision(
		"$N˫�ֺ�ʮ�����������ع���������\n\n"
		"$n˵�ʵ���
        ��һ΢�������������ɾ�һ��΢������
          ����΢���಻������һ������˼ɲ����
��������$N��ͷ�ڷ��������£�ͷ����ͺͺ�ظ���һ��ͷ��������
���굶����������ȸɾ���\n\n",
		me, this_object() );
	name = me->query("name");
	new_name = "��" + name[0..1];
	command("say �ӽ��Ժ���ķ�������" + new_name + "��");
	command("smile");
	me->delete_temp("pending/join_bonze");
	me->set("name", new_name);
	me->set("class", "bonze");
	me->set("K_record", me->query("PKS") + me->query("MKS"));
	me->set("shen_record", me->query("shen"));
        me->set("shen", 0);

	return 1;
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("gender") != "����" )
	{
		command ("say �����ӷ�Ůʩ��ѽ��ƶɮ�ɲ��ҿ������Ц����");
		return;
	}
	if( (string)ob->query("class")!="bonze" )
	{
		command ("say �����ӷ�ƶɮ���ա��׼ҵ��ӡ���");
		return;
	}
        if ((int)ob->query_skill("kurong-changong", 1) < 150) {
                command("say ���ڹ���Ϊ��������򣬽�������Ҳ��ͽ�͡�\n");
                return;
        }
	command("say �����ӷ����գ����գ�");
	command("recruit " + ob->query("id"));
}

