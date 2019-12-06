// xiaofeng.c ����(�Ƿ�)

#include <ansi.h>

inherit NPC;

void check_skills(object ob);
int waiting(object me, object dest);
int checking(object me, object dest);
int do_back(object me);
int do_kill(object me, object dest);

void create()
{
	set_name("����", ({"xiao feng", "xiao", "feng"}));
	set("gender", "����");
	set("nickname",HIB"���ƽ���"NOR);
	set("age", 28);
	set("long", 
		"������ؤ��ǰ�ΰ������򱻷����������˶��������롣\n"
		"�ڽ��������������Ľ�ٸ�����Ϊ�����Ƿ壬��Ľ�١���\n"
		"����һ����ͨ�Ĵֲ����ӣ�������һ���������һϵ��\n"
		"������������࣬���ʮ�ֿ��࣬����һ�������ֿ���ʮ\n"
		"�����Ի������ӣ�˫Ŀ��磬��������\n");
	set("attitude", "peaceful");
	
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("chat_chance", 1);
	set("chat_msg", ({
		"����̾�˿����������������벻�����������ж�����Ȼ�����������һ��Ů����ƭ��\n",
		"�����૵���������ؤ��ġ�����ʮ���ơ���������Ե����Ʒ�����\n",
		(: random_move :),
	}));
	set("inquiry", ([
		"������" : "����������������\n",
		"ؤ��" : "����������������\n",
		"��ʦ" : "�����ȥ�����ŵ��Ұ��ܶ��³�нš�\n",
	]));

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	
	set("combat_exp", 180000);
	set("score", 20000);
	 
	set_skill("force", 120);             // �����ڹ�
	set_skill("huntian-qigong", 120);    // ��������
	set_skill("unarmed", 120);           // ����ȭ��
	set_skill("xianglong-zhang", 120);   // ����ʮ����
	set_skill("dodge", 120);      	     // ��������
	set_skill("xiaoyaoyou", 120);        // ��ң��
	set_skill("parry", 120);             // �����м�
	set_skill("begging", 50);            // �л�����
	set_skill("checking", 50);           // ����;˵
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) )
	{
                remove_call_out("check_skills");
                call_out("check_skills", 2, ob);
        }
}

void check_skills(object ob)
{
	mapping skl; 
	object  me;
	string *sname;
	int i, counter, ob_shen;

	me = this_object();
	skl = ob->query_skills();
        if(!sizeof(skl)) return;
	sname  = sort_array( keys(skl), (: strcmp :) );
	ob_shen = (int)ob->query("shen");

	counter = 0;
	for(i=0; i<sizeof(skl); i++)
	{
		if (skl[sname[i]] >= 100)
			counter++;
	}

	if(counter >= 3)
//	if((counter >= 3) && (ob_shen < 0))
	{
		me->set_leader(ob);
	
		if ( !environment(me)->query("no_fight"))
		{
			call_out("do_kill", 1, me, ob);
			return ;
		}
		else
		{
			call_out("waiting", 0, me, ob);
			return ;
		}
	}
	return ;
}

int do_kill(object me, object dest)
{
	if (!(int)dest->query("yipin/joined"))
	        return 1;
	if( objectp(dest) && present(dest, environment(me))
		 && !environment(me)->query("no_fight"))
	{
		message_vision(HIR "$N��$n˵��������һ��һƷ�ø��־�������"
			+RANK_D->query_rude(dest)+"����������\n" NOR, me, dest);
		me->set_leader(dest);
		me->kill_ob(dest);
		dest->fight_ob(me);

		call_out("checking", 0,  me, dest);
	}
	else  
		call_out("waiting", 1, me, dest);
	
	return 1;
}

int waiting(object me, object dest)
{
	if ( objectp(dest) )
	{
		if (dest->is_ghost())
		{
			call_out("do_back", 1, me);
			return 1;
		}
		else if (me->is_fighting() && present(dest, environment(me)))
		{
			call_out("checking", 0, me);
			return 1;
		}
		else if (living(me) && !environment(dest)->query("no_fight"))
		{
			call_out("do_chase", 0, me);
			return 1;
		}
	}		
	
	remove_call_out("waiting");
	call_out("waiting", 60, me);
    return 1;
}

int checking(object me, object dest)
{
	object ob;

	if (me->is_fighting()) 
	{
		call_out("checking", 1, me);
	        return 1;
	}

	if( objectp(ob = present("corpse", environment(me)))
		 && ob->query("victim_name") ==	dest->query("name") )
	{
		call_out("do_back", 1, me);
        return 1;
	}
	
	call_out("waiting", 0, me, dest);
	return 1;
}

int do_back(object me)
{

	me->move("/d/city/dongdajie2");
	me->set("combat_exp", 1000000);
	message("vision", "�������˹��������������ϵĳ�����΢΢һЦ˵�����ֳ���һ��������\n", 
		environment(), me );

	me->set_leader(0);
	return 1;
}
